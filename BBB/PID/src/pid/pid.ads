with Ada.Text_IO;

package PID is
   procedure Go_To_Desired_Position_And_Orientation;
   procedure setDesiredState(x, y, z, roll, pitch, yaw : float);
   procedure setDesiredRelativeState(x, y, z, roll, pitch, yaw : float);
   procedure setCurrentState(Yaw, Pitch, Roll, AccX, AccY, AccZ, GyroX, GyroY, GyroZ, Depth : float);

   currentYaw : float := 0.0;
   currentPitch : float := 0.0;
   currentRoll : float := 0.0;

   currentAccX : float := 0.0;
   currentAccY : float := 0.0;
   currentAccZ : float := 0.0;

   AccXoffset : float := 0.0;
   AccYoffset : float := 0.0;

   currentXVelocity : float := 0.0;
   currentYVelocity : float := 0.0;

   currentGyroX : float := 0.0;
   currentGyroY : float := 0.0;
   currentGyroZ : float := 0.0;

   desiredYaw : float := 0.0;
   desiredPitch : float := 0.0;
   desiredRoll : float := 0.0;

   --  desiredGyroX : float := 0.0;
   --  desiredGyroY : float := 0.0;
   --  desiredGyroZ : float := 0.0;
   --
   --  desiredAccX : float := 0.0;
   --  desiredAccY : float := 0.0;
   --  desiredAccZ : float := 0.0;

   desiredPosX : float := 0.0;
   desiredPosY : float := 0.0;
   desiredPosZ : float := 0.0;


   currentPosX : float := 0.0;
   currentPosY : float := 0.0;
   currentPosZ : float := 0.0;

   errorPosX : float := 0.0;
   errorPosY : float := 0.0;
   errorPosZ : float := 0.0;

   errorYaw : float   := 0.0;
   errorPitch : float := 0.0;
   errorRoll : float  := 0.0;

   errorAccX : float := 0.0;
   errorAccY : float := 0.0;
   errorAccZ : float := 0.0;

   errorGyroX : float := 0.0;
   errorGyroy : float := 0.0;
   errorGyroZ : float := 0.0;

   lastErrorYaw : float   := 0.0;
   lastErrorPitch : float := 0.0;
   lastErrorRoll : float  := 0.0;

   lastErrorAccX : float := 0.0;
   lastErrorAccY : float := 0.0;
   lastErrorAccZ : float := 0.0;

   lastErrorPosX : float := 0.0;
   lastErrorPosY : float := 0.0;
   lastErrorPosZ : float := 0.0;

   lastErrorGyroX : float := 0.0;
   lastErrorGyroy : float := 0.0;
   lastErrorGyroZ : float := 0.0;

   deltaTime   : float := 0.05;
   lastTime    : float := 0.0;
   currentTime : float := 0.0;

   pitch_P_Value : float := 0.0;
   pitch_I_Value : float := 0.0;
   pitch_D_Value : float := 0.0;

   roll_P_Value : float := 0.0;
   roll_I_Value : float := 0.0;
   roll_D_Value : float := 0.0;

   yaw_P_Value : float := 0.0;
   yaw_I_Value : float := 0.0;
   yaw_D_Value : float := 0.0;

   kp_position : float := 10.0;
   ki_position : float := 0.0;--1;--0.01;
   kd_position : float := 40.0;--5;--0.005;

   kp_orientation : float := 20.0;
   ki_orientation : float := 0.0;--1;--0.01;
   kd_orientation : float := 20.0;--5;--0.005;


   zeroLimit : float := 0.01;


  --subtype motor is float range 0.0..255.0;
   thruster : array (1..6) of float := (others => 0.0);

   type matris is array (1..6, 1..6) of float;
   type pidmatris is array (1..3, 1..6) of float;
                              --x     y     z    roll   pitch    yaw
   xPIDconfig : pidmatris := ((10.0, 10.0, 10.0, 20.0 , 20.0   , 20.0),--P
                              (0.0 ,  0.0, 0.0,   0.0 ,  0.0   ,  0.0),--I
                              (40.0, 40.0, 40.0, 20.0 , 20.0   , 20.0));--D

   --                           x           y    z  roll   pitch     yaw
   xThrusterConfig : matris :=((0.866025, 0.5, 0.0, 0.0   , 0.0   , -0.28),--motor1
                               (0.0      , 1.0, 0.0, 0.0   , 0.0   , -0.22),--motor2
                               (0.866025 ,-0.5, 0.0, 0.0   , 0.0   ,  0.28),--motor3
                               (0.0      , 0.0, 1.0, 0.355 , 0.230 ,  0.0),--motor4
                               (0.0      , 0.0, 1.0,-0.355 , 0.230 ,  0.0),--motor5
                               (0.0      , 0.0, 1.0, 0.0   , 0.355 ,  0.0));--motor6



   posX_P_Value : float := 0.0;
   posX_I_Value : float := 0.0;
   posX_D_Value : float := 0.0;

   posY_P_Value : float := 0.0;
   posY_I_Value : float := 0.0;
   posY_D_Value : float := 0.0;

   posZ_P_Value : float := 0.0;
   posZ_I_Value : float := 0.0;
   posZ_D_Value : float := 0.0;

   lastAccX : float := 0.0;
   lastAccY : float := 0.0;


end PID;
