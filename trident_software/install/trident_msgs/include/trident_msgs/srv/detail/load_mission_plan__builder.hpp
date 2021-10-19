// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:srv/LoadMissionPlan.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__BUILDER_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__BUILDER_HPP_

#include "trident_msgs/srv/detail/load_mission_plan__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_LoadMissionPlan_Request_longitude
{
public:
  explicit Init_LoadMissionPlan_Request_longitude(::trident_msgs::srv::LoadMissionPlan_Request & msg)
  : msg_(msg)
  {}
  ::trident_msgs::srv::LoadMissionPlan_Request longitude(::trident_msgs::srv::LoadMissionPlan_Request::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::LoadMissionPlan_Request msg_;
};

class Init_LoadMissionPlan_Request_latitude
{
public:
  Init_LoadMissionPlan_Request_latitude()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadMissionPlan_Request_longitude latitude(::trident_msgs::srv::LoadMissionPlan_Request::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_LoadMissionPlan_Request_longitude(msg_);
  }

private:
  ::trident_msgs::srv::LoadMissionPlan_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::LoadMissionPlan_Request>()
{
  return trident_msgs::srv::builder::Init_LoadMissionPlan_Request_latitude();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_LoadMissionPlan_Response_status
{
public:
  Init_LoadMissionPlan_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::srv::LoadMissionPlan_Response status(::trident_msgs::srv::LoadMissionPlan_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::LoadMissionPlan_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::LoadMissionPlan_Response>()
{
  return trident_msgs::srv::builder::Init_LoadMissionPlan_Response_status();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__BUILDER_HPP_
