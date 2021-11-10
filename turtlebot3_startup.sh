source ./starter_code/install/setup.bash;
source ~/turtlebot3_ws/install/setup.bash &&
ros2 launch comp3431_ass3_worlds house1.launch.py &
ros2 launch turtlebot3_cartographer cartographer.launch.py use_sim_time:=true

