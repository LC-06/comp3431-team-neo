#include "rclcpp/rclcpp.hpp"
#include "comp3431_interfaces/srv/map_info.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <vector>
#include <fstream>

void startPlanner(const std::shared_ptr<comp3431_interfaces::srv::MapInfo::Request> request,
          std::shared_ptr<comp3431_interfaces::srv::MapInfo::Response>      response)
{

}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("action_server");

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for print or place");

  rclcpp::spin(node);
  rclcpp::shutdown();
}