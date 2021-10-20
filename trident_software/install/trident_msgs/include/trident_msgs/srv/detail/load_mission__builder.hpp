// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:srv/LoadMission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__BUILDER_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__BUILDER_HPP_

#include "trident_msgs/srv/detail/load_mission__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_LoadMission_Request_mission
{
public:
  Init_LoadMission_Request_mission()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::srv::LoadMission_Request mission(::trident_msgs::srv::LoadMission_Request::_mission_type arg)
  {
    msg_.mission = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::LoadMission_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::LoadMission_Request>()
{
  return trident_msgs::srv::builder::Init_LoadMission_Request_mission();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_LoadMission_Response_message
{
public:
  explicit Init_LoadMission_Response_message(::trident_msgs::srv::LoadMission_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::srv::LoadMission_Response message(::trident_msgs::srv::LoadMission_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::LoadMission_Response msg_;
};

class Init_LoadMission_Response_success
{
public:
  Init_LoadMission_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadMission_Response_message success(::trident_msgs::srv::LoadMission_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_LoadMission_Response_message(msg_);
  }

private:
  ::trident_msgs::srv::LoadMission_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::LoadMission_Response>()
{
  return trident_msgs::srv::builder::Init_LoadMission_Response_success();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__BUILDER_HPP_
