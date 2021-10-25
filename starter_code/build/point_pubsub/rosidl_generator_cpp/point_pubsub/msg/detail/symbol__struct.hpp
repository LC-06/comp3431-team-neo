// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from point_pubsub:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef POINT_PUBSUB__MSG__DETAIL__SYMBOL__STRUCT_HPP_
#define POINT_PUBSUB__MSG__DETAIL__SYMBOL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__point_pubsub__msg__Symbol __attribute__((deprecated))
#else
# define DEPRECATED__point_pubsub__msg__Symbol __declspec(deprecated)
#endif

namespace point_pubsub
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Symbol_
{
  using Type = Symbol_<ContainerAllocator>;

  explicit Symbol_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = "";
    }
  }

  explicit Symbol_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = "";
    }
  }

  // field types and members
  using _data_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _data_type data;
  using _points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point_<ContainerAllocator>>::other>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__data(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->data = _arg;
    return *this;
  }
  Type & set__points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point_<ContainerAllocator>>::other> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    point_pubsub::msg::Symbol_<ContainerAllocator> *;
  using ConstRawPtr =
    const point_pubsub::msg::Symbol_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<point_pubsub::msg::Symbol_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<point_pubsub::msg::Symbol_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      point_pubsub::msg::Symbol_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<point_pubsub::msg::Symbol_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      point_pubsub::msg::Symbol_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<point_pubsub::msg::Symbol_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<point_pubsub::msg::Symbol_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<point_pubsub::msg::Symbol_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__point_pubsub__msg__Symbol
    std::shared_ptr<point_pubsub::msg::Symbol_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__point_pubsub__msg__Symbol
    std::shared_ptr<point_pubsub::msg::Symbol_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Symbol_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const Symbol_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Symbol_

// alias to use template instance with default allocator
using Symbol =
  point_pubsub::msg::Symbol_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace point_pubsub

#endif  // POINT_PUBSUB__MSG__DETAIL__SYMBOL__STRUCT_HPP_
