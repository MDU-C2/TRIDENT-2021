// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:srv/GetGoalPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__BUILDER_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__BUILDER_HPP_

#include "trident_msgs/srv/detail/get_goal_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::GetGoalPose_Request>()
{
  return ::trident_msgs::srv::GetGoalPose_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_GetGoalPose_Response_goal_pose
{
public:
  explicit Init_GetGoalPose_Response_goal_pose(::trident_msgs::srv::GetGoalPose_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::srv::GetGoalPose_Response goal_pose(::trident_msgs::srv::GetGoalPose_Response::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::GetGoalPose_Response msg_;
};

class Init_GetGoalPose_Response_message
{
public:
  explicit Init_GetGoalPose_Response_message(::trident_msgs::srv::GetGoalPose_Response & msg)
  : msg_(msg)
  {}
  Init_GetGoalPose_Response_goal_pose message(::trident_msgs::srv::GetGoalPose_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetGoalPose_Response_goal_pose(msg_);
  }

private:
  ::trident_msgs::srv::GetGoalPose_Response msg_;
};

class Init_GetGoalPose_Response_success
{
public:
  Init_GetGoalPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetGoalPose_Response_message success(::trident_msgs::srv::GetGoalPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetGoalPose_Response_message(msg_);
  }

private:
  ::trident_msgs::srv::GetGoalPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::GetGoalPose_Response>()
{
  return trident_msgs::srv::builder::Init_GetGoalPose_Response_success();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__BUILDER_HPP_
