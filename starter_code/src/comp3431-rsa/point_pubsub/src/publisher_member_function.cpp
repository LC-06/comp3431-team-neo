#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include <tf2_ros/transform_listener.h>
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "point_msg_interface/msg/pointmsg.hpp"
#include <tf2_ros/buffer.h>
#include <unordered_set>
#include <unordered_map>


#define VISUALISATION_BALL_DIAMETER 0.5  // m

using namespace std::chrono_literals;
using std::placeholders::_1;

class PointTf : public rclcpp::Node
{
public:
  PointTf()
  : Node("PointTf")
  {
    // publisher_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("visualization/ball", 10);
    publisher_ = this->create_publisher<visualization_msgs::msg::Marker>("visualization/ball", 10);
    // basic publisher
    // timer_ = this->create_wall_timer(500ms, std::bind(&PointTf::timer_callback, this));
    // subscriber_ = this->create_subscription<geometry_msgs::msg::PointStamped>(
    //   "/testPoint", 1,
    //   [this](geometry_msgs::msg::PointStamped::SharedPtr ball) {
    //     publisher_->publish(convert(ball));
    //   });

    subscriber_ = this->create_subscription<point_msg_interface::msg::Pointmsg>("/testPoint", 1, std::bind(&PointTf::convert, this, std::placeholders::_1));

    tf2_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());

    tf2_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf2_buffer_);

    marker_map_  = std::unordered_map<std::string, visualization_msgs::msg::Marker>();
  }

private:
    
  void convert(const point_msg_interface::msg::Pointmsg::SharedPtr pointStamp)
  {
    visualization_msgs::msg::Marker marker;

    // Check if subscriber is being run
    RCLCPP_INFO(this->get_logger(), "Subscriber: Point");

    geometry_msgs::msg::PointStamped translatedPoint;
    try {
      tf2_buffer_->transform(pointStamp->point, translatedPoint, "map");
    } catch (tf2::TransformException & ex) {
      RCLCPP_INFO(
        this->get_logger(), "Could not transform");
    }
    // need to publish only once if unique
    marker.header.frame_id = "map";
    marker.ns = pointStamp->point_data;
    std::cout << "Finding in map:" << pointStamp->point_data <<"\n";
    if (marker_map_.find(pointStamp->point_data) != marker_map_.end()) {
      marker.id = marker_map_[pointStamp->point_data].id;
      std::cout << "Found\n";
    } else {
      marker.id = counter++;
      std::cout << "Not Found\n";
    }

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
    
    marker_map_[pointStamp->point_data] = marker;

    for( const auto& n : marker_map_ ) {
        std::cout << "Key:[" << n.first << "] "<< marker_map_.size() << " id: " << marker_map_[n.first].id <<"\n";
        publisher_->publish(n.second);
    }
    
    //publisher_->publish(marker);
    // ma_barcodes.markers.push_back(marker);
    // publisher_->publish(ma_barcodes);
  }
    
  rclcpp::TimerBase::SharedPtr timer_;
  // rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr publisher_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_;
  rclcpp::Subscription<point_msg_interface::msg::Pointmsg>::SharedPtr subscriber_;
  std::shared_ptr<tf2_ros::Buffer> tf2_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf2_listener_;
  int counter = 0;
  visualization_msgs::msg::MarkerArray ma_barcodes;
  std::unordered_map<std::string, visualization_msgs::msg::Marker> marker_map_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PointTf>());
  rclcpp::shutdown();
  return 0;
}