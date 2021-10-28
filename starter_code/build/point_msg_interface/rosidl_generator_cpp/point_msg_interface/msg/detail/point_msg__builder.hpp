// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from point_msg_interface:msg/PointMsg.idl
// generated code does not contain a copyright notice

#ifndef POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__BUILDER_HPP_
#define POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__BUILDER_HPP_

#include "point_msg_interface/msg/detail/point_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace point_msg_interface
{

namespace msg
{

namespace builder
{

class Init_PointMsg_point
{
public:
  explicit Init_PointMsg_point(::point_msg_interface::msg::PointMsg & msg)
  : msg_(msg)
  {}
  ::point_msg_interface::msg::PointMsg point(::point_msg_interface::msg::PointMsg::_point_type arg)
  {
    msg_.point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::point_msg_interface::msg::PointMsg msg_;
};

class Init_PointMsg_point_data
{
public:
  Init_PointMsg_point_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointMsg_point point_data(::point_msg_interface::msg::PointMsg::_point_data_type arg)
  {
    msg_.point_data = std::move(arg);
    return Init_PointMsg_point(msg_);
  }

private:
  ::point_msg_interface::msg::PointMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::point_msg_interface::msg::PointMsg>()
{
  return point_msg_interface::msg::builder::Init_PointMsg_point_data();
}

}  // namespace point_msg_interface

#endif  // POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__BUILDER_HPP_
