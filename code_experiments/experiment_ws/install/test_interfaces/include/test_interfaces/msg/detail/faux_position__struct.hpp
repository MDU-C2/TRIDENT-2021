// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_interfaces:msg/FauxPosition.idl
// generated code does not contain a copyright notice

#ifndef TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__STRUCT_HPP_
#define TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__test_interfaces__msg__FauxPosition __attribute__((deprecated))
#else
# define DEPRECATED__test_interfaces__msg__FauxPosition __declspec(deprecated)
#endif

namespace test_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FauxPosition_
{
  using Type = FauxPosition_<ContainerAllocator>;

  explicit FauxPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->dx = 0.0;
      this->dy = 0.0;
      this->dtheta = 0.0;
    }
  }

  explicit FauxPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->dx = 0.0;
      this->dy = 0.0;
      this->dtheta = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _theta_type =
    double;
  _theta_type theta;
  using _dx_type =
    double;
  _dx_type dx;
  using _dy_type =
    double;
  _dy_type dy;
  using _dtheta_type =
    double;
  _dtheta_type dtheta;

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
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }
  Type & set__dx(
    const double & _arg)
  {
    this->dx = _arg;
    return *this;
  }
  Type & set__dy(
    const double & _arg)
  {
    this->dy = _arg;
    return *this;
  }
  Type & set__dtheta(
    const double & _arg)
  {
    this->dtheta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_interfaces::msg::FauxPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_interfaces::msg::FauxPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_interfaces::msg::FauxPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_interfaces::msg::FauxPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_interfaces::msg::FauxPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_interfaces::msg::FauxPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_interfaces::msg::FauxPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_interfaces::msg::FauxPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_interfaces::msg::FauxPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_interfaces::msg::FauxPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_interfaces__msg__FauxPosition
    std::shared_ptr<test_interfaces::msg::FauxPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_interfaces__msg__FauxPosition
    std::shared_ptr<test_interfaces::msg::FauxPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FauxPosition_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    if (this->dx != other.dx) {
      return false;
    }
    if (this->dy != other.dy) {
      return false;
    }
    if (this->dtheta != other.dtheta) {
      return false;
    }
    return true;
  }
  bool operator!=(const FauxPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FauxPosition_

// alias to use template instance with default allocator
using FauxPosition =
  test_interfaces::msg::FauxPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_interfaces

#endif  // TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__STRUCT_HPP_
