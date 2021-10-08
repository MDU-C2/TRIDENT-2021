with Ada.Float_Text_IO;
with Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;

with PID;
with PID_Utils;
with Interfaces;

procedure motion_control_main is
   sender : string (1..3) := "nul";
   bSendWhat : boolean := true;
begin
   delay(0.5);

   PID_Utils.Send_Server_Message(ethId => 750,
                                 extended => false);

   PID_Utils.Send_Server_Message(ethId => 623,
                                 extended => false,
				 b => 50);

   Pid.Load (Pid.XPIDconfig, "pid_config.txt");
   Pid.Load (Pid.XThrusterConfig, "thruster_config.txt");

   loop
      --        PID.Set_Desired_State(1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
      --        PID.Set_Desired_Relative_State(1.0, 0.0, 0.0, 0.0, 0.0, 0.0);

      PID_Utils.Read_From_Server;

--        Ada.Text_Io.Put_Line("CARL: motion_control_main: calling update pid");
      PID_Utils.Update_PID_Data;

	--PID.fDesiredRoll:=PID.fCurrentRoll; --ludde 160914
	--PID.fDesiredPitch:=PID.fCurrentPitch; --ludde 160914
	--PID.fDesiredYaw:=PID.fCurrentYaw; --ludde 160914
	--PID.fDesiredPosZ:=PID.fCurrentPosZ; --ludde 160914

--  	PID.fCurrentPosZ:=0.0;

	--PID.fDesiredRoll:=0.0;
	--PID.fDesiredPitch:=0.0;

--	PID.thruster(1):=PID_Utils.relX;
--	PID.thruster(2):=-PID_Utils.relYaw;
--	PID.thruster(3):=PID_Utils.relX;
--	PID.thruster(4):=PID_Utils.relDepth;
--	PID.thruster(5):=PID_Utils.relDepth;
--	PID.thruster(6):=PID_Utils.relPitch;

--	for i in 1..6 loop
--		PID.thruster(i):=PID.thruster(i)+128.0;
--		if(PID.thruster(i)<0.0) then
--			Ada.text_IO.put_line("ERROR");
--			PID.thruster(i):=128.0;
--			--return; --probably a bad idea
--		elsif(PID.thruster(i)>255.0) then
--			Ada.text_IO.put_line("ERROR");
--			PID.thruster(i):=128.0;
--			--return; --probably a bad idea
--		end if;
--	end loop;

      --PID_Utils.Update_Desired_State;

      PID.Go_To_Desired_Position_And_Orientation;

      --PID_Utils.Send_Desired_To_User;

      --PID_Utils.Send_Motors_To_User;

      --PID_Utils.Send_P_Error;
      --PID_Utils.Send_Current_To_User;
      declare
         t : PID_Utils.byte_arr (1..6);

      begin

	if not pid_utils.bRunMode then
		pid.thruster:=(others=>128.0);
	end if;

	 for i in t'Range loop
	    t(i) := Interfaces.Unsigned_8(pid.thruster(i));
	 end loop;
         --if PID_Utils.counterForSend > 10 then
            PID_Utils.Send_Server_Message(ethId => 616,
                                          extended => false,
                                          b => t);
         --else
           -- PID_Utils.counterForSend := PID_Utils.counterForSend + 1;
         --end if;

      exception
         when e : others =>
            Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(e) & Ada.Exceptions.Exception_Message(e));
      end;

      --for i in PID.thruster'Range loop
         --Ada.Float_Text_IO.Put(float(PID.thruster (i)), AFT=>0, EXP=>0);
         --Ada.Text_IO.Put(" ");
      --end loop;

	Ada.Text_IO.New_Line;
	Ada.text_IO.put_line("motors");
	Ada.text_IO.put_line("1: "&PID.thruster(1)'img);
	Ada.text_IO.put_line("2: "&PID.thruster(2)'img);
	Ada.text_IO.put_line("3: "&PID.thruster(3)'img);
	Ada.text_IO.put_line("4: "&PID.thruster(4)'img);
	Ada.text_IO.put_line("5: "&PID.thruster(5)'img);
	Ada.text_IO.put_line("6: "&PID.thruster(6)'img);
--	Ada.text_IO.put_line("---------------------");
--	Ada.Text_IO.New_Line;
	Ada.text_IO.put_line("---------Current/Desired Pose---------"); --ludde 160817
	Ada.text_IO.put_line("x: "&PID.fCurrentPosX'Img&"/"&PID.fDesiredPosX'Img);
	Ada.text_IO.put_line("y: "&PID.fCurrentPosY'Img&"/"&PID.fDesiredPosY'Img);
	Ada.text_IO.put_line("z: "&PID.fCurrentPosZ'Img&"/"&PID.fDesiredPosZ'Img);
	Ada.text_IO.put_line("roll: "&PID.fCurrentRoll'Img&"/"&PID.fDesiredRoll'Img);
	Ada.text_IO.put_line("pitch: "&PID.fCurrentPitch'Img&"/"&PID.fDesiredPitch'Img);
	Ada.text_IO.put_line("yaw: "&PID.fCurrentYaw'Img&"/"&PID.fDesiredYaw'Img);
	Ada.text_IO.put_line("--------------------------------------"); --ludde 160817


      if PID.bDebugText then
         Ada.Text_IO.New_Line;
         Ada.text_IO.put_line("Current - yaw :" & PID.fCurrentYaw'Img & " pitch " & PID.fCurrentPitch'Img & " roll " & PID.fCurrentRoll'Img);
         Ada.text_IO.put_line("Desired - yaw :" & PID.fDesiredYaw'Img & " pitch " & PID.fDesiredPitch'Img & " roll " & PID.fDesiredRoll'Img);
         Ada.text_IO.put_line("Errors O - yaw :" & PID.fErrorYaw'Img & " pitch " & PID.fErrorPitch'Img & " roll " & PID.fErrorRoll'Img);
         Ada.text_IO.put_line("Errors P - X :" & PID.fErrorPosX'Img & " Y " & PID.fErrorPosY'Img & " Z " & PID.fErrorPosZ'Img);

         Ada.Text_IO.Put_Line("X: " & PID.fCurrentPosX'Img & " Y: " & PID.fCurrentPosY'Img & " Z: "  & PID.fCurrentPosZ'Img);
      end if;
      --PID_Utils.Log_Data;
   end loop;

end motion_control_main;
