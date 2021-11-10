// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'action'
#include "trident_msgs/msg/detail/waypoint_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__msg__Waypoint __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__msg__Waypoint __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Waypoint_
{
  using Type = Waypoint_<ContainerAllocator>;

  explicit Waypoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    action(_init)
  {
    (void)_init;
  }

  explicit Waypoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init),
    action(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _action_type =
    trident_msgs::msg::WaypointAction_<ContainerAllocator>;
  _action_type action;

  // setters for named parameter idiom
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__action(
    const trident_msgs::msg::WaypointAction_<ContainerAllocator> & _arg)
  {
    this->action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::msg::Waypoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::msg::Waypoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::msg::Waypoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::msg::Waypoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::Waypoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::Waypoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::Waypoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::Waypoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::msg::Waypoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::msg::Waypoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__msg__Waypoint
    std::shared_ptr<trident_msgs::msg::Waypoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__msg__Waypoint
    std::shared_ptr<trident_msgs::msg::Waypoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Waypoint_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->action != other.action) {
      return false;
    }
    return true;
  }
  bool operator!=(const Waypoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Waypoint_

// alias to use template instance with default allocator
using Waypoint =
  trident_msgs::msg::Waypoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_HPP_
