# Testing
A testing platform has been developed to follow the [continuous integration (CI) and continuous delivery (CD) practices](https://en.wikipedia.org/wiki/CI/CD). The testing platform is outlined in accordance with the [ROS 2 developer guide for testing](https://docs.ros.org/en/foxy/Contributing/Developer-Guide.html#testing), that is structured in to three testing levels:

| Test type             | Level | Implemented   |
| :---------------------| :-----| :-------------|
| Unit testing          | 1/2   | Partially     |
| Integration testing   | 3     | Yes           |
| System testing        | 4     | No            |

**Unit testing** aims to test unit specific functionalities and is separated in to two levels, level 1 and 2. Level 1 tests specific functions in a ROS package and level 2 tests the package itself. As of the current version the level 1 unit testing has not been implemented, while level 2 unit testing has been implemented.

**Integration testing** aims to test several ROS packages together in a subsystem. In our case it includes the mission control, navigation, motor control, motor driver, position, and guidance system, of Athena and Naiad.

**System testing** aims to test the whole system together, which in our case is Athena, Naiad, and ground control. This has not yet been implemented.

## prerequisites
* [Install ROS 1 Noetic](http://wiki.ros.org/noetic)
* [Install ROS 2 Foxy](https://docs.ros.org/en/foxy/)
* [Clone the Trident project](https://github.com/ProjectMDH/TRIDENT-2021)
* [Clone the Trident simulation projet](https://github.com/ProjectMDH/TRIDENT-2021-SIM)
* TMUX: `sudo apt install tmux`

## Usage
For unit testing:
1. Navigate to TRIDENT-2021/trident_software/testing/unit_tests
2. Run `bash start_all.sh`, which will run each unit test sequentially. Alternatively, run a specific unit test with the following command: `launch_test path/to/unit_test_launch_file`.

For integration testing:
1. [Build the ros1_bridge](https://github.com/ProjectMDH/TRIDENT-2021/tree/dev/trident_software#building-the-ros1_bridge)
2. Navigate to TRIDENT-2021/trident_software/testing/integration_tests
3. Run `bash start_all.sh`, which will start the simulation and run through each integration test. Alternatively, run `bash start_sim_athena.sh` or `bash start_sim_naiad.sh` to start up the simulation with only Athena or Naiad. Then open a new terminal, source ROS 2, and run `launch_test path/to/integration_test_launch_file`.