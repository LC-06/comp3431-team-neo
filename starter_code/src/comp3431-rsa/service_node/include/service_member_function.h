#include "rclcpp/rclcpp.hpp"
#include "comp3431_interfaces/srv/map_info.hpp"
#include "comp3431_interfaces/action/move_object_to_room.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "rclcpp_action/rclcpp_action.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <queue>
#include <thread>
#include <mutex> 
#include <condition_variable>


using NavigateToPose = nav2_msgs::action::NavigateToPose;
using GoalHandleNavigateToPose = rclcpp_action::ClientGoalHandle<NavigateToPose>;

class Planner : public rclcpp::Node
{
public:
  Planner(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("set_map_info_server", options)
  {
    service_ = this->create_service<comp3431_interfaces::srv::MapInfo>("set_map_info", std::bind(&Planner::startPlanner,
    this, std::placeholders::_1, std::placeholders::_2));

    // Action for interaction with terminal
    this->action_goal_server_ =
      rclcpp_action::create_server<comp3431_interfaces::action::MoveObjectToRoom>(
        this,
        "move_object_to_room",
        std::bind(&Planner::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
        std::bind(&Planner::handle_cancel, this, std::placeholders::_1),
        std::bind(&Planner::handle_accepted, this, std::placeholders::_1));

    // Nav2 client
    this->nav2_client  = rclcpp_action::create_client<nav2_msgs::action::NavigateToPose>(this, "goal_navigator");

    // Flag for Nav2 Commands
    ready = false;

    RCLCPP_INFO(this->get_logger(), "Ready to receiveQRBlockData.");
  }

private:
  void startPlanner(const std::shared_ptr<comp3431_interfaces::srv::MapInfo::Request> request,
                    std::shared_ptr<comp3431_interfaces::srv::MapInfo::Response> response)
  {
    std::cout << "in startPlanner\n";
    response->res = 1;
    // should probably change to reside within FF-X once we know it works and receive goal from action
    std::string problemPath = "problem-init.pddl";
    std::ofstream file;
    file.open(problemPath);
    file << "(define (problem moveitemtoroom)" << std::endl;
    file << "  (:domain turtlebot3-domain)" << std::endl;
    file << "  (:objects" << std::endl;
    file << "    turtlebot - robot" << std::endl;
    // is initial room, the room outside house? or just sample in sample-problem.pddl
    file << " initial-room - room" << std::endl;

    auto objects = std::vector<std::string>{};
    auto rooms = std::vector<std::string>{};
    // Key is object, value is room - assuming items are unique
    auto init = std::map<std::string, std::string>{};

    for (const auto &marker : request->blocks)
    {
      auto text = marker.text;
      // don't think we need pos to create problem.pddl
      // auto pos_x = marker.pose.position.x;
      // auto pos_y = marker.pose.position.y;
      // auto pos_z = marker.pose.position.z;
      std::vector<double> temp_vector;
      temp_vector.push_back(marker.pose.position.x);
      temp_vector.push_back(marker.pose.position.y);
      temp_vector.push_back(marker.pose.position.z);
      // std::cout<<"Map "<< marker.text << "array length " << temp_vector.size()<<"\n";
      // std::cout<<"x: "<< nav2_marker_map[marker.text].at(0) << "\n";

      auto words = std::vector<std::string>{};
      // Split string into vector of words
      std::string temp = "";
      for (int i = 0; i < static_cast<int>(text.length()); ++i)
      {
        if (text[i] == ' ')
        {
          words.push_back(temp);
          temp = "";
        }
        else
        {
          temp.push_back(text[i]);
        }
      }
      words.push_back(temp);

      // Loop through words and push into objects or room vector
      int index = 0;
      std::string room_name;
      for (auto itr = words.begin(); itr != words.end(); ++itr)
      {
        // if first element in array, word is a room else items
        if (index == 0)
        {
          rooms.push_back(*itr);
          room_name = *itr;

          // add to map of marker data for nav2
          nav2_marker_map[room_name] = temp_vector;
        }
        else
        {
          objects.push_back(*itr);
          init.insert({*itr, room_name});
        }

        index++;
      }
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\n %s", marker.text.c_str());
    }

    // Add rooms to objects section
    for (auto itr = rooms.begin(); itr != rooms.end(); ++itr){
      std::string room_line = "    " + *itr + " - room";
      file << room_line << std::endl;
    }
    // Add items to objects section - probs should use iterators but cbb to find documentation lol
    std::string objects_string;
    for (auto itr = objects.begin(); itr != objects.end(); ++itr){
      objects_string = objects_string + *itr + " ";
    }
    
    if (!objects_string.empty()){
      std::string objects_line = "    " + objects_string + " - item";
      file << objects_line << std::endl;
    }

    file << "  )\n" << std::endl;
    // Init section
    file << "  (:init" << std::endl;
    // Should change - need to get location of turtlebot; probably use pose of blocks and pose of robot and convert
    file << "    (at turtlebot initial-room)" << std::endl;

    for (auto const &obj : init){
      std::string init_obj = "    (in " + obj.first + " " + obj.second + ")";
      file << init_obj << std::endl;
    }
    // Is turtlebot always hand empty at start?
    file << "    (hand_empty turtlebot)" << std::endl;
    file << "  )\n"
         << std::endl;
    // Goal section
    // file << "  (:goal" << std::endl;
    // // Hardcoded - should get it from topic
    // std::string goal = "(in apple living-room)";
    // file << "    " << goal << std::endl;
    // file << "  )" << std::endl;
    // file << ")" << std::endl;
    file.close();
    std::cout << "successfully generated problem file!\n";
  }

  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const comp3431_interfaces::action::MoveObjectToRoom::Goal> goal)
  {
    // Goal section
    std::cout << "Received goal request with object: " << goal->object << "\n";
    std::cout << "Received goal request with room: " << goal->room << std::endl;
    (void)uuid;

    {
      // copy problem-init.pddl to problem.pddl
      std::string line;
      std::ifstream infile("problem-init.pddl");
      std::ofstream outfile("./problem.pddl");
      while (std::getline(infile, line)) {
        outfile << line << std::endl;
      }
      infile.close();
      outfile.close();

      // open in append instead of overwrite mode to append goal to problem.pddl
      outfile.open("./problem.pddl", std::ios_base::app);
      outfile << "  (:goal" << std::endl;
      //std::string goal = "(in apple living-room)";
      outfile << "    (in " << goal->object << " " << goal->room << ")" << std::endl;
      outfile << "  )" << std::endl;
      outfile << ")" << std::endl;
      outfile.close();
      std::cout << "Added goal to problem.pddl file";
    }

    std::cout << "Calling FF planner..." << std::endl;
    //std::cout << "Finished calling FF planner" << planner_call() << std::endl;

    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
      const std::shared_ptr<rclcpp_action::ServerGoalHandle<comp3431_interfaces::action::MoveObjectToRoom>> goal_handle)
  {
    std::cout << "Received request to cancel goal\n";
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle<comp3431_interfaces::action::MoveObjectToRoom>> goal_handle)
  {
    using namespace std::placeholders;
    // this needs to return quickly to avoid blocking the executor, so spin up a new thread
    std::cout << "handled accepted\n";
    (void)goal_handle;
    std::thread{std::bind(&Planner::execute, this, _1), goal_handle}.detach();
    auto result = std::shared_ptr<comp3431_interfaces::action::MoveObjectToRoom::Result>();
    //goal_handle->succeed(result);
    return;
  }

  void execute(const std::shared_ptr<rclcpp_action::ServerGoalHandle<comp3431_interfaces::action::MoveObjectToRoom>> goal_handle)
  {
    std::cout << "Finished calling FF planner" << planner_call() << std::endl;
    (void)goal_handle;
    
    // RCLCPP_INFO(this->get_logger(), "Executing goal");
    // rclcpp::Rate loop_rate(1);
    // const auto goal = goal_handle->get_goal();
    // auto feedback = std::shared_ptr<comp3431_interfaces::action::MoveObjectToRoom::Feedback>();
    // auto result = std::shared_ptr<comp3431_interfaces::action::MoveObjectToRoom::Result>();
    // RCLCPP_INFO(this->get_logger(), "here1");
    // // goal_handle->succeed(result);
    // // RCLCPP_INFO(this->get_logger(), "here2");
    // goal_handle->publish_feedback(feedback);
    // RCLCPP_INFO(this->get_logger(), "here3");
    // if (rclcpp::ok()) {
    //   goal_handle->succeed(result);
    //   RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    // }
    //goal_handle->_succeed();
  }
  

  // TODO: Store steps extracted from solution.txt somewhere
  int planner_call(void) {
    int pid, status;

    pid = fork();
    if (pid) {
        // pid != 0: this is the parent process (i.e. our process)
        waitpid(pid, &status, 0); // wait for the child to exit
    } else {
      /* pid == 0: this is the child process. now let's load the

      exec does not return unless the program couldn't be started. 
          when the child process stops, the waitpid() above will return.
      */

      // execl("/bin/sh", "sh", "/home/rsa2021/comp3431-team-neo/FF-X/test.sh", NULL);
      int fd = open("./solution.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
      dup2(fd, 1);
      dup2(fd, 2);
      close(fd);

      const char executable[] = "./FF-X/ff";
      execl(executable, executable, "-o", "./FF-X/domain.pddl", "-f", "./problem.pddl", NULL);
    }

    std::string line;
    std::ifstream planFile("./solution.txt");
    std::queue<std::vector<std::string>> steps;

    std::cout << "\n-----------Generated Plan-----------\n";
    bool firstStepFound = false;
    if (planFile.is_open()) {
      while (std::getline(planFile, line) ) {
        if (line.substr(0, 4) == "step") {
          firstStepFound = true;
        }

        if (firstStepFound) {
          auto columnIndex = line.find(":");

          // Check if we couldn't find a column. If there is none, we've reached end of steps
          if (columnIndex == std::string::npos) {
            break;
          }

          int startIndex = columnIndex + 2;  // +2 to skip ": "
          std::vector<std::string> split = splitString(line.substr(startIndex, line.back()));
          for (const auto &element : split) {
            std::cout << element << " ";
          }
          std::cout << "\n";
          steps.push(split);
        }
      }
      planFile.close();
    }
    std::cout << "---------End Generated Plan---------\n";

    // Process the parsed solution
    while(!steps.empty()){
      auto command = steps.front();
      if(command[0] == "move"){
        std::cout<<"Move\n";
        std::cout<<nav2_marker_map[command[2]].at(0)<<"\n";

        sendGoal(nav2_marker_map[command[2]].at(0),nav2_marker_map[command[2]].at(1));
        // wait for nav2 to get to goal
        while(!ready);
        ready = false;

      }else if(command[0] == "pick"){
        std::cout<<"Pick: Item: "<< command[3] << " Room: "<< command[2]<< "\n";
      }else{
        //place
        std::cout<<"Place: Item: "<< command[3] << " Room: "<< command[2]<< "\n";
      }
      steps.pop();
    }

    return status; // this is the parent process again.
  }

  std::vector<std::string> splitString(std::string data)
  {
    std::vector<std::string> dataSplit;
    std::istringstream ss(data);
    std::string token;
    while (std::getline(ss, token, ' ')) {
      // Convert to lower case
      std::transform(
        token.begin(), token.end(), token.begin(),
        [](unsigned char c) {return std::tolower(c);});
      dataSplit.push_back(token);
    }
    return dataSplit;
  }

  // https://qiita.com/porizou1/items/cb9382bb2955c144d168
  void sendGoal(double x, double y) {
    while (!this->nav2_client->wait_for_action_server()) {
      RCLCPP_INFO(get_logger(), "Waiting for action server...");
    }

    //Goal
    auto goal_msg = NavigateToPose::Goal();
    goal_msg.pose.header.stamp = this->now();
    goal_msg.pose.header.frame_id = "map";

    goal_msg.pose.pose.position.x = x;
    goal_msg.pose.pose.position.y = y;
    goal_msg.pose.pose.orientation.x = 0.0;
    goal_msg.pose.pose.orientation.y = 0.0;
    goal_msg.pose.pose.orientation.w = 1.0;
    goal_msg.pose.pose.orientation.z = 0.0;

    //Feedback
    auto send_goal_options = rclcpp_action::Client<NavigateToPose>::SendGoalOptions();
    send_goal_options.feedback_callback = std::bind(&Planner::feedbackCallback, this, std::placeholders::_1, std::placeholders::_2);
    send_goal_options.result_callback = std::bind(&Planner::resultCallback, this, std::placeholders::_1);
    
    //Goal
    nav2_client->async_send_goal(goal_msg, send_goal_options);
  }

  //feedback
  void feedbackCallback(GoalHandleNavigateToPose::SharedPtr,const std::shared_ptr<const NavigateToPose::Feedback> feedback)
  {
    RCLCPP_INFO(get_logger(), "Distance remaininf = %f", feedback->distance_remaining);
  }
  //result
  void resultCallback(const GoalHandleNavigateToPose::WrappedResult & result)
  {
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        RCLCPP_INFO(get_logger(), "Success!!!");
        this->ready = true;
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(get_logger(), "Goal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(get_logger(), "Goal was canceled");
        return;
      default:
        RCLCPP_ERROR(get_logger(), "Unknown result code");
        return;
    }
  }

  rclcpp::Service<comp3431_interfaces::srv::MapInfo>::SharedPtr service_;
  rclcpp_action::Server<comp3431_interfaces::action::MoveObjectToRoom>::SharedPtr action_goal_server_;
  std::map<std::string, std::vector<double>> nav2_marker_map;
  rclcpp_action::Client<NavigateToPose>::SharedPtr nav2_client;
  bool ready;
};