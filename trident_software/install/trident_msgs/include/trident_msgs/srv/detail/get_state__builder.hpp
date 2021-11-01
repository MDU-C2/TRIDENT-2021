// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:srv/GetState.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GET_STATE__BUILDER_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__GET_STATE__BUILDER_HPP_

#include "trident_msgs/srv/detail/get_state__struct.hpp"
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
auto build<::trident_msgs::srv::GetState_Request>()
{
  return ::trident_msgs::srv::GetState_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_GetState_Response_int_state
{
public:
  explicit Init_GetState_Response_int_state(::trident_msgs::srv::GetState_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::srv::GetState_Response int_state(::trident_msgs::srv::GetState_Response::_int_state_type arg)
  {
    msg_.int_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::GetState_Response msg_;
};

class Init_GetState_Response_state
{
public:
  explicit Init_GetState_Response_state(::trident_msgs::srv::GetState_Response & msg)
  : msg_(msg)
  {}
  Init_GetState_Response_int_state state(::trident_msgs::srv::GetState_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_GetState_Response_int_state(msg_);
  }

private:
  ::trident_msgs::srv::GetState_Response msg_;
};

class Init_GetState_Response_success
{
public:
  Init_GetState_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetState_Response_state success(::trident_msgs::srv::GetState_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetState_Response_state(msg_);
  }

private:
  ::trident_msgs::srv::GetState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::GetState_Response>()
{
  return trident_msgs::srv::builder::Init_GetState_Response_success();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__GET_STATE__BUILDER_HPP_
