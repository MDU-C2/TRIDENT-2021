from enum import IntEnum, IntFlag

class MissionControlState(IntEnum):
    """Enum for the different states the mission control node can be in.
    """
    NO_MISSION = 0
    MISSION_LOADED = 1
    EXECUTING_MISSION = 2
    MISSION_FINISHED = 3

    def __str__(self):
        return self.name

class StartMissionStatus(IntEnum):
    """Enum for the mission status messages in the StartMission action.
    """
    EXECUTING = 0
    WAITING = 1
    FINISHED = 2

    def __str__(self):
        return self.name

class NavigationState(IntEnum):
    """Enum for the different states the mission control node can be in.
    """
    IDLE = 0
    EXECUTING = 1

    def __str__(self):
        return self.name

class GotoWaypointStatus(IntFlag):
    """Combinable enum for status in the the GotoWaypoint action.
    """
    COMPUTING_PATH = 1
    MOVING = 2
    COMPUTING_PATH_AND_MOVING = 3
    WAITING = 4
    HOLDING_POSITION = 8
    FINISHED = 16

    def __str__(self):
        return self.name

class GotoPoseStatus(IntEnum):
    """Enum for the different states the GotoPose action can have.
    """
    MOVING_TO_POSE = 1
    WAITING = 2
    FINISHED = 3
    FAILED = 4

    def __str__(self):
        return self.name

class HoldPoseStatus(IntEnum):
    """Enum for the different states the HoldPose action can have.
    """
    MOVING_TO_POSE = 1
    HOLDING = 2

    def __str__(self):
        return self.name

class WaypointActionType(IntEnum):
    """Enum for different waypoint actions. Only support no action and hold for now.
    """
    NO_ACTION = 0
    HOLD = 1

    def __str__(self):
        return self.name

class MotorControlState(IntEnum):
    """Enum for different motor control states.
    """
    IDLE = 0
    EXECUTING = 1

    def __str__(self):
        return self.name

class MotorDriverState(IntEnum):
    """Enum for different Motor driver state.
    """
    IDLE = 0
    KILLED = 1
    MOTOR_OUTPUT_SILENCE = 2
    ACTIVE = 3

    def __str__(self):
        return self.name
