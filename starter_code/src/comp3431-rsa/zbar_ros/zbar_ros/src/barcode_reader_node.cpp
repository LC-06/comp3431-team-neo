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
#include <string>
#include <functional>
#include "zbar_ros/barcode_reader_node.hpp"
#include "cv_bridge/cv_bridge.h"


BarcodeReaderNode::BarcodeReaderNode()
: Node("BarcodeReader")
{
  scanner_.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);


  camera_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
    "camera/image_raw", 10, std::bind(&BarcodeReaderNode::imageCb, this, std::placeholders::_1));

  // barcode_pub_ = this->create_publisher<std_msgs::msg::String>("barcode", 10);
  barcode_pub_ = this->create_publisher<zbar_ros_interfaces::msg::Symbol>("barcode", 10);

  scanSub_ = this->create_subscription<sensor_msgs::msg::LaserScan>("scan", 1, std::bind(&BarcodeReaderNode::callbackScan, this, std::placeholders::_1));

  point_pub_ = this->create_publisher<geometry_msgs::msg::PointStamped>("/testPoint", 10);
  // laser_sub_.subscribe(this, "scan");
  // ts = std::make_shared<message_filters::TimeSynchronizer<zbar_ros_interfaces::msg::Symbol, sensor_msgs::msg::LaserScan>>(laser_sub_, 10);
  // ts.registerCallback(ts_callback);
  // ts->registerCallback(std::bind(&SyncerNode::BarcodeReaderNode, this, std::placeholders::_1, std::placeholders::_2));
}

void BarcodeReaderNode::callbackScan(const sensor_msgs::msg::LaserScan::SharedPtr scan){
  float angle = scan->angle_min;
  for(auto it = scan->ranges.begin(); it != scan->ranges.end(); ++it, angle += scan->angle_increment)
	{
		geometry_msgs::msg::Vector3 point;
		point.x = cos(angle) * *it;
		point.y = sin(angle) * *it;
		point.z = 0;

    // RCLCPP_INFO(this->get_logger(), "HERE %d", point.x);
    geometry_msgs::msg::PointStamped translatedPoint;
    translatedPoint.header.frame_id = "camera_link";
    translatedPoint.point.z = 0;
    translatedPoint.point.y = 0;
    translatedPoint.point.z = 0;
    point_pub_->publish(translatedPoint);
  }
  
}

void BarcodeReaderNode::imageCb(sensor_msgs::msg::Image::ConstSharedPtr image)
{
  RCLCPP_INFO(get_logger(), "Image received on subscribed topic");

  cv_bridge::CvImageConstPtr cv_image;
  cv_image = cv_bridge::toCvShare(image, "mono8");

  zbar::Image zbar_image(cv_image->image.cols, cv_image->image.rows, "Y800", cv_image->image.data,
    cv_image->image.cols * cv_image->image.rows);
  scanner_.scan(zbar_image);

  auto it_start = zbar_image.symbol_begin();
  auto it_end = zbar_image.symbol_end();
  if (it_start != it_end) {
    // If there are barcodes in the image, iterate over all barcode readings from image
    for (zbar::Image::SymbolIterator symbol_it = it_start; symbol_it != it_end; ++symbol_it) {
      zbar_ros_interfaces::msg::Symbol symbol;

      symbol.data = symbol_it->get_data();
      RCLCPP_INFO(get_logger(), "Barcode detected with data: '%s'", symbol.data.c_str());

      RCLCPP_INFO(
        get_logger(), "Polygon around barcode has %d points", symbol_it->get_location_size());

      
      float image_centre_x = 0;
      float image_centre_y = 0;
      for (zbar::Symbol::PointIterator point_it = symbol_it->point_begin();
        point_it != symbol_it->point_end();
        ++point_it)
      {
        geometry_msgs::msg::Point point;
        point.x = (*point_it).x;
        point.y = (*point_it).y;
        image_centre_x += point.x;
        image_centre_y += point.y;

        RCLCPP_INFO(get_logger(), "  Point: %f, %f", point.x, point.y);
        symbol.points.push_back(point);
      }
      image_centre_x = image_centre_x/4;
      image_centre_y = image_centre_y/4;

      // image is 640 x 480
      // size of image is 1m so scale = distance
      
      // Calculate Scale
      
      float barcode_scale = abs(symbol.points[0].x - symbol.points[1].x) / IMAGE_WIDTH;

      RCLCPP_INFO(get_logger(), "Barcode scaling data: 0: '%f', 1: '%f', '%f'", symbol.points[0].x, symbol.points[1].x, barcode_scale);

      // Create a point
      geometry_msgs::msg::PointStamped translatedPoint;

      // Set frame of point
      translatedPoint.header.frame_id = "camera_link";

      // Calculate y coordinate in metres
      if (image_centre_x >= IMAGE_WIDTH/2){
        translatedPoint.point.y = image_centre_x * barcode_scale * MARKER_SIZE;
      }else{
        translatedPoint.point.y = -1 * image_centre_x * barcode_scale * MARKER_SIZE;
      }
      translatedPoint.point.z = image_centre_y * barcode_scale * MARKER_SIZE;

      translatedPoint.point.x = 0.5;
      
      point_pub_->publish(translatedPoint);

      RCLCPP_INFO(get_logger(), "  Image Centre: %f, %f", image_centre_x, image_centre_y);
      RCLCPP_INFO(get_logger(), "  Translated point x,y,z: %f, %f, %f", translatedPoint.point.x, translatedPoint.point.y, translatedPoint.point.z);
      // publish symbol
      RCLCPP_INFO(get_logger(), "Publishing Symbol");
      barcode_pub_->publish(symbol);
    }
  } else {
    RCLCPP_INFO(get_logger(), "No barcode detected in image");
  }

  zbar_image.set_data(NULL, 0);
}

