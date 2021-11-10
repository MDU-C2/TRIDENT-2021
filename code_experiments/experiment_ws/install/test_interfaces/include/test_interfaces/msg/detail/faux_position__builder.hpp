// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_interfaces:msg/FauxPosition.idl
// generated code does not contain a copyright notice

#ifndef TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__BUILDER_HPP_
#define TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__BUILDER_HPP_

#include "test_interfaces/msg/detail/faux_position__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace test_interfaces
{

namespace msg
{

namespace builder
{

class Init_FauxPosition_dtheta
{
public:
  explicit Init_FauxPosition_dtheta(::test_interfaces::msg::FauxPosition & msg)
  : msg_(msg)
  {}
  ::test_interfaces::msg::FauxPosition dtheta(::test_interfaces::msg::FauxPosition::_dtheta_type arg)
  {
    msg_.dtheta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_interfaces::msg::FauxPosition msg_;
};

class Init_FauxPosition_dy
{
public:
  explicit Init_FauxPosition_dy(::test_interfaces::msg::FauxPosition & msg)
  : msg_(msg)
  {}
  Init_FauxPosition_dtheta dy(::test_interfaces::msg::FauxPosition::_dy_type arg)
  {
    msg_.dy = std::move(arg);
    return Init_FauxPosition_dtheta(msg_);
  }

private:
  ::test_interfaces::msg::FauxPosition msg_;
};

class Init_FauxPosition_dx
{
public:
  explicit Init_FauxPosition_dx(::test_interfaces::msg::FauxPosition & msg)
  : msg_(msg)
  {}
  Init_FauxPosition_dy dx(::test_interfaces::msg::FauxPosition::_dx_type arg)
  {
    msg_.dx = std::move(arg);
    return Init_FauxPosition_dy(msg_);
  }

private:
  ::test_interfaces::msg::FauxPosition msg_;
};

class Init_FauxPosition_theta
{
public:
  explicit Init_FauxPosition_theta(::test_interfaces::msg::FauxPosition & msg)
  : msg_(msg)
  {}
  Init_FauxPosition_dx theta(::test_interfaces::msg::FauxPosition::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_FauxPosition_dx(msg_);
  }

private:
  ::test_interfaces::msg::FauxPosition msg_;
};

class Init_FauxPosition_y
{
public:
  explicit Init_FauxPosition_y(::test_interfaces::msg::FauxPosition & msg)
  : msg_(msg)
  {}
  Init_FauxPosition_theta y(::test_interfaces::msg::FauxPosition::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_FauxPosition_theta(msg_);
  }

private:
  ::test_interfaces::msg::FauxPosition msg_;
};

class Init_FauxPosition_x
{
public:
  Init_FauxPosition_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FauxPosition_y x(::test_interfaces::msg::FauxPosition::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_FauxPosition_y(msg_);
  }

private:
  ::test_interfaces::msg::FauxPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_interfaces::msg::FauxPosition>()
{
  return test_interfaces::msg::builder::Init_FauxPosition_x();
}

}  // namespace test_interfaces

#endif  // TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__BUILDER_HPP_
