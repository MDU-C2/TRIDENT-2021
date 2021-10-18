import numpy as np
import math

#///////////////////////////////
#       PID CLASS
#///////////////////////////////
class PID():
    def __init__(self):
        super().__init__()
        self.currentYaw = 0.0
        self.currentPitch = 0.0
        self.currentRoll = 0.0

        self.currentAccX = 0.0
        self.currentAccY = 0.0
        self.currentAccZ = 0.0

        self.AccXoffset = 0.0
        self.AccYoffset = 0.0

        self.currentXVelocity = 0.0
        self.currentYVelocity = 0.0

        self.currentGyroX = 0.0
        self.currentGyroY = 0.0
        self.currentGyroZ = 0.0

        self.desiredYaw = 0.0
        self.desiredPitch = 0.0
        self.desiredRoll = 0.0

        self.desiredPosX = 0.0
        self.desiredPosY = 0.0
        self.desiredPosZ = 0.0


        self.currentPosX = 0.0
        self.currentPosY = 0.0
        self.currentPosZ = 0.0

        self.errorPosX = 0.0
        self.errorPosY = 0.0
        self.errorPosZ = 0.0

        self.errorYaw = 0.0
        self.errorPitch = 0.0
        self.errorRoll = 0.0

        self.errorAccX = 0.0
        self.errorAccY = 0.0
        self.errorAccZ = 0.0

        self.errorGyroX = 0.0
        self.errorGyroy = 0.0
        self.errorGyroZ = 0.0

        self.lastErrorYaw = 0.0
        self.lastErrorPitch = 0.0
        self.lastErrorRoll = 0.0

        self.lastErrorAccX = 0.0
        self.lastErrorAccY = 0.0
        self.lastErrorAccZ = 0.0

        self.lastErrorPosX = 0.0
        self.lastErrorPosY = 0.0
        self.lastErrorPosZ = 0.0

        self.lastErrorGyroX = 0.0
        self.lastErrorGyroy = 0.0
        self.lastErrorGyroZ = 0.0

        self.deltaTime   = 0.05
        self.lastTime    = 0.0
        self.currentTime = 0.0

        self.pitch_P_Value = 0.0
        self.pitch_I_Value = 0.0
        self.pitch_D_Value = 0.0

        self.roll_P_Value = 0.0
        self.roll_I_Value = 0.0
        self.roll_D_Value = 0.0

        self.yaw_P_Value = 0.0
        self.yaw_I_Value = 0.0
        self.yaw_D_Value = 0.0

        self.kp_position = 10.0
        self.ki_position = 0.0
        self.kd_position = 40.0

        self.kp_orientation = 20.0
        self.ki_orientation = 0.0
        self.kd_orientation = 20.0

        self.zeroLimit = 0.01

        self.thruster = np.zeros(6)

        self.matrix = np.zeros((6,6))
        self.pidmatrix = np.zeros((3,6))
                                            #x    y    z    roll pitch yaw
        self.xPIDconfig = self.pidmatrix = [(2.0, 2.0, 5.0, 0.1, 0.5, 1.0),  #P
                                            (0.0, 0.0, 0.0, 0.0, 0.0, 0.0),  #I
                                            (0.5, 0.5, 2.0, 0.1, 0.5, 0.1)]  #D

                                              #x          y    z    roll    pitch    yaw
        self.xThrusterConfig = self.matrix = [(0.866025 , 0.5, 0.0, 0.0   , 0.0   ,  0.28),  #motor1
                                              (0.0      , 1.0, 0.0, 0.0   , 0.0   ,  0.22),  #motor2
                                              (0.866025 ,-0.5, 0.0, 0.0   , 0.0   , -0.28),  #motor3
                                              (0.0      , 0.0, 1.0,-0.355 ,-0.230 ,  0.0),   #motor4
                                              (0.0      , 0.0, 1.0, 0.355 ,-0.230 ,  0.0),   #motor5
                                              (0.0      , 0.0, 1.0, 0.0   , 0.455 ,  0.0)]   #motor6



        self.posX_P_Value = 0.0
        self.posX_I_Value = 0.0
        self.posX_D_Value = 0.0

        self.posY_P_Value = 0.0
        self.posY_I_Value = 0.0
        self.posY_D_Value = 0.0

        self.posZ_P_Value = 0.0
        self.posZ_I_Value = 0.0
        self.posZ_D_Value = 0.0

        self.lastAccX = 0.0
        self.lastAccY = 0.0

    def setDesiredState(self, x, y, z, roll, pitch, yaw):
      self.desiredYaw   = yaw
      self.desiredPitch = pitch
      self.desiredRoll  = roll

      self.desiredPosX  = x
      self.desiredPosY  = y
      self.desiredPosZ  = z

    def setDesiredRelativeState(self, x, y, z, roll, pitch, yaw):
      self.desiredYaw   = self.currentYaw + yaw
      self.desiredPitch = self.currentPitch + pitch
      self.desiredRoll  = self.currentRoll + roll

      if self.desiredYaw > 180.0:
         self.desiredYaw = self.desiredYaw - 360.0
      elif self.desiredYaw < -180.0:
         self.desiredYaw = self.desiredYaw + 360.0

      if self.desiredPitch > 180.0:
         self.desiredPitch = self.desiredPitch - 360.0
      elif self.desiredPitch < -180.0:
         self.desiredPitch = self.desiredPitch - 360.0

      if self.desiredRoll > 180.0:
         self.desiredRoll = self.desiredRoll - 360.0
      elif self.desiredRoll < -180.0:
         self.desiredRoll = self.desiredRoll + 360.0

      self.desiredPosX = self.currentPosX + x
      self.desiredPosY = self.currentPosY + y
      self.desiredPosZ = self.currentPosZ + z

    def setCurrentState(self, yaw, pitch, roll, accX, accY, accZ, gyroX, gyroY, gyroZ, depth):
      self.currentYaw = yaw
      self.currentPitch = pitch
      self.currentRoll = roll
      self.currentAccX = accX
      self.currentAccY = accY
      self.currentAccZ = accZ
      self.currentGyroX = gyroX
      self.currentGyroY = gyroY
      self.currentGyroZ = gyroZ
      self.currentPosZ = depth

    def Trapezoid_Integration(self):
      self.currentXVelocity = self.currentXVelocity + self.deltaTime*((self.currentAccX + self.lastAccX)/2.0)
      self.currentYVelocity = self.currentYVelocity + self.deltaTime*((self.currentAccY + self.lastAccY)/2.0)


    def Rectangular_Integration(self):
      self.currentXVelocity = self.currentXVelocity + (self.currentAccX) * self.deltaTime
      self.currentYVelocity = self.currentYVelocity + (self.currentAccY) * self.deltaTime


    def Anti_Spike_Filter(self):
      spikeLimit = 0.05 #find correct value
      if abs(self.currentAccX) < spikeLimit:
         currentAccX = 0.0

      if abs(self.currentAccY) < spikeLimit:
         self.currentAccY = 0.0

      if self.currentAccX != 0.0 and self.lastAccX == 0.0:
         self.lastAccX = self.currentAccX
         self.currentAccX = 0.0
      else:
         self.lastAccX = self.currentAccX

      if self.currentAccY != 0.0 and self.lastAccY == 0.0:
         self.lastAccY = self.currentAccY
         self.currentAccY = 0.0
      else:
         self.lastAccY = self.currentAccY
      self.Rectangular_Integration()

    def Update_Thruster_Value(self, motorNumber):
      # thruster =   - - - - - - x-axis
      #              - - - - - - y-axis
      #              - - - - - - z-axis
      #              - - - - - - x rotation
      #              - - - - - - y rotation
      #              - - - - - - z rotation
      self.thruster[motorNumber] = 128.0 + ((self.posX_P_Value  * self.xPIDconfig(1,1) + self.posX_I_Value  * self.xPIDconfig(2,1)  +self.posX_D_Value  * self.xPIDconfig(3,1) )    *self.xThrusterConfig(motorNumber,1)) + \
                                           ((self.posY_P_Value  * self.xPIDconfig(1,2) + self.posY_I_Value  * self.xPIDconfig(2,2)  +self.posY_D_Value  * self.xPIDconfig(3,2) )    *self.xThrusterConfig(motorNumber,2)) + \
                                           ((self.posZ_P_Value  * self.xPIDconfig(1,3) + self.posZ_I_Value  * self.xPIDconfig(2,3)  +self.posZ_D_Value  * self.xPIDconfig(3,3) )    *self.xThrusterConfig(motorNumber,3)) + \
                                           ((self.Roll_P_Value  * self.xPIDconfig(1,4) + self.Roll_I_Value  * self.xPIDconfig(2,4)  +self.Roll_D_Value  * self.xPIDconfig(3,4) )    *self.xThrusterConfig(motorNumber,4)) + \
                                           ((self.Pitch_P_Value * self.xPIDconfig(1,5) + self.Pitch_I_Value * self.xPIDconfig(2,5)  +self.Pitch_D_Value * self.xPIDconfig(3,5) )    *self.xThrusterConfig(motorNumber,5)) + \
                                           ((self.Yaw_P_Value   * self.xPIDconfig(1,6) + self.Yaw_I_Value   * self.xPIDconfig(2,6)  +self.Yaw_D_Value   * self.xPIDconfig(3,6) )    *self.xThrusterConfig(motorNumber,6))  

      if self.thruster[self.motorNumber] < 0.0:
         self.thruster[self.motorNumber] = 0.0
      elif self.thruster[self.motorNumber] > 255.0:
         self.thruster[self.motorNumber] = 255.0

   
    def Update_Errors(self):

      self.errorYaw = self.currentYaw - self.desiredYaw
      if abs(self.errorYaw) < self.zeroLimit:
         self.errorYaw = 0.0

      self.errorPitch = self.currentPitch - self.desiredPitch
      if abs(self.errorPitch) < self.zeroLimit:
         self.errorPitch = 0.0

      self.errorRoll = self.currentRoll  - self.desiredRoll
      if abs(self.errorRoll) < self.zeroLimit:
         self.errorRoll = 0.0

      self.errorPosX  = self.currentPosX - self.desiredPosX
      self.errorPosY  = self.currentPosY - self.desiredPosY
      self.errorPosZ  = self.currentPosZ - self.desiredPosZ


    def Update_Last_Errors(self):
      #Update last errors
      self.lastErrorYaw   = self.errorYaw
      self.lastErrorPitch = self.errorPitch
      self.lastErrorRoll  = self.errorRoll

      self.lastErrorPosX  = self.errorPosX
      self.lastErrorPosY  = self.errorPosY
      self.lastErrorPosZ  = self.errorPosZ

    def Update_PID_orientation(self):
      #P for all ORIENTATION
      self.pitch_P_Value = self.errorPitch
      self.roll_P_Value  = self.errorRoll
      self.yaw_P_Value   = self.errorYaw

      #I for all ORIENTATION
      self.pitch_I_Value = self.pitch_I_Value  + self.errorPitch * self.deltaTime
      self.roll_I_Value  = self.roll_I_Value   + self.errorRoll  * self.deltaTime
      self.yaw_I_Value   = self.yaw_I_Value    + self.errorYaw   * self.deltaTime

      #D for all ORIENTATION
      self.pitch_D_Value = (self.errorPitch - self.lastErrorPitch) /self.deltaTime
      self.roll_D_Value  = (self.errorRoll  - self.lastErrorRoll)  /self.deltaTime
      self.yaw_D_Value   = (self.errorYaw   - self.lastErrorYaw)   /self.deltaTime


    def Update_PID_position(self):
      #P for all POSITIONS
      self.posX_P_Value  =  self.errorPosX
      self.posY_P_Value  =  self.errorPosY
      self.posZ_P_Value  =  self.errorPosZ

      #I for all POSITIONS
      self.posX_I_Value  = self.posX_I_Value + self.errorPosX * self.deltaTime
      self.posY_I_Value  = self.posY_I_Value + self.errorPosY * self.deltaTime
      self.posZ_I_Value  = self.posZ_I_Value + self.errorPosZ * self.deltaTime
      
      #D for all POSITIONS
      self.posX_D_Value  = (self.errorPosX - self.lastErrorPosX) / self.deltaTime
      self.posY_D_Value  = (self.errorPosY - self.lastErrorPosY) / self.deltaTime
      self.posZ_D_Value  = (self.errorPosZ - self.lastErrorPosZ) / self.deltaTime

    def Go_To_Desired_Position_And_Orientation(self):
      #add positionx/y integration if using position.
      self.Update_Errors()
      self.Update_PID_position
      self.Update_PID_orientation
      self.Update_Last_Errors
      for i in range(6):
         self.update_thruster_value(i)
   