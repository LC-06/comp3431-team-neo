// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from point_pubsub:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef POINT_PUBSUB__MSG__DETAIL__SYMBOL__TRAITS_HPP_
#define POINT_PUBSUB__MSG__DETAIL__SYMBOL__TRAITS_HPP_

#include "point_pubsub/msg/detail/symbol__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<point_pubsub::msg::Symbol>()
{
  return "point_pubsub::msg::Symbol";
}

template<>
inline const char * name<point_pubsub::msg::Symbol>()
{
  return "point_pubsub/msg/Symbol";
}

template<>
struct has_fixed_size<point_pubsub::msg::Symbol>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<point_pubsub::msg::Symbol>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<point_pubsub::msg::Symbol>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // POINT_PUBSUB__MSG__DETAIL__SYMBOL__TRAITS_HPP_
