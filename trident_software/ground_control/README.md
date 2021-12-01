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