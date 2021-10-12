with Ada.Float_Text_IO; use Ada.Float_Text_IO;
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Numerics; use Ada.Numerics;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;
with Ada.Real_Time;

package PID is
   procedure Go_To_Desired_Position_And_Orientation;
   --Dispatcher that gets things done by calling other awesome functions

   procedure Set_Desired_State(x, y, z, roll, pitch, yaw : float);
   --Sets a new desired state relative to starting state

   procedure Set_Desired_Relative_State(x, y, z, roll, pitch, yaw : float);
   --Sets a new desired state relative to current state

   procedure Go_To_Surface;

   procedure Desired_To_Local_Space;
   --Converts global space coordinates to local space coordinates

   procedure Vel_Integration;
   --Integrates the acceleration to velocity

   procedure Pos_Integration;
   --Integrates the velocity to position

   procedure Update_Thruster_Value(motorNumber : integer);
   --Calculates the thruster values of each motor based on the Proportional, Derivative and Integration parts
   --that is set in the PID matrix and also based on the thruster configuration matrix

   procedure Update_Errors;
   --Calculates the error that the entire PID system will base it's calculations on

   procedure Update_Last_Errors;
   --Sets the last error to be able to calculate the derivative parts.
   --The derivative parts should be based on the gyro scope later for the rotation part.

   procedure Update_PID_orientation;
   --Sets the Proportional, Integration and Derivative parts for the orientation

   procedure Update_PID_position;
   --Sets the Proportional, Integration and Derivative parts for the position

   procedure Set_Derivatives_To_Zero;
   tTimeStart : Ada.Real_Time.Time := Ada.Real_Time.Clock;
   tTimeSpan : Ada.Real_Time.Time_Span := Ada.Real_Time.Time_Span_Zero;
   tTimeStop : Ada.Real_Time.Time;

   fCurrentYaw : float := 0.0;
   fCurrentPitch : float := 0.0;
   fCurrentRoll : float := 0.0;

   fCurrentAccX : float := 0.0;
   fCurrentAccY : float := 0.0;
   fCurrentAccZ : float := 0.0;

   surfacePosZ : float := 0.0;

   fAccXOffset : float := 0.0;
   fAccYOffset : float := 0.0;

   fCurrentXVelocity : float := 0.0;
   fCurrentYVelocity : float := 0.0;

   fCurrentGyroX : float := 0.0;
   fCurrentGyroY : float := 0.0;
   fCurrentGyroZ : float := 0.0;

   fDesiredYaw : float := 0.0;
   fDesiredPitch : float := 0.0;
   fDesiredRoll : float := 0.0;

   --  desiredGyroX : float := 0.0;
   --  desiredGyroY : float := 0.0;
   --  desiredGyroZ : float := 0.0;
   --
   --  desiredAccX : float := 0.0;
   --  desiredAccY : float := 0.0;
   --  desiredAccZ : float := 0.0;

   fLastDesiredPosX : float := 0.0;
   fLastDesiredPosY : float := 0.0;
   fLastDesiredPosZ : float := 0.0;
   fLastDesiredYaw : float := 0.0;
   fLastDesiredRoll : float := 0.0;
   fLastDesiredPitch : float := 0.0;

   fDesiredPosX : float := 0.0;
   fDesiredPosY : float := 0.0;
   fDesiredPosZ : float := 0.0;

   fLocalErrorPosX : float := 0.0;
   fLocalErrorPosY : float := 0.0;

   fCurrentPosX : float := 0.0;
   fCurrentPosY : float := 0.0;
   fCurrentPosZ : float := 0.0;

   fErrorPosX : float := 0.0;
   fErrorPosY : float := 0.0;
   fErrorPosZ : float := 0.0;

   fErrorYaw : float   := 0.0;
   fErrorPitch : float := 0.0;
   fErrorRoll : float  := 0.0;

   fErrorAccX : float := 0.0;
   fErrorAccY : float := 0.0;
   fErrorAccZ : float := 0.0;

   fErrorGyroX : float := 0.0;
   fErrorGyroY : float := 0.0;
   fErrorGyroZ : float := 0.0;

   fLastErrorYaw : float   := 0.0;
   fLastErrorPitch : float := 0.0;
   fLastErrorRoll : float  := 0.0;

   fLastErrorAccX : float := 0.0;
   fLastErrorAccY : float := 0.0;
   fLastErrorAccZ : float := 0.0;

   fLastErrorPosX : float := 0.0;
   fLastErrorPosY : float := 0.0;
   fLastErrorPosZ : float := 0.0;

   fLastErrorGyroX : float := 0.0;
   fLastErrorGyroY : float := 0.0;
   fLastErrorGyroZ : float := 0.0;

   fDeltaTime   : float := 0.05;
   fLastTime    : float := 0.0;
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

