// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:action/HoldPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__STRUCT_HPP_
#define TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__action__HoldPose_Goal __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__action__HoldPose_Goal __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HoldPose_Goal_
{
  using Type = HoldPose_Goal_<ContainerAllocator>;

  explicit HoldPose_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0ll;
    }
  }

  explicit HoldPose_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0ll;
    }
  }

  // field types and members
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _duration_type =
    int64_t;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__duration(
    const int64_t & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::action::HoldPose_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::action::HoldPose_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__action__HoldPose_Goal
    std::shared_ptr<trident_msgs::action::HoldPose_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__action__HoldPose_Goal
    std::shared_ptr<trident_msgs::action::HoldPose_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoldPose_Goal_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoldPose_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoldPose_Goal_

// alias to use template instance with default allocator
using HoldPose_Goal =
  trident_msgs::action::HoldPose_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trident_msgs


// Include directives for member types
// Member 'pose_mean'
// Member 'pose_variance'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__action__HoldPose_Result __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__action__HoldPose_Result __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HoldPose_Result_
{
  using Type = HoldPose_Result_<ContainerAllocator>;

  explicit HoldPose_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_mean(_init),
    pose_variance(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0ll;
      this->status = 0;
      this->message = "";
    }
  }

  explicit HoldPose_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    pose_mean(_alloc, _init),
    pose_variance(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0ll;
      this->status = 0;
      this->message = "";
    }
  }

  // field types and members
  using _duration_type =
    int64_t;
  _duration_type duration;
  using _status_type =
    int16_t;
  _status_type status;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;
  using _pose_mean_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_mean_type pose_mean;
  using _pose_variance_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_variance_type pose_variance;

  // setters for named parameter idiom
  Type & set__duration(
    const int64_t & _arg)
  {
    this->duration = _arg;
    return *this;
  }
  Type & set__status(
    const int16_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__pose_mean(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose_mean = _arg;
    return *this;
  }
  Type & set__pose_variance(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose_variance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::action::HoldPose_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::action::HoldPose_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__action__HoldPose_Result
    std::shared_ptr<trident_msgs::action::HoldPose_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__action__HoldPose_Result
    std::shared_ptr<trident_msgs::action::HoldPose_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoldPose_Result_ & other) const
  {
    if (this->duration != other.duration) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->pose_mean != other.pose_mean) {
      return false;
    }
    if (this->pose_variance != other.pose_variance) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoldPose_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoldPose_Result_

// alias to use template instance with default allocator
using HoldPose_Result =
  trident_msgs::action::HoldPose_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trident_msgs


// Include directives for member types
// Member 'pose_mean'
// Member 'pose_variance'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__action__HoldPose_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__action__HoldPose_Feedback __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HoldPose_Feedback_
{
  using Type = HoldPose_Feedback_<ContainerAllocator>;

  explicit HoldPose_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_mean(_init),
    pose_variance(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->message = "";
    }
  }

  explicit HoldPose_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    pose_mean(_alloc, _init),
    pose_variance(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->message = "";
    }
  }

  // field types and members
  using _status_type =
    int16_t;
  _status_type status;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;
  using _pose_mean_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_mean_type pose_mean;
  using _pose_variance_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_variance_type pose_variance;

  // setters for named parameter idiom
  Type & set__status(
    const int16_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__pose_mean(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose_mean = _arg;
    return *this;
  }
  Type & set__pose_variance(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose_variance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::action::HoldPose_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::action::HoldPose_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__action__HoldPose_Feedback
    std::shared_ptr<trident_msgs::action::HoldPose_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__action__HoldPose_Feedback
    std::shared_ptr<trident_msgs::action::HoldPose_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoldPose_Feedback_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->pose_mean != other.pose_mean) {
      return false;
    }
    if (this->pose_variance != other.pose_variance) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoldPose_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoldPose_Feedback_

// alias to use template instance with default allocator
using HoldPose_Feedback =
  trident_msgs::action::HoldPose_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trident_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "trident_msgs/action/detail/hold_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__action__HoldPose_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__action__HoldPose_SendGoal_Request __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HoldPose_SendGoal_Request_
{
  using Type = HoldPose_SendGoal_Request_<ContainerAllocator>;

  explicit HoldPose_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit HoldPose_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    trident_msgs::action::HoldPose_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const trident_msgs::action::HoldPose_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__action__HoldPose_SendGoal_Request
    std::shared_ptr<trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__action__HoldPose_SendGoal_Request
    std::shared_ptr<trident_msgs::action::HoldPose_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoldPose_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoldPose_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoldPose_SendGoal_Request_

// alias to use template instance with default allocator
using HoldPose_SendGoal_Request =
  trident_msgs::action::HoldPose_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trident_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__action__HoldPose_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__action__HoldPose_SendGoal_Response __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HoldPose_SendGoal_Response_
{
  using Type = HoldPose_SendGoal_Response_<ContainerAllocator>;

  explicit HoldPose_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit HoldPose_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__action__HoldPose_SendGoal_Response
    std::shared_ptr<trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__action__HoldPose_SendGoal_Response
    std::shared_ptr<trident_msgs::action::HoldPose_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoldPose_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoldPose_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoldPose_SendGoal_Response_

// alias to use template instance with default allocator
using HoldPose_SendGoal_Response =
  trident_msgs::action::HoldPose_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trident_msgs

namespace trident_msgs
{

namespace action
{

struct HoldPose_SendGoal
{
  using Request = trident_msgs::action::HoldPose_SendGoal_Request;
  using Response = trident_msgs::action::HoldPose_SendGoal_Response;
};

}  // namespace action

}  // namespace trident_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__action__HoldPose_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__action__HoldPose_GetResult_Request __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HoldPose_GetResult_Request_
{
  using Type = HoldPose_GetResult_Request_<ContainerAllocator>;

  explicit HoldPose_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit HoldPose_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__action__HoldPose_GetResult_Request
    std::shared_ptr<trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__action__HoldPose_GetResult_Request
    std::shared_ptr<trident_msgs::action::HoldPose_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoldPose_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoldPose_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoldPose_GetResult_Request_

// alias to use template instance with default allocator
using HoldPose_GetResult_Request =
  trident_msgs::action::HoldPose_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trident_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__action__HoldPose_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__action__HoldPose_GetResult_Response __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HoldPose_GetResult_Response_
{
  using Type = HoldPose_GetResult_Response_<ContainerAllocator>;

  explicit HoldPose_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit HoldPose_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    trident_msgs::action::HoldPose_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const trident_msgs::action::HoldPose_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__action__HoldPose_GetResult_Response
    std::shared_ptr<trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__action__HoldPose_GetResult_Response
    std::shared_ptr<trident_msgs::action::HoldPose_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoldPose_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoldPose_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoldPose_GetResult_Response_

// alias to use template instance with default allocator
using HoldPose_GetResult_Response =
  trident_msgs::action::HoldPose_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trident_msgs

namespace trident_msgs
{

namespace action
{

struct HoldPose_GetResult
{
  using Request = trident_msgs::action::HoldPose_GetResult_Request;
  using Response = trident_msgs::action::HoldPose_GetResult_Response;
};

}  // namespace action

}  // namespace trident_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__action__HoldPose_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__action__HoldPose_FeedbackMessage __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HoldPose_FeedbackMessage_
{
  using Type = HoldPose_FeedbackMessage_<ContainerAllocator>;

  explicit HoldPose_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit HoldPose_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    trident_msgs::action::HoldPose_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const trident_msgs::action::HoldPose_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__action__HoldPose_FeedbackMessage
    std::shared_ptr<trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__action__HoldPose_FeedbackMessage
    std::shared_ptr<trident_msgs::action::HoldPose_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoldPose_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoldPose_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoldPose_FeedbackMessage_

// alias to use template instance with default allocator
using HoldPose_FeedbackMessage =
  trident_msgs::action::HoldPose_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trident_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace trident_msgs
{

namespace action
{

struct HoldPose
{
  /// The goal message defined in the action definition.
  using Goal = trident_msgs::action::HoldPose_Goal;
  /// The result message defined in the action definition.
  using Result = trident_msgs::action::HoldPose_Result;
  /// The feedback message defined in the action definition.
  using Feedback = trident_msgs::action::HoldPose_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = trident_msgs::action::HoldPose_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = trident_msgs::action::HoldPose_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = trident_msgs::action::HoldPose_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct HoldPose HoldPose;

}  // namespace action

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__STRUCT_HPP_
