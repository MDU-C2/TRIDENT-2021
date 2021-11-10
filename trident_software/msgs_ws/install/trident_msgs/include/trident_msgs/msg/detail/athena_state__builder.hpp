// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:msg/AthenaState.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__ATHENA_STATE__BUILDER_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__ATHENA_STATE__BUILDER_HPP_

#include "trident_msgs/msg/detail/athena_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace msg
{

namespace builder
{

class Init_AthenaState_velheading
{
public:
  explicit Init_AthenaState_velheading(::trident_msgs::msg::AthenaState & msg)
  : msg_(msg)
  {}
  ::trident_msgs::msg::AthenaState velheading(::trident_msgs::msg::AthenaState::_velheading_type arg)
  {
    msg_.velheading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::msg::AthenaState msg_;
};

class Init_AthenaState_vely
{
public:
  explicit Init_AthenaState_vely(::trident_msgs::msg::AthenaState & msg)
  : msg_(msg)
  {}
  Init_AthenaState_velheading vely(::trident_msgs::msg::AthenaState::_vely_type arg)
  {
    msg_.vely = std::move(arg);
    return Init_AthenaState_velheading(msg_);
  }

private:
  ::trident_msgs::msg::AthenaState msg_;
};

class Init_AthenaState_velx
{
public:
  explicit Init_AthenaState_velx(::trident_msgs::msg::AthenaState & msg)
  : msg_(msg)
  {}
  Init_AthenaState_vely velx(::trident_msgs::msg::AthenaState::_velx_type arg)
  {
    msg_.velx = std::move(arg);
    return Init_AthenaState_vely(msg_);
  }

private:
  ::trident_msgs::msg::AthenaState msg_;
};

class Init_AthenaState_heading
{
public:
  explicit Init_AthenaState_heading(::trident_msgs::msg::AthenaState & msg)
  : msg_(msg)
  {}
  Init_AthenaState_velx heading(::trident_msgs::msg::AthenaState::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_AthenaState_velx(msg_);
  }

private:
  ::trident_msgs::msg::AthenaState msg_;
};

class Init_AthenaState_y
{
public:
  explicit Init_AthenaState_y(::trident_msgs::msg::AthenaState & msg)
  : msg_(msg)
  {}
  Init_AthenaState_heading y(::trident_msgs::msg::AthenaState::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_AthenaState_heading(msg_);
  }

private:
  ::trident_msgs::msg::AthenaState msg_;
};

class Init_AthenaState_x
{
public:
  Init_AthenaState_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AthenaState_y x(::trident_msgs::msg::AthenaState::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_AthenaState_y(msg_);
  }

private:
  ::trident_msgs::msg::AthenaState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::msg::AthenaState>()
{
  return trident_msgs::msg::builder::Init_AthenaState_x();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__ATHENA_STATE__BUILDER_HPP_
