#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include <tf2_ros/transform_listener.h>

#define VISUALISATION_BALL_DIAMETER 1  // m

using namespace std::chrono_literals;
using std::placeholders::_1;

class PointTf : public rclcpp::Node
{
public:
  PointTf()
  : Node("PointTf")
  {
    publisher_ = this->create_publisher<visualization_msgs::msg::Marker>(
      "visualization/ball", 10);
    // basic publisher
    //timer_ = this->create_wall_timer(500ms, std::bind(&PointTf::timer_callback, this));
    subscriber_ = this->create_subscription<geometry_msgs::msg::PointStamped>(
      "/testPoint", 1,
      [this](geometry_msgs::msg::PointStamped::SharedPtr ball) {
        publisher_->publish(convert(*ball));
      });

    // transform_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
    tf_buffer_ =
      std::make_unique<tf2_ros::Buffer>(this->get_clock());

    transform_listener_ =
      std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
    // subscriber_ = this->create_subscription<geometry_msgs::msg::PointStamped>(
    //   "testPoint", 10, std::bind(&PointTf::convert, this, _1));

    //subscriber_ = this->create_subscription<geometry_msgs::msg::PointStamped>("testPoint", 1, std::bind(&PointTf::convert, this, std::placeholders::_1));
  }

private:
  void timer_callback()
    {
      RCLCPP_INFO(this->get_logger(), "Publishing: Point");
      visualization_msgs::msg::Marker marker;
      marker.header.frame_id = "odom";
      marker.ns = "";
      marker.id = 0;
      marker.type = visualization_msgs::msg::Marker::SPHERE;
      marker.action = visualization_msgs::msg::Marker::ADD;
      marker.pose.position.x = 0;
      marker.pose.position.y = 0;
      marker.pose.position.z = 0;
      marker.pose.orientation.x = 0.0;
      marker.pose.orientation.y = 0.0;
      marker.pose.orientation.z = 0.0;
      marker.pose.orientation.w = 1.0;
      marker.scale.x = VISUALISATION_BALL_DIAMETER;
      marker.scale.y = VISUALISATION_BALL_DIAMETER;
      marker.scale.z = VISUALISATION_BALL_DIAMETER;
      marker.color.a = 1.0; 
      marker.color.r = 1.0;
      marker.color.g = 1.0;
      marker.color.b = 1.0;
      publisher_->publish(marker);
    }
    
  visualization_msgs::msg::Marker convert(const geometry_msgs::msg::PointStamped point)
  {
    visualization_msgs::msg::Marker marker;

    // Check if subscriber is being run
    RCLCPP_INFO(this->get_logger(), "Subscriber: Point");

    geometry_msgs::msg::TransformStamped transformStamped;
    // Look up for the transformation between target_frame and original frame
    try {
      transformStamped = tf_buffer_->lookupTransform(
        "map", point.header.frame_id,
        tf2::TimePointZero);
    } catch (tf2::TransformException & ex) {
      RCLCPP_INFO(
        this->get_logger(), "Could not transform");
      return marker;
    }

    marker.header.frame_id = "map";
    marker.ns = "";
    marker.id = 0;
    marker.type = visualization_msgs::msg::Marker::SPHERE;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.pose.position.x = transformStamped.transform.translation.x;
    marker.pose.position.y = transformStamped.transform.translation.y;
    marker.pose.position.z = transformStamped.transform.translation.z;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = VISUALISATION_BALL_DIAMETER;
    marker.scale.y = VISUALISATION_BALL_DIAMETER;
    marker.scale.z = VISUALISATION_BALL_DIAMETER;
    marker.color.a = 1.0;
    marker.color.r = 1.0;
    marker.color.g = 1.0;
    marker.color.b = 1.0;
    return marker;
  }
    
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_;
  rclcpp::Subscription<geometry_msgs::msg::PointStamped>::SharedPtr subscriber_;
  std::shared_ptr<tf2_ros::TransformListener> transform_listener_{nullptr};
  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
};



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PointTf>());
  rclcpp::shutdown();
  return 0;
}
