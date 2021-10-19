// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_interfaces:msg/FauxPosition.idl
// generated code does not contain a copyright notice

#ifndef TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__TRAITS_HPP_
#define TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__TRAITS_HPP_

#include "test_interfaces/msg/detail/faux_position__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<test_interfaces::msg::FauxPosition>()
{
  return "test_interfaces::msg::FauxPosition";
}

template<>
inline const char * name<test_interfaces::msg::FauxPosition>()
{
  return "test_interfaces/msg/FauxPosition";
}

template<>
struct has_fixed_size<test_interfaces::msg::FauxPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<test_interfaces::msg::FauxPosition>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<test_interfaces::msg::FauxPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__TRAITS_HPP_
