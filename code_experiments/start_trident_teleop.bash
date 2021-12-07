#!/bin/bash
# Initialize the different paths used in sourcing installs
trident_dir_path=$(find ~ -wholename "*/TRIDENT-2021/trident_software" -type d)
simulator_ws_path=$(find ~ -wholename "*/catkin_ws/src/TRIDENT-2021-SIM" -type d | xargs dirname | xargs dirname)
ros2_install=/opt/ros/foxy/setup.bash
ros1_install=/opt/ros/noetic/setup.bash
ros2_local_install="install/local_setup.bash"
ros1_local_install="devel/setup.bash"



shopt -s expand_aliases
set -a # Export the following quality of life functions (usable in subshells)
start_bridge() { ros2 run ros1_bridge dynamic_bridge --bridge-all-topics; }
start_sim() { roslaunch trident_sim trident_simulation.launch camera_show:=false; }
athena_start_core() { ros2 launch athena_bringup sim.system.launch.py; }
naiad_start_naiad_core() { ros2 launch naiad_bringup sim.system.launch.py; }
athena_start_mission() { ros2 action send_goal /athena/mission_control/mission/start trident_msgs/action/StartMission "{}"; }
naiad_start_mission() { ros2 action send_goal /naiad/mission_control/mission/start trident_msgs/action/StartMission "{}"; }
naiad_enable_teleop() { ros2 service call /naiad/motor_control/manual_override std_srvs/srv/SetBool '{data: true}'; }
naiad_disable_teleop() { ros2 service call /naiad/motor_control/manual_override std_srvs/srv/SetBool '{data: false}'; }
athena_enable_teleop() { ros2 service call /athena/motor_control/manual_override std_srvs/srv/SetBool '{data: true}'; }
athena_disable_teleop() { ros2 service call /athena/motor_control/manual_override std_srvs/srv/SetBool '{data: false}'; }
naiad_start_teleop() { ros2 launch naiad_bringup teleop.launch.py; }
athena_start_teleop() { ros2 launch athena_bringup teleop.launch.py; }
set +a # Stop exporting

# Start Naiad teleop
gnome-terminal --tab --title="NAIAD Teleop" -- bash -c "source ${ros2_install} &&
                                                           source ${trident_dir_path}/${ros2_local_install} &&
                                                           read -p 'Press [enter] to enable manual override for NAIAD' &&
                                                           naiad_enable_teleop &&
                                                           naiad_start_teleop;
                                                           bash"
# Start Athena teleop
gnome-terminal --tab --title="Athena Teleop" -- bash -c "source ${ros2_install} &&
                                                           source ${trident_dir_path}/${ros2_local_install} &&
                                                           read -p 'Press [enter] to enable manual override for Athena' &&
                                                           athena_enable_teleop &&
                                                           athena_start_teleop;
                                                           bash"  