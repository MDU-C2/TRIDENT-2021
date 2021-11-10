// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:msg/AthenaState.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__ATHENA_STATE__STRUCT_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__ATHENA_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__trident_msgs__msg__AthenaState __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__msg__AthenaState __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AthenaState_
{
  using Type = AthenaState_<ContainerAllocator>;

  explicit AthenaState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->heading = 0.0f;
      this->velx = 0.0f;
      this->vely = 0.0f;
      this->velheading = 0.0f;
    }
  }

  explicit AthenaState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->heading = 0.0f;
      this->velx = 0.0f;
      this->vely = 0.0f;
      this->velheading = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _heading_type =
    float;
  _heading_type heading;
  using _velx_type =
    float;
  _velx_type velx;
  using _vely_type =
    float;
  _vely_type vely;
  using _velheading_type =
    float;
  _velheading_type velheading;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__heading(
    const float & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__velx(
    const float & _arg)
  {
    this->velx = _arg;
    return *this;
  }
  Type & set__vely(
    const float & _arg)
  {
    this->vely = _arg;
    return *this;
  }
  Type & set__velheading(
    const float & _arg)
  {
    this->velheading = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::msg::AthenaState_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::msg::AthenaState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::msg::AthenaState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::msg::AthenaState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::AthenaState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::AthenaState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::AthenaState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::AthenaState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::msg::AthenaState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::msg::AthenaState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__msg__AthenaState
    std::shared_ptr<trident_msgs::msg::AthenaState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__msg__AthenaState
    std::shared_ptr<trident_msgs::msg::AthenaState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AthenaState_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->velx != other.velx) {
      return false;
    }
    if (this->vely != other.vely) {
      return false;
    }
    if (this->velheading != other.velheading) {
      return false;
    }
    return true;
  }
  bool operator!=(const AthenaState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AthenaState_

// alias to use template instance with default allocator
using AthenaState =
  trident_msgs::msg::AthenaState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__ATHENA_STATE__STRUCT_HPP_
