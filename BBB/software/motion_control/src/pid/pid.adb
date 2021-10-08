Package body PID is
   procedure Set_Desired_State(x, y, z, roll, pitch, yaw : float) is
   begin
      fDesiredYaw   := fStartYaw + yaw;
      fDesiredPitch := pitch;
      fDesiredRoll  := roll;

      fDesiredPosX  := x*cos(-fStartYaw*Pi/180.0) + y*sin(-fStartYaw*Pi/180.0);
      fDesiredPosY  := -x*sin(-fStartYaw*Pi/180.0) + y*cos(-fStartYaw*Pi/180.0);
      fDesiredPosZ  := z;

      if bDebugText then
         Ada.Text_IO.Put_Line("------Desired changed------");
         Ada.Text_IO.Put_Line("Roll: " & fDesiredRoll'Img & " Pitch: " & fDesiredPitch'Img & " Yaw: " & fDesiredYaw'Img);
         Ada.Text_IO.Put_Line("X: " & fDesiredPosX'Img & " Y: " & fDesiredPosY'Img & " Z: " & fDesiredPosZ'Img);
         Ada.Text_IO.Put_Line("---------------------------");
      end if;
   end Set_Desired_State;

   --Change state to coordinates as if current is all zero.
   procedure Set_Desired_Relative_State(x, y, z, roll, pitch, yaw : float) is
   begin

      if bDebugText then
         Ada.Text_IO.Put_Line("------Desired Relative changed------");
         Ada.Text_IO.Put_Line("Roll: " & roll'Img & " Pitch: " & pitch'Img & " Yaw: " & yaw'Img);
         Ada.Text_IO.Put_Line("X: " & x'Img & " Y: " & y'Img & " Z: " & z'Img);
         Ada.Text_IO.Put_Line("------------------------------------");
      end if;
      if yaw /= 0.0 then --Jonatans test för joystick fix --commented out by ludde 160816
	 FDesiredYaw   := FDesiredYaw + Yaw; --FCurrentYaw + Yaw;
      end if;

      --fDesiredPitch := fCurrentPitch + Pitch;
      --fDesiredRoll  := fCurrentRoll + Roll;

	--fDesiredYaw := fCurrentYaw; --ludde 160914
	--fDesiredRoll := fCurrentRoll; --ludde 160914

      --fDesiredPitch := 0.0; --commented out by ludde 160816
      --fDesiredRoll := 0.0; --commented out by ludde 160816


      if fDesiredYaw > 180.0 then
         fDesiredYaw := fDesiredYaw - 360.0;
      elsif fDesiredYaw < -180.0 then
         fDesiredYaw := fDesiredYaw + 360.0;
      end if;

      if fDesiredPitch > 180.0 then
         fDesiredPitch := fDesiredPitch - 360.0;
      elsif fDesiredPitch < -180.0 then
         fDesiredPitch := fDesiredPitch - 360.0;
      end if;

      if fDesiredRoll > 180.0 then
         fDesiredRoll := fDesiredRoll - 360.0;
      elsif fDesiredRoll < -180.0 then
         fDesiredRoll := fDesiredRoll + 360.0;
      end if;

      fDesiredPosX  := fCurrentPosX+x;--fCurrentPosX + x*cos(-fCurrentYaw*Pi/180.0) + y*sin(-fCurrentYaw*Pi/180.0); --ludde 160817
      fDesiredPosY  := fCurrentPosY+y;--fCurrentPosY - x*sin(-fCurrentYaw*Pi/180.0) + y*cos(-fCurrentYaw*Pi/180.0); --ludde 160817
      if Z /= 0.0 then --commented out by ludde 160816
            fDesiredPosZ  := fCurrentPosZ + z;
--  	 FDesiredPosZ := FCurrentPosZ; --ludde 160914
	--Ada.Text_IO.Put_Line("---------temp---------");
	--Ada.Text_IO.Put_Line("desired: " & PID.fDesiredPosZ'Img&" current: "&PID.fCurrentPosZ'img&" z: "&z'img);
	--Ada.Text_IO.Put_Line("----------------------");
      end if;




   end Set_Desired_Relative_State;





   procedure Go_To_Surface is
   begin
      fDesiredPosZ := surfacePosZ;
      fDesiredPosX := 0.0;
      fDesiredPosY := 0.0;
   end Go_To_Surface;

   procedure Desired_To_Local_Space is
      x : float := fDesiredPosX - fCurrentPosX;
      y : float := fDesiredPosY - fCurrentPosY;
   begin
      fLocalErrorPosX := x*cos(fCurrentYaw*Pi/180.0) + y*sin(fCurrentYaw*Pi/180.0);
      fLocalErrorPosY := -x*sin(fCurrentYaw*Pi/180.0) + y*cos(fCurrentYaw*Pi/180.0);
   end Desired_To_Local_Space;

   procedure Vel_Integration is
   begin
      fCurrentXVelocity := fCurrentXVelocity + (fCurrentAccX)*fDeltaTime;
      fCurrentYVelocity := fCurrentYVelocity + (fCurrentAccY)*fDeltaTime;

      fCurrentXVelocity := fCurrentXVelocity*1.0;--0.99;
      fCurrentYVelocity := fCurrentYVelocity*1.0;--0.99;
   end Vel_Integration;


   procedure Pos_Integration is
   begin
      fCurrentPosX := fCurrentPosX + fCurrentXVelocity*fDeltaTime;
      fCurrentPosY := fCurrentPosY + fCurrentYVelocity*fDeltaTime;
   end Pos_Integration;


   procedure Update_Thruster_Value(motorNumber : integer) is
   begin
      thruster(motorNumber) := 128.0 +
        ((fPosXPValue  * xPIDconfig(1,1) + fPosXIValue  * xPIDconfig(2,1)  +fPosXDValue  * xPIDconfig(3,1) )    *xThrusterConfig(motorNumber,1)) + --x axis
        ((fPosYPValue  * xPIDconfig(1,2) + fPosYIValue  * xPIDconfig(2,2)  +fPosYDValue  * xPIDconfig(3,2) )    *xThrusterConfig(motorNumber,2)) + --y axis
        ((fPosZPValue  * xPIDconfig(1,3) + fPosZIValue  * xPIDconfig(2,3)  +fPosZDValue  * xPIDconfig(3,3) )    *xThrusterConfig(motorNumber,3)) + --z axis
        ((fRollPValue  * xPIDconfig(1,4) + fRollIValue  * xPIDconfig(2,4)  +fRollDValue  * xPIDconfig(3,4) )    *xThrusterConfig(motorNumber,4)) + --x rotaion
        ((fPitchPValue * xPIDconfig(1,5) + fPitchIValue * xPIDconfig(2,5)  +fPitchDValue * xPIDconfig(3,5) )    *xThrusterConfig(motorNumber,5)) + --y rotaion
        ((fYawPValue   * xPIDconfig(1,6) + fYawIValue   * xPIDconfig(2,6)  +fYawDValue   * xPIDconfig(3,6) )    *xThrusterConfig(motorNumber,6));  --z rotaion

      if thruster(motorNumber) < 0.0 then
         thruster(motorNumber) := 0.0;
      elsif thruster(motorNumber) > 255.0 then
         thruster(motorNumber) := 255.0;
      end if;
   end Update_Thruster_Value;

   procedure Update_Errors is
   begin
      fErrorYaw   := fCurrentYaw - fDesiredYaw;

      if fErrorYaw > 180.0 then
         fErrorYaw := -360.0 + fErrorYaw;
      end if;

      if fErrorYaw < -180.0 then
         fErrorYaw := 360.0 + fErrorYaw;
      end if;

      if abs(fErrorYaw) < fZeroLimit then
         fErrorYaw := 0.0;
      end if;

      fErrorPitch := fCurrentPitch - fDesiredPitch;
      if abs(fErrorPitch) < fZeroLimit then
         fErrorPitch := 0.0;
      end if;

      fErrorRoll  := fCurrentRoll  - fDesiredRoll;
      if abs(fErrorRoll) < fZeroLimit then
         fErrorRoll := 0.0;
      end if;

      if bDebugText then
         Ada.Text_IO.Put_Line("------Desired position------");
         Ada.Text_IO.Put_Line("X: " & fDesiredPosX'Img & " Y: " & fDesiredPosY'Img & " Z: " & fDesiredPosZ'Img);
         Ada.Text_IO.Put_Line("----------------------------");
      end if;
      fErrorPosX  := fCurrentPosX - fDesiredPosX;--fLocalErrorPosX;
      fErrorPosY  := fCurrentPosY - fDesiredPosY;--fLocalErrorPosY;
      fErrorPosZ  := fCurrentPosZ - fDesiredPosZ;
      --fErrorPosZ  := -fErrorPosZ; --commented out by ludde 160816

   end Update_Errors;

   procedure Update_Last_Errors is
   begin
      --Update last errors
      fLastErrorYaw   := fErrorYaw;
      fLastErrorPitch := fErrorPitch;
      fLastErrorRoll  := fErrorRoll;

      fLastErrorPosX  := fErrorPosX;
      fLastErrorPosY  := fErrorPosY;
      fLastErrorPosZ  := fErrorPosZ;
   end Update_Last_Errors;

   procedure Update_PID_orientation is
   begin
      --P for all ORIENTATION
      fPitchPValue := fErrorPitch;
      fRollPValue  := fErrorRoll;
      fYawPValue   := fErrorYaw;

      --I for all ORIENTATION
      fPitchIValue := fPitchIValue  + fErrorPitch*fDeltaTime;
      fRollIValue  := fRollIValue   + fErrorRoll *fDeltaTime;
      fYawIValue   := fYawIValue    + fErrorYaw  *fDeltaTime;

      --D for all ORIENTATION
      fPitchDValue := (fErrorPitch-fLastErrorPitch)/fDeltaTime;
      fRollDValue  := (fErrorRoll-fLastErrorRoll)  /fDeltaTime;
      fYawDValue   := (fErrorYaw-fLastErrorYaw)    /fDeltaTime;
   end Update_PID_orientation;


   procedure Update_PID_position is
   begin

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

   end Update_PID_position;

   procedure Set_Derivatives_To_Zero is
   begin

      --D for all POSITIONS
      fPosXDValue  := 0.0;
      fPosYDValue  := 0.0;
      fPosZDValue  := 0.0;

      --D for all ORIENTATION
      fPitchDValue := 0.0;
      fRollDValue  := 0.0;
      fYawDValue   := 0.0;

   end Set_Derivatives_To_Zero;


   procedure Go_To_Desired_Position_And_Orientation is
      use Ada.Real_Time;
   begin
      tTimeStop := Ada.Real_Time.Clock;
      tTimeSpan := tTimeStop - tTimeStart;

      if bSimulation then
         fDeltaTime := fSimulationTime;
      else
         fDeltaTime := float(tTimeSpan / Ada.Real_Time.Microseconds(1))*0.000001;
      end if;

      --Desired_To_Local_Space;
      Update_Errors;
      Update_PID_position; --set pid error values
      Update_PID_orientation;

      if bFirstRunDerivativePart then
         Set_Derivatives_To_Zero;
         bFirstRunDerivativePart := False;
      end if;

      --Vel_Integration;
      --Pos_Integration;
      Update_Last_Errors;

	--ada.text_io.put_line("Update_Thruster_Value: fYawPValue: "&fYawPValue'img);
	--ada.text_io.put_line("Update_Thruster_Value: fYawDValue: "&fYawDValue'img);
      for i in 1..6 loop
         update_thruster_value(i);
      end loop;
      tTimeStart := tTimeStop;
   end Go_To_Desired_Position_And_Orientation;


      ----------
   -- Save --
   ----------

   procedure Save (PM : Pidmatris; File_Name : String) is
      File_Handle : File_Type;
   begin
      Create (File_Handle, Out_File, File_Name);
      Print (Pm, File_Handle);
      Close (File_Handle);
   end Save;

   ----------
   -- Load --
   ----------

   procedure Load (PM : out Pidmatris; File_Name : String) is
      File_Handle : File_Type;
      Str : String (1 .. 1000);
      Len : Natural;
   begin
      Open (File_Handle, In_File, File_Name);
      Get_Line (File_Handle, Str, Len);
      for I in Pm'Range (1) loop
	 for J in Pm'Range (2) loop
	    Get (File_Handle, Pm (I, J));
	 end loop;
	 Get_Line (File_Handle, Str, Len);
      end loop;
      Close (File_Handle);
   end Load;


   ----------
   -- Print --
   ----------

   procedure Print (PM : Pidmatris; File_Handle : File_Type := Standard_Output) is
      Pid_Str : String := "PID";
   begin
      Put_Line (File_Handle,"          x          y          z       roll      pitch        yaw");
      for I in Pm'Range (1) loop
	 for J in Pm'Range (2) loop
	    Put (File_Handle, Pm (I, J), 5, 5, 0);
	 end loop;
	 Put(File_Handle, "   " & Pid_Str(I));
	 New_Line(File_Handle);
      end loop;
      New_Line(File_Handle);
   end Print;

   ----------
   -- Save --
   ----------

   procedure Save (M : Matris; File_Name : String) is
      File_Handle : File_Type;
   begin
      Create (File_Handle, Out_File, File_Name);
      Print (M, File_Handle);
      Close (File_Handle);
   end Save;

   ----------
   -- Load --
   ----------

   procedure Load (M : out Matris; File_Name : String) is
      File_Handle : File_Type;
      Str : String (1 .. 1000);
      Len : Natural;
   begin
      Open (File_Handle, In_File, File_Name);
      Get_Line (File_Handle, Str, Len);
      for I in M'Range (1) loop
	 for J in M'Range (2) loop
	    Get (File_Handle, M (I, J));
	 end loop;
	 Get_Line (File_Handle, Str, Len);
      end loop;
      Close (File_Handle);
   end Load;


   ----------
   -- Print --
   ----------

   procedure Print (M : Matris; File_Handle : File_Type := Standard_Output) is
      Num_Str : String := "123456";
   begin
      Put_Line (File_Handle, "           x           y          z         roll       pitch         yaw");
      for I in M'Range (1) loop
	 for J in M'Range (2) loop
	    Put (File_Handle, M (I, J), 5, 6, 0);
	 end loop;
	 Put(File_Handle, "   motor" & Num_Str(I));
	 New_Line(File_Handle);
      end loop;
      New_Line (File_Handle);
   end Print;
end PID;
