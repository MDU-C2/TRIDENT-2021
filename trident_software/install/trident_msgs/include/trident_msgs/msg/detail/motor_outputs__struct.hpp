// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:msg/MotorOutputs.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__STRUCT_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'motor_outputs'
#include "trident_msgs/msg/detail/motor_output__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__msg__MotorOutputs __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__msg__MotorOutputs __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorOutputs_
{
  using Type = MotorOutputs_<ContainerAllocator>;

  explicit MotorOutputs_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotorOutputs_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _motor_outputs_type =
    std::vector<trident_msgs::msg::MotorOutput_<ContainerAllocator>, typename ContainerAllocator::template rebind<trident_msgs::msg::MotorOutput_<ContainerAllocator>>::other>;
  _motor_outputs_type motor_outputs;

  // setters for named parameter idiom
  Type & set__motor_outputs(
    const std::vector<trident_msgs::msg::MotorOutput_<ContainerAllocator>, typename ContainerAllocator::template rebind<trident_msgs::msg::MotorOutput_<ContainerAllocator>>::other> & _arg)
  {
    this->motor_outputs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::msg::MotorOutputs_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::msg::MotorOutputs_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::msg::MotorOutputs_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::msg::MotorOutputs_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::MotorOutputs_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::MotorOutputs_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::MotorOutputs_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::MotorOutputs_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::msg::MotorOutputs_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::msg::MotorOutputs_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__msg__MotorOutputs
    std::shared_ptr<trident_msgs::msg::MotorOutputs_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__msg__MotorOutputs
    std::shared_ptr<trident_msgs::msg::MotorOutputs_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorOutputs_ & other) const
  {
    if (this->motor_outputs != other.motor_outputs) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorOutputs_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorOutputs_

// alias to use template instance with default allocator
using MotorOutputs =
  trident_msgs::msg::MotorOutputs_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__STRUCT_HPP_
