Package body PID2 is

bFirstRun : Boolean := true;

   procedure runThis is




      procedure Trapezoid_Integration is
      begin--                                                 ?
         fCurrentXVelocity := fCurrentXVelocity + fDeltaTime*( (fCurrentAccX+fLastAccX)/2.0);
         fCurrentYVelocity := fCurrentYVelocity + fDeltaTime*((fCurrentAccY+fLastAccY)/2.0);
      end Trapezoid_Integration;


      procedure Rectangular_Integration is
      begin
         fCurrentXVelocity := fCurrentXVelocity + (fCurrentAccX)*fDeltaTime;
         fCurrentYVelocity := fCurrentYVelocity + (fCurrentAccY)*fDeltaTime;
      end Rectangular_Integration;


      procedure Anti_Spike_Filter is
      begin
         if abs(fCurrentAccX) < 0.05 then --find correct value
            fCurrentAccX := 0.0;
         end if;

         if abs(fCurrentAccY) < 0.05 then
            fCurrentAccY := 0.0;
         end if;

         if fCurrentAccX /= 0.0 and fLastAccX = 0.0 then
            fLastAccX := fCurrentAccX;
            fCurrentAccX := 0.0;
         else
            fLastAccX := fCurrentAccX;
         end if;

         if fCurrentAccY /= 0.0 and fLastAccY = 0.0 then
            fLastAccY := fCurrentAccY;
            fCurrentAccY := 0.0;
         else
            fLastAccY := fCurrentAccY;
         end if;
         Rectangular_Integration;
         --Trapezoid_Integration;
      end Anti_Spike_Filter;

      procedure Update_Thruster_Value(motorNumber : integer) is
      begin
       thruster(motorNumber) := 128.0 +
           ((fPosXPValue*kp+fPosXIValue*ki+fPosXDValue*kD)    *xThrusterConfig(motorNumber,1)) + --x axis
           ((fPosYPValue*kp+fPosYIValue*ki+fPosYDValue*kD)    *xThrusterConfig(motorNumber,2)) + --y axis
           ((fPosZPValue*kp+fPosZIValue*ki+fPosZDValue*kD)    *xThrusterConfig(motorNumber,3)) + --z axis
           ((fRollPValue*kp+fRollIValue*ki+fRollDValue*kD)    *xThrusterConfig(motorNumber,4)) + --x rotaion
           ((fPitchPValue*kp+fPitchIValue*ki+fPitchDValue*kD) *xThrusterConfig(motorNumber,5)) + --y rotaion
           ((fYawPValue*kp+fYawIValue*ki+fYawDValue*kD)       *xThrusterConfig(motorNumber,6));  --z rotaion
      end Update_Thruster_Value;






            begin

            --read sensor
            --fDeltaTime := fCurrentTime-fLastTime;
            --fDeltaTime := 0.05;

            fErrorYaw   := fCurrentYaw   - fDesiredYaw;
            if abs(fErrorYaw) < 0.01 then
            fErrorYaw := 0.0;
            end if;

            fErrorPitch := fCurrentPitch - fDesiredPitch;
            if abs(fErrorPitch) < 0.01 then
            fErrorPitch := 0.0;
            end if;

            fErrorRoll  := fCurrentRoll  - fDesiredRoll;
            if abs(fErrorRoll) < 0.01 then
            fErrorRoll := 0.0;
            end if;


            --           fErrorAccX  := fCurrentAccX - desiredAccX;
            --           fErrorAccY  := fCurrentAccY - desiredAccY;
            --           fErrorAccZ  := fCurrentAccZ - desiredAccZ;
            --
            --           fErrorGyroX := fCurrentGyroX - desiredGyroX;
            --           fErrorGyroY := fCurrentGyroY - desiredGyroY;
            --           fErrorGyroZ := fCurrentGyroZ - desiredGyroZ;

            --Trapezoid_Integration;
            Rectangular_Integration;
            --Anti_Spike_Filter;

            fCurrentPosX := fCurrentPosX + fCurrentXVelocity*fDeltaTime;
            fCurrentPosY := fCurrentPosY + fCurrentYVelocity*fDeltaTime;

            fErrorPosX  :=  fCurrentPosX - fDesiredPosX;
            fErrorPosY  := fCurrentPosY - fDesiredPosY;
            fErrorPosZ  := fCurrentPosZ - fDesiredPosZ;

      Ada.Text_IO.Put_Line("Yaw Error." & fErrorYaw'Img);

            --P for all ANLGES
            fPitchPValue := fErrorPitch;
            fRollPValue  := fErrorRoll;
            fYawPValue   := fErrorYaw;

            --I for all ANLGES
            fPitchIValue := fPitchIValue  + fErrorPitch*fDeltaTime;
            fRollIValue  := fRollIValue   + fErrorRoll*fDeltaTime;
            fYawIValue   := fYawIValue    + fErrorYaw*fDeltaTime;

            --D for all ANLGES
            fPitchDValue := (fErrorPitch-fLastErrorPitch)/fDeltaTime;
            fRollDValue  := (fErrorRoll-fLastErrorRoll)/fDeltaTime;
      fYawDValue   := (fErrorYaw-fLastErrorYaw)/fDeltaTime;


            fLastErrorYaw   := fErrorYaw;
            fLastErrorPitch := fErrorPitch;
            fLastErrorRoll  := fErrorRoll;

            --P for all POSITIONS
            fPosXPValue  :=  fErrorPosX;
            fPosYPValue  :=  fErrorPosY;
            fPosZPValue  :=  fErrorPosZ;

            --I for all POSITIONS
            fPosXIValue  := fPosXIValue + fErrorPosX*fDeltaTime;
            fPosYIValue  := fPosYIValue + fErrorPosY*fDeltaTime;
            fPosZIValue  := fPosZIValue + fErrorPosZ*fDeltaTime;
            --D for all POSITIONS

            fPosXDValue  := (fErrorPosX-fLastErrorPosX)/fDeltaTime;
            fPosYDValue  := (fErrorPosY-fLastErrorPosY)/fDeltaTime;
            fPosZDValue  := (fErrorPosZ-fLastErrorPosZ)/fDeltaTime;
            Ada.Text_IO.Put_Line("hahahaha: " & fPosZDValue'Img);
            fLastErrorYaw   := fErrorYaw;
            fLastErrorPitch := fErrorPitch;
            fLastErrorRoll  := fErrorRoll;

            fLastErrorPosX  := fErrorPosX;
            fLastErrorPosY  := fErrorPosY;
            fLastErrorPosZ  := fErrorPosZ;

      if bFirstRun then
         fPosXDValue := 0.0;
         fPosYDValue := 0.0;
         fPosZDValue := 0.0;

         fRollDValue := 0.0;
         fPitchDValue := 0.0;
         fYawDValue := 0.0;

         bFirstRun := false;
      end if;

            for i in 1..6 loop
            update_thruster_value(i);
            end loop;

            end runThis;




            end PID2;
