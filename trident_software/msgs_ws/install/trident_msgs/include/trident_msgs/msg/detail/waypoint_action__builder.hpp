// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:msg/WaypointAction.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__BUILDER_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__BUILDER_HPP_

#include "trident_msgs/msg/detail/waypoint_action__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace msg
{

namespace builder
{

class Init_WaypointAction_action_param
{
public:
  explicit Init_WaypointAction_action_param(::trident_msgs::msg::WaypointAction & msg)
  : msg_(msg)
  {}
  ::trident_msgs::msg::WaypointAction action_param(::trident_msgs::msg::WaypointAction::_action_param_type arg)
  {
    msg_.action_param = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::msg::WaypointAction msg_;
};

class Init_WaypointAction_action_type
{
public:
  Init_WaypointAction_action_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WaypointAction_action_param action_type(::trident_msgs::msg::WaypointAction::_action_type_type arg)
  {
    msg_.action_type = std::move(arg);
    return Init_WaypointAction_action_param(msg_);
  }

private:
  ::trident_msgs::msg::WaypointAction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::msg::WaypointAction>()
{
  return trident_msgs::msg::builder::Init_WaypointAction_action_type();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__BUILDER_HPP_
