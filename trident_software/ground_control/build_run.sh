#!/usr/bin/env bash

#Source ROS2 environment
source ~/ros2_foxy/install/setup.bash

#Go to root of trident software
cd ~/Documents/gitclones/TRIDENT-2021/trident_software/
#Build project
colcon build
#Source project
. install/setup.bash

#Start ground control server
cd ground_control/gui_backend_ws/
node index.js