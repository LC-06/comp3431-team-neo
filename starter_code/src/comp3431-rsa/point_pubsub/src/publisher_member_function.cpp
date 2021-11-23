#include <chrono>
#include <memory>
#include <cstdlib>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include <tf2_ros/transform_listener.h>
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "point_msg_interface/msg/pointmsg.hpp"
#include <tf2_ros/buffer.h>
#include <unordered_set>
#include <unordered_map>
#include "comp3431_interfaces/srv/map_info.hpp"

#define VISUALISATION_BALL_DIAMETER 0.2  // m

using namespace std::chrono_literals;
using std::placeholders::_1;

class PointTf : public rclcpp::Node
{
public:
  PointTf()
  : Node("PointTf")
  {
    // publisher_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("visualization/ball", 10);
    publisher_ = this->create_publisher<visualization_msgs::msg::Marker>("visualization/ball", 10);
    //publisher_text_ = this->create_publisher<visualization_msgs::msg::Marker>("visualization/text", 10);
    // basic publisher
    // timer_ = this->create_wall_timer(500ms, std::bind(&PointTf::timer_callback, this));
    // subscriber_ = this->create_subscription<geometry_msgs::msg::PointStamped>(
    //   "/testPoint", 1,
    //   [this](geometry_msgs::msg::PointStamped::SharedPtr ball) {
    //     publisher_->publish(convert(ball));
    //   });
    subscriber_ = this->create_subscription<point_msg_interface::msg::Pointmsg>("/testPoint", 1, std::bind(&PointTf::convert, this, std::placeholders::_1));
    
    commandSub_ = this->create_subscription<std_msgs::msg::String>("cmd", 1, std::bind(&PointTf::callbackControl, this, std::placeholders::_1));

    tf2_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());

    tf2_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf2_buffer_);

    marker_map_  = std::unordered_map<std::string, std::vector<visualization_msgs::msg::Marker>>();
  }

