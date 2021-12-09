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
if [ -f "~/ros2_foxy/ros2-linux/setup.bash" ]; then
    source ~/ros2_foxy/ros2-linux/setup.bash
elif [ -f "/opt/ros/foxy/setup.bash" ]; then
    source /opt/ros/foxy/setup.bash
else
    printf "${red}WARNING: ROS setup file not found in ~/ros2_foxy/ros2-linux/setup.bash or /opt/ros/foxy/setup.bash.\n${end}"
fi

printf "${cyn}\n=========================\nBuilding Trident project\n=========================\n${end}"
cd ../../
colcon build

printf "${cyn}\n=========================\nSourcing Trident environment\n=========================\n${end}"
source install/setup.bash

printf "${cyn}\n=========================\nStart unit tests\n=========================\n${end}"
cd testing/unit_tests

#Athena test cases
printf "${cyn}\nStart Athena mission control test...\n${end}"
launch_test athena/athena_mission_control_test.launch.py &> logs.txt
if [ $? -ne 0 ]
then
    res_athena_mission_control="${red}Fail${end}"
else
    res_athena_mission_control="${grn}Pass${end}"
fi

printf "${cyn}\nStart Athena navigation test...\n${end}"
launch_test athena/athena_navigation_test.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_athena_navigation="${red}Fail${end}"
else
    res_athena_navigation="${grn}Pass${end}"
fi

printf "${cyn}\nStart Athena motor control test...\n${end}"
res_athena_motor_control="${grn}Pass${end}"

launch_test athena/athena_hold_pose.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_athena_motor_control="${red}Fail${end}" 
fi
launch_test athena/athena_go_to_pose.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_athena_motor_control="${red}Fail${end}" 
fi
launch_test athena/athena_manual_override.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_athena_motor_control="${red}Fail${end}" 
fi

printf "${cyn}\nStart Athena motor driver test...\n${end}"
res_athena_motor_driver="${grn}Pass${end}"
launch_test athena/athena_get_state.launch.py &>> logs.txt

launch_test athena/athena_activate_motors.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_athena_motor_driver="${red}Fail${end}"
fi
launch_test athena/athena_kill_motors.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_athena_motor_driver="${red}Fail${end}"
fi
launch_test athena/athena_motor_outputs.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_athena_motor_driver="${red}Fail${end}"
fi

#printf "\nStart Athena position test...\n${end}"
#launch_test naiad/naiad_navigation_test.launch.py

printf "${cyn}\nStart Athena guidance system test...\n${end}"
launch_test athena/athena_guidance_system_test.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_athena_guidance_system="${red}Fail${end}"
else
    res_athena_guidance_system="${grn}Pass${end}"
fi

#Naiad test cases
printf "${cyn}\nStart Naiad mission control test...\n${end}"
launch_test naiad/naiad_mission_control_test.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_naiad_mission_control="${red}Fail${end}"
else
    res_naiad_mission_control="${grn}Pass${end}"
fi

printf "${cyn}\nStart Naiad navigation test...\n${end}"
launch_test naiad/naiad_navigation_test.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_naiad_navigation="${red}Fail${end}"
else
    res_naiad_navigation="${grn}Pass${end}"
fi

printf "${cyn}\nStart Naiad motor control test...\n${end}"
res_naiad_motor_control="${grn}Pass${end}"

launch_test naiad/naiad_hold_pose.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_naiad_motor_control="${red}Fail${end}"  
fi
launch_test naiad/naiad_go_to_pose.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_naiad_motor_control="${red}Fail${end}"  
fi
launch_test naiad/naiad_manual_override.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_naiad_motor_control="${red}Fail${end}"  
fi

printf "${cyn}\nStart Naiad motor driver test...\n${end}"
launch_test naiad/naiad_get_state.launch.py &>> logs.txt
res_naiad_motor_driver="${grn}Pass${end}"

launch_test naiad/naiad_activate_motors.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_naiad_motor_driver="${red}Fail${end}"
fi
launch_test naiad/naiad_kill_motors.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_naiad_motor_driver="${red}Fail${end}"
fi
launch_test naiad/naiad_motor_outputs.launch.py &>> logs.txt
if [ $? -ne 0 ]
then
    res_naiad_motor_driver="${red}Fail${end}"
fi


#Print test results
printf "\n+---------------------------------------+-----------+\n"
printf "| Test results: Athena                  |   Status  |\n"
printf "+---------------------------------------+-----------+\n"
printf "| Mission control                       |   %s    |\n" $res_athena_mission_control
printf "| Navigation                            |   %s    |\n" $res_athena_navigation
printf "| Motor control                         |   %s    |\n" $res_athena_motor_control
printf "| Motor driver                          |   %s    |\n" $res_athena_motor_driver
printf "| Guidance system                       |   %s    |\n" $res_athena_guidance_system
printf "+---------------------------------------+-----------+\n\n"

printf "+---------------------------------------+-----------+\n"
printf "| Test results: Naiad                   |   Status  |\n"
printf "+---------------------------------------+-----------+\n"
printf "| Mission control                       |   %s    |\n" $res_naiad_mission_control
printf "| Navigation                            |   %s    |\n" $res_naiad_navigation
printf "| Motor control                         |   %s    |\n" $res_naiad_motor_control
printf "| Motor driver                          |   %s    |\n" $res_naiad_motor_driver
printf "+---------------------------------------+-----------+\n\n"