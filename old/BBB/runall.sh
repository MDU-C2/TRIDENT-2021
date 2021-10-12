#!/bin/bash

software/net_com/bin/net_com_main &
software/can_node/bin/can_node_main &
software/mission_control/bin/mission_main &
software/path_planning/bin/path_planning_main &
software/sensor_node/bin/sensor_main &
software/motion_control/bin/pid_main &
wait
echo "All processes done."
