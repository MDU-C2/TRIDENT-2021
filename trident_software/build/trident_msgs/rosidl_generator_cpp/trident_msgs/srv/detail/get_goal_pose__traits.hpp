// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trident_msgs:srv/GetGoalPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__TRAITS_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__TRAITS_HPP_

#include "trident_msgs/srv/detail/get_goal_pose__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::GetGoalPose_Request>()
{
  return "trident_msgs::srv::GetGoalPose_Request";
}

template<>
inline const char * name<trident_msgs::srv::GetGoalPose_Request>()
{
  return "trident_msgs/srv/GetGoalPose_Request";
}

template<>
struct has_fixed_size<trident_msgs::srv::GetGoalPose_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<trident_msgs::srv::GetGoalPose_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<trident_msgs::srv::GetGoalPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::GetGoalPose_Response>()
{
  return "trident_msgs::srv::GetGoalPose_Response";
}

template<>
inline const char * name<trident_msgs::srv::GetGoalPose_Response>()
{
  return "trident_msgs/srv/GetGoalPose_Response";
}

template<>
struct has_fixed_size<trident_msgs::srv::GetGoalPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trident_msgs::srv::GetGoalPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trident_msgs::srv::GetGoalPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::GetGoalPose>()
{
  return "trident_msgs::srv::GetGoalPose";
}

template<>
inline const char * name<trident_msgs::srv::GetGoalPose>()
{
  return "trident_msgs/srv/GetGoalPose";
}

template<>
struct has_fixed_size<trident_msgs::srv::GetGoalPose>
  : std::integral_constant<
    bool,
    has_fixed_size<trident_msgs::srv::GetGoalPose_Request>::value &&
    has_fixed_size<trident_msgs::srv::GetGoalPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<trident_msgs::srv::GetGoalPose>
  : std::integral_constant<
    bool,
    has_bounded_size<trident_msgs::srv::GetGoalPose_Request>::value &&
    has_bounded_size<trident_msgs::srv::GetGoalPose_Response>::value
  >
{
};

template<>
struct is_service<trident_msgs::srv::GetGoalPose>
  : std::true_type
{
};

template<>
struct is_service_request<trident_msgs::srv::GetGoalPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trident_msgs::srv::GetGoalPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__TRAITS_HPP_
