## Trident Software

This is the root folder for the software related to the Trident project. 

Athena, NAIAD and the ROS1 bridge have separate ROS workspaces that each contain their specific ROS(2) packages and files.

Most of the core functionality that is shared between Athena and NAIAD are located in the baseclasses (python package), where base classes for the core modules are located. Base classes are to be designed with generalization and adaptability in mind so that they can be inherited from and modified to fit Athena and NAIAD's needs.

Custom messages that are used in the Trident ecosystem are located in the trident_msgs package that reside is the msgs_ws. Before any custom message is created, the creator must ensure that this custom message can't be replaced by one of the standard messages that come packed with the ROS core library. A list of the common interface files can be found here: https://github.com/ros2/common_interfaces



For now, if the bridge requires building, consult with Johannes Deivard.