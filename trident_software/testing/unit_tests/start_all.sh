#!/usr/bin/env bash

#Color codes that can be used in printf.
#Remember to finish printf with ${end} to swap back to normal color
red=$'\e[1;31m'
grn=$'\e[1;32m'
yel=$'\e[1;33m'
blu=$'\e[1;34m'
mag=$'\e[1;35m'
cyn=$'\e[1;36m'
end=$'\e[0m'

#Source ROS2 environment
printf "${cyn}\n=========================\nSourcing ROS2 environment\n=========================\n${end}"
source ~/ros2_foxy/ros2-linux/setup.bash

printf "${cyn}\n=========================\nBuilding Trident project\n=========================\n${end}"
cd ../../
colcon build

printf "${cyn}\n=========================\nSourcing Trident environment\n=========================\n${end}"
source install/setup.bash

printf "${cyn}\n=========================\nStart unit tests\n=========================\n${end}"
cd testing/unit_tests

#Athena test cases
printf "${cyn}\n--- Athena mission control ---\n${end}"
launch_test athena/athena_mission_control_test.launch.py

printf "${cyn}\n--- Athena navigation ---\n${end}"
launch_test athena/athena_navigation_test.launch.py

printf "${cyn}\n--- Athena motor control ---\n${end}"
launch_test athena/athena_hold_pose.launch.py
launch_test athena/athena_go_to_pose.launch.py
launch_test athena/athena_manual_override.launch.py

printf "${cyn}\n--- Athena motor driver ---\n${end}"
launch_test athena/athena_get_state.launch.py
launch_test athena/athena_activate_motors.launch.py
launch_test athena/athena_kill_motors.launch.py
launch_test athena/athena_motor_outputs.launch.py

#printf "\n--- Athena position ---\n${end}"
#launch_test naiad/naiad_navigation_test.launch.py

printf "${cyn}\n--- Athena guidance ---\n${end}"
launch_test athena/athena_guidance_system_test.launch.py

#Naiad test cases
printf "${cyn}\n--- Naiad mission control ---\n${end}"
launch_test naiad/naiad_mission_control_test.launch.py

printf "${cyn}\n--- Naiad navigation ---\n${end}"
launch_test naiad/naiad_navigation_test.launch.py

printf "${cyn}\n--- Naiad motor control ---\n${end}"
launch_test naiad/naiad_hold_pose.launch.py
launch_test naiad/naiad_go_to_pose.launch.py
launch_test naiad/naiad_manual_override.launch.py

printf "${cyn}\n--- Naiad motor driver ---\n${end}"
launch_test naiad/naiad_get_state.launch.py
launch_test naiad/naiad_activate_motors.launch.py
launch_test naiad/naiad_kill_motors.launch.py
launch_test naiad/naiad_motor_outputs.launch.py