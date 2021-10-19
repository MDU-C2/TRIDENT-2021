from motor_control.pid import PID
import rclpy
from rclpy.node import Node
from test_interfaces.msg import FauxPosition as FauxState

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
