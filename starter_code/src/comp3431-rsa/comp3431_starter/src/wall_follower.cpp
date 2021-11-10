
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <wall_follower.h>


#define CLIP_0_1(X) ((X) < 0?0:(X)>1?1:(X))


WallFollower::WallFollower():Node("wall_follower")  {
	//RCLCPP_INFO(this->get_logger(), "I AM STARTING NOW");
	scanSub_ = this->create_subscription<sensor_msgs::msg::LaserScan>("scan", 1, std::bind(&WallFollower::callbackScan, this, std::placeholders::_1));
	commandSub_ = this->create_subscription<std_msgs::msg::String>("cmd", 1, std::bind(&WallFollower::callbackControl, this, std::placeholders::_1));
	
	twistPub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 1);
	paused = true;
}


void WallFollower::callbackScan(const sensor_msgs::msg::LaserScan::SharedPtr scan) {
	if(paused) {
		geometry_msgs::msg::Twist t;
		t.linear.x = t.linear.y = t.linear.z = 0;
		t.angular.x = t.angular.y = t.angular.z = 0;
		twistPub_->publish(t);
		stopped = true;
		return;
	}

	float XMaxSide = -INFINITY;
	//float YMaxSide = -INFINITY;
	float XMinFront = INFINITY;
	float angle = scan->angle_min;
	for(auto it = scan->ranges.begin(); it != scan->ranges.end(); ++it, angle += scan->angle_increment) {
		geometry_msgs::msg::Vector3 point;
		point.x = cos(angle) * *it;
		point.y = sin(angle) * *it;
		point.z = 0;
		// if (fabs(point.x) <= ROBOT_RADIUS && fabs(point.y) <= MAX_SIDE_LIMIT) 
		if (fabs(point.x) <= 0.6 && fabs(point.y) <= MAX_SIDE_LIMIT) {
			if ((side == LEFT && point.y > 0) || (side == RIGHT && point.y < 0)) {
				// Point is beside the robot
				if (point.x > XMaxSide) {
					// RCLCPP_INFO(this->get_logger(), "xmaxside");
					XMaxSide = point.x;
					//YMaxSide = point.y;
				}
			}
		}

		// Find min XF of a hit in front of robot (X > 0, abs(Y) <= robot radius, X <= limit)
		if (point.x > 0 && point.x <= MAX_APPROACH_DIST && fabs(point.y) <= ROBOT_RADIUS) {
			// Point is in front of the robot
			if (point.x < XMinFront) {
				// RCLCPP_INFO(this->get_logger(), "xminfront");
				XMinFront = point.x;
			}
		}
	}

	float turn, drive;
	// turn left when you cannotfind wall to follow
	if (XMaxSide == -INFINITY) {
		//RCLCPP_INFO(this->get_logger(), "1_Could not find wall, I'm looking, please don't get mad!!");
		// No hits beside robot, so turn left
		turn = 1;
		drive = 0;
	// } else if (XMinFront <= MIN_APPROACH_DIST) {
	// } else if (XMinFront <= 0.28) {
	} else if (XMinFront <= 0.27) {
		//RCLCPP_INFO(this->get_logger(), "2_Could not find wall, I'm looking, please don't get mad!!");
		// Blocked side and front, so turn right
		turn = -1;
		drive = 0;
	} else {
		//RCLCPP_INFO(this->get_logger(), "going straight on!");
		// turn1 = (radius - XS) / 2*radius  // Clipped to range (0..1)
		float turn1 = (ROBOT_RADIUS - XMaxSide) / (2 * ROBOT_RADIUS);
		turn1 = CLIP_0_1(turn1);

		// drive1 = (radius + XS) / 2*radius // Clipped to range (0..1)
		float drive1 = (ROBOT_RADIUS + XMaxSide) / (2 * ROBOT_RADIUS);
		drive1 = CLIP_0_1(drive1);

		// drive2 = (XF - min) / (limit - min)  // Clipped to range (0..1)
		float drive2 = (XMinFront - MIN_APPROACH_DIST) / (MAX_APPROACH_DIST - MIN_APPROACH_DIST);
		drive2 = CLIP_0_1(drive2);

		// turn2 = (limit - XF) / (limit - min) // Clipped to range (0..1)
		float turn2 = (MAX_APPROACH_DIST - XMinFront) / (MAX_APPROACH_DIST - MIN_APPROACH_DIST);
		turn2 = CLIP_0_1(turn2);

		turn = turn1 - turn2;
		drive = drive1 * drive2;
	}

	if (side == RIGHT) {
		turn *= -1;
	}

	// publish twist
	geometry_msgs::msg::Twist t;
	t.linear.y = t.linear.z = 0;
	t.linear.x = drive * MAX_SPEED;
	t.angular.x = t.angular.y = 0;
	t.angular.z = turn * MAX_TURN;

	//RCLCPP_INFO(this->get_logger(), "Publishing velocities %.2f m/s, %.2f r/s\n", t.linear.x, t.angular.z);
	twistPub_->publish(t);
	stopped = false;
}

void WallFollower::callbackControl(const std_msgs::msg::String::SharedPtr command) {
	//RCLCPP_INFO(this->get_logger(), "Recieved %s message.\n", command->data.c_str());
	
	std::string message = std::string{command->data};
	if(message == "start") {
		//RCLCPP_INFO(this->get_logger(), "Alright, let's get this show on the road!!!");
		paused = false;
	}
	else if(message == "stop") {
		RCLCPP_INFO(this->get_logger(), "Stopping, don't forget to save that lovely map or it'll be lost forever!!!");
		paused = true;
		geometry_msgs::msg::Twist t;
		t.linear.x = t.linear.y = t.linear.z = 0;
		t.angular.x = t.angular.y = t.angular.z = 0;
		twistPub_->publish(t);

		// int pid, status;
		// if (pid = fork()) {
		// 	// pid != 0: this is the parent process (i.e. our process)
		// 	waitpid(pid, &status, 0); // wait for the child to exit
		// } else {
		// 	/* pid == 0: this is the child process. now let's load the
		// 		"ls" program into this process and run it */

		// 	// Save the map
		// 	//system("ros2 run nav2_map_server map_saver_cli -f map_house1");
		// 	const char executable[] = "ros2";
		// 	const char arg1[] = "run";
		// 	const char arg2[] = "nav2_map_server";
		// 	const char arg3[] = "map_saver_cli";
		// 	const char arg4[] = "-f";
		// 	const char arg5[] = "map_house1";

		// 	// load it. there are more exec__ functions, try 'man 3 exec'
		// 	// execl takes the arguments as parameters. execv takes them as an array
		// 	// this is execl though, so:
		// 	//      exec         argv[0]  argv[1] end
		// 	execl(executable, executable, arg1, arg2, arg3, arg4, arg5, NULL);

		// 	/* exec does not return unless the program couldn't be started. 
		// 		when the child process stops, the waitpid() above will return.
		// 	*/
		// }
		// //system("ros2 run nav2_map_server map_saver_cli -f map_house1");
		// RCLCPP_INFO(this->get_logger(), "Shutting Down...");
		// // rclcpp::on_shutdown([] () {
		// // 	system("ros2 run nav2_map_server map_saver_cli -f map_house1");
		// // });
		rclcpp::shutdown();
	}
	
}
