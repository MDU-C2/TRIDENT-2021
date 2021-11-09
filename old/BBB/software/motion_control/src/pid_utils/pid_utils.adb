package body PID_Utils is
   procedure Update_Desired_State is
      fileName : String := "json/pid_desired.json";
      file : Ada.Text_IO.File_Type;
      raw_jsonObj : GNATCOLL.JSON.JSON_Value;

      d : pidDesired;
   begin
      Ada.Text_IO.Open(File => file,
                       Mode => Ada.Text_IO.In_File,
                       Name => fileName);

      while not Ada.Text_IO.End_Of_Line(file) loop
         declare
            line : String := Ada.Text_IO.Get_Line(file);
         begin
            raw_jsonObj := GNATCOLL.JSON.Read(line, "json.errors");

            d.x := Float'Value(raw_jsonObj.Get("x"));
            d.y := Float'Value(raw_jsonObj.Get("y"));
            d.z := Float'Value(raw_jsonObj.Get("z"));
            d.roll := Float'Value(raw_jsonObj.Get("roll"));
            d.pitch := Float'Value(raw_jsonObj.Get("pitch"));
            d.yaw := Float'Value(raw_jsonObj.Get("yaw"));
            Filter_Desired_Yaw(d.yaw);
         end;
      end loop;

      Ada.Text_IO.Close(file);

      PID.Set_Desired_State(d.x,d.y,d.z,d.roll,d.pitch,d.yaw);
   end Update_Desired_State;

--     function Update_Scalings return pidArray is
--        fileName : String := "../json/pid_data.json";
--        file : Ada.Text_IO.File_Type;
--        raw_jsonObj : GNATCOLL.JSON.JSON_Value;
--        iterator_jsonObj : GNATCOLL.JSON.JSON_Value;
--
--        arr : pidArray (1..6);
--
--     begin
--        Ada.Text_IO.Open(File => file,
--                         Mode => Ada.Text_IO.In_File,
--                         Name => fileName);
--
--        while not Ada.Text_IO.End_Of_Line(file) loop
--           declare
--              line : String := Ada.Text_IO.Get_Line(file);
--           begin
--              raw_jsonObj := GNATCOLL.JSON.Read(line, "json.errors");
--
--              arr(1).P := Float'Value(raw_jsonObj.Get("pxp"));
--              arr(1).I := Float'Value(raw_jsonObj.Get("pxi"));
--              arr(1).D := Float'Value(raw_jsonObj.Get("pxd"));
--              arr(2).P := Float'Value(raw_jsonObj.Get("pyp"));
--              arr(2).I := Float'Value(raw_jsonObj.Get("pyi"));
--              arr(2).D := Float'Value(raw_jsonObj.Get("pyd"));
--              arr(3).P := Float'Value(raw_jsonObj.Get("pzp"));
--              arr(3).I := Float'Value(raw_jsonObj.Get("pzi"));
--              arr(3).D := Float'Value(raw_jsonObj.Get("pzd"));
--              arr(4).P := Float'Value(raw_jsonObj.Get("oxp"));
--              arr(4).I := Float'Value(raw_jsonObj.Get("oxi"));
--              arr(4).D := Float'Value(raw_jsonObj.Get("oxd"));
--              arr(5).P := Float'Value(raw_jsonObj.Get("oyp"));
--              arr(5).I := Float'Value(raw_jsonObj.Get("oyi"));
--              arr(5).D := Float'Value(raw_jsonObj.Get("oyd"));
--              arr(6).P := Float'Value(raw_jsonObj.Get("ozp"));
--              arr(6).I := Float'Value(raw_jsonObj.Get("ozi"));
--              arr(6).D := Float'Value(raw_jsonObj.Get("ozd"));
--
--           end;
--        end loop;
--
--
--        Ada.Text_IO.Close(file);
--
--        return arr;
--     end Update_Scalings;

   procedure Send_Server_Message (ethId : Integer; extended : Boolean;  b : byte_arr) is
      thrusterMsgToSend : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      success : Boolean := False;
      c : Integer := 0;
   begin
      thrusterMsgToSend.Set_Field("sender","pid");
      thrusterMsgToSend.Set_Field("target","can");
      thrusterMsgToSend.Set_Field("ethid",ethId);
      thrusterMsgToSend.Set_Field("len",b'Length);
      thrusterMsgToSend.Set_Field("extended",extended);
      thrusterMsgToSend.Set_Field("unique",counter);
      for i in b'range loop
         thrusterMsgToSend.Set_Field(("b" & Character'val(Character'pos('0') + i)) ,integer(b(i)));
      end loop;

      tcp_client.Send(thrusterMsgToSend, success);

      counter := counter + 1;
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end Send_Server_Message;

    procedure Send_Server_Message (ethId : Integer; extended : Boolean;  b : Interfaces.Unsigned_8) is
      thrusterMsgToSend : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      success : Boolean := False;
   begin
      thrusterMsgToSend.Set_Field("sender","pid");
      thrusterMsgToSend.Set_Field("target","can");
      thrusterMsgToSend.Set_Field("ethid",ethId);
      thrusterMsgToSend.Set_Field("len", 1);
      thrusterMsgToSend.Set_Field("extended",extended);
      thrusterMsgToSend.Set_Field("unique",counter);

      thrusterMsgToSend.Set_Field("b1" ,integer(b));

      tcp_client.Send(thrusterMsgToSend, success);

      counter := counter + 1;
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end Send_Server_Message;


   procedure Send_Server_Message (ethId : Integer; extended : Boolean) is
      thrusterMsgToSend : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      --space_filler : String (1..256) := (others => ' ');
      success : Boolean := False;
   begin
      thrusterMsgToSend.Set_Field("sender","pid");
      thrusterMsgToSend.Set_Field("target","can");
      thrusterMsgToSend.Set_Field("ethid",ethId);
      thrusterMsgToSend.Set_Field("len",0);
      thrusterMsgToSend.Set_Field("extended",extended);
      thrusterMsgToSend.Set_Field("unique",counter);
      tcp_client.Send(thrusterMsgToSend, success);

      counter := counter + 1;
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end Send_Server_Message;


   procedure Read_From_Server is
      read_c : Character := 'b';

      success : Boolean := False;
   begin
      if PID.bDebugText then
         Ada.Text_IO.Put_line("Reading...");
         Ada.Text_IO.Put_Line("Start Read.");
      end if;
      while not success loop
	 --Ada.Text_IO.Put_Line("Still reading.");

	 tcp_client.Get (receivedMsg, success);

	delay 0.01;
	 if success = true then
