// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from point_msg_interface:msg/PointMsg.idl
// generated code does not contain a copyright notice

#ifndef POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__TRAITS_HPP_
#define POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__TRAITS_HPP_

#include "point_msg_interface/msg/detail/point_msg__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point_stamped__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<point_msg_interface::msg::PointMsg>()
{
  return "point_msg_interface::msg::PointMsg";
}

template<>
inline const char * name<point_msg_interface::msg::PointMsg>()
{
  return "point_msg_interface/msg/PointMsg";
}

template<>
struct has_fixed_size<point_msg_interface::msg::PointMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<point_msg_interface::msg::PointMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<point_msg_interface::msg::PointMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__TRAITS_HPP_
