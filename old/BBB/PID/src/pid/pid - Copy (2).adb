Package body PID2 is

firstRun : Boolean := true;

   procedure runThis is




      procedure Trapezoid_Integration is
      begin--                                                 ?
         currentXVelocity := currentXVelocity + deltaTime*( (currentAccX+lastAccX)/2.0);
         currentYVelocity := currentYVelocity + deltaTime*((currentAccY+lastAccY)/2.0);
      end Trapezoid_Integration;


      procedure Rectangular_Integration is
      begin
         currentXVelocity := currentXVelocity + (currentAccX)*deltaTime;
         currentYVelocity := currentYVelocity + (currentAccY)*deltaTime;
      end Rectangular_Integration;


      procedure Anti_Spike_Filter is
      begin
         if abs(currentAccX) < 0.05 then --find correct value
            currentAccX := 0.0;
         end if;

         if abs(currentAccY) < 0.05 then
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
           ((posX_P_Value*kp+posX_I_Value*ki+posX_D_Value*kD)    *xThrusterConfig(motorNumber,1)) + --x axis
           ((posY_P_Value*kp+posY_I_Value*ki+posY_D_Value*kD)    *xThrusterConfig(motorNumber,2)) + --y axis
           ((posZ_P_Value*kp+posZ_I_Value*ki+posZ_D_Value*kD)    *xThrusterConfig(motorNumber,3)) + --z axis
           ((Roll_P_Value*kp+Roll_I_Value*ki+Roll_D_Value*kD)    *xThrusterConfig(motorNumber,4)) + --x rotaion
           ((Pitch_P_Value*kp+Pitch_I_Value*ki+Pitch_D_Value*kD) *xThrusterConfig(motorNumber,5)) + --y rotaion
           ((Yaw_P_Value*kp+Yaw_I_Value*ki+Yaw_D_Value*kD)       *xThrusterConfig(motorNumber,6));  --z rotaion
      end Update_Thruster_Value;






            begin

            --read sensor
            --deltaTime := currentTime-LastTime;
            --deltaTime := 0.05;

            errorYaw   := currentYaw   - desiredYaw;
            if abs(errorYaw) < 0.01 then
            errorYaw := 0.0;
            end if;

            errorPitch := currentPitch - desiredPitch;
            if abs(errorPitch) < 0.01 then
            errorPitch := 0.0;
            end if;

            errorRoll  := currentRoll  - desiredRoll;
            if abs(errorRoll) < 0.01 then
            errorRoll := 0.0;
            end if;


            --           errorAccX  := currentAccX - desiredAccX;
            --           errorAccY  := currentAccY - desiredAccY;
            --           errorAccZ  := currentAccZ - desiredAccZ;
            --
            --           errorGyroX := currentGyroX - desiredGyroX;
            --           errorGyroY := currentGyroY - desiredGyroY;
            --           errorGyroZ := currentGyroZ - desiredGyroZ;

            --Trapezoid_Integration;
            Rectangular_Integration;
            --Anti_Spike_Filter;

            currentPosX := currentPosX + currentXVelocity*deltaTime;
            currentPosY := currentPosY + currentYVelocity*deltaTime;

            errorPosX  :=  currentPosX - desiredPosX;
            errorPosY  := currentPosY - desiredPosY;
            errorPosZ  := currentPosZ - desiredPosZ;

      Ada.Text_IO.Put_Line("Yaw Error." & errorYaw'Img);

            --P for all ANLGES
            Pitch_P_Value := errorPitch;
            roll_P_Value  := errorRoll;
            yaw_P_Value   := errorYaw;

            --I for all ANLGES
            Pitch_I_Value := pitch_I_Value  + errorPitch*deltaTime;
            roll_I_Value  := roll_I_Value   + errorRoll*deltaTime;
            yaw_I_Value   := yaw_I_Value    + erroryaw*deltaTime;

            --D for all ANLGES
            Pitch_D_Value := (errorPitch-lastErrorPitch)/deltaTime;
            roll_D_Value  := (errorRoll-lastErrorRoll)/deltaTime;
      yaw_D_Value   := (errorYaw-lastErrorYaw)/deltaTime;


            lastErrorYaw   := errorYaw;
            lastErrorPitch := errorPitch;
            lastErrorRoll  := errorRoll;

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
            Ada.Text_IO.Put_Line("hahahaha: " & posZ_D_Value'Img);
            lastErrorYaw   := errorYaw;
            lastErrorPitch := errorPitch;
            lastErrorRoll  := errorRoll;

            lastErrorPosX  := errorPosX;
            lastErrorPosY  := errorPosY;
            lastErrorPosZ  := errorPosZ;

      if firstRun then
         posX_D_Value := 0.0;
         posY_D_Value := 0.0;
         posZ_D_Value := 0.0;

         roll_D_Value := 0.0;
         pitch_D_Value := 0.0;
         yaw_D_Value := 0.0;

         firstRun := false;
      end if;

            for i in 1..6 loop
            update_thruster_value(i);
            end loop;

            end runThis;




            end PID2;
