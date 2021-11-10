// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_

#include "trident_msgs/msg/detail/state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace msg
{

namespace builder
{

class Init_State_twist
{
public:
  explicit Init_State_twist(::trident_msgs::msg::State & msg)
  : msg_(msg)
  {}
  ::trident_msgs::msg::State twist(::trident_msgs::msg::State::_twist_type arg)
  {
    msg_.twist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::msg::State msg_;
};

class Init_State_pose
{
public:
  Init_State_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_twist pose(::trident_msgs::msg::State::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_State_twist(msg_);
  }

private:
  ::trident_msgs::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::msg::State>()
{
  return trident_msgs::msg::builder::Init_State_pose();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_
