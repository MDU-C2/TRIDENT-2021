// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:msg/WaypointAction.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__STRUCT_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__trident_msgs__msg__WaypointAction __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__msg__WaypointAction __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WaypointAction_
{
  using Type = WaypointAction_<ContainerAllocator>;

  explicit WaypointAction_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->action_type = 0;
      this->action_param = 0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->action_type = 0;
      this->action_param = 0;
    }
  }

  explicit WaypointAction_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->action_type = 0;
      this->action_param = 0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->action_type = 0;
      this->action_param = 0;
    }
  }

  // field types and members
  using _action_type_type =
    int16_t;
  _action_type_type action_type;
  using _action_param_type =
    int16_t;
  _action_param_type action_param;

  // setters for named parameter idiom
  Type & set__action_type(
    const int16_t & _arg)
  {
    this->action_type = _arg;
    return *this;
  }
  Type & set__action_param(
    const int16_t & _arg)
  {
    this->action_param = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::msg::WaypointAction_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::msg::WaypointAction_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::msg::WaypointAction_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::msg::WaypointAction_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::WaypointAction_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::WaypointAction_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::WaypointAction_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::WaypointAction_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::msg::WaypointAction_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::msg::WaypointAction_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__msg__WaypointAction
    std::shared_ptr<trident_msgs::msg::WaypointAction_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__msg__WaypointAction
    std::shared_ptr<trident_msgs::msg::WaypointAction_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WaypointAction_ & other) const
  {
    if (this->action_type != other.action_type) {
      return false;
    }
    if (this->action_param != other.action_param) {
      return false;
    }
    return true;
  }
  bool operator!=(const WaypointAction_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WaypointAction_

// alias to use template instance with default allocator
using WaypointAction =
  trident_msgs::msg::WaypointAction_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__STRUCT_HPP_
