// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trident_msgs:srv/KalmanSensorService.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__TRAITS_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__TRAITS_HPP_

#include "trident_msgs/srv/detail/kalman_sensor_service__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace trident_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const KalmanSensorService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    if (msg.state.size() == 0) {
      out << "state: []";
    } else {
      out << "state: [";
      size_t pending_items = msg.state.size();
      for (auto item : msg.state) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: covar
  {
    if (msg.covar.size() == 0) {
      out << "covar: []";
    } else {
      out << "covar: [";
      size_t pending_items = msg.covar.size();
      for (auto item : msg.covar) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const KalmanSensorService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.state.size() == 0) {
      out << "state: []\n";
    } else {
      out << "state:\n";
      for (auto item : msg.state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: covar
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.covar.size() == 0) {
      out << "covar: []\n";
    } else {
      out << "covar:\n";
      for (auto item : msg.covar) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KalmanSensorService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace trident_msgs

namespace rosidl_generator_traits
{

[[deprecated("use trident_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trident_msgs::srv::KalmanSensorService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  trident_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trident_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const trident_msgs::srv::KalmanSensorService_Request & msg)
{
  return trident_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<trident_msgs::srv::KalmanSensorService_Request>()
{
  return "trident_msgs::srv::KalmanSensorService_Request";
}

template<>
inline const char * name<trident_msgs::srv::KalmanSensorService_Request>()
{
  return "trident_msgs/srv/KalmanSensorService_Request";
}

template<>
struct has_fixed_size<trident_msgs::srv::KalmanSensorService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trident_msgs::srv::KalmanSensorService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trident_msgs::srv::KalmanSensorService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace trident_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const KalmanSensorService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: residual
  {
    if (msg.residual.size() == 0) {
      out << "residual: []";
    } else {
      out << "residual: [";
      size_t pending_items = msg.residual.size();
      for (auto item : msg.residual) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gain
  {
    if (msg.gain.size() == 0) {
      out << "gain: []";
    } else {
      out << "gain: [";
      size_t pending_items = msg.gain.size();
      for (auto item : msg.gain) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: observationmatrix
  {
    if (msg.observationmatrix.size() == 0) {
      out << "observationmatrix: []";
    } else {
      out << "observationmatrix: [";
      size_t pending_items = msg.observationmatrix.size();
      for (auto item : msg.observationmatrix) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const KalmanSensorService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: residual
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.residual.size() == 0) {
      out << "residual: []\n";
    } else {
      out << "residual:\n";
      for (auto item : msg.residual) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.gain.size() == 0) {
      out << "gain: []\n";
    } else {
      out << "gain:\n";
      for (auto item : msg.gain) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: observationmatrix
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.observationmatrix.size() == 0) {
      out << "observationmatrix: []\n";
    } else {
      out << "observationmatrix:\n";
      for (auto item : msg.observationmatrix) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KalmanSensorService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace trident_msgs

namespace rosidl_generator_traits
{

[[deprecated("use trident_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trident_msgs::srv::KalmanSensorService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  trident_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trident_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const trident_msgs::srv::KalmanSensorService_Response & msg)
{
  return trident_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<trident_msgs::srv::KalmanSensorService_Response>()
{
  return "trident_msgs::srv::KalmanSensorService_Response";
}

template<>
inline const char * name<trident_msgs::srv::KalmanSensorService_Response>()
{
  return "trident_msgs/srv/KalmanSensorService_Response";
}

template<>
struct has_fixed_size<trident_msgs::srv::KalmanSensorService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trident_msgs::srv::KalmanSensorService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trident_msgs::srv::KalmanSensorService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::srv::KalmanSensorService>()
{
  return "trident_msgs::srv::KalmanSensorService";
}

template<>
inline const char * name<trident_msgs::srv::KalmanSensorService>()
{
  return "trident_msgs/srv/KalmanSensorService";
}

template<>
struct has_fixed_size<trident_msgs::srv::KalmanSensorService>
  : std::integral_constant<
    bool,
    has_fixed_size<trident_msgs::srv::KalmanSensorService_Request>::value &&
    has_fixed_size<trident_msgs::srv::KalmanSensorService_Response>::value
  >
{
};

template<>
struct has_bounded_size<trident_msgs::srv::KalmanSensorService>
  : std::integral_constant<
    bool,
    has_bounded_size<trident_msgs::srv::KalmanSensorService_Request>::value &&
    has_bounded_size<trident_msgs::srv::KalmanSensorService_Response>::value
  >
{
};

template<>
struct is_service<trident_msgs::srv::KalmanSensorService>
  : std::true_type
{
};

template<>
struct is_service_request<trident_msgs::srv::KalmanSensorService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trident_msgs::srv::KalmanSensorService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__TRAITS_HPP_
