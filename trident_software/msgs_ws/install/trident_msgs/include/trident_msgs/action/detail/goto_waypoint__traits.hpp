// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trident_msgs:action/GotoWaypoint.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__GOTO_WAYPOINT__TRAITS_HPP_
#define TRIDENT_MSGS__ACTION__DETAIL__GOTO_WAYPOINT__TRAITS_HPP_

#include "trident_msgs/action/detail/goto_waypoint__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'waypoint'
#include "trident_msgs/msg/detail/waypoint__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_Goal>()
{
  return "trident_msgs::action::GotoWaypoint_Goal";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_Goal>()
{
  return "trident_msgs/action/GotoWaypoint_Goal";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_Goal>
  : std::integral_constant<bool, has_fixed_size<trident_msgs::msg::Waypoint>::value> {};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_Goal>
  : std::integral_constant<bool, has_bounded_size<trident_msgs::msg::Waypoint>::value> {};

template<>
struct is_message<trident_msgs::action::GotoWaypoint_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_Result>()
{
  return "trident_msgs::action::GotoWaypoint_Result";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_Result>()
{
  return "trident_msgs/action/GotoWaypoint_Result";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trident_msgs::action::GotoWaypoint_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_Feedback>()
{
  return "trident_msgs::action::GotoWaypoint_Feedback";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_Feedback>()
{
  return "trident_msgs/action/GotoWaypoint_Feedback";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trident_msgs::action::GotoWaypoint_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "trident_msgs/action/detail/goto_waypoint__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_SendGoal_Request>()
{
  return "trident_msgs::action::GotoWaypoint_SendGoal_Request";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_SendGoal_Request>()
{
  return "trident_msgs/action/GotoWaypoint_SendGoal_Request";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<trident_msgs::action::GotoWaypoint_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<trident_msgs::action::GotoWaypoint_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trident_msgs::action::GotoWaypoint_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_SendGoal_Response>()
{
  return "trident_msgs::action::GotoWaypoint_SendGoal_Response";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_SendGoal_Response>()
{
  return "trident_msgs/action/GotoWaypoint_SendGoal_Response";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<trident_msgs::action::GotoWaypoint_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_SendGoal>()
{
  return "trident_msgs::action::GotoWaypoint_SendGoal";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_SendGoal>()
{
  return "trident_msgs/action/GotoWaypoint_SendGoal";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<trident_msgs::action::GotoWaypoint_SendGoal_Request>::value &&
    has_fixed_size<trident_msgs::action::GotoWaypoint_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<trident_msgs::action::GotoWaypoint_SendGoal_Request>::value &&
    has_bounded_size<trident_msgs::action::GotoWaypoint_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<trident_msgs::action::GotoWaypoint_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<trident_msgs::action::GotoWaypoint_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trident_msgs::action::GotoWaypoint_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_GetResult_Request>()
{
  return "trident_msgs::action::GotoWaypoint_GetResult_Request";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_GetResult_Request>()
{
  return "trident_msgs/action/GotoWaypoint_GetResult_Request";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trident_msgs::action::GotoWaypoint_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_GetResult_Response>()
{
  return "trident_msgs::action::GotoWaypoint_GetResult_Response";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_GetResult_Response>()
{
  return "trident_msgs/action/GotoWaypoint_GetResult_Response";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<trident_msgs::action::GotoWaypoint_Result>::value> {};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<trident_msgs::action::GotoWaypoint_Result>::value> {};

template<>
struct is_message<trident_msgs::action::GotoWaypoint_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_GetResult>()
{
  return "trident_msgs::action::GotoWaypoint_GetResult";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_GetResult>()
{
  return "trident_msgs/action/GotoWaypoint_GetResult";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<trident_msgs::action::GotoWaypoint_GetResult_Request>::value &&
    has_fixed_size<trident_msgs::action::GotoWaypoint_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<trident_msgs::action::GotoWaypoint_GetResult_Request>::value &&
    has_bounded_size<trident_msgs::action::GotoWaypoint_GetResult_Response>::value
  >
{
};

template<>
struct is_service<trident_msgs::action::GotoWaypoint_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<trident_msgs::action::GotoWaypoint_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trident_msgs::action::GotoWaypoint_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trident_msgs::action::GotoWaypoint_FeedbackMessage>()
{
  return "trident_msgs::action::GotoWaypoint_FeedbackMessage";
}

template<>
inline const char * name<trident_msgs::action::GotoWaypoint_FeedbackMessage>()
{
  return "trident_msgs/action/GotoWaypoint_FeedbackMessage";
}

template<>
struct has_fixed_size<trident_msgs::action::GotoWaypoint_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<trident_msgs::action::GotoWaypoint_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trident_msgs::action::GotoWaypoint_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<trident_msgs::action::GotoWaypoint_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trident_msgs::action::GotoWaypoint_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<trident_msgs::action::GotoWaypoint>
  : std::true_type
{
};

template<>
struct is_action_goal<trident_msgs::action::GotoWaypoint_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<trident_msgs::action::GotoWaypoint_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<trident_msgs::action::GotoWaypoint_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TRIDENT_MSGS__ACTION__DETAIL__GOTO_WAYPOINT__TRAITS_HPP_
