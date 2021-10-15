from enum import IntEnum, IntFlag

class MissionControlState(IntEnum):
    """Enum for the different states the mission control node can be in.
    """
    NO_MISSION = 0
    MISSION_LOADED = 1
    EXECUTING_MISSION = 2
    MISSION_FINISHED = 3

class GotoWaypointStatus(IntFlag):
    """Combinable enum for the GotoWaypoint action.
    """
    COMPUTING_PATH = 1,
    MOVING = 2,
    COMPUTING_PATH_AND_MOVING = 3
    WAITING = 4
    HOLDING_POSITION = 8
    FINISHED = 16
    