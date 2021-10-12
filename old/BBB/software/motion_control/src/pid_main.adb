with Ada.Float_Text_IO;
with Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;

with PID;
with PID_Utils;
with Interfaces;

procedure pid_main is
   --     bb : PID_Utils.byte_arr := (2);
   sender : string (1..3) := "nul";

begin
   PID.setDesiredState(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

   --     PID_Utils.connectToServer("192.168.1.1",315);
   --     PID_Utils.connectToServer("127.0.0.1",314);
   --     PID_Utils.connectToServer("192.168.7.1",314);
   delay(0.5);

   PID_Utils.sendServerMessage(ethId => 0,
                               canId => 750,
                               extended => false);

   PID_Utils.sendServerMessage(ethId => 0,
                               canId => 623,
                               extended => false,
                               b => 50);

   loop
      PID_Utils.readFromServer;

      PID_Utils.updatePIDData;
      --PID_Utils.Update_Desired_State;
      --PID.deltaTime := 0.01; --FIX!
      PID.Go_To_Desired_Position_And_Orientation;

      declare
         t : PID_Utils.byte_arr (1..6);

      begin

         for i in t'Range loop
--              Ada.Text_IO.Put_Line("Tiiiio: " & pid.thruster(i)'img);
            t(i) := Interfaces.Unsigned_8(pid.thruster(i));
         end loop;

      PID_Utils.sendServerMessage(ethId => 0,
                                  canId => 616,
                                  extended => false,
                                  b => t);
      exception
         when e : others =>
            Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(e) & Ada.Exceptions.Exception_Message(e));
      end;

      for i in PID.thruster'Range loop
         Ada.Float_Text_IO.Put(float(PID.thruster (i)), AFT=>0, EXP=>0);
         Ada.Text_IO.Put(" ");
      end loop;

      Ada.Text_IO.New_Line;
      Ada.text_IO.put_line("Current - yaw :" & PID.currentYaw'Img & " pitch " & PID.currentPitch'Img & " roll " & PID.currentRoll'Img);
      Ada.text_IO.put_line("Desired - yaw :" & PID.desiredYaw'Img & " pitch " & PID.desiredPitch'Img & " roll " & PID.desiredRoll'Img);
      Ada.text_IO.put_line("Errors O - yaw :" & PID.errorYaw'Img & " pitch " & PID.errorPitch'Img & " roll " & PID.errorRoll'Img);
      Ada.text_IO.put_line("Errors P - X :" & PID.errorPosX'Img & " Y " & PID.errorPosY'Img & " Z " & PID.errorPosZ'Img);

      Ada.Text_IO.Put_Line("X: " & PID.currentPosX'Img & " Y: " & PID.currentPosY'Img & " Z: "  & PID.currentPosZ'Img);

      --PID_Utils.Log_Data;
   end loop;

end pid_main;
