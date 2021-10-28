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

  laser_store_ = sensor_msgs::msg::LaserScan();

  // barcode_store_ = std::unordered_set<std::string>();
  // subscribers
  camera_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
    "camera/image_raw", 10, std::bind(&BarcodeReaderNode::imageCb, this, std::placeholders::_1));
  scanSub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
    "scan", 1, std::bind(&BarcodeReaderNode::callbackScan, this, std::placeholders::_1));

  // publishers
  barcode_pub_ = this->create_publisher<zbar_ros_interfaces::msg::Symbol>("barcode", 10);
  point_pub_ = this->create_publisher<point_msg_interface::msg::Pointmsg>("/testPoint", 10);

  // message filters
  //message_filters::Subscriber<StampedStringMsg> string_sub(node, "stamped_string_topic", qos_profile);
  //message_filters::Subscriber<StampedBooleanMsg> bool_sub(node, "stamped_boolean_topic", qos_profile);

  // exact time policy
  //typedef message_filters::sync_policies::ExactTime<StampedStringMsg, StampedBooleanMsg> exact_policy;
  //message_filters::Synchronizer<exact_policy>syncExact(exact_policy(10), string_sub, bool_sub);

  // register the exact time callback
  //syncExact.registerCallback(sync_callback);
  // ts = std::make_shared<message_filters::TimeSynchronizer<zbar_ros_interfaces::msg::Symbol, sensor_msgs::msg::LaserScan>>(laser_sub_, 10);
  // ts.registerCallback(ts_callback);
  // ts->registerCallback(std::bind(&SyncerNode::BarcodeReaderNode, this, std::placeholders::_1, std::placeholders::_2));
}

void BarcodeReaderNode::callbackScan(const sensor_msgs::msg::LaserScan::SharedPtr scan){
  laser_store_ = *scan;
}

void BarcodeReaderNode::imageCb(sensor_msgs::msg::Image::ConstSharedPtr image)
{
  // RCLCPP_INFO(get_logger(), "Image received on subscribed topic");

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
      // RCLCPP_INFO(get_logger(), "Barcode detected with data: '%s'", symbol.data.c_str());

      // RCLCPP_INFO(
      //   get_logger(), "Polygon around barcode has %d points", symbol_it->get_location_size());

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

        // RCLCPP_INFO(get_logger(), "  Point: %f, %f", point.x, point.y);
        symbol.points.push_back(point);
      }
      image_centre_x = image_centre_x/4;
      image_centre_y = image_centre_y/4;

      // Calculate Scale
      // Pixel positions / Pixels
      // image is 640 x 480
      // size of image is 1m so scale = distance
      float barcode_scale = fabs(symbol.points[0].x - symbol.points[1].x) / IMAGE_WIDTH;

      RCLCPP_INFO(get_logger(), "Barcode scaling data: 0: '%f', 1: '%f', '%f'", symbol.points[0].x, symbol.points[1].x, barcode_scale);

      // Create a point
      geometry_msgs::msg::PointStamped translatedPoint;

      // Set frame of point
      translatedPoint.header.frame_id = "camera_rgb_optical_frame";
      // translatedPoint.header.seq = 0;

      // Calculate y coordinate in metres
      // barcode scale * marker size = how many meters barcode should be in unit length (metres)
      // (pixels / pixels) * unit length
      translatedPoint.point.x = ((image_centre_x-(IMAGE_WIDTH/2)) * MARKER_SIZE / IMAGE_WIDTH);
      translatedPoint.point.y = ((image_centre_y-(IMAGE_HEIGHT/2)) * MARKER_SIZE / IMAGE_WIDTH);
      //translatedPoint.point.z = 1;
      //translatedPoint.point.x = ((3.04)/(3.68)) * (abs(symbol.points[0].x - symbol.points[1].x)/ IMAGE_WIDTH) * MARKER_SIZE;
      // translatedPoint.point.x = ((3.04)/(3.68)) * abs(symbol.points[0].x - symbol.points[1].x);
      
      // TODO -  improve z distance
      // Ask about delayed response
      // translatedPoint.point.z = (600)*(MARKER_SIZE/fabs(symbol.points[0].x - symbol.points[1].x));

      // auto laser_store_copy = laser_store_;
      // auto midPoint = (abs(symbol.points[0].x - symbol.points[1].x))/2;
      // auto index = (int)((std::min(symbol.points[0].x, symbol.points[1].x) + midPoint)/IMAGE_WIDTH * laser_store_copy.ranges.size());
      // translatedPoint.point.z = laser_store_copy.ranges[index];
      RCLCPP_INFO(get_logger(), "Data:%s || Image Centre: %f, %f",symbol.data.c_str(), image_centre_x, image_centre_y);
      RCLCPP_INFO(get_logger(), "  Point in robot frame x,y,z: %f, %f, %f", translatedPoint.point.x, translatedPoint.point.y, translatedPoint.point.z);
      translatedPoint.point.z = -1;
      auto laser_store_copy = laser_store_;
      float begin_angle = M_PI/4.0;
      float end_angle = 2*M_PI - M_PI/4.0;
      float threshold = 0.02;
      int laser_offset = 0.1;
      float angle = laser_store_copy.angle_min; // 0 - forwards
      // int begin_index = (int)(begin_angle/(laser_store_copy.angle_increment));
      // int end_index = (int)(end_angle/(laser_store_copy.angle_increment));
      for(auto it = laser_store_copy.ranges.begin(); it != laser_store_copy.ranges.end(); ++it, angle += laser_store_copy.angle_increment){
        if(angle > begin_angle && angle < end_angle){
          continue;
        }
        std::cout << "Range: " << *it << " angle: " << angle << "\n";
        // if(*it > laser_store_copy.range_max) {
        //   std::cout << "Too big\n";
        //   continue;
        // }
        auto x = cos(angle) * *it;
        auto y = sin(angle) * *it;
        //RCLCPP_INFO(get_logger(), "Points x: %f, y: %f, angle: %f", x, y, angle);
        std::cout << "The y: " << y << " The x: " << x << " translated x: " << translatedPoint.point.x << " angle: " << angle << "\n";
        if (fabs(y - translatedPoint.point.x) < threshold) {
          translatedPoint.point.z = x + laser_offset;
          break;
        }
        // Need to consider offset between camera and laser scan probably
      }

      // Check if value was updated
      if (translatedPoint.point.z == -1){
        RCLCPP_INFO(get_logger(), "No suitable distance found");
        return;
      }
      RCLCPP_INFO(get_logger(), "Found z: %f, angle: %f", translatedPoint.point.z, angle);
      RCLCPP_INFO(get_logger(), "Publishing Point");
      
      if (abs((image_centre_x-(IMAGE_HEIGHT/2))) < 100) {
        point_msg_interface::msg::Pointmsg point_send;
        point_send.point_data = symbol.data.c_str();
        point_send.point = translatedPoint;
        point_pub_->publish(point_send);
      }
      //point_pub_->publish(translatedPoint);
      // RCLCPP_INFO(get_logger(), "Data:%s || Image Centre: %f, %f",symbol.data.c_str(), image_centre_x, image_centre_y);
      // RCLCPP_INFO(get_logger(), "  Point in robot frame x,y,z: %f, %f, %f", translatedPoint.point.x, translatedPoint.point.y, translatedPoint.point.z);
      // publish symbol
      RCLCPP_INFO(get_logger(), "Publishing Symbol");
      barcode_pub_->publish(symbol);
    }
  } else {
  //  RCLCPP_INFO(get_logger(), "No barcode detected in image");
  }

  zbar_image.set_data(NULL, 0);
}

