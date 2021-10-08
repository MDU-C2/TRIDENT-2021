package body Mission_Handler is

   procedure connectToServer (ip : String; port : Integer) is
   begin
      Serial_Net.Open(con,ip,port);
   end connectToServer;

   procedure sendServerMessage (ethId, canId : Integer; extended : Boolean;  b : byte_arr) is
      thrusterMsgToSend : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      space_filler : String (1..256) := (others => ' ');
   begin
      thrusterMsgToSend.Set_Field("ethId",ethId);
      thrusterMsgToSend.Set_Field("canId",canId);
      thrusterMsgToSend.Set_Field("size",b'last);
      thrusterMsgToSend.Set_Field("extended",extended);
      thrusterMsgToSend.Set_Field("unique",counter);
      for i in b'range loop
         thrusterMsgToSend.Set_Field(("b" & Character'val(Character'pos('0') + i)) ,b(i));
      end loop;
      Serial_Net.Write_Buffer(con,thrusterMsgToSend.Write & space_filler(thrusterMsgToSend.Write'length+1..space_filler'Length)); --SERVER
      Ada.Text_IO.Put_Line(thrusterMsgToSend.write);
      counter := counter + 1;
   exception
      when GNAT.Sockets.Socket_Error =>
         Ada.Text_IO.Put_Line("GNAT Errors.");
   end sendServerMessage;

   procedure sendServerMessage (ethId, canId : Integer; extended : Boolean;  b : byte) is
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
   end sendServerMessage;


   procedure sendServerMessage (ethId, canId : Integer; extended : Boolean) is
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
   end sendServerMessage;


   procedure readFromServer is
      read_c : Character := 'b';
      raw_imu_data : String (1..256) := (others => ' ');
      str_iterator : Integer := raw_imu_data'First;
   begin
      Ada.Text_IO.Put_line("Reading...");
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
   end readFromServer;

   procedure updatePIDData is
      --   depth : Integer := receivedMsg.Get("depth");
   begin

      pid.setCurrentState(Yaw   => receivedMsg.Get("yaw"),
                          Pitch => receivedMsg.Get("pitch"),
                          Roll  => receivedMsg.Get("roll"),
                          AccX  => receivedMsg.Get("accX"),
                          AccY  => receivedMsg.Get("accY"),
                          AccZ  => receivedMsg.Get("accZ"),
                          GyroX => receivedMsg.Get("gyrX"),
                          GyroY => receivedMsg.Get("gyrY"),
                          GyroZ => receivedMsg.Get("gyrZ"),
                          Depth => (receivedMsg.Get("depth")/100.0));
   end updatePIDData;




   --------------
   -- Log_Data --
   --------------

   procedure Log_Data is
      use Ada.Text_IO;
      use Ada.Calendar;

      sFileName : string := "mission001.txt";


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
      -- put timestamp and recived message and action taken etc
      --time/count
      PUT(File => xOutput,
          Item => counter'Img);
      --sensors--yaw pitch roll xpos ypos zpos thruster 1..6

   end Log_Data;

end Mission_Handler;
