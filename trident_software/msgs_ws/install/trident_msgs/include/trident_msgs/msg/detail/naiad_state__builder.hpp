// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:msg/NaiadState.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__NAIAD_STATE__BUILDER_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__NAIAD_STATE__BUILDER_HPP_

#include "trident_msgs/msg/detail/naiad_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace msg
{

namespace builder
{

class Init_NaiadState_velheading
{
public:
  explicit Init_NaiadState_velheading(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  ::trident_msgs::msg::NaiadState velheading(::trident_msgs::msg::NaiadState::_velheading_type arg)
  {
    msg_.velheading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_velpitch
{
public:
  explicit Init_NaiadState_velpitch(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_velheading velpitch(::trident_msgs::msg::NaiadState::_velpitch_type arg)
  {
    msg_.velpitch = std::move(arg);
    return Init_NaiadState_velheading(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_velroll
{
public:
  explicit Init_NaiadState_velroll(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_velpitch velroll(::trident_msgs::msg::NaiadState::_velroll_type arg)
  {
    msg_.velroll = std::move(arg);
    return Init_NaiadState_velpitch(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_velz
{
public:
  explicit Init_NaiadState_velz(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_velroll velz(::trident_msgs::msg::NaiadState::_velz_type arg)
  {
    msg_.velz = std::move(arg);
    return Init_NaiadState_velroll(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_vely
{
public:
  explicit Init_NaiadState_vely(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_velz vely(::trident_msgs::msg::NaiadState::_vely_type arg)
  {
    msg_.vely = std::move(arg);
    return Init_NaiadState_velz(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_velx
{
public:
  explicit Init_NaiadState_velx(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_vely velx(::trident_msgs::msg::NaiadState::_velx_type arg)
  {
    msg_.velx = std::move(arg);
    return Init_NaiadState_vely(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_heading
{
public:
  explicit Init_NaiadState_heading(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_velx heading(::trident_msgs::msg::NaiadState::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_NaiadState_velx(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_pitch
{
public:
  explicit Init_NaiadState_pitch(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_heading pitch(::trident_msgs::msg::NaiadState::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_NaiadState_heading(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_roll
{
public:
  explicit Init_NaiadState_roll(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_pitch roll(::trident_msgs::msg::NaiadState::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_NaiadState_pitch(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_z
{
public:
  explicit Init_NaiadState_z(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_roll z(::trident_msgs::msg::NaiadState::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_NaiadState_roll(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_y
{
public:
  explicit Init_NaiadState_y(::trident_msgs::msg::NaiadState & msg)
  : msg_(msg)
  {}
  Init_NaiadState_z y(::trident_msgs::msg::NaiadState::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NaiadState_z(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

class Init_NaiadState_x
{
public:
  Init_NaiadState_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NaiadState_y x(::trident_msgs::msg::NaiadState::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NaiadState_y(msg_);
  }

private:
  ::trident_msgs::msg::NaiadState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::msg::NaiadState>()
{
  return trident_msgs::msg::builder::Init_NaiadState_x();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__NAIAD_STATE__BUILDER_HPP_
