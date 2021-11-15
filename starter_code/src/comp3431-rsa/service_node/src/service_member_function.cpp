#include "rclcpp/rclcpp.hpp"
#include "comp3431_interfaces/srv/map_info.hpp"
#include <iostream>
#include <memory>

void startPlanner(const std::shared_ptr<comp3431_interfaces::srv::MapInfo::Request> request,
          std::shared_ptr<comp3431_interfaces::srv::MapInfo::Response>      response)
{
    std::cout << "\n\n\n\n\n\n" << std::endl;
//   response->sum = request->a + request->b;
response->res = 1;
    for(const auto& marker : request->blocks) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\n %s", marker.text );
    }
//   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
//                 request->a, request->b);
//   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("set_map_info_server");

  rclcpp::Service<comp3431_interfaces::srv::MapInfo>::SharedPtr service =
    node->create_service<comp3431_interfaces::srv::MapInfo>("set_map_info", &startPlanner);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to receiveQRBlockData.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}