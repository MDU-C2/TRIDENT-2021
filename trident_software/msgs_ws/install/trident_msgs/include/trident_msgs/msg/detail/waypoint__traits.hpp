// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trident_msgs:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
#define TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__TRAITS_HPP_

#include "trident_msgs/msg/detail/waypoint__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'action'
#include "trident_msgs/msg/detail/waypoint_action__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::msg::Waypoint>()
{
  return "trident_msgs::msg::Waypoint";
}

template<>
inline const char * name<trident_msgs::msg::Waypoint>()
{
  return "trident_msgs/msg/Waypoint";
}

template<>
struct has_fixed_size<trident_msgs::msg::Waypoint>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<trident_msgs::msg::WaypointAction>::value> {};

template<>
struct has_bounded_size<trident_msgs::msg::Waypoint>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<trident_msgs::msg::WaypointAction>::value> {};

template<>
struct is_message<trident_msgs::msg::Waypoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
