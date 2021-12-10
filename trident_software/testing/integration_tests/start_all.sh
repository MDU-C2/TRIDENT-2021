#!/bin/bash
# Initialize the different paths used in sourcing installs
trident_dir_path=$(find ~ -wholename "*/TRIDENT-2021/trident_software" -type d)
simulator_ws_path=$(find ~ -wholename "*/catkin_ws/src/TRIDENT-2021-SIM" -type d | xargs dirname | xargs dirname)
ros2_install=/opt/ros/foxy/setup.bash
ros1_install=/opt/ros/noetic/setup.bash
ros2_local_install="install/local_setup.bash"
ros1_local_install="devel/setup.bash"
logdir="logs"

session="Trident"

#Color codes that can be used in printf.
#Remember to finish printf with ${end} to swap back to normal color
red=$'\e[1;31m'
grn=$'\e[1;32m'
yel=$'\e[1;33m'
blu=$'\e[1;34m'
mag=$'\e[1;35m'
cyn=$'\e[1;36m'
end=$'\e[0m'


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
restart_bridge_sim() {
    # Create new tmux session, kill first if exists
    tmux has-session -t $session 2>/dev/null
    if [ $? == 0 ]; then
	tmux kill-session -t $session
    fi
    TMUX='' tmux new-session -d -s $session

    # Start the bridge
    tmux rename-window -t $session:0 'Ros1bridge'
    tmux send-keys -t $session:0 "source ${ros2_install} &&
	source ${ros1_install} &&
	source ${trident_dir_path}/${ros2_local_install} &&
	ros2 run ros1_bridge dynamic_bridge --bridge-all-topics" C-m  

    # Start the simulator
    tmux new-window -t $session:1 -n 'StonefishSimulator'
    if   [ $1 == "athena" ]; then
	tmux send-keys -t $session:1 "source ${ros1_install} &&
	    source ${simulator_ws_path}/${ros1_local_install} &&
	    roslaunch trident_sim athena_simulation.launch" C-m
    elif [ $1 == "naiad" ]; then
	tmux send-keys -t $session:1 "source ${ros1_install} &&
	    source ${simulator_ws_path}/${ros1_local_install} &&
	    roslaunch trident_sim naiad_simulation.launch camera_show:=false" C-m
    else
	tmux send-keys -t $session:1 "source ${ros1_install} &&
	    source ${simulator_ws_path}/${ros1_local_install} &&
	    roslaunch trident_sim trident_simulation.launch camera_show:=false" C-m
    fi

    # Attach to new session in new terminal
    gnome-terminal -- tmux attach -t $session
}
set +a # Stop exporting


#Source ROS2 environment
printf "${cyn}\n=========================\nSourcing ROS2 environment\n=========================\n${end}"
if [ -f "~/ros2_foxy/ros2-linux/setup.bash" ]; then
    source ~/ros2_foxy/ros2-linux/setup.bash
elif [ -f "/opt/ros/foxy/setup.bash" ]; then
    source /opt/ros/foxy/setup.bash
else
    printf "${red}WARNING: ROS setup file not found in ~/ros2_foxy/ros2-linux/setup.bash or /opt/ros/foxy/setup.bash.\n${end}"
fi

printf "${cyn}\n=========================\nBuilding Trident project\n=========================\n${end}"
cd ../../
colcon build --symlink-install --packages-skip ros1_bridge

printf "${cyn}\n=========================\nSourcing Trident environment\n=========================\n${end}"
source install/setup.bash

printf "${cyn}\n=========================\nStart integration tests\n=========================\n${end}"
cd testing/integration_tests

rm -rf $logdir
mkdir $logdir

printf "${cyn}\nStarting Ros Bridge and Athena Simulation\n${cyn}"
#Startup the ros1_bridge and the athena simulation
restart_bridge_sim "athena"

################################################################
#Athena test cases
printf "${cyn}\nStart Athena abort mission test...\n${end}"
launch_test athena/abort_executing_mission.launch.py &> $logdir/athena_abort_executing_mission.txt
if [ $? -ne 0 ]
then
    res_athena_abort_mission="${red}Fail${end}"
else
    res_athena_abort_mission="${grn}Pass${end}"
fi

printf "${cyn}\nStart Athena manual override test...\n${end}"
launch_test athena/manual_override.launch.py &>> $logdir/athena_manual_override.txt
if [ $? -ne 0 ]
then
    res_athena_manual_override="${red}Fail${end}"
else
    res_athena_manual_override="${grn}Pass${end}"
fi

printf "${cyn}\nStart Athena simple mission test...\n${end}"
launch_test athena/simple_mission.launch.py &>> $logdir/athena_simple_mission.txt
if [ $? -ne 0 ]
then
    res_athena_simple_mission="${red}Fail${end}"
else
    res_athena_simple_mission="${grn}Pass${end}"
fi

printf "${cyn}\nStarting Ros Bridge and Naiad Simulation\n${cyn}"
#Startup the ros1_bridge and the naiad simulation
restart_bridge_sim "naiad"

################################################################
#Naiad test cases
printf "${cyn}\nStart Naiad abort mission test...\n${end}"
launch_test naiad/abort_executing_mission.launch.py &>> $logdir/naiad_abort_executing_mission.txt
if [ $? -ne 0 ]
then
    res_naiad_abort_mission="${red}Fail${end}"
else
    res_naiad_abort_mission="${grn}Pass${end}"
fi

printf "${cyn}\nStart Naiad manual override test...\n${end}"
launch_test naiad/manual_override.launch.py &>> $logdir/naiad_manual_override.txt
if [ $? -ne 0 ]
then
    res_naiad_manual_override="${red}Fail${end}"
else
    res_naiad_manual_override="${grn}Pass${end}"
fi

printf "${cyn}\nStart Naiad simple mission test...\n${end}"
launch_test naiad/simple_mission.launch.py &>> $logdir/naiad_simple_mission.txt
if [ $? -ne 0 ]
then
    res_naiad_simple_mission="${red}Fail${end}"
else
    res_naiad_simple_mission="${grn}Pass${end}"
fi

# kill the bridge and simulation
tmux kill-session -t $session

#Print test results
printf "\n+---------------------------------------+-----------+\n"
printf "| Test results: Athena                  |   Status  |\n"
printf "+---------------------------------------+-----------+\n"
printf "| Abort Mission                         |   %s    |\n" $res_athena_abort_mission
printf "| Manual Override                       |   %s    |\n" $res_athena_manual_override
printf "| Simple Mission                        |   %s    |\n" $res_athena_simple_mission
printf "+---------------------------------------+-----------+\n\n"

printf "+---------------------------------------+-----------+\n"
printf "| Test results: Naiad                   |   Status  |\n"
printf "+---------------------------------------+-----------+\n"
printf "| Abort Mission                         |   %s    |\n" $res_naiad_abort_mission
printf "| Manual Override                       |   %s    |\n" $res_naiad_manual_override
printf "| Simple Mission                        |   %s    |\n" $res_naiad_simple_mission
printf "+---------------------------------------+-----------+\n\n"
