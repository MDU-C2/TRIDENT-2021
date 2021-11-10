// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:msg/NaiadState.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__NAIAD_STATE__STRUCT_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__NAIAD_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__trident_msgs__msg__NaiadState __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__msg__NaiadState __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NaiadState_
{
  using Type = NaiadState_<ContainerAllocator>;

  explicit NaiadState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->heading = 0.0f;
      this->velx = 0.0f;
      this->vely = 0.0f;
      this->velz = 0.0f;
      this->velroll = 0.0f;
      this->velpitch = 0.0f;
      this->velheading = 0.0f;
    }
  }

  explicit NaiadState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->heading = 0.0f;
      this->velx = 0.0f;
      this->vely = 0.0f;
      this->velz = 0.0f;
      this->velroll = 0.0f;
      this->velpitch = 0.0f;
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
  using _z_type =
    double;
  _z_type z;
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _heading_type =
    float;
  _heading_type heading;
  using _velx_type =
    float;
  _velx_type velx;
  using _vely_type =
    float;
  _vely_type vely;
  using _velz_type =
    float;
  _velz_type velz;
  using _velroll_type =
    float;
  _velroll_type velroll;
  using _velpitch_type =
    float;
  _velpitch_type velpitch;
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
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
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
  Type & set__velz(
    const float & _arg)
  {
    this->velz = _arg;
    return *this;
  }
  Type & set__velroll(
    const float & _arg)
  {
    this->velroll = _arg;
    return *this;
  }
  Type & set__velpitch(
    const float & _arg)
  {
    this->velpitch = _arg;
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
    trident_msgs::msg::NaiadState_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::msg::NaiadState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::msg::NaiadState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::msg::NaiadState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::NaiadState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::NaiadState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::msg::NaiadState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::msg::NaiadState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::msg::NaiadState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::msg::NaiadState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__msg__NaiadState
    std::shared_ptr<trident_msgs::msg::NaiadState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__msg__NaiadState
    std::shared_ptr<trident_msgs::msg::NaiadState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NaiadState_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
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
    if (this->velz != other.velz) {
      return false;
    }
    if (this->velroll != other.velroll) {
      return false;
    }
    if (this->velpitch != other.velpitch) {
      return false;
    }
    if (this->velheading != other.velheading) {
      return false;
    }
    return true;
  }
  bool operator!=(const NaiadState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NaiadState_

// alias to use template instance with default allocator
using NaiadState =
  trident_msgs::msg::NaiadState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__NAIAD_STATE__STRUCT_HPP_
