// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trident_msgs:srv/LoadMission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__TRAITS_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__TRAITS_HPP_

#include "trident_msgs/srv/detail/load_mission__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'mission'
#include "trident_msgs/msg/detail/mission__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::LoadMission_Request>()
{
  return "trident_msgs::srv::LoadMission_Request";
}

template<>
inline const char * name<trident_msgs::srv::LoadMission_Request>()
{
  return "trident_msgs/srv/LoadMission_Request";
}

template<>
struct has_fixed_size<trident_msgs::srv::LoadMission_Request>
  : std::integral_constant<bool, has_fixed_size<trident_msgs::msg::Mission>::value> {};

template<>
struct has_bounded_size<trident_msgs::srv::LoadMission_Request>
  : std::integral_constant<bool, has_bounded_size<trident_msgs::msg::Mission>::value> {};

template<>
struct is_message<trident_msgs::srv::LoadMission_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::LoadMission_Response>()
{
  return "trident_msgs::srv::LoadMission_Response";
}

template<>
inline const char * name<trident_msgs::srv::LoadMission_Response>()
{
  return "trident_msgs/srv/LoadMission_Response";
}

template<>
struct has_fixed_size<trident_msgs::srv::LoadMission_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trident_msgs::srv::LoadMission_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trident_msgs::srv::LoadMission_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::LoadMission>()
{
  return "trident_msgs::srv::LoadMission";
}

template<>
inline const char * name<trident_msgs::srv::LoadMission>()
{
  return "trident_msgs/srv/LoadMission";
}

template<>
struct has_fixed_size<trident_msgs::srv::LoadMission>
  : std::integral_constant<
    bool,
    has_fixed_size<trident_msgs::srv::LoadMission_Request>::value &&
    has_fixed_size<trident_msgs::srv::LoadMission_Response>::value
  >
{
};

template<>
struct has_bounded_size<trident_msgs::srv::LoadMission>
  : std::integral_constant<
    bool,
    has_bounded_size<trident_msgs::srv::LoadMission_Request>::value &&
    has_bounded_size<trident_msgs::srv::LoadMission_Response>::value
  >
{
};

template<>
struct is_service<trident_msgs::srv::LoadMission>
  : std::true_type
{
};

template<>
struct is_service_request<trident_msgs::srv::LoadMission_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trident_msgs::srv::LoadMission_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__TRAITS_HPP_
