cmake_minimum_required(VERSION 3.5)
project(trident_msgs)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(action_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rosidl_typesupport_c REQUIRED)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

find_package(rosidl_default_generators REQUIRED)

set(msg_files
  "msg/Waypoint.msg"
  "msg/WaypointAction.msg"
  "msg/Mission.msg"
  "msg/MotorOutput.msg"
  "msg/MotorOutputs.msg"
  "msg/State.msg"
  "msg/PidParam.msg"
  "srv/LoadMission.srv"
  "srv/GuidanceRequest.srv"
  "srv/GetGoalPose.srv"
  "srv/GetState.srv"
  "srv/KalmanSensorService.srv"
  "srv/BasicSensorService.srv"
  "action/StartMission.action"
  "action/GotoWaypoint.action"
  "action/GotoPose.action"
  "action/HoldPose.action"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES builtin_interfaces geometry_msgs std_msgs action_msgs nav_msgs
 )

ament_export_dependencies(rosidl_default_runtime)

ament_package()
