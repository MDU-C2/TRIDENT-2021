from .pid import PID
import rclpy
from rclpy.node import Node
from test_interfaces.msg import GoToPos

class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            GoToPos,
            '/go_to_pos',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)
        PIDUtils.updatePIDData()
        PID.goToDesiredPositionAndOrientation()
        PIDUtils.sendToThrusters()

class PIDUtils:

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

      if (sender == "s_c"):
         if (PIDUtils.receivedMsg["ethid"] == 1):
            absRoll  = PIDUtils.receivedMsg["roll"]
            absPitch = PIDUtils.receivedMsg["pitch"]
            absYaw   = PIDUtils.receivedMsg["yaw"]
            absX     = PIDUtils.receivedMsg["posX"]
            absY     = PIDUtils.receivedMsg["posY"]
            absZ     = PIDUtils.receivedMsg["posZ"]

            PID.desiredGpsLat  = "0.0"
            PID.desiredGpsLong = "0.0"
            
            PID.setDesiredState(absX, absY, absZ, absRoll, absPitch, absYaw)
         elif (PIDUtils.receivedMsg["ethid"] == 2):
            relRoll  = PIDUtils.receivedMsg["roll"]
            relPitch = PIDUtils.receivedMsg["pitch"]
            relYaw   = PIDUtils.receivedMsg["yaw"]
            relX     = -PIDUtils.receivedMsg["posX"]
            relY     = PIDUtils.receivedMsg["posY"]
            relDepth = PIDUtils.receivedMsg["posZ"]
            PID.setDesiredRelativeState(relX, relY, relDepth, relRoll, relPitch, relYaw)

   def sendToThrusters():
      print(PID.thruster)
      #Send thruster values to motors (to mini maestro?)