--  	    declare
--  	       D : Integer := ReceivedMsg.Get ("posz");
--  	       I : Integer := ReceivedMsg.Get ("ethid");
--  	    begin
--  	       Ada.Text_IO.Put_Line ("CARL: Read_From_Server " & ReceivedMsg.Get ("sender") & " " & ReceivedMsg.Get ("target") & I'Img & D'Img);
--  	    end;
            exit;
         end if;
         delay(0.5);
      end loop;

      --Ada.Text_IO.Put_Line(receivedMsg.write);

   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end Read_From_Server;

   procedure Filter_Desired_Yaw (yawToConvert : in out Float) is
   begin
      if PID.fStartYaw + yawToConvert > 180.0 then
         yawToConvert := -180.0 + (-180.0 + PID.fStartYaw + yawToConvert);
      elsif PID.fStartYaw + yawToConvert < -180.0 then
        yawToConvert  :=  180.0 + ( 180.0 + PID.fStartYaw + yawToConvert);
      else
         yawToConvert := PID.fStartYaw + yawToConvert;
      end if;
   end Filter_Desired_Yaw;

   procedure Update_PID_Data is
      depth1 : integer := receivedMsg.Get("posz");
      absX : Float := 0.0;
      depth : Float := float(depth1);
      absY : Float := 0.0;
      absZ : Float := 0.0;

      absRoll : Float := 0.0;
      absPitch : Float := 0.0;
      absYaw : Float := 0.0;

      ethid : integer := 0;
   begin
