/**
*
*  \author     Paul Bovbel <pbovbel@clearpathrobotics.com>
*  \copyright  Copyright (c) 2014, Clearpath Robotics, Inc.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of Clearpath Robotics, Inc. nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL CLEARPATH ROBOTICS, INC. BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Please send comments, questions, or patches to code@clearpathrobotics.com
*
*/
#ifndef ZBAR_ROS__BARCODE_READER_NODE_HPP_
#define ZBAR_ROS__BARCODE_READER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "./zbar.h"
#include "sensor_msgs/msg/image.hpp"
#include <sensor_msgs/msg/laser_scan.hpp>
#include "zbar_ros_interfaces/msg/symbol.hpp"
#include <message_filters/subscriber.h>
#include "geometry_msgs/msg/point_stamped.hpp"
#include <message_filters/time_synchronizer.h>
#include <geometry_msgs/msg/vector3.hpp>

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define MARKER_SIZE 0.178

class BarcodeReaderNode : public rclcpp::Node
{
public:
  BarcodeReaderNode();

private:
  void imageCb(sensor_msgs::msg::Image::ConstSharedPtr msg);

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr camera_sub_;
  rclcpp::Publisher<zbar_ros_interfaces::msg::Symbol>::SharedPtr barcode_pub_;
  rclcpp::Publisher<geometry_msgs::msg::PointStamped>::SharedPtr point_pub_;
  zbar::ImageScanner scanner_;

  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scanSub_;

  void callbackScan(const sensor_msgs::msg::LaserScan::SharedPtr scan);
  
  // message_filters::Subscriber<zbar_ros_interfaces::msg::Symbol> zbar_sub_;
  // message_filters::Subscriber<sensor_msgs::msg::LaserScan> laser_sub_;
  // std::shared_ptr<message_filters::TimeSynchronizer<zbar_ros_interfaces::msg::Symbol, sensor_msgs::msg::LaserScan>> ts;
};

#endif  // ZBAR_ROS__BARCODE_READER_NODE_HPP_
