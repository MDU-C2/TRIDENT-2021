with ada.Text_IO;
package body can_id is


   --------------
   -- Log_Data --
   --------------
   procedure Log_Data_From_Can(isOutput : boolean; msg : can_defs.can_message);
   bFile_Created : boolean := false;
   xOutput : Ada.Text_IO.File_type;


   procedure Log_Data_From_Can(isOutput : boolean; msg : can_defs.can_message) is
      use Ada.Text_IO;

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
      if isOutput then
         Put(File => xOutput,
             Item => "out");
      else
         Put(File => xOutput,
             Item => "in ");
      end if;
      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => msg.ID.identifier'img);
      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => msg.ID.isExtended'img);
      PUT(File => xOutput,
          Item => " ");
      PUT(File => xOutput,
          Item => msg.Len'img);
      PUT(File => xOutput,
          Item => " ");
      for i in 1..8 loop
         PUT(File => xOutput,
             Item => msg.Data(can_defs.DLC_TYPE(i))'img);
         PUT(File => xOutput,
             Item => " ");
      end loop;
      PUT_LINE(File => xOutput,
               Item => " ");

   end Log_Data_From_Can;


   procedure can_to_bbb is

      procedure get_data_from_can is
         str : string := "b1";
      begin
         for i in 1..8 loop
            str(2) := Character'Val(Character'pos('0') + i);
            can_to_json.Set_Field(str, integer(messageOut.Data(can_defs.DLC_TYPE(i))));
         end loop;
      end get_data_from_can;

   begin

      case messageID is
         when 1594 => --imu Yaw and Pitch
         when 1595 => --imu Roll and AccZ
         when 1596 => --imu AccX and AccY

            --send to SNS- sensor fusion
         when 1593 => --depth
            null;
            --send to SNS- sensor fusion
         when 1591 => --fog
            null;
            --send to SNS- sensor fusion
            --           when 616 => --set speed
            --              null;
            --           when 623 => --set limit
            --              null;
         when others =>
            null;
      end case;

      Log_Data_From_Can(isOutput => false,
                        msg      => messageIn);
   end can_to_bbb;


   procedure bbb_to_can(msg : GNATCOLL.JSON.Create_Object) is
      tempInt : integer;
      procedure get_data_to_can(nr : integer) is
         str : string := "b1";
         int : integer;
      begin
         for i in 1.. nr loop
            str(2) := Character'Val(Character'pos('0') + i);
            int := msg.get(str);
            messageOut.Data(can_defs.DLC_TYPE(i)) := interfaces.unsigned_8(int);
         end loop;
      end get_data_to_can;

   begin
      tempInt := msg.get("ethid");
      case tempInt is
         when 616 => --set speed
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
            get_data_to_can(messageOut.Len);
         when 623 => --set limit
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
            get_data_to_can(messageOut.Len);
         when 752 => --set lights
            null;
         when 753 => --turn off all lights
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
         when 754 => --run port/left(red)///starboard(green) blinking
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
         when 755 => --stop port/left(red)///starboard(green) blinking
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
         when 756 => --set left --rgbrgb?
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
            get_data_to_can(messageOut.Len);
         when 757 =>--set right --rgbrgb?
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
            get_data_to_can(messageOut.Len);
         when 758 =>
            null;
         when 759 =>
            null;
         when 760 => --set pwm for front spotlight
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
            get_data_to_can(messageOut.Len);
         when 761 => --set pwm for bot spotlight
            messageOut.ID := (can_defs.CAN_identifier(ethid), false);
            messageOut.Len := msg.get("len");
            get_data_to_can(messageOut.Len);
         when 762 =>
            null;
         when 763 =>
            null;
         when 764 =>
            null;
         when 765 =>
            null;
         when 766 =>
            null;
         when 767 =>
            null;
         when others =>
            null;
      end case;
      BBB_CAN.Send(messageOut);
      Log_Data_From_Can(isOutput => true,
                        msg      => messageOut);

   end bbb_to_can;


end can_id;

pr
