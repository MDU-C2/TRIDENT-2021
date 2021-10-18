from pid import PID
from pid_utils import PIDUtils

def getSensorValues():
    PID.currentRoll     = 0
    PID.currentPitch    = 0
    PID.currentYaw      = 0
    PID.currentPosX     = 0
    PID.currentPosY     = 0
    PID.currentPosZ     = 0

def setDesiredState():
    relativeState = False
    x = 0
    y = 0
    z = 0
    roll = 0
    pitch = 0
    yaw = 0

    if (relativeState):
        PID.setDesiredRelativeState(x,y,z,roll,pitch,yaw)
    else:
        PID.setDesiredState(x,y,z,roll,pitch,yaw)


def main():
    print("starting...")

    PID.setDesiredState(1.0, 2.0, 3.0, 0.0, 0.0, 0.0)

    PID.goToDesiredPositionAndOrientation()

    print("Current - yaw :" , PID.currentYaw, " pitch " , PID.currentPitch , " roll " , PID.currentRoll)
    print("Desired - yaw :" , PID.desiredYaw , " pitch " , PID.desiredPitch , " roll " , PID.desiredRoll)
    print("Errors O - yaw :" , PID.errorYaw , " pitch " , PID.errorPitch , " roll " , PID.errorRoll)
    print("Errors P - X :" , PID.errorPosX , " Y " , PID.errorPosY , " Z " , PID.errorPosZ)

    #PIDUtils.filterDesiredYaw(1)
    

if __name__ == '__main__':
    main()