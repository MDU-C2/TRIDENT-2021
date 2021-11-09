#!/bin/bash

bin/net_com_main &
bin/can_node_main &
bin/sensor_node_main &
wait
echo "All processes done."
