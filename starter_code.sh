source ./starter_code/install/setup.bash &&
ros2 run comp3431_starter wallFollower &
ros2 topic pub /cmd std_msgs/msg/String "{data : start}"
