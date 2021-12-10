# Ground control
The ground control is divided in to the following sections: header bar, map window, logging window, payload window, and state window. These are depicted in the figure below.
![Image of GUI](https://i.imgur.com/XMxbskp.png)

### Header bar
The header bar consists of the connection status elements, that shows if a connecting with Athena Naiad has been established, and an abort button that puts both Athena and Naiad in idle mode.

### Map Window
The map consists of an interactive map where it is possible to see Athena and Naiad and their respective waypoint markers. The relative nullpoint marker is also visible at C2. Waypoint markers can be added by clicking on the map, which then appears in the waypoint list on the right hand side of the map window. Apart from showing the coordinates of each waypoint marker it is possible to set desired depth (for Naiad), action type, and action parameter. To add a waypoint marker to a specific target the target selector at the bottom right of map window can be used.

### Logging window
The logging window consists of three logging windows: Main, Athena, and Naiad. Main logging window shows the message status of requested and received messages between ground control and Athena/Naiad. Athena and Naiad logging window shows logging messages accumulated from respective system. On the top right of the window are three buttons that can expand logging windows, freeze automatic vertical scroll, and clear logging windows.

### Payload window
The payload window can be used to send payloads to either Athena or Naiad. The commands available are: load mission plan, start mission plan, toggle manual override, and abort.

### State window
The state window shows the current sub state of each module in Athena and Naiad. These modules are the following: mission control, navigation, motor control, motor driver, position, and guidance. Table \ref{tab:trident-states} shows the possible states and their meaning.

| Module            | State                 | Description                                                                       |
| :--------------   | :-------------------- | :---------------------------------------------------------------------------------|
| Mission control   | NO MISSION            | No mission loaded onthe mission control.                                          |
| Mission control   | MISSION LOADED        | Mission plan has beenloaded on the mission control.                               |
| Mission control   | EXECUTING MISSION     | Currently executing theloaded mission plan.                                       |
| Mission control   | MISSION FINISHED      | Executed mission plan hasfinished.                                                |
| Guidance          | IDLE                  | Idling                                                                            |
| Guidance          | PREPARING GUIDANCE    | Preparing the guidance system(pinger).                                            |
| Guidance          | GUIDING               | Currently guiding Naiad,i.e. pinger is active.                                    |
| Navigation        | IDLE                  | Idling                                                                            |
| Navigation        | EXECUTING             | Currently executing a waypoint.                                                   |
| Motor control     | IDLE                  | IdlingMotor control EXECUTING Currently executing a pose.                         |
| Motor control     | MANUAL OVERRIDE       | Motor control is in manualoverride, i.e. manual controlactive from ground control.|
| Motor driver      | IDLE                  | Idling                                                                            |
| Motor driver      | KILLED                | Motor power is turned off.                                                        |
| Motor driver      | MOTOR OUTPUT SILENCE  | Motor power turned off due to watchdog timer not beingserved in time.             |
| Motor driver      | ACTIVE                | Motor power is turned on.                                                         |

## Setup
1. [Install ROS2 Foxy](https://docs.ros.org/en/foxy/index.html)
2. Install Nodejs version 10.23.1-12.x, the version may be updated in the future depending on what version rclnodejs is used. Check https://github.com/RobotWebTools/rclnodejs for more information.
3. Install npm
4. Clone Trident Github repository and hea

In case there are unresolved errors with the node modules in the ground_control/gui_backend folder a reinstall of the node modules can be done:
1. Head in to trident_software/ground_control/gui_backend_ws
2. Delete node_modules folder, package.json, and package-lock.json
3. run `npm init` to initialize node modules
4. Install [express](https://expressjs.com/en/starter/installing.html), [socket.io](https://socket.io/get-started/chat), [three.js](https://threejs.org/docs/index.html#manual/en/introduction/Installation), and [rclnodejs](https://github.com/RobotWebTools/rclnodejs#installation).

## Usage
There are two ways of starting the ground control:
###### Method 1:
Run `bash start_gc.sh` script in the ground control folder. Table shown below shows the mandatory and optional parameters for the script.

Example: `bash start_gc.sh index`


| Argument          | Description                                                           | Type          |
| :--------------   | :-------------------------------------------------------------------- | :------------ |
| index OR tester   | Start the server script OR the tester script                          | Mandatory     |
| -b                | Build the Trident project before sourcing                             | Optional      |
| -g                | Generate ROS2 messages from Trident project in to the ground control  | Optional      |

###### Method 2:
1. Run `source /opt/ros/foxy/setup.bash`
2. Head in to trident_software folder and run `colcon build`
3. Run `source install/setup.bash`
4. Head in to ground_control folder and run `node index.js` to start server or `node tester.js` to start tester.