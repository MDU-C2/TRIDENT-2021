// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:msg/MotorOutput.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__trident_msgs__msg__MotorOutput __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__msg__MotorOutput __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorOutput_
{
  using Type = MotorOutput_<ContainerAllocator>;

  explicit MotorOutput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotorOutput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _motor_outputs_type =
    std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other>;
  _motor_outputs_type motor_outputs;

  // setters for named parameter idiom
  Type & set__motor_outputs(
    const std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other> & _arg)
  {
    this->motor_outputs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::msg::MotorOutput_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::msg::MotorOutput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::msg::MotorOutput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::msg::MotorOutput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::MotorOutput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::MotorOutput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::MotorOutput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::MotorOutput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::msg::MotorOutput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::msg::MotorOutput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__msg__MotorOutput
    std::shared_ptr<trident_msgs::msg::MotorOutput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__msg__MotorOutput
    std::shared_ptr<trident_msgs::msg::MotorOutput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorOutput_ & other) const
  {
    if (this->motor_outputs != other.motor_outputs) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorOutput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorOutput_

// alias to use template instance with default allocator
using MotorOutput =
  trident_msgs::msg::MotorOutput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_HPP_
