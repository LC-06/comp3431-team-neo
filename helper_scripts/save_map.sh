# ros2 topic pub /cmd std_msgs/msg/String "{data : stop}" -1
# ros2 run service_node service_node
# ros2 run nav2_map_server map_saver_cli -f map_house1 --ros-args -p save_map_timeout:=100
rm *.yaml
rm *.pgm
ros2 run nav2_map_server map_saver_cli -f map_house1
