import numpy as np

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
                                   #x     y     z    roll   pitch    yaw
        self.xPIDconfig = self.pidmatrix = [(10.0, 10.0, 10.0, 20.0 , 20.0   , 20.0),  #P
                                  (0.0 ,  0.0,  0.0,  0.0 ,  0.0   ,  0.0),  #I
                                  (40.0, 40.0, 40.0, 20.0 , 20.0   , 20.0)]  #D

                                    #x          y    z    roll    pitch    yaw
        self.xThrusterConfig = self.matrix = [(0.866025 , 0.5, 0.0, 0.0   , 0.0   , -0.28),  #motor1
                                    (0.0      , 1.0, 0.0, 0.0   , 0.0   , -0.22), #motor2
                                    (0.866025 ,-0.5, 0.0, 0.0   , 0.0   ,  0.28), #motor3
                                    (0.0      , 0.0, 1.0, 0.355 , 0.230 ,  0.0),  #motor4
                                    (0.0      , 0.0, 1.0,-0.355 , 0.230 ,  0.0),  #motor5
                                    (0.0      , 0.0, 1.0, 0.0   , 0.355 ,  0.0)]  #motor6



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
