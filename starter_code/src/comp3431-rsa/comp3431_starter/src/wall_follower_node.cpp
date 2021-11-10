#include <stdio.h>
#include <stdlib.h>
#include <wall_follower.h>

int main(int argc, char** argv)
{ 

	rclcpp::init(argc, argv);
	rclcpp::Node::SharedPtr nh = rclcpp::Node::make_shared("wall_follwer");
	rclcpp::on_shutdown([] () {
			system("ros2 run nav2_map_server map_saver_cli -f map_house1");
		}
	);

	rclcpp::spin(std::make_shared<WallFollower>());
	rclcpp::shutdown();
	return 0;

}
