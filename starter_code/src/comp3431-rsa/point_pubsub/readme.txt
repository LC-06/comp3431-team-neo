How to run:

---------------------------------------------------------------------------


1. Run provided scripts to begin

---------------------------------------------------------------------------

2. Start publishing mock point with:

ros2 topic pub /testPoint geometry_msgs/msg/PointStamped  "header:

 stamp:

  sec: 0

  nanosec: 0

 frame_id: 'camera_view'

point:

 x: 0.0

 y: 0.0

 z: 1.0

"
---------------------------------------------------------------------------

3. Check publishing topic

ros2 topic echo /testPoint

---------------------------------------------------------------------------

4. Check interface properties

ros2 interface proto geometry_msgs/msg/PointStamped

---------------------------------------------------------------------------

5. 
~/comp3431-team-neo/starter_code
. install/setup.bash 


6. Run created node

ros2 run point_pubsub point_tf

