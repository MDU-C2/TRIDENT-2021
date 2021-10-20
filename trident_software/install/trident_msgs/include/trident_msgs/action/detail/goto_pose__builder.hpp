// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:action/GotoPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__GOTO_POSE__BUILDER_HPP_
#define TRIDENT_MSGS__ACTION__DETAIL__GOTO_POSE__BUILDER_HPP_

#include "trident_msgs/action/detail/goto_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoPose_Goal_pose
{
public:
  Init_GotoPose_Goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::action::GotoPose_Goal pose(::trident_msgs::action::GotoPose_Goal::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoPose_Goal>()
{
  return trident_msgs::action::builder::Init_GotoPose_Goal_pose();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoPose_Result_distance_to_goal
{
public:
  explicit Init_GotoPose_Result_distance_to_goal(::trident_msgs::action::GotoPose_Result & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoPose_Result distance_to_goal(::trident_msgs::action::GotoPose_Result::_distance_to_goal_type arg)
  {
    msg_.distance_to_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Result msg_;
};

class Init_GotoPose_Result_delta_pose
{
public:
  explicit Init_GotoPose_Result_delta_pose(::trident_msgs::action::GotoPose_Result & msg)
  : msg_(msg)
  {}
  Init_GotoPose_Result_distance_to_goal delta_pose(::trident_msgs::action::GotoPose_Result::_delta_pose_type arg)
  {
    msg_.delta_pose = std::move(arg);
    return Init_GotoPose_Result_distance_to_goal(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Result msg_;
};

class Init_GotoPose_Result_message
{
public:
  explicit Init_GotoPose_Result_message(::trident_msgs::action::GotoPose_Result & msg)
  : msg_(msg)
  {}
  Init_GotoPose_Result_delta_pose message(::trident_msgs::action::GotoPose_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GotoPose_Result_delta_pose(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Result msg_;
};

class Init_GotoPose_Result_status
{
public:
  Init_GotoPose_Result_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoPose_Result_message status(::trident_msgs::action::GotoPose_Result::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GotoPose_Result_message(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoPose_Result>()
{
  return trident_msgs::action::builder::Init_GotoPose_Result_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoPose_Feedback_distance_to_goal
{
public:
  explicit Init_GotoPose_Feedback_distance_to_goal(::trident_msgs::action::GotoPose_Feedback & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoPose_Feedback distance_to_goal(::trident_msgs::action::GotoPose_Feedback::_distance_to_goal_type arg)
  {
    msg_.distance_to_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Feedback msg_;
};

class Init_GotoPose_Feedback_delta_pose
{
public:
  explicit Init_GotoPose_Feedback_delta_pose(::trident_msgs::action::GotoPose_Feedback & msg)
  : msg_(msg)
  {}
  Init_GotoPose_Feedback_distance_to_goal delta_pose(::trident_msgs::action::GotoPose_Feedback::_delta_pose_type arg)
  {
    msg_.delta_pose = std::move(arg);
    return Init_GotoPose_Feedback_distance_to_goal(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Feedback msg_;
};

class Init_GotoPose_Feedback_message
{
public:
  explicit Init_GotoPose_Feedback_message(::trident_msgs::action::GotoPose_Feedback & msg)
  : msg_(msg)
  {}
  Init_GotoPose_Feedback_delta_pose message(::trident_msgs::action::GotoPose_Feedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GotoPose_Feedback_delta_pose(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Feedback msg_;
};

class Init_GotoPose_Feedback_status
{
public:
  Init_GotoPose_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoPose_Feedback_message status(::trident_msgs::action::GotoPose_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GotoPose_Feedback_message(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoPose_Feedback>()
{
  return trident_msgs::action::builder::Init_GotoPose_Feedback_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoPose_SendGoal_Request_goal
{
public:
  explicit Init_GotoPose_SendGoal_Request_goal(::trident_msgs::action::GotoPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoPose_SendGoal_Request goal(::trident_msgs::action::GotoPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_SendGoal_Request msg_;
};

class Init_GotoPose_SendGoal_Request_goal_id
{
public:
  Init_GotoPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoPose_SendGoal_Request_goal goal_id(::trident_msgs::action::GotoPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GotoPose_SendGoal_Request_goal(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoPose_SendGoal_Request>()
{
  return trident_msgs::action::builder::Init_GotoPose_SendGoal_Request_goal_id();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoPose_SendGoal_Response_stamp
{
public:
  explicit Init_GotoPose_SendGoal_Response_stamp(::trident_msgs::action::GotoPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoPose_SendGoal_Response stamp(::trident_msgs::action::GotoPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_SendGoal_Response msg_;
};

class Init_GotoPose_SendGoal_Response_accepted
{
public:
  Init_GotoPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoPose_SendGoal_Response_stamp accepted(::trident_msgs::action::GotoPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_GotoPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoPose_SendGoal_Response>()
{
  return trident_msgs::action::builder::Init_GotoPose_SendGoal_Response_accepted();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoPose_GetResult_Request_goal_id
{
public:
  Init_GotoPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::action::GotoPose_GetResult_Request goal_id(::trident_msgs::action::GotoPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoPose_GetResult_Request>()
{
  return trident_msgs::action::builder::Init_GotoPose_GetResult_Request_goal_id();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoPose_GetResult_Response_result
{
public:
  explicit Init_GotoPose_GetResult_Response_result(::trident_msgs::action::GotoPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoPose_GetResult_Response result(::trident_msgs::action::GotoPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_GetResult_Response msg_;
};

class Init_GotoPose_GetResult_Response_status
{
public:
  Init_GotoPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoPose_GetResult_Response_result status(::trident_msgs::action::GotoPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GotoPose_GetResult_Response_result(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoPose_GetResult_Response>()
{
  return trident_msgs::action::builder::Init_GotoPose_GetResult_Response_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_GotoPose_FeedbackMessage_feedback
{
public:
  explicit Init_GotoPose_FeedbackMessage_feedback(::trident_msgs::action::GotoPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::GotoPose_FeedbackMessage feedback(::trident_msgs::action::GotoPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_FeedbackMessage msg_;
};

class Init_GotoPose_FeedbackMessage_goal_id
{
public:
  Init_GotoPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GotoPose_FeedbackMessage_feedback goal_id(::trident_msgs::action::GotoPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GotoPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::trident_msgs::action::GotoPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::GotoPose_FeedbackMessage>()
{
  return trident_msgs::action::builder::Init_GotoPose_FeedbackMessage_goal_id();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__ACTION__DETAIL__GOTO_POSE__BUILDER_HPP_
