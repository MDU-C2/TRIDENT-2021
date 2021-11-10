// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_interfaces:msg/FauxPosition.idl
// generated code does not contain a copyright notice

#ifndef TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__TRAITS_HPP_
#define TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__TRAITS_HPP_

#include "test_interfaces/msg/detail/faux_position__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace test_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FauxPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: dx
  {
    out << "dx: ";
    rosidl_generator_traits::value_to_yaml(msg.dx, out);
    out << ", ";
  }

  // member: dy
  {
    out << "dy: ";
    rosidl_generator_traits::value_to_yaml(msg.dy, out);
    out << ", ";
  }

  // member: dtheta
  {
    out << "dtheta: ";
    rosidl_generator_traits::value_to_yaml(msg.dtheta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FauxPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: dx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dx: ";
    rosidl_generator_traits::value_to_yaml(msg.dx, out);
    out << "\n";
  }

  // member: dy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dy: ";
    rosidl_generator_traits::value_to_yaml(msg.dy, out);
    out << "\n";
  }

  // member: dtheta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dtheta: ";
    rosidl_generator_traits::value_to_yaml(msg.dtheta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FauxPosition & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace test_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use test_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const test_interfaces::msg::FauxPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  test_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use test_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const test_interfaces::msg::FauxPosition & msg)
{
  return test_interfaces::msg::to_yaml(msg);
}

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
