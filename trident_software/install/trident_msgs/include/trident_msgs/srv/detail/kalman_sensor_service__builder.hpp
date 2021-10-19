// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trident_msgs:srv/KalmanSensorService.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__BUILDER_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__BUILDER_HPP_

#include "trident_msgs/srv/detail/kalman_sensor_service__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_KalmanSensorService_Request_covar
{
public:
  explicit Init_KalmanSensorService_Request_covar(::trident_msgs::srv::KalmanSensorService_Request & msg)
  : msg_(msg)
  {}
  ::trident_msgs::srv::KalmanSensorService_Request covar(::trident_msgs::srv::KalmanSensorService_Request::_covar_type arg)
  {
    msg_.covar = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::KalmanSensorService_Request msg_;
};

class Init_KalmanSensorService_Request_state
{
public:
  Init_KalmanSensorService_Request_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KalmanSensorService_Request_covar state(::trident_msgs::srv::KalmanSensorService_Request::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_KalmanSensorService_Request_covar(msg_);
  }

private:
  ::trident_msgs::srv::KalmanSensorService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::KalmanSensorService_Request>()
{
  return trident_msgs::srv::builder::Init_KalmanSensorService_Request_state();
}

}  // namespace trident_msgs


namespace trident_msgs
{

namespace srv
{

namespace builder
{

class Init_KalmanSensorService_Response_observationmatrix
{
public:
  explicit Init_KalmanSensorService_Response_observationmatrix(::trident_msgs::srv::KalmanSensorService_Response & msg)
  : msg_(msg)
  {}
  ::trident_msgs::srv::KalmanSensorService_Response observationmatrix(::trident_msgs::srv::KalmanSensorService_Response::_observationmatrix_type arg)
  {
    msg_.observationmatrix = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trident_msgs::srv::KalmanSensorService_Response msg_;
};

class Init_KalmanSensorService_Response_gain
{
public:
  explicit Init_KalmanSensorService_Response_gain(::trident_msgs::srv::KalmanSensorService_Response & msg)
  : msg_(msg)
  {}
  Init_KalmanSensorService_Response_observationmatrix gain(::trident_msgs::srv::KalmanSensorService_Response::_gain_type arg)
  {
    msg_.gain = std::move(arg);
    return Init_KalmanSensorService_Response_observationmatrix(msg_);
  }

private:
  ::trident_msgs::srv::KalmanSensorService_Response msg_;
};

class Init_KalmanSensorService_Response_residual
{
public:
  Init_KalmanSensorService_Response_residual()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KalmanSensorService_Response_gain residual(::trident_msgs::srv::KalmanSensorService_Response::_residual_type arg)
  {
    msg_.residual = std::move(arg);
    return Init_KalmanSensorService_Response_gain(msg_);
  }

private:
  ::trident_msgs::srv::KalmanSensorService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::trident_msgs::srv::KalmanSensorService_Response>()
{
  return trident_msgs::srv::builder::Init_KalmanSensorService_Response_residual();
}

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__BUILDER_HPP_