--        Ada.Text_Io.Put_Line ("CARL: depth " & Depth'Img);
      depth := ((depth*3059.0)/1024.0)/100.0; --Needs to be calibrated to give proper depth value, this is not good enough.
      sender := receivedMsg.Get("sender");
      ethid := receivedMsg.Get("ethid");

      if sender = "sns" then -- sensor

         if PID.bFirstRun then
            --PID.fDesiredYaw := PID.fCurrentYaw;
            counterForSend := 0;
            PID.fRollIValue := 0.0;
            PID.fPitchIValue := 0.0;
            PID.fYawIValue := 0.0;
            PID.fPosXIValue := 0.0;
            PID.fPosYIValue := 0.0;
            PID.fPosZIValue := 0.0;
            PID.bFirstRun := False;
            PID.fStartYaw := receivedMsg.Get("yaw");
            PID.fCurrentYaw := PID.fStartYaw;
            PID.fStartPosZ := depth;
            PID.fCurrentPosZ := 0.0; --depth - PID.fStartPosZ;
            PID.surfacePosZ := PID.fCurrentPosZ;
            PID.Set_Desired_State(0.0,0.0,PID.fCurrentPosZ,0.0,0.0,0.0);
            if PID.bDebugText then
               ada.Text_IO.Put_Line("First run, setting desired to current.");
            end if;
         end if;
         PID.fCurrentYaw := receivedMsg.Get("yaw")-PID.fStartYaw;
         PID.fCurrentPitch := receivedMsg.Get("pitch");
         PID.fCurrentRoll := receivedMsg.Get("roll");

         if PID.bSimulation then
            PID.fCurrentAccX := receivedMsg.Get("accx");
            PID.fCurrentAccY := receivedMsg.Get("accy");
            PID.fCurrentAccZ := receivedMsg.Get("accz");
         else
            PID.fCurrentAccX := 0.0;
            PID.fCurrentAccY := 0.0;
            PID.fCurrentAccZ := 0.0;

            if PID.bGetFilteredPosition then
               PID.fCurrentPosX := receivedMsg.Get("posx");
               PID.fCurrentPosY := receivedMsg.Get("posy");
            end if;
         end if;

         --Gyro data might be added later to get better estimation on the derivative part.
         PID.fCurrentGyroX := 0.0; --receivedMsg.Get("gyrX");
         PID.fCurrentGyroY := 0.0; --receivedMsg.Get("gyrY");
         PID.fCurrentGyroZ := 0.0; --receivedMsg.Get("gyrZ");
         PID.fCurrentPosZ :=  depth - PID.fStartPosZ;--float(depth)/100.0 - PID.fStartPosZ;


      elsif sender = "msn" then -- mission control
         null;
      elsif sender = "pth" then -- path planner
          if ethid = 1 then
            absRoll := receivedMsg.Get("roll");
            absPitch := receivedMsg.Get("pitch");
            absYaw := receivedMsg.Get("yaw");
            absX := receivedMsg.Get("posx");
            absY := receivedMsg.Get("posy");
            absZ := receivedMsg.Get("posz");

            PID.Set_Desired_State(absX,absY,absZ,absRoll,absPitch,absYaw);
         elsif ethid = 2 then
		--ada.text_io.put_line("pth ethid 2------------------------------");
            relRoll := receivedMsg.Get("roll");
            relPitch := receivedMsg.Get("pitch");
            relYaw := receivedMsg.Get("yaw");
            relX := -receivedMsg.Get("posx");
            relY := receivedMsg.Get("posy");
            relDepth := receivedMsg.Get("posz");

            --relPitch := 0.0; --commented out by ludde 160816
            --relRoll := 0.0; --commented out by ludde 160816
            PID.Set_Desired_Relative_State(relX,relY,relDepth,relRoll,relPitch,relYaw);
         elsif ethid = 3 then
            PID.Go_To_Surface;
         end if;

      elsif sender = "usr" then
         if ethid = 1 then
            declare
               sDim : string := receivedMsg.Get("pid");
               sAxis : string := receivedMsg.Get("axis");
               iDim : integer := 0;
               iAxis : integer := 0;

            begin
               if sDim = "p" then
                  iDim := 1;
               elsif sDim = "i" then
                  iDim := 2;
               elsif sDim = "d" then
                  iDim := 3;
               end if;

               if sAxis = "x" then
                  iAxis := 1;
--		ada.text_io.put_line("asdfasdf");
               elsif sAxis = "y" then
                  iAxis := 2;
               elsif sAxis = "z" then
                  iAxis := 3;
               elsif sAxis = "roll" then
                  iAxis := 4;
               elsif sAxis = "pitch" then
                  iAxis := 5;
               elsif sAxis = "yaw" then
                  iAxis := 6;
               end if;

               if PID.bDebugText then
                  for i in 1..3 loop

                     for j in 1..6 loop
                        ada.text_io.put(pid.xpidconfig(i,j)'img);
                        --ada.text_io.new_line();
                        ada.text_io.put(",");

                     end loop;

                     ada.text_io.new_line;
                  end loop;
               end if;




                  pid.xPIDconfig(iDim, iAxis) := receivedMsg.Get("value");
            end;

         end if;
      elsif sender = "can" then
		ada.text_io.put("sender=can !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"); --ludde 160816
		ada.text_io.new_line; --ludde 160816
         Delay 3.0;
         PID.bFirstRun := True;
	elsif sender = "m_0" then
		bRunMode:=False;
		--pid.bFirstRun:=True;
		PID.fDesiredRoll:=PID.fCurrentRoll;
		PID.fDesiredPitch:=PID.fCurrentPitch;
		--ada.text_io.put_line("motor offfffffffffffffffff!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	elsif sender = "m_1" then
		bRunMode:=True;
		--ada.text_io.put_line("motor on!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

      end if;


   end Update_PID_Data;

   procedure Send_Desired_To_User is
      sendMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      success : boolean := false;
   begin
      sendMsg.set_field("sender", "pid");
      sendMsg.set_field("ethid", 1);
      sendMsg.set_field("target", "usr");
      sendMsg.set_field("posx", PID.fDesiredPosX);
      sendMsg.set_field("posy", PID.fDesiredPosY);
      sendMsg.set_field("posz", PID.fDesiredPosZ);
      sendMsg.set_field("yaw", PID.fDesiredYaw);
      sendMsg.set_field("pitch", PID.fDesiredPitch);
      sendMsg.set_field("roll", PID.fDesiredRoll);
      tcp_client.Send(sendMsg, success);
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
         --send
   end;

      procedure Send_Current_To_User is
      sendMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      success : boolean := false;
   begin
      sendMsg.set_field("sender", "pid");
      sendMsg.set_field("ethid", 4);
      sendMsg.set_field("target", "usr");
      sendMsg.set_field("posx", PID.fCurrentPosX);
      sendMsg.set_field("posy", PID.fCurrentPosY);
      sendMsg.set_field("posz", PID.fCurrentPosZ);
      sendMsg.set_field("yaw", PID.fCurrentYaw);
      sendMsg.set_field("pitch", PID.fCurrentPitch);
      sendMsg.set_field("roll", PID.fCurrentRoll);
      tcp_client.Send(sendMsg, success);
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
         --send
   end;

   procedure Send_Motors_To_User is
      sendMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      success : boolean := false;
   begin
      sendMsg.set_field("sender", "pid");
      sendMsg.set_field("ethid", 2);
      sendMsg.set_field("target", "usr");
      sendMsg.set_field("m1", PID.thruster(1));
      sendMsg.set_field("m2", PID.thruster(2));
      sendMsg.set_field("m3", PID.thruster(3));
      sendMsg.set_field("m4", PID.thruster(4));
      sendMsg.set_field("m5", PID.thruster(5));
      sendMsg.set_field("m6", PID.thruster(6));
      tcp_client.Send(sendMsg, success);
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
         --send
   end;

   procedure Send_P_Error is
      sendMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      success : boolean := false;
   begin
      sendMsg.set_field("sender", "pid");
      sendMsg.set_field("ethid", 3);
      sendMsg.set_field("target", "usr");
      sendMsg.set_field("xp", PID.fPosXPValue);
      sendMsg.set_field("yp", PID.fPosYPValue);
      sendMsg.set_field("zp", PID.fPosZPValue);
      sendMsg.set_field("rp", PID.fRollPValue);
      sendMsg.set_field("pp", PID.fPitchPValue);
      sendMsg.set_field("yawp", PID.fYawPValue);
      tcp_client.Send(sendMsg, success);
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
         --send
   end;


   procedure Log_Data is
      use Ada.Text_IO;
      use Ada.Calendar;

      sFileName : string := "logdata001.txt";


      function Does_File_Exist (Name : String) return Boolean is
      The_File : Ada.Text_IO.File_Type;
   begin
      Open (The_File, In_File, Name);
      Close (The_File);
      return True;
   exception
      when Name_Error =>
         return False;
      end Does_File_Exist;

      procedure Open_File is
         n100 : integer := 0;
         n10  : integer := 0;
         n1   : integer := 1;
      begin
         while Does_File_Exist(Name => sFileName) loop
           Ada.Text_IO.Put_Line("file found");
            n1 := n1 + 1;
            if n1 = 10 then
               n1 := 0;
               n10 := n10 + 1;
               if n10 = 10 then
                  n100 := n100 + 1;
                  n10 := 0;
               end if;
            end if;
            sFileName(8) := Character'val(Character'pos('0') + n100);
            sFileName(9) := Character'val(Character'pos('0') + n10);
            sFileName(10) := Character'val(Character'pos('0') + n1);
         end loop;
         CREATE(xOutput, Out_File ,sFileName);
         bFile_Created := true;
      end Open_File;




   begin
      if not bFile_Created then
         Open_File;
      end if;

      --time/count
      PUT(File => xOutput,
          Item => counter'Img);
      --sensors--yaw pitch roll xpos ypos zpos thruster 1..6
      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => (PID.fCurrentYaw'img));

      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => (PID.fCurrentPitch'img));

      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => (PID.fCurrentRoll'img));

      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => (PID.fCurrentPosX'img));

      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => (PID.fCurrentPosY'img));

      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => (PID.fCurrentPosZ'img));


      --motors
      for i in 1..6 loop
         PUT(File => xOutput,
             Item => " ");
         PUT(File => xOutput,
             Item => (PID.thruster(i)'img));
      end loop;

      PUT_LINE(File => xOutput,
               Item => "");
   end Log_Data;

begin
   tcp_client.SetTimeout(3.0);
   ada.Text_IO.Put_Line("Connecting...");
     tcp_client.Set_IP_And_Port("127.0.0.1", "pid");
--     tcp_client.Set_IP_And_Port("192.168.1.1", "pid");
   ada.Text_IO.Put_Line("Connected.");
end PID_Utils;
