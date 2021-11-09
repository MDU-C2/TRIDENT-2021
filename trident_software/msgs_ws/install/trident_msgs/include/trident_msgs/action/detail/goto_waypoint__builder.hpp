// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:action/GotoWaypoint.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__GOTO_WAYPOINT__BUILDER_HPP_
#define TRIDENT_MSGS__ACTION__DETAIL__GOTO_WAYPOINT__BUILDER_HPP_

#include "trident_msgs/action/detail/goto_waypoint__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoWaypoint_Goal_waypoint
{
public:
  Init_GotoWaypoint_Goal_waypoint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::action::GotoWaypoint_Goal waypoint(::trident_msgs::action::GotoWaypoint_Goal::_waypoint_type arg)
  {
    msg_.waypoint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoWaypoint_Goal>()
{
  return trident_msgs::action::builder::Init_GotoWaypoint_Goal_waypoint();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoWaypoint_Result_distance_to_goal
{
public:
  explicit Init_GotoWaypoint_Result_distance_to_goal(::trident_msgs::action::GotoWaypoint_Result & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoWaypoint_Result distance_to_goal(::trident_msgs::action::GotoWaypoint_Result::_distance_to_goal_type arg)
  {
    msg_.distance_to_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_Result msg_;
};

class Init_GotoWaypoint_Result_message
{
public:
  explicit Init_GotoWaypoint_Result_message(::trident_msgs::action::GotoWaypoint_Result & msg)
  : msg_(msg)
  {}
  Init_GotoWaypoint_Result_distance_to_goal message(::trident_msgs::action::GotoWaypoint_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GotoWaypoint_Result_distance_to_goal(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_Result msg_;
};

class Init_GotoWaypoint_Result_status
{
public:
  Init_GotoWaypoint_Result_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoWaypoint_Result_message status(::trident_msgs::action::GotoWaypoint_Result::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GotoWaypoint_Result_message(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoWaypoint_Result>()
{
  return trident_msgs::action::builder::Init_GotoWaypoint_Result_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoWaypoint_Feedback_distance_to_goal
{
public:
  explicit Init_GotoWaypoint_Feedback_distance_to_goal(::trident_msgs::action::GotoWaypoint_Feedback & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoWaypoint_Feedback distance_to_goal(::trident_msgs::action::GotoWaypoint_Feedback::_distance_to_goal_type arg)
  {
    msg_.distance_to_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_Feedback msg_;
};

class Init_GotoWaypoint_Feedback_message
{
public:
  explicit Init_GotoWaypoint_Feedback_message(::trident_msgs::action::GotoWaypoint_Feedback & msg)
  : msg_(msg)
  {}
  Init_GotoWaypoint_Feedback_distance_to_goal message(::trident_msgs::action::GotoWaypoint_Feedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GotoWaypoint_Feedback_distance_to_goal(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_Feedback msg_;
};

class Init_GotoWaypoint_Feedback_status
{
public:
  Init_GotoWaypoint_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoWaypoint_Feedback_message status(::trident_msgs::action::GotoWaypoint_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GotoWaypoint_Feedback_message(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoWaypoint_Feedback>()
{
  return trident_msgs::action::builder::Init_GotoWaypoint_Feedback_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoWaypoint_SendGoal_Request_goal
{
public:
  explicit Init_GotoWaypoint_SendGoal_Request_goal(::trident_msgs::action::GotoWaypoint_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoWaypoint_SendGoal_Request goal(::trident_msgs::action::GotoWaypoint_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_SendGoal_Request msg_;
};

class Init_GotoWaypoint_SendGoal_Request_goal_id
{
public:
  Init_GotoWaypoint_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoWaypoint_SendGoal_Request_goal goal_id(::trident_msgs::action::GotoWaypoint_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GotoWaypoint_SendGoal_Request_goal(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoWaypoint_SendGoal_Request>()
{
  return trident_msgs::action::builder::Init_GotoWaypoint_SendGoal_Request_goal_id();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoWaypoint_SendGoal_Response_stamp
{
public:
  explicit Init_GotoWaypoint_SendGoal_Response_stamp(::trident_msgs::action::GotoWaypoint_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoWaypoint_SendGoal_Response stamp(::trident_msgs::action::GotoWaypoint_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_SendGoal_Response msg_;
};

class Init_GotoWaypoint_SendGoal_Response_accepted
{
public:
  Init_GotoWaypoint_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoWaypoint_SendGoal_Response_stamp accepted(::trident_msgs::action::GotoWaypoint_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_GotoWaypoint_SendGoal_Response_stamp(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoWaypoint_SendGoal_Response>()
{
  return trident_msgs::action::builder::Init_GotoWaypoint_SendGoal_Response_accepted();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoWaypoint_GetResult_Request_goal_id
{
public:
  Init_GotoWaypoint_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::action::GotoWaypoint_GetResult_Request goal_id(::trident_msgs::action::GotoWaypoint_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoWaypoint_GetResult_Request>()
{
  return trident_msgs::action::builder::Init_GotoWaypoint_GetResult_Request_goal_id();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoWaypoint_GetResult_Response_result
{
public:
  explicit Init_GotoWaypoint_GetResult_Response_result(::trident_msgs::action::GotoWaypoint_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoWaypoint_GetResult_Response result(::trident_msgs::action::GotoWaypoint_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_GetResult_Response msg_;
};

class Init_GotoWaypoint_GetResult_Response_status
{
public:
  Init_GotoWaypoint_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoWaypoint_GetResult_Response_result status(::trident_msgs::action::GotoWaypoint_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GotoWaypoint_GetResult_Response_result(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoWaypoint_GetResult_Response>()
{
  return trident_msgs::action::builder::Init_GotoWaypoint_GetResult_Response_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoWaypoint_FeedbackMessage_feedback
{
public:
  explicit Init_GotoWaypoint_FeedbackMessage_feedback(::trident_msgs::action::GotoWaypoint_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoWaypoint_FeedbackMessage feedback(::trident_msgs::action::GotoWaypoint_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_FeedbackMessage msg_;
};

class Init_GotoWaypoint_FeedbackMessage_goal_id
{
public:
  Init_GotoWaypoint_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoWaypoint_FeedbackMessage_feedback goal_id(::trident_msgs::action::GotoWaypoint_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GotoWaypoint_FeedbackMessage_feedback(msg_);
  }

private:
  ::trident_msgs::action::GotoWaypoint_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoWaypoint_FeedbackMessage>()
{
  return trident_msgs::action::builder::Init_GotoWaypoint_FeedbackMessage_goal_id();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__ACTION__DETAIL__GOTO_WAYPOINT__BUILDER_HPP_
