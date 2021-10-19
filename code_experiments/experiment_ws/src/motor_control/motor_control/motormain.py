import numpy as np
import math
import time

import rclpy
from rclpy.node import Node

from test_interfaces.msg import FauxPosition as FauxState

#///////////////////////////////
#       PID CLASS
#///////////////////////////////
class PID:
   timeStart = time.time()
   timeSpan = 0.0
   timeStop = 0.0

   currentYaw = 0.0
   currentPitch = 0.0
   currentRoll = 0.0

   currentAccX = 0.0
   currentAccY = 0.0
   currentAccZ = 0.0

   surfacePosZ = 0.0

   AccXoffset = 0.0
   AccYoffset = 0.0

   currentXVelocity = 0.0
   currentYVelocity = 0.0

   currentGyroX = 0.0
   currentGyroY = 0.0
   currentGyroZ = 0.0

   desiredYaw = 0.0
   desiredPitch = 0.0
   desiredRoll = 0.0

   desiredPosX = 0.0
   desiredPosY = 0.0
   desiredPosZ = 0.0

   lastDesiredPosX = 0.0
   lastDesiredPosY = 0.0
   lastDesiredPosZ = 0.0
   lastDesiredYaw = 0.0
   lastDesiredRoll = 0.0
   lastDesiredPitch = 0.0

   localErrorPosX = 0.0
   localErrorPosY = 0.0

   currentPosX = 0.0
   currentPosY = 0.0
   currentPosZ = 0.0

   errorPosX = 0.0
   errorPosY = 0.0
   errorPosZ = 0.0

   errorYaw = 0.0
   errorPitch = 0.0
   errorRoll = 0.0

   errorAccX = 0.0
   errorAccY = 0.0
   errorAccZ = 0.0

   errorGyroX = 0.0
   errorGyroy = 0.0
   errorGyroZ = 0.0

   lastErrorYaw = 0.0
   lastErrorPitch = 0.0
   lastErrorRoll = 0.0

   lastErrorAccX = 0.0
   lastErrorAccY = 0.0
   lastErrorAccZ = 0.0

   lastErrorPosX = 0.0
   lastErrorPosY = 0.0
   lastErrorPosZ = 0.0

   lastErrorGyroX = 0.0
   lastErrorGyroy = 0.0
   lastErrorGyroZ = 0.0

   deltaTime   = 0.05
   lastTime    = 0.0
   currentTime = 0.0

   pitchPValue = 0.0
   pitchIValue = 0.0
   pitchDValue = 0.0

   rollPValue = 0.0
   rollIValue = 0.0
   rollDValue = 0.0

   yawPValue = 0.0
   yawIValue = 0.0
   yawDValue = 0.0

   firstRun = True
   firstRunDerivativePart = True

   zeroLimit = 0.01

   startYaw = 0.0
   startPosZ = 0.0

   thruster = np.zeros(6)

   matrix = np.zeros((6,6))
   pidmatrix = np.zeros((3,6))
                                          #x    y    z    roll pitch yaw
   xPIDconfig = pidmatrix = [(2.0, 2.0, 5.0, 0.1, 0.5, 1.0),  #P
                                          (0.0, 0.0, 0.0, 0.0, 0.0, 0.0),  #I
                                          (0.5, 0.5, 2.0, 0.1, 0.5, 0.1)]  #D

                                              #x          y    z    roll    pitch    yaw
   xThrusterConfig = matrix = [(0.866025 , 0.5, 0.0, 0.0   , 0.0   ,  0.28),  #motor1
                                            (0.0      , 1.0, 0.0, 0.0   , 0.0   ,  0.22),  #motor2
                                            (0.866025 ,-0.5, 0.0, 0.0   , 0.0   , -0.28),  #motor3
                                            (0.0      , 0.0, 1.0,-0.355 ,-0.230 ,  0.0),   #motor4
                                            (0.0      , 0.0, 1.0, 0.355 ,-0.230 ,  0.0),   #motor5
                                            (0.0      , 0.0, 1.0, 0.0   , 0.455 ,  0.0)]   #motor6



   posXPValue = 0.0
   posXIValue = 0.0
   posXDValue = 0.0

   posYPValue = 0.0
   posYIValue = 0.0
   posYDValue = 0.0

   posZPValue = 0.0
   posZIValue = 0.0
   posZDValue = 0.0

   lastAccX = 0.0
   lastAccY = 0.0

      #Set bSimulation TRUE if using the simulator to get a synchronous time step
      #hence the bSimulation time is the same in the simulator.
   simulation = False
   simulationTime = 0.01
   debugText = False #if true then printing debug text
   getFilteredPosition = False

   def setDesiredState( x, y, z, roll, pitch, yaw):
      PID.desiredYaw   = PID.startYaw + yaw
      PID.desiredPitch = pitch
      PID.desiredRoll  = roll

      PID.desiredPosX  = x * math.cos(-PID.startYaw*math.pi/180.0) + y * math.sin(-PID.startYaw*math.pi/180.0)
      PID.desiredPosY  = y * math.sin(-PID.startYaw*math.pi/180.0) + y * math.cos(-PID.startYaw*math.pi/180.0)
      PID.desiredPosZ  = z

   def setDesiredRelativeState( x, y, z, roll, pitch, yaw):

      if (yaw != 0.0):
         PID.desiredYaw = PID.desiredYaw + yaw

      if PID.desiredYaw > 180.0:
         PID.desiredYaw = PID.desiredYaw - 360.0
      elif PID.desiredYaw < -180.0:
         PID.desiredYaw = PID.desiredYaw + 360.0

      if PID.desiredPitch > 180.0:
         PID.desiredPitch = PID.desiredPitch - 360.0
      elif PID.desiredPitch < -180.0:
         PID.desiredPitch = PID.desiredPitch - 360.0

      if PID.desiredRoll > 180.0:
         PID.desiredRoll = PID.desiredRoll - 360.0
      elif PID.desiredRoll < -180.0:
         PID.desiredRoll = PID.desiredRoll + 360.0

      PID.desiredPosX = PID.currentPosX + x
      PID.desiredPosY = PID.currentPosY + y

      if (z != 0.0):
         PID.desiredPosZ = PID.currentPosZ + z

   def goToSurface():
      PID.desiredPosX = 0.0
      PID.desiredPosY = 0.0
      PID.desiredPosZ = PID.surfacePosZ

   def desiredToLocalSpace():
      x = PID.desiredPosX - PID.currentPosX
      y = PID.desiredPosY - PID.currentPosY

      PID.localErrorPosX = x * math.cos(PID.currentYaw*math.pi/180.0) + y * math.sin(PID.currentYaw * math.pi/180.0)
      PID.localErrorPosY = -x * math.sin(PID.currentYaw * math.pi/180.0) + y * math.cos(PID.currentYaw * math.pi/180.0)

   def velIntegration():
      PID.currentXVelocity = PID.currentXVelocity + (PID.currentAccX) * PID.deltaTime
      PID.currentYVelocity = PID.currentYVelocity + (PID.currentAccY) * PID.deltaTime

      PID.currentXVelocity = PID.currentXVelocity * 1.0 #0.99
      PID.currentYVelocity = PID.currentYVelocity * 1.0; #0.99

   def posIntegration():
      PID.currentPosX = PID.currentPosX + PID.currentXVelocity * PID.deltaTime
      PID.currentPosY = PID.currentPosY + PID.currentYVelocity * PID.deltaTime

   def updateThrusterValue( motorNumber):
      # thruster =   - - - - - - x-axis
      #              - - - - - - y-axis
      #              - - - - - - z-axis
      #              - - - - - - x rotation
      #              - - - - - - y rotation
      #              - - - - - - z rotation
      PID.thruster[motorNumber] = 128.0 + ((PID.posXPValue  * PID.xPIDconfig[0][0] + PID.posXIValue  * PID.xPIDconfig[1][0]  + PID.posXDValue  * PID.xPIDconfig[2][0] )    *PID.xThrusterConfig[motorNumber][0]) + \
                                           ((PID.posYPValue  * PID.xPIDconfig[0][1] + PID.posYIValue  * PID.xPIDconfig[1][1]  + PID.posYDValue  * PID.xPIDconfig[2][1] )    *PID.xThrusterConfig[motorNumber][1]) + \
                                           ((PID.posZPValue  * PID.xPIDconfig[0][2] + PID.posZIValue  * PID.xPIDconfig[1][2]  + PID.posZDValue  * PID.xPIDconfig[2][2] )    *PID.xThrusterConfig[motorNumber][2]) + \
                                           ((PID.rollPValue  * PID.xPIDconfig[0][3] + PID.rollIValue  * PID.xPIDconfig[1][3]  + PID.rollDValue  * PID.xPIDconfig[2][3] )    *PID.xThrusterConfig[motorNumber][3]) + \
                                           ((PID.pitchPValue * PID.xPIDconfig[0][4] + PID.pitchIValue * PID.xPIDconfig[1][4]  + PID.pitchDValue * PID.xPIDconfig[2][4] )    *PID.xThrusterConfig[motorNumber][4]) + \
                                           ((PID.yawPValue   * PID.xPIDconfig[0][5] + PID.yawIValue   * PID.xPIDconfig[1][5]  + PID.yawDValue   * PID.xPIDconfig[2][5] )    *PID.xThrusterConfig[motorNumber][5])  

      if PID.thruster[motorNumber] < 0.0:
         PID.thruster[motorNumber] = 0.0
      elif PID.thruster[motorNumber] > 255.0:
         PID.thruster[motorNumber] = 255.0

   
   def updateErrors():

      PID.errorYaw = PID.currentYaw - PID.desiredYaw

      if PID.errorYaw > 180.0:
         PID.errorYaw = -360.0 + PID.errorYaw

      if PID.errorYaw < -180.0:
         PID.errorYaw = 360.0 + PID.errorYaw

      if abs(PID.errorYaw) < PID.zeroLimit:
         PID.errorYaw = 0.0

      PID.errorPitch = PID.currentPitch - PID.desiredPitch
      if abs(PID.errorPitch) < PID.zeroLimit:
         PID.errorPitch = 0.0

      PID.errorRoll = PID.currentRoll - PID.desiredRoll
      if abs(PID.errorRoll) < PID.zeroLimit:
         PID.errorRoll = 0.0

      PID.errorPosX  = PID.currentPosX - PID.desiredPosX
      PID.errorPosY  = PID.currentPosY - PID.desiredPosY
      PID.errorPosZ  = PID.currentPosZ - PID.desiredPosZ


   def updateLastErrors():
      #Update last errors
      PID.lastErrorYaw   = PID.errorYaw
      PID.lastErrorPitch = PID.errorPitch
      PID.lastErrorRoll  = PID.errorRoll

      PID.lastErrorPosX  = PID.errorPosX
      PID.lastErrorPosY  = PID.errorPosY
      PID.lastErrorPosZ  = PID.errorPosZ

   def updatePIDOrientation():
      #P for all ORIENTATION
      PID.pitchPValue = PID.errorPitch
      PID.rollPValue  = PID.errorRoll
      PID.yawPValue   = PID.errorYaw

      #I for all ORIENTATION
      PID.pitchIValue = PID.pitchIValue  + PID.errorPitch * PID.deltaTime
      PID.rollIValue  = PID.rollIValue   + PID.errorRoll  * PID.deltaTime
      PID.yawIValue   = PID.yawIValue    + PID.errorYaw   * PID.deltaTime

      #D for all ORIENTATION
      PID.pitchDValue = (PID.errorPitch - PID.lastErrorPitch) /PID.deltaTime
      PID.rollDValue  = (PID.errorRoll  - PID.lastErrorRoll)  /PID.deltaTime
      PID.yawDValue   = (PID.errorYaw   - PID.lastErrorYaw)   /PID.deltaTime


   def updatePIDPosition():
      #P for all POSITIONS
      PID.posXPValue  =  PID.errorPosX
      PID.posYPValue  =  PID.errorPosY
      PID.posZPValue  =  PID.errorPosZ

      #I for all POSITIONS
      PID.posXIValue  = PID.posXIValue + PID.errorPosX * PID.deltaTime
      PID.posYIValue  = PID.posYIValue + PID.errorPosY * PID.deltaTime
      PID.posZIValue  = PID.posZIValue + PID.errorPosZ * PID.deltaTime
      
      #D for all POSITIONS
      PID.posXDValue  = (PID.errorPosX - PID.lastErrorPosX) / PID.deltaTime
      PID.posYDValue  = (PID.errorPosY - PID.lastErrorPosY) / PID.deltaTime
      PID.posZDValue  = (PID.errorPosZ - PID.lastErrorPosZ) / PID.deltaTime

   def setDerivativesToZero():
      #D for all POSITIONS
      PID.fPosXDValue  = 0.0
      PID.fPosYDValue  = 0.0
      PID.fPosZDValue  = 0.0

      #D for all ORIENTATION
      PID.fPitchDValue = 0.0
      PID.fRollDValue  = 0.0
      PID.fYawDValue   = 0.0

   def goToDesiredPositionAndOrientation():
      PID.timeStop = time.time()
      PID.timeSpan = PID.timeStop - PID.timeStart

      if (PID.simulation):
         PID.deltaTime = PID.simulationTime
      else:
         PID.deltaTime = PID.timeSpan / float(10^(-12))

      #add positionx/y integration if using position.
      PID.updateErrors()
      PID.updatePIDPosition()
      PID.updatePIDOrientation()

      if (PID.firstRunDerivativePart):
         PID.setDerivativesToZero()
         PID.firstRunDerivativePart = False

      PID.updateLastErrors()
      for i in range(6):
         PID.updateThrusterValue(i)
      PID.timeStart = PID.timeStop