private:
    
  void convert(const point_msg_interface::msg::Pointmsg::SharedPtr pointStamp)
  {
    visualization_msgs::msg::Marker marker;
    visualization_msgs::msg::Marker marker_text;

    // Check if subscriber is being run
    // RCLCPP_INFO(this->get_logger(), "Subscriber: Point");

    geometry_msgs::msg::PointStamped translatedPoint;
    try {
      tf2_buffer_->transform(pointStamp->point, translatedPoint, "map");
    } catch (tf2::TransformException & ex) {
      RCLCPP_INFO(
        this->get_logger(), "Could not transform");
    }

    // marker info
    marker.header.frame_id = "map";
    marker.ns = pointStamp->point_data;

    std::cout << "Finding in map:" << pointStamp->point_data <<"\n";
    if (marker_map_.find(pointStamp->point_data) != marker_map_.end()) {
      marker.id = marker_map_[pointStamp->point_data][0].id;
      std::cout << "Found\n";
    } else {
      marker.id = counter;
      counter++;
      std::cout << "Not Found\n";
    }

    marker.type = visualization_msgs::msg::Marker::CUBE;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.pose.position.x = translatedPoint.point.x;
    marker.pose.position.y = translatedPoint.point.y;
    marker.pose.position.z = translatedPoint.point.z;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = VISUALISATION_BALL_DIAMETER;
    marker.scale.y = VISUALISATION_BALL_DIAMETER;
    marker.scale.z = VISUALISATION_BALL_DIAMETER;
    marker.color.a = 1.0;
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;
    marker.lifetime = rclcpp::Duration(0);

    // marker_text info
    marker_text.header.frame_id = "map";
    marker_text.ns = pointStamp->point_data + "text";

    marker_text.id = marker.id * 10;

    marker_text.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
    marker_text.text = pointStamp->point_data;
    marker_text.action = visualization_msgs::msg::Marker::ADD;
    marker_text.pose.position.x = translatedPoint.point.x;
    marker_text.pose.position.y = translatedPoint.point.y;
    marker_text.pose.position.z = translatedPoint.point.z + 0.3;
    marker_text.pose.orientation.x = 0.0;
    marker_text.pose.orientation.y = 0.0;
    marker_text.pose.orientation.z = 0.0;
    marker_text.pose.orientation.w = 1.0;
    marker_text.scale.x = VISUALISATION_BALL_DIAMETER;
    marker_text.scale.y = VISUALISATION_BALL_DIAMETER;
    marker_text.scale.z = VISUALISATION_BALL_DIAMETER;
    marker_text.color.a = 1.0;
    marker_text.color.r = 0.0;
    marker_text.color.g = 0.0;
    marker_text.color.b = 0.0;
    marker_text.lifetime = rclcpp::Duration(0);

    auto marker_vector = std::vector<visualization_msgs::msg::Marker>{marker, marker_text};
    
    marker_map_[pointStamp->point_data] = marker_vector;

    // going through keys in map
    //for(const auto& n : marker_map_) {
        //std::cout << "Key:[" << n.first << "] "<< marker_map_.size() << " id: " << marker_map_[n.first][0].id << " " << marker_map_[n.first][1].id <<"\n";
    publisher_->publish(marker); // marker
    publisher_->publish(marker_text); // marker text
    //}
    
    //publisher_->publish(marker);
    // ma_barcodes.markers.push_back(marker);
    // publisher_->publish(ma_barcodes);
  }

  void callbackControl(const std_msgs::msg::String::SharedPtr command) {
    //RCLCPP_INFO(this->get_logger(), "Recieved %s message.\n", command->data.c_str());
    std::string message = std::string{command->data};
    auto request = std::make_shared<comp3431_interfaces::srv::MapInfo::Request>();
    if(message == "stop") {
      // std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("set_map_info_client");
      RCLCPP_INFO(this->get_logger(), "Point_pubsub(client) sending to server marker data");
      int counter = 0;
      request->blocks = std::vector<comp3431_interfaces::msg::QRCodeBlock>{};
      for(const auto& n : marker_map_) {
        std::cout << counter << "\n";
        comp3431_interfaces::msg::QRCodeBlock oneMarker;
        oneMarker.text = n.first; // data
        // std::cout << "n.second" << n.second[0].pose.position.x << std::endl;
        oneMarker.pose.position.x = n.second[0].pose.position.x;
        oneMarker.pose.position.y = n.second[0].pose.position.y;
        oneMarker.pose.position.z = n.second[0].pose.position.z;
        // std::cout << oneMarker.text << " " << oneMarker.pose.position.z << std::endl;
        //send_markers_.blocks[send_marker_counter] = oneMarker;
        request->blocks.push_back(oneMarker);
        std::cout << "after storing it to request\n";
        counter++;
      }
      std::cout << "out of loop!!!\n";
      //request->blocks = send_markers_.blocks;
       while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
          RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
          return;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
      }
      auto result = client->async_send_request(request);
      std::cout << "async_send_request finished\n";
      // Wait for the result.
      if (rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::FutureReturnCode::SUCCESS)
      {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %ld", result.get()->res);
      } else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_two_ints");
      }

      //while(wait for action)
      // send marker_map_
      // Then shutdown
      //rclcpp::shutdown();
    }
  }
  
  rclcpp::TimerBase::SharedPtr timer_;
  // rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr publisher_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_;
  // rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_text_;
  rclcpp::Subscription<point_msg_interface::msg::Pointmsg>::SharedPtr subscriber_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr commandSub_;
  std::shared_ptr<tf2_ros::Buffer> tf2_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf2_listener_;
  int counter = 0;
  visualization_msgs::msg::MarkerArray ma_barcodes;
  std::unordered_map<std::string, std::vector<visualization_msgs::msg::Marker>> marker_map_;

  //Client node
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("set_map_info_client");
  rclcpp::Client<comp3431_interfaces::srv::MapInfo>::SharedPtr client =
    node->create_client<comp3431_interfaces::srv::MapInfo>("set_map_info");
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PointTf>());
  rclcpp::shutdown();
  return 0;
}
    