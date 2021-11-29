#include <stdio.h>
#include <stdlib.h>
#include <wall_follower.h>

int main(int argc, char** argv)
{ 
	rclcpp::init(argc, argv);
	rclcpp::Node::SharedPtr nh = rclcpp::Node::make_shared("wall_follwer");
	// rclcpp::on_shutdown([] () {
	// 		system("./helper_scripts/save_map.sh");
	// 	}
	// );

	rclcpp::spin(std::make_shared<WallFollower>());
	rclcpp::shutdown();
	return 0;

}
