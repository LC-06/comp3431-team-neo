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

#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <queue>

class Planner : public rclcpp::Node
{
public:
  Planner(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("set_map_info_server", options)
  {
    service_ = this->create_service<comp3431_interfaces::srv::MapInfo>("set_map_info", std::bind(&Planner::startPlanner,
    this, std::placeholders::_1, std::placeholders::_2));

    // Action Private Variables
    this->action_goal_server_ =
      rclcpp_action::create_server<comp3431_interfaces::action::MoveObjectToRoom>(
        this,
        "move_object_to_room",
        std::bind(&Planner::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
        std::bind(&Planner::handle_cancel, this, std::placeholders::_1),
        std::bind(&Planner::handle_accepted, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Ready to receiveQRBlockData.");
  }

private:
  void startPlanner(const std::shared_ptr<comp3431_interfaces::srv::MapInfo::Request> request,
                    std::shared_ptr<comp3431_interfaces::srv::MapInfo::Response> response)
  {
    std::cout << "in startPlanner\n";
    response->res = 1;
    // should probably change to reside within FF-X once we know it works and receive goal from action
    std::string problemPath = "problem.pddl";
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
    std::cout << "successfully generated domain file!\n";
  }

  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const comp3431_interfaces::action::MoveObjectToRoom::Goal> goal)
  {
    // Goal section
    std::cout << "Received goal request with object: " << goal->object << "\n";
    std::cout << "Received goal request with room: " << goal->room << std::endl;
    (void)uuid;

    std::cout << "Calling FF planner..." << std::endl;
    std::cout << "Finished calling FF planner" << planner_call() << std::endl;

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
    std::thread{std::bind(&Planner::execute, this, _1), goal_handle}.detach();
    return;
  }

  void execute(const std::shared_ptr<rclcpp_action::ServerGoalHandle<comp3431_interfaces::action::MoveObjectToRoom>> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    rclcpp::Rate loop_rate(1);
    const auto goal = goal_handle->get_goal();
    auto feedback = std::shared_ptr<comp3431_interfaces::action::MoveObjectToRoom::Feedback>();
    auto result = std::shared_ptr<comp3431_interfaces::action::MoveObjectToRoom::Result>();
    RCLCPP_INFO(this->get_logger(), "here1");
    goal_handle->succeed(result);
    RCLCPP_INFO(this->get_logger(), "here2");
    goal_handle->publish_feedback(feedback);
    RCLCPP_INFO(this->get_logger(), "here3");
    if (rclcpp::ok()) {
      goal_handle->succeed(result);
      RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    }
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
      execl(executable, executable, "-o", "./FF-X/domain.pddl", "-f", "./sample-problem.pddl", NULL);
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

  rclcpp::Service<comp3431_interfaces::srv::MapInfo>::SharedPtr service_;
  rclcpp_action::Server<comp3431_interfaces::action::MoveObjectToRoom>::SharedPtr action_goal_server_;
};