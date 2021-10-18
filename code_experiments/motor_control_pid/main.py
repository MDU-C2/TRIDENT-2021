from pid import PID

pid = PID()

def getSensorValues():
    pid.currentRoll     = 0
    pid.currentPitch    = 0
    pid.currentYaw      = 0
    pid.currentPosX     = 0
    pid.currentPosY     = 0
    pid.currentPosZ     = 0

def setDesiredState():
    relativeState = False
    x = 0
    y = 0
    z = 0
    roll = 0
    pitch = 0
    yaw = 0

    if (relativeState):
        pid.setDesiredRelativeState(x,y,z,roll,pitch,yaw)
    else:
        pid.setDesiredState(x,y,z,roll,pitch,yaw)


def main():
    print("starting...")


if __name__ == '__main__':
    main()