with Ada.Text_IO;

package PID2 is
   --to do
   -- find kp, ki, kd, or set induvidual for different (pos/angle)?

   procedure runThis;

   fCurrentYaw : float := 0.0;
   fCurrentPitch : float := 0.0;
   fCurrentRoll : float := 0.0;

   fCurrentAccX : float := 0.0;
   fCurrentAccY : float := 0.0;
   fCurrentAccZ : float := 0.0;

   fAccXOffset : float := 0.0;
   fAccYOffset : float := 0.0;

   fCurrentXVelocity : float := 0.0;
   fCurrentYVelocity : float := 0.0;

   fCurrentGyroX : float := 0.0;
   fCurrentGyroY : float := 0.0;
   fCurrentGyroZ : float := 0.0;

   fDesiredYaw : float := 45.0;
   fDesiredPitch : float := 0.0;
   fDesiredRoll : float := 0.0;

   --  desiredGyroX : float := 0.0;
   --  desiredGyroY : float := 0.0;
   --  desiredGyroZ : float := 0.0;
   --
   --  desiredAccX : float := 0.0;
   --  desiredAccY : float := 0.0;
   --  desiredAccZ : float := 0.0;

   fDesiredPosX : float := 0.0;
   fDesiredPosY : float := 0.0;
   fDesiredPosZ : float := 0.0;

   fCurrentPosX : float := 0.0;
   fCurrentPosY : float := 0.0;
   fCurrentPosZ : float := 0.0;

   fErrorPosX : float := 0.0;
   fErrorPosY : float := 0.0;
   fErrorPosZ : float := 0.0;

   fErrorYaw : float := 0.0;
   fErrorPitch : float := 0.0;
   fErrorRoll : float := 0.0;

   fErrorAccX : float := 0.0;
   fErrorAccY : float := 0.0;
   fErrorAccZ : float := 0.0;

   fErrorGyroX : float := 0.0;
   fErrorGyroY : float := 0.0;
   fErrorGyroZ : float := 0.0;

   fLastErrorYaw : float := 0.0;
   fLastErrorPitch : float := 0.0;
   fLastErrorRoll : float := 0.0;

   fLastErrorAccX : float := 0.0;
   fLastErrorAccY : float := 0.0;
   fLastErrorAccZ : float := 0.0;

   fLastErrorPosX : float := 0.0;
   fLastErrorPosY : float := 0.0;
   fLastErrorPosZ : float := 0.0;

   fLastErrorGyroX : float := 0.0;
   fLastErrorGyroY : float := 0.0;
   fLastErrorGyroZ : float := 0.0;

   fDeltaTime : float := 0.05;
   fLastTime : float := 0.0;
   fCurrentTime : float := 0.0;

   fPitchPValue : float := 0.0;
   fPitchIValue : float := 0.0;
   fPitchDValue : float := 0.0;

   fRollPValue : float := 0.0;
   fRollIValue : float := 0.0;
   fRollDValue : float := 0.0;

   fYawPValue : float := 0.0;
   fYawIValue : float := 0.0;
   fYawDValue : float := 0.0;

   kp : float := 10.0;
   ki : float := 0.00;--1;--0.01;
   kd : float := 20.0;--5;--0.005;


   thruster : array (1..6) of float := (others => 0.0);

   type matris is array (1..6, 1..6) of float;
   xThrusterConfig : matris :=((0.866025, 0.5, 0.0, 0.0   , 0.0   , -0.28),--motor1
                               (0.0      , 1.0, 0.0, 0.0   , 0.0   , -0.22),--motor2
                               (0.866025 ,-0.5, 0.0, 0.0   , 0.0   ,  0.28),--motor3
                               (0.0      , 0.0, 1.0, 0.355 , 0.230 ,  0.0),--motor4
                               (0.0      , 0.0, 1.0,-0.355 , 0.230 ,  0.0),--motor5
                               (0.0      , 0.0, 1.0, 0.0   , 0.355 ,  0.0));--motor6


   fPosXPValue : float := 0.0;
   fPosXIValue : float := 0.0;
   fPosXDValue : float := 0.0;

   fPosYPValue : float := 0.0;
   fPosYIValue : float := 0.0;
   fPosYDValue : float := 0.0;

   fPosZPValue : float := 0.0;
   fPosZIValue : float := 0.0;
   fPosZDValue : float := 0.0;

   fLastAccX : float := 0.0;
   fLastAccY : float := 0.0;


end PID2;