#///////////////////////////////
#       SUBSCRIBER CLASS
#///////////////////////////////
class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            FauxState,
            '/faux_state',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)
        PIDUtils.updatePIDData()
        PID.goToDesiredPositionAndOrientation()


#///////////////////////////////
#       PID UTILS CLASS
#///////////////////////////////
class PIDUtils():

   relRoll = 0.0
   relPitch = 0.0
   relYaw = 0.0

   relX = 0.0
   relY = 0.0
   relDepth = 0.0

   runMode = False
   counter = 0

   pidValue = {
      "P": 0.0,
      "I": 0.0,
      "D": 0.0
   }

   pidDesired = {
      "x": 0.0,
      "y": 0.0,
      "z": 0.0,
      "roll": 0.0,
      "pitch": 0.0,
      "yaw": 0.0
   }

   receivedMsg = {
      "posX": 0.0,
      "posY": 0.0,
      "posZ": 0.0,
      "accX": 0.0,
      "accY": 0.0,
      "accZ": 0.0,
      "gyrX": 0.0,
      "gyrY": 0.0,
      "gyrZ": 0.0,
      "yaw": 0.0,
      "roll": 0.0,
      "pitch": 0.0,
      "sender": "",
      "ethid": 0,
      "pid": "",
      "axis": ""
   }

   def updateDesiredState():
      d = PIDUtils.pidDesired

     #Insert real input values here!!
      d["x"] = 0.0
      d["y"] = 0.0
      d["z"] = 0.0
      d["roll"] = 0.0
      d["pitch"] = 0.0
      d["yaw"] = 0.0


   def filterDesiredYaw(yawToConvert):

      if PID.startYaw + yawToConvert > 180.0:
         yawToConvert = -180.0 + (-180.0 + PID.startYaw + yawToConvert)
      elif PID.startYaw + yawToConvert < -180.0:
         yawToConvert  =  180.0 + ( 180.0 + PID.startYaw + yawToConvert)
      else:
         yawToConvert = PID.startYaw + yawToConvert

   def updatePIDData():
      depth = PIDUtils.receivedMsg["posZ"]
      absX = 0.0
      absY = 0.0
      absZ = 0.0

      absRoll = 0.0
      absPitch = 0.0
      absYaw = 0.0

      depth = ((depth*3059.0)/1024.0)/100.0 #Needs to be calibrated to give proper depth value, this is not good enough.
      sender = PIDUtils.receivedMsg["sender"]
      ethid =  PIDUtils.receivedMsg["ethid"]

      if (sender == "sns"): # sensor
         if (PID.firstRun):
            counterForSend = 0
            PID.rollIValue = 0.0
            PID.pitchIValue = 0.0
            PID.yawIValue = 0.0
            PID.posXIValue = 0.0
            PID.posYIValue = 0.0
            PID.posZIValue = 0.0
            PID.firstRun = False
            PID.startYaw = PIDUtils.receivedMsg["yaw"] #receivedMsg.Get("yaw")
            PID.currentYaw = PID.startYaw
            PID.startPosZ = depth
            PID.currentPosZ = 0.0
            PID.surfacePosZ = PID.currentPosZ
            PID.setDesiredState(0.0,0.0,PID.currentPosZ,0.0,0.0,0.0)
            if PID.debugText:
               print("First run, setting desired to current.")
         
         PID.currentYaw    = PIDUtils.receivedMsg["yaw"] - PID.startYaw
         PID.currentPitch  = PIDUtils.receivedMsg["pitch"]
         PID.currentRoll   = PIDUtils.receivedMsg["roll"]

         if (PID.simulation):
            PID.currentAccX = PIDUtils.receivedMsg["accX"]
            PID.currentAccY = PIDUtils.receivedMsg["accY"]
            PID.currentAccZ = PIDUtils.receivedMsg["accZ"]
         else:
            PID.currentAccX = 0.0
            PID.currentAccY = 0.0
            PID.currentAccZ = 0.0

            if (PID.getFilteredPosition):
               PID.currentPosX = PIDUtils.receivedMsg["posX"]
               PID.currentPosY = PIDUtils.receivedMsg["posY"]

         #Gyro data might be added later to get better estimation on the derivative part.
         PID.currentGyroX = 0.0
         PID.currentGyroY = 0.0
         PID.currentGyroZ = 0.0
         PID.currentPosZ  = depth - PID.startPosZ
      elif (sender == "pth"): #path planner
         if (ethid == 1):
            absRoll  = PIDUtils.receivedMsg["roll"]
            absPitch = PIDUtils.receivedMsg["pitch"]
            absYaw   = PIDUtils.receivedMsg["yaw"]
            absX     = PIDUtils.receivedMsg["posX"]
            absY     = PIDUtils.receivedMsg["posY"]
            absZ     = PIDUtils.receivedMsg["posZ"]
            PID.setDesiredState(absX,absY,absZ,absRoll,absPitch,absYaw)
         elif (ethid == 2):
		      #ada.text_io.put_line("pth ethid 2------------------------------");
            relRoll  = PIDUtils.receivedMsg["roll"]
            relPitch = PIDUtils.receivedMsg["pitch"]
            relYaw   = PIDUtils.receivedMsg["yaw"]
            relX     = -PIDUtils.receivedMsg["posX"]
            relY     = PIDUtils.receivedMsg["posY"]
            relDepth = PIDUtils.receivedMsg["posZ"]

            #relPitch := 0.0; --commented out by ludde 160816
            #relRoll := 0.0; --commented out by ludde 160816
            PID.Set_Desired_Relative_State(relX,relY,relDepth,relRoll,relPitch,relYaw)
         elif (ethid == 3):
            PID.goToSurface()
      elif (sender == "usr"):
         if (ethid == 1):
            sDim  = PIDUtils.receivedMsg["pid"]
            sAxis = PIDUtils.receivedMsg["axis"]
            iDim  = 0
            iAxis = 0

            if (sDim == "p"):
               iDim = 1
            elif (sDim == "i"):
               iDim = 2
            elif (sDim == "d"):
               iDim = 3

            if (sAxis == "x"):
               iAxis = 1
            elif (sAxis == "y"):
               iAxis = 2
            elif (sAxis == "z"):
               iAxis = 3
            elif (sAxis == "roll"):
               iAxis = 4
            elif (sAxis == "pitch"):
               iAxis = 5
            elif (sAxis == "yaw"):
               iAxis = 6
      elif (sender == "can"):
         print("sender=can !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!") #ludde 160816
         PID.firstRun = True
      elif (sender == "m_0"):
         PIDUtils.runMode = False
         PID.desiredRoll = PID.currentRoll
         PID.desiredPitch = PID.currentPitch
      elif (sender == "m_1"):
         PIDUtils.runMode = True
         print("motor on!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")



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
    rclpy.init()
    motor_control = MinimalSubscriber()
    rclpy.spin(motor_control)

    motor_control.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()