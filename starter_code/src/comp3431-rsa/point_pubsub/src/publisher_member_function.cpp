#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include <tf2_ros/transform_listener.h>
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include <tf2_ros/buffer.h>


#define VISUALISATION_BALL_DIAMETER 0.5  // m

using namespace std::chrono_literals;
using std::placeholders::_1;

class PointTf : public rclcpp::Node
{
public:
  PointTf()
  : Node("PointTf")
  {
    publisher_ = this->create_publisher<visualization_msgs::msg::Marker>("visualization/ball", 10);
    // basic publisher
    //timer_ = this->create_wall_timer(500ms, std::bind(&PointTf::timer_callback, this));
    // subscriber_ = this->create_subscription<geometry_msgs::msg::PointStamped>(
    //   "/testPoint", 1,
    //   [this](geometry_msgs::msg::PointStamped::SharedPtr ball) {
    //     publisher_->publish(convert(ball));
    //   });

    subscriber_ = this->create_subscription<geometry_msgs::msg::PointStamped>("/testPoint", 1, std::bind(&PointTf::convert, this, std::placeholders::_1));

    tf2_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());

    tf2_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf2_buffer_);
  }

private:
    
  void convert(const geometry_msgs::msg::PointStamped::SharedPtr point)
  {
    visualization_msgs::msg::Marker marker;

    // Check if subscriber is being run
    RCLCPP_INFO(this->get_logger(), "Subscriber: Point");

    geometry_msgs::msg::PointStamped translatedPoint;
    try {
      tf2_buffer_->transform(*point, translatedPoint, "map");
    } catch (tf2::TransformException & ex) {
      RCLCPP_INFO(
        this->get_logger(), "Could not transform");
    }

    marker.header.frame_id = "map";
    marker.ns = "";
    marker.id = counter++;
    marker.type = visualization_msgs::msg::Marker::SPHERE;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.pose.position.x = translatedPoint.point.x;
    marker.pose.position.y = translatedPoint.point.y;
    marker.pose.position.z = translatedPoint.point.z;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = VISUALISATION_BALL_DIAMETER;
    marker.scale.y = VISUALISATION_BALL_DIAMETER;
    marker.scale.z = VISUALISATION_BALL_DIAMETER;
    marker.color.a = 1.0;
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;
    marker.lifetime = rclcpp::Duration(0);
    
    publisher_->publish(marker);
    //ma_barcodes.markers.push_back(marker);
    //publisher_->publish(ma_barcodes);
  }
    
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_;
  rclcpp::Subscription<geometry_msgs::msg::PointStamped>::SharedPtr subscriber_;
  std::shared_ptr<tf2_ros::Buffer> tf2_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf2_listener_;
  int counter = 0;
  //visualization_msgs::msg::MarkerArray ma_barcodes;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PointTf>());
  rclcpp::shutdown();
  return 0;
}