--     kp_position : float := 0.0;
--     ki_position : float := 0.0;--1;--0.01;
--     kd_position : float := 0.0;--5;--0.005;
--
--     kp_orientation : float := 0.0;
--     ki_orientation : float := 0.0;--1;--0.01;
--     kd_orientation : float := 0.0;--5;--0.005;

   bFirstRun : Boolean := True;
   bFirstRunDerivativePart : Boolean := True;

   fZeroLimit : float := 0.01;

   fStartYaw : float := 0.0;
   fStartPosZ : float := 0.0;

   thruster : array (1..6) of float := (others => 0.0);

   type matris is array (1..6, 1..6) of float;
   type pidmatris is array (1..3, 1..6) of float;
                              --x     y     z    roll   pitch    yaw
--     xPIDconfig : pidmatris := ((5.0, 5.0, 10.0, 4.0, 4.0, 4.0),--P
--                                (0.0, 0.0, 0.0, 0.0, 0.0, 0.0),--I
--                                (5.0, 5.0, 2.0, 0.5, 0.5, 2.0));--D

--     xPIDconfig : pidmatris := ((2.0, 2.0, 10.0, 0.1, 0.5, 0.5),--P
--                                (0.0, 0.0, 0.0, 0.0, 0.0, 0.0),--I
--  			      (0.5, 0.5, 2.0, 0.1, 0.5, 0.1)); --D

   XPIDconfig : Pidmatris := ((2.0, 2.0, 5.0, 0.1, 0.5, 1.0), --P
			      (0.0, 0.0, 0.0, 0.0, 0.0, 0.0), --I
			      (0.5, 0.5, 2.0, 0.1, 0.5, 0.1)); --D

   --                           x           y    z  roll   pitch     yaw
   xThrusterConfig : matris :=((0.866025, 0.5, 0.0, 0.0   , 0.0   , 0.28),--motor1
                               (0.0      , 1.0, 0.0, 0.0   , 0.0   , 0.22),--motor2
                               (0.866025 ,-0.5, 0.0, 0.0   , 0.0   ,  -0.28),--motor3
                               (0.0      , 0.0, 1.0,-0.355 , -0.230 ,  0.0),--motor4
                               (0.0      , 0.0, 1.0,0.355 , -0.230 ,  0.0),--motor5
                               (0.0      , 0.0, 1.0, 0.0   , 0.455 ,  0.0));--motor6

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

   --Set bSimulation TRUE if using the simulator to get a synchronous time step
   --hence the bSimulation time is the same in the simulator.
   bSimulation : boolean := false;
   fSimulationTime : float := 0.01;
   bDebugText : boolean := false; --if true then printing debug text
   bGetFilteredPosition : boolean := false;


   procedure Save (PM : Pidmatris; File_Name : String);
   procedure Load (PM : out Pidmatris; File_Name : String);
   procedure Print (PM : Pidmatris; File_Handle : File_Type := Standard_Output);
   procedure Save (M : Matris; File_Name : String);
   procedure Load (M : out Matris; File_Name : String);
   procedure Print (M : Matris; File_Handle : File_Type := Standard_Output);

end PID;
