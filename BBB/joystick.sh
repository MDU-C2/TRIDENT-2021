#!/bin/bash

if [ "$1" = "kill" ]
then

	if [ "$2" = "pth" ]; then
		kill -9 $(pidof path_planning_main)
	elif [ "$2" = "msn" ]; then
		kill -9 $(pidof mission_control_main)
	elif [ "$2" = "pid" ]; then
		kill -9 $(pidof motion_control_main)
	elif [ "$2" = "bgw" ]; then
		kill -9 $(pidof net_com_main)
	elif [ "$2" = "can" ]; then
		kill -9 $(pidof can_node_main)
	elif [ "$2" = "sns" ]; then
		kill -9 $(pidof sensor_node_main)
	else
		kill -9 $(pidof path_planning_main)
		kill -9 $(pidof mission_control_main)
		kill -9 $(pidof motion_control_main)
		kill -9 $(pidof net_com_main)
		kill -9 $(pidof can_node_main)
		kill -9 $(pidof sensor_node_main)
		echo "All processes killed."
	fi
elif [ "$1" = "run" ]
then
{
	if [ "$2" = "pth" ]; then
		/home/ubuntu/BBB/bin/path_planning_main &
	elif [ "$2" = "msn" ]; then
		/home/ubuntu/BBB/bin/mission_control_main &
	elif [ "$2" = "pid" ]; then
		/home/ubuntu/BBB/bin/motion_control_main &
	elif [ "$2" = "bgw" ]; then
		/home/ubuntu/BBB/bin/net_com_main &
	elif [ "$2" = "can" ]; then
		/home/ubuntu/BBB/bin/can_node_main &
	elif [ "$2" = "sns" ]; then
		/home/ubuntu/BBB/bin/sensor_node_main &
	else
		/home/ubuntu/BBB/bin/net_com_main &
		/home/ubuntu/BBB/bin/can_node_main &
#		/home/ubuntu/BBB/bin/mission_control_main &
#		/home/ubuntu/BBB/bin/path_planning_main &
 		/home/ubuntu/BBB/bin/motion_control_main &

		/home/ubuntu/BBB/bin/sensor_node_main &


		#wait
		echo "All processes done."
	fi
}&> /dev/null
elif [ "$1" = "build" ]
then

if [ "$2" = "all" ] 
then
	make all -C software/can_node
	cp software/can_node/bin/can_node_main bin/can_node_main
	make all -C software/net_com
	cp software/net_com/bin/net_com_main bin/net_com_main
	make all -C software/mission_control
	cp software/mission_control/bin/mission_control_main bin/mission_control_main
	make all -C software/path_planning
	cp software/path_planning/bin/path_planning_main bin/path_planning_main
	make all -C software/sensor_node
	cp software/sensor_node/bin/sensor_node_main bin/sensor_node_main
	make all -C software/motion_control
	cp software/motion_control/bin/motion_control_main bin/motion_control_main
	echo "Building done!"
else
	make this -C software/can_node
	cp software/can_node/bin/can_node_main bin/can_node_main
	make this -C software/net_com
	cp software/net_com/bin/net_com_main bin/net_com_main
	make this -C software/mission_control
	cp software/mission_control/bin/mission_control_main bin/mission_control_main
	make this -C software/path_planning
	cp software/path_planning/bin/path_planning_main bin/path_planning_main
	make this -C software/sensor_node
	cp software/sensor_node/bin/sensor_node_main bin/sensor_node_main
	make this -C software/motion_control
	cp software/motion_control/bin/motion_control_main bin/motion_control_main
	echo "Building done!"
fi

elif [ "$1" = "restart" ]
then
{
        if [ "$2" = "pth" ]; then
                kill -9 $(pidof path_planning_main)
        elif [ "$2" = "msn" ]; then
                kill -9 $(pidof mission_control_main)
        elif [ "$2" = "pid" ]; then
                kill -9 $(pidof motion_control_main)
        elif [ "$2" = "bgw" ]; then
                kill -9 $(pidof net_com_main)
        elif [ "$2" = "can" ]; then
                kill -9 $(pidof can_node_main)
        elif [ "$2" = "sns" ]; then
                kill -9 $(pidof sensor_node_main)
        else
                kill -9 $(pidof path_planning_main)
                kill -9 $(pidof mission_control_main)
                kill -9 $(pidof motion_control_main)
                kill -9 $(pidof net_com_main)
                kill -9 $(pidof can_node_main)
                kill -9 $(pidof sensor_node_main)
                echo "All processes killed."
        fi

        if [ "$2" = "pth" ]; then
                bin/path_planning_main &
        elif [ "$2" = "msn" ]; then
                bin/mission_control_main &
        elif [ "$2" = "pid" ]; then
                bin/motion_control_main &
        elif [ "$2" = "bgw" ]; then
                bin/net_com_main &
        elif [ "$2" = "can" ]; then
                bin/can_node_main &
        elif [ "$2" = "sns" ]; then
                bin/sensor_node_main &
        else
                bin/net_com_main &
                bin/can_node_main &
                bin/mission_control_main &
                bin/path_planning_main &
                bin/sensor_node_main &
                bin/motion_control_main &
                wait
                echo "All processes done."
        fi
}&> /dev/null
elif [ "$1" = "move" ]
then

	if [ "$2" = "pth" ]; then
                cp software/path_planning/bin/path_planning_main bin/path_planning_main
        elif [ "$2" = "msn" ]; then
                cp software/mission_control/bin/mission_control_main bin/mission_control_main
        elif [ "$2" = "pid" ]; then
                cp software/motion_control/bin/motion_control_main bin/motion_control_main
        elif [ "$2" = "bgw" ]; then
                cp software/net_com/bin/net_com_main bin/net_com_main
        elif [ "$2" = "can" ]; then
                cp software/can_node/bin/can_node_main bin/can_node_main
        elif [ "$2" = "sns" ]; then
                cp software/sensor_node/bin/sensor_node_main bin/sensor_node_main
	else
		cp software/can_node/bin/can_node_main bin/can_node_main
		cp software/net_com/bin/net_com_main bin/net_com_main
		cp software/mission_control/bin/mission_control_main bin/mission_control_main
		cp software/path_planning/bin/path_planning_main bin/path_planning_main
		cp software/sensor_node/bin/sensor_node_main bin/sensor_node_main
		cp software/motion_control/bin/motion_control_main bin/motion_control_main
	fi

fi
