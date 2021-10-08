#!/bin/bash

bin/net_com_main &
bin/can_node_main &
bin/mission_control_main &
bin/path_planning_main &
bin/sensor_node_main &
bin/motion_control_main &
wait
echo "All processes done."
