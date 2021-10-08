Package body PID is



   procedure Trapezoid_Integration;
   procedure Rectangular_Integration;
   procedure Anti_Spike_Filter;
   procedure Update_Thruster_Value(motorNumber : integer) ;
   procedure Update_Errors;
   procedure Update_Last_Errors;
   procedure Update_PID_orientation;
   procedure Update_PID_position;


   procedure setDesiredState(x, y, z, roll, pitch, yaw : float) is
   begin
      desiredYaw   := yaw;
      desiredPitch := pitch;
      desiredRoll  := roll;

      desiredPosX  := x;
      desiredPosY  := y;
      desiredPosZ  := z;
   end setDesiredState;


   --Change state to coordinates as if current is all zero.
   procedure setDesiredRelativeState(x, y, z, roll, pitch, yaw : float) is
   begin
      desiredYaw   := currentYaw + yaw;
      desiredPitch := currentPitch + Pitch;
      desiredRoll  := currentRoll + Roll;

      if desiredYaw > 180.0 then
         desiredYaw := desiredYaw - 360.0;
      elsif desiredYaw < -180.0 then
         desiredYaw := desiredYaw + 360.0;
      end if;

      if desiredPitch > 180.0 then
         desiredPitch := desiredPitch - 360.0;
      elsif desiredPitch < -180.0 then
         desiredPitch := desiredPitch - 360.0;
      end if;

      if desiredRoll > 180.0 then
         desiredRoll := desiredRoll - 360.0;
      elsif desiredRoll < -180.0 then
         desiredRoll := desiredRoll + 360.0;
      end if;

      desiredPosX  := currentPosX + x;
      desiredPosY  := currentPosY + y;
      desiredPosZ  := currentPosZ + z;
   end setDesiredRelativeState;

   procedure setCurrentState(Yaw, Pitch, Roll, AccX, AccY, AccZ, GyroX, GyroY, GyroZ, Depth : float) is
   begin
      currentYaw := yaw;
      currentPitch := Pitch;
      currentRoll := roll;
      currentAccX := AccX;
      currentAccY := AccY;
      currentAccZ := AccZ;
      currentGyroX := GyroX;
      currentGyroY := GyroY;
      currentGyroZ := GyroZ;
      currentPosZ := Depth;
      end setCurrentState;

   procedure Trapezoid_Integration is
   begin--                                                 ?
      currentXVelocity := currentXVelocity + deltaTime*((currentAccX+lastAccX)/2.0);
      currentYVelocity := currentYVelocity + deltaTime*((currentAccY+lastAccY)/2.0);
   end Trapezoid_Integration;


   procedure Rectangular_Integration is
   begin
      currentXVelocity := currentXVelocity + (currentAccX)*deltaTime;
      currentYVelocity := currentYVelocity + (currentAccY)*deltaTime;
   end Rectangular_Integration;


   procedure Anti_Spike_Filter is
      spikeLimit : float := 0.05; --find correct value
   begin
      if abs(currentAccX) < spikeLimit then
         currentAccX := 0.0;
      end if;

      if abs(currentAccY) < spikeLimit then
         currentAccY := 0.0;
      end if;

      if currentAccX /= 0.0 and lastAccX = 0.0 then
         lastAccX := currentAccX;
         currentAccX := 0.0;
      else
         lastAccX := currentAccX;
      end if;

      if currentAccY /= 0.0 and lastAccY = 0.0 then
         lastAccY := currentAccY;
         currentAccY := 0.0;
      else
         lastAccY := currentAccY;
      end if;
      Rectangular_Integration;
      --Trapezoid_Integration;
   end Anti_Spike_Filter;

   procedure Update_Thruster_Value(motorNumber : integer) is
   begin
      thruster(motorNumber) := 128.0 +
        ((posX_P_Value  * xPIDconfig(1,1) + posX_I_Value  * xPIDconfig(2,1)  +posX_D_Value  * xPIDconfig(3,1) )    *xThrusterConfig(motorNumber,1)) + --x axis
        ((posY_P_Value  * xPIDconfig(1,2) + posY_I_Value  * xPIDconfig(2,2)  +posY_D_Value  * xPIDconfig(3,2) )    *xThrusterConfig(motorNumber,2)) + --y axis
        ((posZ_P_Value  * xPIDconfig(1,3) + posZ_I_Value  * xPIDconfig(2,3)  +posZ_D_Value  * xPIDconfig(3,3) )    *xThrusterConfig(motorNumber,3)) + --z axis
        ((Roll_P_Value  * xPIDconfig(1,4) + Roll_I_Value  * xPIDconfig(2,4)  +Roll_D_Value  * xPIDconfig(3,4) )    *xThrusterConfig(motorNumber,4)) + --x rotaion
        ((Pitch_P_Value * xPIDconfig(1,5) + Pitch_I_Value * xPIDconfig(2,5)  +Pitch_D_Value * xPIDconfig(3,5) )    *xThrusterConfig(motorNumber,5)) + --y rotaion
        ((Yaw_P_Value   * xPIDconfig(1,6) + Yaw_I_Value   * xPIDconfig(2,6)  +Yaw_D_Value   * xPIDconfig(3,6) )    *xThrusterConfig(motorNumber,6));  --z rotaion

      if thruster(motorNumber) < 0.0 then
         thruster(motorNumber) := 0.0;
      elsif thruster(motorNumber) > 255.0 then
         thruster(motorNumber) := 255.0;
      end if;

   end Update_Thruster_Value;


   procedure Update_Errors is
   begin

      errorYaw   := currentYaw - desiredYaw;
      if abs(errorYaw) < zeroLimit then
         errorYaw := 0.0;
      end if;

      errorPitch := currentPitch - desiredPitch;
      if abs(errorPitch) < zeroLimit then
         errorPitch := 0.0;
      end if;

      errorRoll  := currentRoll  - desiredRoll;
      if abs(errorRoll) < zeroLimit then
         errorRoll := 0.0;
      end if;

      errorPosX  := currentPosX - desiredPosX;
      errorPosY  := currentPosY - desiredPosY;
      errorPosZ  := currentPosZ - desiredPosZ;

   end Update_Errors;



   procedure Update_Last_Errors is

   begin

      --Update last errors
      lastErrorYaw   := errorYaw;
      lastErrorPitch := errorPitch;
      lastErrorRoll  := errorRoll;

      lastErrorPosX  := errorPosX;
      lastErrorPosY  := errorPosY;
      lastErrorPosZ  := errorPosZ;
   end Update_Last_Errors;

   procedure Update_PID_orientation is
   begin
      --P for all ORIENTATION
      Pitch_P_Value := errorPitch;
      roll_P_Value  := errorRoll;
      yaw_P_Value   := errorYaw;

      --I for all ORIENTATION
      Pitch_I_Value := pitch_I_Value  + errorPitch*deltaTime;
      roll_I_Value  := roll_I_Value   + errorRoll *deltaTime;
      yaw_I_Value   := yaw_I_Value    + erroryaw  *deltaTime;

      --D for all ORIENTATION
      Pitch_D_Value := (errorPitch-lastErrorPitch)/deltaTime;
      roll_D_Value  := (errorRoll-lastErrorRoll)  /deltaTime;
      yaw_D_Value   := (errorYaw-lastErrorYaw)    /deltaTime;
   end Update_PID_orientation;


   procedure Update_PID_position is

   begin
      --P for all POSITIONS
      posX_P_Value  :=  errorPosX;
      posY_P_Value  :=  errorPosY;
      posZ_P_Value  :=  errorPosZ;

      --I for all POSITIONS
      posX_I_Value  := posX_I_Value + errorPosX*deltaTime;
      posY_I_Value  := posY_I_Value + errorPosY*deltaTime;
      posZ_I_Value  := posZ_I_Value + errorPosZ*deltaTime;
      --D for all POSITIONS

      posX_D_Value  := (errorPosX-lastErrorPosX)/deltaTime;
      posY_D_Value  := (errorPosY-lastErrorPosY)/deltaTime;
      posZ_D_Value  := (errorPosZ-lastErrorPosZ)/deltaTime;

   end Update_PID_position;


   procedure Go_To_Desired_Position_And_Orientation is
   begin
      --add positionx/y integration if using position.
      Update_Errors;
      Update_PID_position;
      Update_PID_orientation;
      Update_Last_Errors;
      for i in 1..6 loop
         update_thruster_value(i);
      end loop;

   end Go_To_Desired_Position_And_Orientation;




end PID;
