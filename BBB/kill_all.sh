#!/bin/bash
kill -9 $(pidof path_planning_main)
kill -9 $(pidof mission_control_main)
kill -9 $(pidof motion_control_main)
kill -9 $(pidof net_com_main)
kill -9 $(pidof can_node_main)
kill -9 $(pidof sensor_node_main)
echo "All processes killed."

