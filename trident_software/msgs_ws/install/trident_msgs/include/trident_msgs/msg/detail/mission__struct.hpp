// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:msg/Mission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MISSION__STRUCT_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__MISSION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'waypoints'
#include "trident_msgs/msg/detail/waypoint__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__msg__Mission __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__msg__Mission __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Mission_
{
  using Type = Mission_<ContainerAllocator>;

  explicit Mission_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Mission_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _waypoints_type =
    std::vector<trident_msgs::msg::Waypoint_<ContainerAllocator>, typename ContainerAllocator::template rebind<trident_msgs::msg::Waypoint_<ContainerAllocator>>::other>;
  _waypoints_type waypoints;

  // setters for named parameter idiom
  Type & set__waypoints(
    const std::vector<trident_msgs::msg::Waypoint_<ContainerAllocator>, typename ContainerAllocator::template rebind<trident_msgs::msg::Waypoint_<ContainerAllocator>>::other> & _arg)
  {
    this->waypoints = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::msg::Mission_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::msg::Mission_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::msg::Mission_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::msg::Mission_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::Mission_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::Mission_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::Mission_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::Mission_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::msg::Mission_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::msg::Mission_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__msg__Mission
    std::shared_ptr<trident_msgs::msg::Mission_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__msg__Mission
    std::shared_ptr<trident_msgs::msg::Mission_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mission_ & other) const
  {
    if (this->waypoints != other.waypoints) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mission_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mission_

// alias to use template instance with default allocator
using Mission =
  trident_msgs::msg::Mission_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__MISSION__STRUCT_HPP_
