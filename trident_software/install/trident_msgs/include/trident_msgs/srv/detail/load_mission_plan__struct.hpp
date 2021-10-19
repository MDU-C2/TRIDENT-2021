// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:srv/LoadMissionPlan.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__STRUCT_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__trident_msgs__srv__LoadMissionPlan_Request __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__srv__LoadMissionPlan_Request __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadMissionPlan_Request_
{
  using Type = LoadMissionPlan_Request_<ContainerAllocator>;

  explicit LoadMissionPlan_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit LoadMissionPlan_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _latitude_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _latitude_type latitude;
  using _longitude_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _longitude_type longitude;

  // setters for named parameter idiom
  Type & set__latitude(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->longitude = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__srv__LoadMissionPlan_Request
    std::shared_ptr<trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__srv__LoadMissionPlan_Request
    std::shared_ptr<trident_msgs::srv::LoadMissionPlan_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMissionPlan_Request_ & other) const
  {
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMissionPlan_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMissionPlan_Request_

// alias to use template instance with default allocator
using LoadMissionPlan_Request =
  trident_msgs::srv::LoadMissionPlan_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trident_msgs


#ifndef _WIN32
# define DEPRECATED__trident_msgs__srv__LoadMissionPlan_Response __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__srv__LoadMissionPlan_Response __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadMissionPlan_Response_
{
  using Type = LoadMissionPlan_Response_<ContainerAllocator>;

  explicit LoadMissionPlan_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit LoadMissionPlan_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
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

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__srv__LoadMissionPlan_Response
    std::shared_ptr<trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__srv__LoadMissionPlan_Response
    std::shared_ptr<trident_msgs::srv::LoadMissionPlan_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMissionPlan_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMissionPlan_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMissionPlan_Response_

// alias to use template instance with default allocator
using LoadMissionPlan_Response =
  trident_msgs::srv::LoadMissionPlan_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trident_msgs

namespace trident_msgs
{

namespace srv
{

struct LoadMissionPlan
{
  using Request = trident_msgs::srv::LoadMissionPlan_Request;
  using Response = trident_msgs::srv::LoadMissionPlan_Response;
};

}  // namespace srv

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__STRUCT_HPP_
