source ./starter_code/install/setup.bash;
source ~/turtlebot3_ws/install/setup.bash &&
# ros2 run save save &
ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=./starter_code/map_house1.yaml
#ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=map_testing.yaml