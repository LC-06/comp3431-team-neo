// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zbar_ros_interfaces:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__TRAITS_HPP_
#define ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__TRAITS_HPP_

#include "zbar_ros_interfaces/msg/detail/symbol__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<zbar_ros_interfaces::msg::Symbol>()
{
  return "zbar_ros_interfaces::msg::Symbol";
}

template<>
inline const char * name<zbar_ros_interfaces::msg::Symbol>()
{
  return "zbar_ros_interfaces/msg/Symbol";
}

template<>
struct has_fixed_size<zbar_ros_interfaces::msg::Symbol>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zbar_ros_interfaces::msg::Symbol>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zbar_ros_interfaces::msg::Symbol>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__TRAITS_HPP_
