#include <stdio.h>
#include <stdlib.h>
#include <service_member_function.h>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<Planner>());
  rclcpp::shutdown();
}