// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:msg/MotorOutputs.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__BUILDER_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__BUILDER_HPP_

#include "trident_msgs/msg/detail/motor_outputs__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorOutputs_motor_outputs
{
public:
  Init_MotorOutputs_motor_outputs()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::msg::MotorOutputs motor_outputs(::trident_msgs::msg::MotorOutputs::_motor_outputs_type arg)
  {
    msg_.motor_outputs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::msg::MotorOutputs msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::msg::MotorOutputs>()
{
  return trident_msgs::msg::builder::Init_MotorOutputs_motor_outputs();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__BUILDER_HPP_
