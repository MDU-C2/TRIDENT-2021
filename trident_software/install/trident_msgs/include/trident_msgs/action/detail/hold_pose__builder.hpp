// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:action/HoldPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__BUILDER_HPP_
#define TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__BUILDER_HPP_

#include "trident_msgs/action/detail/hold_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_HoldPose_Goal_duration
{
public:
  explicit Init_HoldPose_Goal_duration(::trident_msgs::action::HoldPose_Goal & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::HoldPose_Goal duration(::trident_msgs::action::HoldPose_Goal::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Goal msg_;
};

class Init_HoldPose_Goal_pose
{
public:
  Init_HoldPose_Goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoldPose_Goal_duration pose(::trident_msgs::action::HoldPose_Goal::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_HoldPose_Goal_duration(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::HoldPose_Goal>()
{
  return trident_msgs::action::builder::Init_HoldPose_Goal_pose();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_HoldPose_Result_pose_variance
{
public:
  explicit Init_HoldPose_Result_pose_variance(::trident_msgs::action::HoldPose_Result & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::HoldPose_Result pose_variance(::trident_msgs::action::HoldPose_Result::_pose_variance_type arg)
  {
    msg_.pose_variance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Result msg_;
};

class Init_HoldPose_Result_pose_mean
{
public:
  explicit Init_HoldPose_Result_pose_mean(::trident_msgs::action::HoldPose_Result & msg)
  : msg_(msg)
  {}
  Init_HoldPose_Result_pose_variance pose_mean(::trident_msgs::action::HoldPose_Result::_pose_mean_type arg)
  {
    msg_.pose_mean = std::move(arg);
    return Init_HoldPose_Result_pose_variance(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Result msg_;
};

class Init_HoldPose_Result_message
{
public:
  explicit Init_HoldPose_Result_message(::trident_msgs::action::HoldPose_Result & msg)
  : msg_(msg)
  {}
  Init_HoldPose_Result_pose_mean message(::trident_msgs::action::HoldPose_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_HoldPose_Result_pose_mean(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Result msg_;
};

class Init_HoldPose_Result_status
{
public:
  explicit Init_HoldPose_Result_status(::trident_msgs::action::HoldPose_Result & msg)
  : msg_(msg)
  {}
  Init_HoldPose_Result_message status(::trident_msgs::action::HoldPose_Result::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_HoldPose_Result_message(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Result msg_;
};

class Init_HoldPose_Result_duration
{
public:
  Init_HoldPose_Result_duration()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoldPose_Result_status duration(::trident_msgs::action::HoldPose_Result::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_HoldPose_Result_status(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::HoldPose_Result>()
{
  return trident_msgs::action::builder::Init_HoldPose_Result_duration();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_HoldPose_Feedback_pose_variance
{
public:
  explicit Init_HoldPose_Feedback_pose_variance(::trident_msgs::action::HoldPose_Feedback & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::HoldPose_Feedback pose_variance(::trident_msgs::action::HoldPose_Feedback::_pose_variance_type arg)
  {
    msg_.pose_variance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Feedback msg_;
};

class Init_HoldPose_Feedback_pose_mean
{
public:
  explicit Init_HoldPose_Feedback_pose_mean(::trident_msgs::action::HoldPose_Feedback & msg)
  : msg_(msg)
  {}
  Init_HoldPose_Feedback_pose_variance pose_mean(::trident_msgs::action::HoldPose_Feedback::_pose_mean_type arg)
  {
    msg_.pose_mean = std::move(arg);
    return Init_HoldPose_Feedback_pose_variance(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Feedback msg_;
};

class Init_HoldPose_Feedback_message
{
public:
  explicit Init_HoldPose_Feedback_message(::trident_msgs::action::HoldPose_Feedback & msg)
  : msg_(msg)
  {}
  Init_HoldPose_Feedback_pose_mean message(::trident_msgs::action::HoldPose_Feedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_HoldPose_Feedback_pose_mean(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Feedback msg_;
};

class Init_HoldPose_Feedback_status
{
public:
  Init_HoldPose_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoldPose_Feedback_message status(::trident_msgs::action::HoldPose_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_HoldPose_Feedback_message(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::HoldPose_Feedback>()
{
  return trident_msgs::action::builder::Init_HoldPose_Feedback_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_HoldPose_SendGoal_Request_goal
{
public:
  explicit Init_HoldPose_SendGoal_Request_goal(::trident_msgs::action::HoldPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::HoldPose_SendGoal_Request goal(::trident_msgs::action::HoldPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_SendGoal_Request msg_;
};

class Init_HoldPose_SendGoal_Request_goal_id
{
public:
  Init_HoldPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoldPose_SendGoal_Request_goal goal_id(::trident_msgs::action::HoldPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HoldPose_SendGoal_Request_goal(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::HoldPose_SendGoal_Request>()
{
  return trident_msgs::action::builder::Init_HoldPose_SendGoal_Request_goal_id();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_HoldPose_SendGoal_Response_stamp
{
public:
  explicit Init_HoldPose_SendGoal_Response_stamp(::trident_msgs::action::HoldPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::HoldPose_SendGoal_Response stamp(::trident_msgs::action::HoldPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_SendGoal_Response msg_;
};

class Init_HoldPose_SendGoal_Response_accepted
{
public:
  Init_HoldPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoldPose_SendGoal_Response_stamp accepted(::trident_msgs::action::HoldPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_HoldPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::HoldPose_SendGoal_Response>()
{
  return trident_msgs::action::builder::Init_HoldPose_SendGoal_Response_accepted();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_HoldPose_GetResult_Request_goal_id
{
public:
  Init_HoldPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trident_msgs::action::HoldPose_GetResult_Request goal_id(::trident_msgs::action::HoldPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::HoldPose_GetResult_Request>()
{
  return trident_msgs::action::builder::Init_HoldPose_GetResult_Request_goal_id();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_HoldPose_GetResult_Response_result
{
public:
  explicit Init_HoldPose_GetResult_Response_result(::trident_msgs::action::HoldPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::HoldPose_GetResult_Response result(::trident_msgs::action::HoldPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_GetResult_Response msg_;
};

class Init_HoldPose_GetResult_Response_status
{
public:
  Init_HoldPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoldPose_GetResult_Response_result status(::trident_msgs::action::HoldPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_HoldPose_GetResult_Response_result(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::HoldPose_GetResult_Response>()
{
  return trident_msgs::action::builder::Init_HoldPose_GetResult_Response_status();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace action
{

namespace builder
{

class Init_HoldPose_FeedbackMessage_feedback
{
public:
  explicit Init_HoldPose_FeedbackMessage_feedback(::trident_msgs::action::HoldPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::trident_msgs::action::HoldPose_FeedbackMessage feedback(::trident_msgs::action::HoldPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_FeedbackMessage msg_;
};

class Init_HoldPose_FeedbackMessage_goal_id
{
public:
  Init_HoldPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoldPose_FeedbackMessage_feedback goal_id(::trident_msgs::action::HoldPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HoldPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::trident_msgs::action::HoldPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::action::HoldPose_FeedbackMessage>()
{
  return trident_msgs::action::builder::Init_HoldPose_FeedbackMessage_goal_id();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__BUILDER_HPP_
