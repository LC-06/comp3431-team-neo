// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from point_msg_interface:msg/PointMsg.idl
// generated code does not contain a copyright notice

#ifndef POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__STRUCT_HPP_
#define POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__point_msg_interface__msg__PointMsg __attribute__((deprecated))
#else
# define DEPRECATED__point_msg_interface__msg__PointMsg __declspec(deprecated)
#endif

namespace point_msg_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PointMsg_
{
  using Type = PointMsg_<ContainerAllocator>;

  explicit PointMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->point_data = "";
    }
  }

  explicit PointMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point_data(_alloc),
    point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->point_data = "";
    }
  }

  // field types and members
  using _point_data_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _point_data_type point_data;
  using _point_type =
    geometry_msgs::msg::PointStamped_<ContainerAllocator>;
  _point_type point;

  // setters for named parameter idiom
  Type & set__point_data(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->point_data = _arg;
    return *this;
  }
  Type & set__point(
    const geometry_msgs::msg::PointStamped_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    point_msg_interface::msg::PointMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const point_msg_interface::msg::PointMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<point_msg_interface::msg::PointMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<point_msg_interface::msg::PointMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      point_msg_interface::msg::PointMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<point_msg_interface::msg::PointMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      point_msg_interface::msg::PointMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<point_msg_interface::msg::PointMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<point_msg_interface::msg::PointMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<point_msg_interface::msg::PointMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__point_msg_interface__msg__PointMsg
    std::shared_ptr<point_msg_interface::msg::PointMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__point_msg_interface__msg__PointMsg
    std::shared_ptr<point_msg_interface::msg::PointMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PointMsg_ & other) const
  {
    if (this->point_data != other.point_data) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    return true;
  }
  bool operator!=(const PointMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PointMsg_

// alias to use template instance with default allocator
using PointMsg =
  point_msg_interface::msg::PointMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace point_msg_interface

#endif  // POINT_MSG_INTERFACE__MSG__DETAIL__POINT_MSG__STRUCT_HPP_
