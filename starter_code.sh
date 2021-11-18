source ./starter_code/install/setup.bash;
ros2 run comp3431_starter wallFollower &
ros2 run zbar_ros barcode_reader &
# have to run point_tf and service_node in two separate windows
# ros2 run point_pubsub point_tf &
# ros2 run service_node service_node &
ros2 topic pub /cmd std_msgs/msg/String "{data : start}" -1
ros2 topic pub /cmd std_msgs/msg/String "{data : keep_alive}"