# Trident Software

This is the root folder for the software related to the Trident project. 

Athena, NAIAD and the ROS1 bridge have separate ROS workspaces that each contain their specific ROS(2) packages and files.

Most of the core functionality that is shared between Athena and NAIAD are located in the baseclasses (python package), where base classes for the core modules are located. Base classes are to be designed with generalization and adaptability in mind so that they can be inherited from and modified to fit Athena and NAIAD's needs.

Custom messages that are used in the Trident ecosystem are located in the trident_msgs package that reside is the msgs_ws. Before any custom message is created, the creator must ensure that this custom message can't be replaced by one of the standard messages that come packed with the ROS core library. A list of the common interface files can be found here: https://github.com/ros2/common_interfaces


## Building the ros1_bridge
__Note: It is recommended to delete all install/ and build/ directories before starting this process.__
Source your ros2 installation
Then, build everything but the bridge in the ros2 workspaces by running this command in the root of the trident_software directory:
```
colcon build --symlink-install --packages-skip ros1_bridge
```

If the simulator needs to be built, build the simulator in a new terminal. For information on how to build the simulator, see: https://github.com/ProjectMDH/TRIDENT-2021-SIM

Now we can build the bridge. Start by sourcing your ros2 installation, followed by your ros1 installation, then the simulation workspace (catkin_ws) and finally the ros2 workspace (trident_software). Run the following command to build the bridge:

```
colcon build --symlink-install --packages-select ros1_bridge --cmake-force-configure
```

### Running the bridge
In a new terminal:
1. Source ros1 installation
2. Source ros2 installation
3. Source ros2 overlay (the trident_software directory)
4. Run the following command to start the bridge:
```
ros2 run ros1_bridge dynamic_bridge --bridge-all-topics
```
__Note: The bridge may need to be restarted if the simulation or the athena/trident core are restarted. Sometimes the bridge doesn't register the new topics__


# Running the bridge and the simulator on separate computers on the same network
It is possible to have the ros1_bridge and the stonefish simulator running on separate computers, however, in order for this to work, certain environment variables needs to be set beforehand. 

On the simulation computer: 
1. Start the simulation.
2. Write down the port of the roscore started by the simulation.
3. Write down the hostname/IP of the computer.

On the ros1_bridge computer: 
1. Set the `ROS_MASTER_URI` to the hostname/IP of the simulation computer and the port of the roscore. If the hostname of the simulation computer is athena-sim and the port of the roscore is 11311 (default port) the command would be:
```
export ROS_MASTER_URI=http://athena-sim.local:11311
```   
2. Set the `ROS_IP` to the bridge computer's IP (yes, the IP of itself). E.g.:
```
export ROS_IP=192.168.1.135
```


# Quality of life bash scripts
In order to make starting of the entire trident stack (i.e., the simulation, ros1_bridge, athena core, naiad core and prepared terminals with the start debug mission commands in them) easier, we have made some bash scripts that does all of that. Note that the simulator needs to be located somewhere in the user's home directory with a directory named `catkin_ws` as the root of the simulation workspace. In addition to that, the `trident_software` directory also needs to be somewhere in the user's home directory, with a directory named `TRIDENT-2021`as a parent directory (this is the default structure we have on GitHub).

We have also created a bash script that prepares the manual override commands for NAIAD and Athena and then starts the command line teleop for each vehicle.

To start the scripts (located in `TRIDENT-2021/code_experiments`), simply run them with bash:
```
bash start_simulation_env.bash
bash start_trident_teleop.bash
```

Further, the scripts also export some very useful functions that can be used in the terminals that are opened by the scripts. A list of the functions and their functionality is shown below:
| Function | Functionality | Command being run |
|---|---|---|
|`start_bridge` | Starts the ros1_bridge | ros2 run ros1_bridge dynamic_bridge --bridge-all-topics; |
|`start_sim` | Starts the simulation | roslaunch trident_sim trident_simulation.launch camera_show:=false; |
|`athena_start_core` | Starts the athena simulation core | ros2 launch athena_bringup sim.system.launch.py; |
|`naiad_start_naiad_core` | Starts the NAIAD simulation core | ros2 launch naiad_bringup sim.system.launch.py; |
|`athena_start_mission` | Starts the start_mission action for Athena | ros2 action send_goal /athena/mission_control/mission/start trident_msgs/action/StartMission "{}"; |
|`naiad_start_mission` | Starts the start_mission action for NAIAD | ros2 action send_goal /naiad/mission_control/mission/start trident_msgs/action/StartMission "{}"; |
|`naiad_enable_teleop` | Sets manual override to True for NAIAD to enable teleop | ros2 service call /naiad/motor_control/manual_override std_srvs/srv/SetBool '{data: true}'; |
|`naiad_disable_teleop` | Sets manual override to False for NAIAD to disable teleop | ros2 service call /naiad/motor_control/manual_override std_srvs/srv/SetBool '{data: false}'; |
|`athena_enable_teleop` |  Sets manual override to True for Athena to enable teleop | ros2 service call /athena/motor_control/manual_override std_srvs/srv/SetBool '{data: true}'; |
|`athena_disable_teleop` | Sets manual override to False for Athena to disable teleop | ros2 service call /athena/motor_control/manual_override std_srvs/srv/SetBool '{data: false}'; |
|`naiad_start_teleop` | Starts the keyboard teleop for NAIAD | ros2 launch naiad_bringup teleop.launch.py; |
|`athena_start_teleop` | Starts the keyboard teleop for Athena | ros2 launch athena_bringup teleop.launch.py; |


# Dependencies
In order to run the systems, certain dependencies needs to be installed.

Simple pid (v1.0.1):
```
pip install simple-pid
```
Simple Quaternions (squaternion v0.3.3):
```
pip install squaternion
```
Jax and jaxlib (for Jacobians calculations);
```
pip install jax && pip install jaxlib
```

