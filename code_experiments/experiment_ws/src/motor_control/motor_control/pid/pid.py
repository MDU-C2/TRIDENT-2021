import numpy as np
import math
import time

#///////////////////////////////
#       PID CLASS
#///////////////////////////////
class PID:

   earthRadius = 6371.0 #in kilometers
   piOver180 = 0.017453292519943295769236907684886127

   timeStart = time.time()
   timeSpan = 0.0
   timeStop = 0.0

   currentLat = 0.0
   currentLong = 0.0
   desiredLat = 0.0
   desiredLong = 0.0

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

   currentMagX = 0.0
   currentMagY = 0.0
   currentMagZ = 0.0

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

   gpsLat = gpsLong = "0.0"
   desiredGpsLat = desiredGpsLong = "0.0"
   savedLat = savedLong = "0.0"
   distanceFromGPSPosition = 2.0
   gpsNS = "N"
   gpsWE = "E"
   gpsTime = 0.0
   goToLastGps = 0
   setDesiredGpsCurrent = 0

   firstRun = True
   firstRunDerivativePart = True

   zeroLimit = 0.01

   startYaw = 0.0
   offsetYaw = 0.0
   startPosZ = 0.0
   startPitch = 0.0

   thruster = np.zeros(6)
                 #x    y    z    roll pitch yaw
   xPIDconfig = [(2.0, 2.0, 5.0, 0.1, 0.5, 1.0),  #P
                 (0.0, 0.0, 0.0, 0.0, 0.0, 0.0),  #I
                 (0.5, 0.5, 2.0, 0.1, 0.5, 0.1)]  #D

                      #x          y    z    roll    pitch    yaw
   xThrusterConfig = [(0.866025 , 0.5, 0.0, 0.0   , 0.0   ,  0.28),  #motor1
                      (0.0      , 1.0, 0.0, 0.0   , 0.0   ,  0.22),  #motor2
                      (0.866025 ,-0.5, 0.0, 0.0   , 0.0   , -0.28),  #motor3
                      (0.0      , 0.0, 1.0,-0.355 ,-0.230 ,  0.0),   #motor4
                      (0.0      , 0.0, 1.0, 0.355 ,-0.230 ,  0.0),   #motor5
                      (0.0      , 0.0, 1.0, 0.0   , 0.455 ,  0.0)]   #motor6

   THRUSTER_BOOST = 6000.0          #Scaling the old values to fit the expected values for the mini maestro servo controller
   THRUSTER_SCALING = 15.7          #From the old range of 0-255 with 128 being neutral, to 4000-8000 with 6000 being neutral
   THRUSTER_MAX_FORWARD = 6800.0    #The thrusters are strong. We are not utilizing the maximum. Max possible = 8000
   THRUSTER_MAX_BACKWARD = 5200.0   # Minimum possible = 4000 (Full thrust backwards)

   THRUSTER_MAX_SPEED = 50.0
   
   thrusterMinStep = -50.0
   thrusterMaxStep = 50.0
   thrusterLowCalib = -150.0
   thrusterHighCalib = 100.0

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

   #Set Simulation TRUE if using the simulator to get a synchronous time step
   #hence the Simulation time is the same in the simulator.
   simulation = False
   simulationTime = 0.01
   debugText = False #if true then printing debug text
   getFilteredPosition = False

   def setDesiredState( x, y, z, roll, pitch, yaw):
      PID.desiredYaw   = yaw
      PID.desiredPitch = pitch
      PID.desiredRoll  = roll

      PID.desiredPosX  = x
      PID.desiredPosY  = y
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
      PID.desiredGpsLat = "0.0"
      PID.desiredGpsLong = "0.0"

   def desiredToLocalSpace():
      x = PID.desiredPosX - PID.currentPosX
      y = PID.desiredPosY - PID.currentPosY

      PID.localErrorPosX = x * math.cos(PID.currentYaw*math.pi/180.0) + y * math.sin(PID.currentYaw * math.pi/180.0)
      PID.localErrorPosY = -x * math.sin(PID.currentYaw * math.pi/180.0) + y * math.cos(PID.currentYaw * math.pi/180.0)

   def velIntegration():
      PID.currentXVelocity = PID.currentXVelocity + (PID.currentAccX) * PID.deltaTime
      PID.currentYVelocity = PID.currentYVelocity + (PID.currentAccY) * PID.deltaTime

      PID.currentXVelocity = PID.currentXVelocity * 1.0
      PID.currentYVelocity = PID.currentYVelocity * 1.0;

   def posIntegration():
      PID.currentPosX = PID.currentPosX + PID.currentXVelocity * PID.deltaTime
      PID.currentPosY = PID.currentPosY + PID.currentYVelocity * PID.deltaTime

   def updateThrusterValue( motorNumber):
      thrusterX = 0.0
      thrusterZ = 0.0
     
      PID.thruster[motorNumber] = 0.0
      #To limit the velocity
      thrusterX = ((PID.posXPValue * PID.xPIDconfig[0][0] + PID.posXIValue * PID.xPIDconfig[1][0] + PID.posXDValue * PID.xPIDconfig[2][0]) * PID.xThrusterConfig[motorNumber][0])
      thrusterZ = ((PID.posZPValue * PID.xPIDconfig[0][2] + PID.posZIValue * PID.xPIDconfig[1][2] + PID.posZDValue * PID.xPIDconfig[2][2]) * PID.xThrusterConfig[motorNumber][2])
      
      #Check x values
      if thrusterX >= PID.THRUSTER_MAX_SPEED:
         PID.thruster[motorNumber] = PID.thruster[motorNumber] + PID.THRUSTER_MAX_SPEED
      elif thrusterX <= -PID.THRUSTER_MAX_SPEED:
         PID.thruster[motorNumber] = PID.thruster[motorNumber] - PID.THRUSTER_MAX_SPEED
      else:
         PID.thruster[motorNumber] = PID.thruster[motorNumber] + thrusterX; 

      #Check z values
      if thrusterZ >= PID.THRUSTER_MAX_SPEED:
         PID.thruster[motorNumber] = PID.thruster[motorNumber] + PID.THRUSTER_MAX_SPEED
      elif thrusterZ	<= -PID.THRUSTER_MAX_SPEED:
         PID.thruster[motorNumber] = PID.thruster[motorNumber] - PID.THRUSTER_MAX_SPEED
      else:
         PID.thruster[motorNumber] = PID.thruster[motorNumber] + thrusterZ
      
      #Sum remaining values
      # y axis
      # x rotation
      # y rotation
      # z rotation
      PID.thruster[motorNumber] = PID.thruster[motorNumber] + \
      ((PID.posYPValue  * PID.xPIDconfig[0][1] + PID.posYIValue  * PID.xPIDconfig[1][1] + PID.posYDValue  * PID.xPIDconfig[2][1]) * PID.xThrusterConfig[motorNumber][1]) + \
      ((PID.rollPValue  * PID.xPIDconfig[0][3] + PID.rollIValue  * PID.xPIDconfig[1][3] + PID.rollDValue  * PID.xPIDconfig[2][3]) * PID.xThrusterConfig[motorNumber][3]) + \
      ((PID.pitchPValue * PID.xPIDconfig[0][4] + PID.pitchIValue * PID.xPIDconfig[1][4] + PID.pitchDValue * PID.xPIDconfig[2][4]) * PID.xThrusterConfig[motorNumber][4]) + \
      ((PID.yawPValue   * PID.xPIDconfig[0][5] + PID.yawIValue   * PID.xPIDconfig[1][5] + PID.yawDValue   * PID.xPIDconfig[2][5]) * PID.xThrusterConfig[motorNumber][5])

      #Rescale motor values
      PID.thruster[motorNumber] = PID.thruster[motorNumber] * PID.THRUSTER_SCALING

      #Add offset to value
      if PID.thruster[motorNumber] < PID.thrusterMinStep:
         PID.thruster[motorNumber] = PID.thruster[motorNumber] + PID.thrusterLowCalib
      elif PID.thruster[motorNumber] > PID.thrusterMaxStep:
         PID.thruster[motorNumber] = PID.thruster[motorNumber] + PID.thrusterHighCalib

      PID.thruster[motorNumber] = PID.thruster[motorNumber] + PID.THRUSTER_BOOST

      if PID.thruster[motorNumber] < PID.THRUSTER_MAX_BACKWARD:
         PID.thruster[motorNumber] = PID.THRUSTER_MAX_BACKWARD
      elif PID.thruster[motorNumber] > PID.THRUSTER_MAX_FORWARD:
         PID.thruster[motorNumber] = PID.THRUSTER_MAX_FORWARD

      #thrusterDir (Thruster_Dir) seems to be always 1 in old code,
      #Hence this code below is unnecessary
      #if not PID.thrusterDir[motorNumber] (MotorNumber):
      #   PID.thruster[motorNumber] = (PID.THRUSTER_BOOST - (PID.thruster[motorNumber]) - PID.THRUSTER_BOOST)

   def bearing(lat1, long1, lat2, long2):
      dx = long2 - long1
      Y = math.sin(dx) * math.cos(lat2)
      X = math.cos(lat1) * math.sin(lat2) - math.sin(lat1) * math.cos(lat2) * math.cos(dx)
      X = (math.atan(Y, X) / PID.piOver180)
      if X < 0.0:
         return 360.0 + X
      else:
         return X

   def greatCircleDistance(lat1, long1, lat2, long2):
      a = math.sin(0.5 * (lat2 - lat1))
      b = math.sin(0.5 * (long2 - long1))
      return 2.0 * PID.earthRadius * math.asin(math.sqrt(a * a + math.cos(lat1) * math.cos(lat2) * b * b))

   def ddToRadians(dd):
      return dd * PID.piOver180

   def updateHeadingAndDistance():
      currentLat  = float(PID.gpsLat)
      currentLong = float(PID.gpsLong)
      desiredLat  = float(PID.desiredGpsLat)
      desiredLong = float(PID.desiredGpsLong)
		
      radCLat  = ddToRadians(currentLat)
      radCLong = ddToRadians(currentLong)
      radDLat  = ddToRadians(desiredLat)
      radDLong = ddToRadians(desiredLong)

      PID.desiredPosX = float(greatCircleDistance(radCLat, radCLong, radDLat, radDLong))
		
		# dont do anything if within 2 meters
      if PID.desiredPosX < PID.distanceFromGPSPosition:
         PID.desiredPosX = 0.0
      else:
         PID.desiredYaw = float(bearing(radCLat, radCLong, radDLat, radDLong))

   
   
   def updateErrors():

      emptyString = "0.0"
      if (PID.gpsLat != emptyString and PID.gpsLong != emptyString):
         PID.updateHeadingAndDistance()

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

   def updatePIDPose():
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
      PID.posXDValue  = 0.0
      PID.posYDValue  = 0.0
      PID.posZDValue  = 0.0

      #D for all ORIENTATION
      PID.pitchDValue = 0.0
      PID.rollDValue  = 0.0
      PID.yawDValue   = 0.0

   def goToDesiredPositionAndOrientation():
      PID.timeStop = time.time()
      PID.timeSpan = PID.timeStop - PID.timeStart

      if (PID.simulation):
         PID.deltaTime = PID.simulationTime
      else:
         PID.deltaTime = PID.timeSpan / float(10^(-12))

      #add positionx/y integration if using position.
      PID.updateErrors()
      PID.updatePIDPose()

      if (PID.firstRunDerivativePart):
         PID.setDerivativesToZero()
         PID.firstRunDerivativePart = False

      PID.updateLastErrors()
      for i in range(6):
         PID.updateThrusterValue(i)
      PID.timeStart = PID.timeStop

