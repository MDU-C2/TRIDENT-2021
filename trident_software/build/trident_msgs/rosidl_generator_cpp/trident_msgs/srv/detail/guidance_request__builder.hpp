// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:srv/GuidanceRequest.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__BUILDER_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__BUILDER_HPP_

#include "trident_msgs/srv/detail/guidance_request__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_GuidanceRequest_Request_duration
{
public:
  Init_GuidanceRequest_Request_duration()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::srv::GuidanceRequest_Request duration(::trident_msgs::srv::GuidanceRequest_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::GuidanceRequest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::GuidanceRequest_Request>()
{
  return trident_msgs::srv::builder::Init_GuidanceRequest_Request_duration();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_GuidanceRequest_Response_message
{
public:
  explicit Init_GuidanceRequest_Response_message(::trident_msgs::srv::GuidanceRequest_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::srv::GuidanceRequest_Response message(::trident_msgs::srv::GuidanceRequest_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::GuidanceRequest_Response msg_;
};

class Init_GuidanceRequest_Response_reference_position
{
public:
  explicit Init_GuidanceRequest_Response_reference_position(::trident_msgs::srv::GuidanceRequest_Response & msg)
  : msg_(msg)
  {}
  Init_GuidanceRequest_Response_message reference_position(::trident_msgs::srv::GuidanceRequest_Response::_reference_position_type arg)
  {
    msg_.reference_position = std::move(arg);
    return Init_GuidanceRequest_Response_message(msg_);
  }

private:
  ::trident_msgs::srv::GuidanceRequest_Response msg_;
};

class Init_GuidanceRequest_Response_accepted
{
public:
  Init_GuidanceRequest_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GuidanceRequest_Response_reference_position accepted(::trident_msgs::srv::GuidanceRequest_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_GuidanceRequest_Response_reference_position(msg_);
  }

private:
  ::trident_msgs::srv::GuidanceRequest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::GuidanceRequest_Response>()
{
  return trident_msgs::srv::builder::Init_GuidanceRequest_Response_accepted();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__BUILDER_HPP_
