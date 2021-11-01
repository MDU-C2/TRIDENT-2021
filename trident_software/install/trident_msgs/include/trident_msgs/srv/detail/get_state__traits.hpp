// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trident_msgs:srv/GetState.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GET_STATE__TRAITS_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__GET_STATE__TRAITS_HPP_

#include "trident_msgs/srv/detail/get_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::GetState_Request>()
{
  return "trident_msgs::srv::GetState_Request";
}

template<>
inline const char * name<trident_msgs::srv::GetState_Request>()
{
  return "trident_msgs/srv/GetState_Request";
}

template<>
struct has_fixed_size<trident_msgs::srv::GetState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<trident_msgs::srv::GetState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<trident_msgs::srv::GetState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::GetState_Response>()
{
  return "trident_msgs::srv::GetState_Response";
}

template<>
inline const char * name<trident_msgs::srv::GetState_Response>()
{
  return "trident_msgs/srv/GetState_Response";
}

template<>
struct has_fixed_size<trident_msgs::srv::GetState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trident_msgs::srv::GetState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trident_msgs::srv::GetState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::GetState>()
{
  return "trident_msgs::srv::GetState";
}

template<>
inline const char * name<trident_msgs::srv::GetState>()
{
  return "trident_msgs/srv/GetState";
}

template<>
struct has_fixed_size<trident_msgs::srv::GetState>
  : std::integral_constant<
    bool,
    has_fixed_size<trident_msgs::srv::GetState_Request>::value &&
    has_fixed_size<trident_msgs::srv::GetState_Response>::value
  >
{
};

template<>
struct has_bounded_size<trident_msgs::srv::GetState>
  : std::integral_constant<
    bool,
    has_bounded_size<trident_msgs::srv::GetState_Request>::value &&
    has_bounded_size<trident_msgs::srv::GetState_Response>::value
  >
{
};

template<>
struct is_service<trident_msgs::srv::GetState>
  : std::true_type
{
};

template<>
struct is_service_request<trident_msgs::srv::GetState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trident_msgs::srv::GetState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TRIDENT_MSGS__SRV__DETAIL__GET_STATE__TRAITS_HPP_
