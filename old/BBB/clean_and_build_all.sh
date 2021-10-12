#!/bin/bash

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
