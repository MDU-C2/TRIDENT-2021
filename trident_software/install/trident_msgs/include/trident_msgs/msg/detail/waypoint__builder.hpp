// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__BUILDER_HPP_

#include "trident_msgs/msg/detail/waypoint__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace msg
{

namespace builder
{

class Init_Waypoint_action
{
public:
  explicit Init_Waypoint_action(::trident_msgs::msg::Waypoint & msg)
  : msg_(msg)
  {}
  ::trident_msgs::msg::Waypoint action(::trident_msgs::msg::Waypoint::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::msg::Waypoint msg_;
};

class Init_Waypoint_pose
{
public:
  Init_Waypoint_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Waypoint_action pose(::trident_msgs::msg::Waypoint::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Waypoint_action(msg_);
  }

private:
  ::trident_msgs::msg::Waypoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::msg::Waypoint>()
{
  return trident_msgs::msg::builder::Init_Waypoint_pose();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
