// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cola2_msgs:msg/Setpoints.idl
// generated code does not contain a copyright notice

#ifndef COLA2_MSGS__MSG__DETAIL__SETPOINTS__TRAITS_HPP_
#define COLA2_MSGS__MSG__DETAIL__SETPOINTS__TRAITS_HPP_

#include "cola2_msgs/msg/detail/setpoints__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cola2_msgs::msg::Setpoints>()
{
  return "cola2_msgs::msg::Setpoints";
}

template<>
inline const char * name<cola2_msgs::msg::Setpoints>()
{
  return "cola2_msgs/msg/Setpoints";
}

template<>
struct has_fixed_size<cola2_msgs::msg::Setpoints>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cola2_msgs::msg::Setpoints>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cola2_msgs::msg::Setpoints>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COLA2_MSGS__MSG__DETAIL__SETPOINTS__TRAITS_HPP_
