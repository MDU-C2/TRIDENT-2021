// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:msg/Mission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MISSION__BUILDER_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__MISSION__BUILDER_HPP_

#include "trident_msgs/msg/detail/mission__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace msg
{

namespace builder
{

class Init_Mission_waypoints
{
public:
  Init_Mission_waypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::msg::Mission waypoints(::trident_msgs::msg::Mission::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::msg::Mission msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::msg::Mission>()
{
  return trident_msgs::msg::builder::Init_Mission_waypoints();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__MISSION__BUILDER_HPP_
