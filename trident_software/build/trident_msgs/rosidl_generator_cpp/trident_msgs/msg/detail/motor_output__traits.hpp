// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trident_msgs:msg/MotorOutput.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__TRAITS_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__TRAITS_HPP_

#include "trident_msgs/msg/detail/motor_output__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::msg::MotorOutput>()
{
  return "trident_msgs::msg::MotorOutput";
}

template<>
inline const char * name<trident_msgs::msg::MotorOutput>()
{
  return "trident_msgs/msg/MotorOutput";
}

template<>
struct has_fixed_size<trident_msgs::msg::MotorOutput>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<trident_msgs::msg::MotorOutput>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<trident_msgs::msg::MotorOutput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__TRAITS_HPP_
