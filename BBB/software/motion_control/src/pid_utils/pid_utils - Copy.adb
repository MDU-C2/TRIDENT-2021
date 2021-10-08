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

   procedure connectToServer (ip : String; port : Integer) is
   begin
      Serial_Net.Open(con,ip,port);
   end connectToServer;

   procedure Send_Server_Message (ethId, canId : Integer; extended : Boolean;  b : byte_arr) is
      thrusterMsgToSend : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      space_filler : String (1..256) := (others => ' ');
   begin
      thrusterMsgToSend.Set_Field("ethId",ethId);
      thrusterMsgToSend.Set_Field("canId",canId);
      thrusterMsgToSend.Set_Field("size",b'Length);
      thrusterMsgToSend.Set_Field("extended",extended);
      thrusterMsgToSend.Set_Field("unique",counter);
      for i in b'range loop
         thrusterMsgToSend.Set_Field(("b" & Character'val(Character'pos('1') + i)) ,b(i));
      end loop;
      Serial_Net.Write_Buffer(con,thrusterMsgToSend.Write & space_filler(thrusterMsgToSend.Write'length+1..space_filler'Length)); --SERVER
      Ada.Text_IO.Put_Line(thrusterMsgToSend.write);
      counter := counter + 1;
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end Send_Server_Message;

    procedure Send_Server_Message (ethId, canId : Integer; extended : Boolean;  b : byte) is
      thrusterMsgToSend : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      space_filler : String (1..256) := (others => ' ');
   begin
      thrusterMsgToSend.Set_Field("ethId",ethId);
      thrusterMsgToSend.Set_Field("canId",canId);
      thrusterMsgToSend.Set_Field("size", 1);
      thrusterMsgToSend.Set_Field("extended",extended);
      thrusterMsgToSend.Set_Field("unique",counter);

      thrusterMsgToSend.Set_Field("b1" ,b);

      Serial_Net.Write_Buffer(con,thrusterMsgToSend.Write & space_filler(thrusterMsgToSend.Write'length+1..space_filler'Length)); --SERVER
      Ada.Text_IO.Put_Line(thrusterMsgToSend.write);
      counter := counter + 1;
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end Send_Server_Message;


   procedure Send_Server_Message (ethId, canId : Integer; extended : Boolean) is
      thrusterMsgToSend : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      space_filler : String (1..256) := (others => ' ');
   begin
      thrusterMsgToSend.Set_Field("ethId",ethId);
      thrusterMsgToSend.Set_Field("canId",canId);
      thrusterMsgToSend.Set_Field("size",0);
      thrusterMsgToSend.Set_Field("extended",extended);
      thrusterMsgToSend.Set_Field("unique",counter);
      Serial_Net.Write_Buffer(con,thrusterMsgToSend.Write & space_filler(thrusterMsgToSend.Write'length+1..space_filler'Length)); --SERVER
      Ada.Text_IO.Put_Line(thrusterMsgToSend.write);

      counter := counter + 1;
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end Send_Server_Message;


   procedure Read_From_Server is
      read_c : Character := 'b';
      raw_imu_data : String (1..256);
      str_iterator : Integer := raw_imu_data'First;
   begin
      Ada.Text_IO.Put_line("Reading...");
      raw_imu_data := (others => ' ');
      raw_imu_data(1..2) := "{}";

      declare
      begin
         loop
            Serial_Net.Read(con,read_c);
            raw_imu_data(str_iterator) := read_c;
            str_iterator := str_iterator + 1;
            exit when str_iterator > raw_imu_data'Length + raw_imu_data'First -1;
         end loop;
      exception
         when Ada.IO_Exceptions.End_Error =>
            null;
      end;

      Ada.Text_IO.Put_Line(raw_imu_data);
      receivedMsg := GNATCOLL.JSON.Read(raw_imu_data, "json.errors");

   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end Read_From_Server;

   procedure Update_PID_Data is
      depth : Integer := receivedMsg.Get("depth");
   begin
      PID.fCurrentYaw := receivedMsg.Get("yaw");
      PID.fCurrentPitch := receivedMsg.Get("pitch");
      ada.Text_IO.Put_Line("SOKSOSKOSKS-" & PID.fCurrentPitch'Img);
      PID.fCurrentRoll := receivedMsg.Get("roll");
      PID.fCurrentAccX := receivedMsg.Get("accX");
      PID.fCurrentAccY := receivedMsg.Get("accY");
      PID.fCurrentAccZ := receivedMsg.Get("accZ");
      PID.fCurrentGyroX := 0.0; --receivedMsg.Get("gyrX");
      PID.fCurrentGyroY := 0.0; --receivedMsg.Get("gyrY");
      PID.fCurrentGyroZ := 0.0; --receivedMsg.Get("gyrZ");
      PID.fCurrentPosZ := float(depth)/100.0;
--        pid.setCurrentState(Yaw   => receivedMsg.Get("yaw"),
--                            Pitch => receivedMsg.Get("pitch"),
--                            Roll  => receivedMsg.Get("roll"),
--                            AccX  => receivedMsg.Get("accX"),
--                            AccY  => receivedMsg.Get("accY"),
--                            AccZ  => receivedMsg.Get("accZ"),
--                            GyroX => receivedMsg.Get("gyrX"),
--                            GyroY => receivedMsg.Get("gyrY"),
--                            GyroZ => receivedMsg.Get("gyrZ"),
--                            Depth => (receivedMsg.Get("depth")/100.0));
   end Update_PID_Data;

   --------------
   -- Log_Data --
   --------------

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

end PID_Utils;
