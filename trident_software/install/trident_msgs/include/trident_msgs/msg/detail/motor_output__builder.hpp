// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:msg/MotorOutput.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__BUILDER_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__BUILDER_HPP_

#include "trident_msgs/msg/detail/motor_output__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorOutput_value
{
public:
  explicit Init_MotorOutput_value(::trident_msgs::msg::MotorOutput & msg)
  : msg_(msg)
  {}
  ::trident_msgs::msg::MotorOutput value(::trident_msgs::msg::MotorOutput::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::msg::MotorOutput msg_;
};

class Init_MotorOutput_id
{
public:
  Init_MotorOutput_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorOutput_value id(::trident_msgs::msg::MotorOutput::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_MotorOutput_value(msg_);
  }

private:
  ::trident_msgs::msg::MotorOutput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::msg::MotorOutput>()
{
  return trident_msgs::msg::builder::Init_MotorOutput_id();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__BUILDER_HPP_
