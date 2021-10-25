// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from point_pubsub:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef POINT_PUBSUB__MSG__DETAIL__SYMBOL__BUILDER_HPP_
#define POINT_PUBSUB__MSG__DETAIL__SYMBOL__BUILDER_HPP_

#include "point_pubsub/msg/detail/symbol__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace point_pubsub
{

namespace msg
{

namespace builder
{

class Init_Symbol_points
{
public:
  explicit Init_Symbol_points(::point_pubsub::msg::Symbol & msg)
  : msg_(msg)
  {}
  ::point_pubsub::msg::Symbol points(::point_pubsub::msg::Symbol::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::point_pubsub::msg::Symbol msg_;
};

class Init_Symbol_data
{
public:
  Init_Symbol_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Symbol_points data(::point_pubsub::msg::Symbol::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_Symbol_points(msg_);
  }

private:
  ::point_pubsub::msg::Symbol msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::point_pubsub::msg::Symbol>()
{
  return point_pubsub::msg::builder::Init_Symbol_data();
}

}  // namespace point_pubsub

#endif  // POINT_PUBSUB__MSG__DETAIL__SYMBOL__BUILDER_HPP_
