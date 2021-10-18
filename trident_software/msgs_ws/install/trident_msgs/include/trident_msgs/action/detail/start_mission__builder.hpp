// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:action/StartMission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__START_MISSION__BUILDER_HPP_
#define TRIDENT_MSGS__ACTION__DETAIL__START_MISSION__BUILDER_HPP_

#include "trident_msgs/action/detail/start_mission__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::StartMission_Goal>()
{
  return ::trident_msgs::action::StartMission_Goal(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_StartMission_Result_message
{
public:
  explicit Init_StartMission_Result_message(::trident_msgs::action::StartMission_Result & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::StartMission_Result message(::trident_msgs::action::StartMission_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::StartMission_Result msg_;
};

class Init_StartMission_Result_success
{
public:
  Init_StartMission_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartMission_Result_message success(::trident_msgs::action::StartMission_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_StartMission_Result_message(msg_);
  }

private:
  ::trident_msgs::action::StartMission_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::StartMission_Result>()
{
  return trident_msgs::action::builder::Init_StartMission_Result_success();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_StartMission_Feedback_waypoints_completed
{
public:
  explicit Init_StartMission_Feedback_waypoints_completed(::trident_msgs::action::StartMission_Feedback & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::StartMission_Feedback waypoints_completed(::trident_msgs::action::StartMission_Feedback::_waypoints_completed_type arg)
  {
    msg_.waypoints_completed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::StartMission_Feedback msg_;
};

class Init_StartMission_Feedback_message
{
public:
  explicit Init_StartMission_Feedback_message(::trident_msgs::action::StartMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_StartMission_Feedback_waypoints_completed message(::trident_msgs::action::StartMission_Feedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_StartMission_Feedback_waypoints_completed(msg_);
  }

private:
  ::trident_msgs::action::StartMission_Feedback msg_;
};

class Init_StartMission_Feedback_status
{
public:
  Init_StartMission_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartMission_Feedback_message status(::trident_msgs::action::StartMission_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_StartMission_Feedback_message(msg_);
  }

private:
  ::trident_msgs::action::StartMission_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::StartMission_Feedback>()
{
  return trident_msgs::action::builder::Init_StartMission_Feedback_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_StartMission_SendGoal_Request_goal
{
public:
  explicit Init_StartMission_SendGoal_Request_goal(::trident_msgs::action::StartMission_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::StartMission_SendGoal_Request goal(::trident_msgs::action::StartMission_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::StartMission_SendGoal_Request msg_;
};

class Init_StartMission_SendGoal_Request_goal_id
{
public:
  Init_StartMission_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartMission_SendGoal_Request_goal goal_id(::trident_msgs::action::StartMission_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_StartMission_SendGoal_Request_goal(msg_);
  }

private:
  ::trident_msgs::action::StartMission_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::StartMission_SendGoal_Request>()
{
  return trident_msgs::action::builder::Init_StartMission_SendGoal_Request_goal_id();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_StartMission_SendGoal_Response_stamp
{
public:
  explicit Init_StartMission_SendGoal_Response_stamp(::trident_msgs::action::StartMission_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::StartMission_SendGoal_Response stamp(::trident_msgs::action::StartMission_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::StartMission_SendGoal_Response msg_;
};

class Init_StartMission_SendGoal_Response_accepted
{
public:
  Init_StartMission_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartMission_SendGoal_Response_stamp accepted(::trident_msgs::action::StartMission_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_StartMission_SendGoal_Response_stamp(msg_);
  }

private:
  ::trident_msgs::action::StartMission_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::StartMission_SendGoal_Response>()
{
  return trident_msgs::action::builder::Init_StartMission_SendGoal_Response_accepted();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_StartMission_GetResult_Request_goal_id
{
public:
  Init_StartMission_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::action::StartMission_GetResult_Request goal_id(::trident_msgs::action::StartMission_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::StartMission_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::StartMission_GetResult_Request>()
{
  return trident_msgs::action::builder::Init_StartMission_GetResult_Request_goal_id();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_StartMission_GetResult_Response_result
{
public:
  explicit Init_StartMission_GetResult_Response_result(::trident_msgs::action::StartMission_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::StartMission_GetResult_Response result(::trident_msgs::action::StartMission_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::StartMission_GetResult_Response msg_;
};

class Init_StartMission_GetResult_Response_status
{
public:
  Init_StartMission_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartMission_GetResult_Response_result status(::trident_msgs::action::StartMission_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_StartMission_GetResult_Response_result(msg_);
  }

private:
  ::trident_msgs::action::StartMission_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::StartMission_GetResult_Response>()
{
  return trident_msgs::action::builder::Init_StartMission_GetResult_Response_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_StartMission_FeedbackMessage_feedback
{
public:
  explicit Init_StartMission_FeedbackMessage_feedback(::trident_msgs::action::StartMission_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::StartMission_FeedbackMessage feedback(::trident_msgs::action::StartMission_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::StartMission_FeedbackMessage msg_;
};

class Init_StartMission_FeedbackMessage_goal_id
{
public:
  Init_StartMission_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartMission_FeedbackMessage_feedback goal_id(::trident_msgs::action::StartMission_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_StartMission_FeedbackMessage_feedback(msg_);
  }

private:
  ::trident_msgs::action::StartMission_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::StartMission_FeedbackMessage>()
{
  return trident_msgs::action::builder::Init_StartMission_FeedbackMessage_goal_id();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__ACTION__DETAIL__START_MISSION__BUILDER_HPP_
