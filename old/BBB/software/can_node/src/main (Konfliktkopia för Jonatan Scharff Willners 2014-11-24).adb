--  with Mission_Handler;
with BBB_CAN;
with CAN_Defs;
with ada.Text_IO;
with Interfaces; use interfaces;
with ada.Unchecked_Conversion;
with GNATCOLL.JSON;
with ada.real_time; use Ada.Real_Time;
with tcp_client;
with byte_conv;
with UartWrapper;
with Ada.Exceptions; use Ada.Exceptions;


procedure Main is






   INS_JSON : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;

   messageOut : CAN_Defs.CAN_Message;
   jsonToCan : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   bNewMessage : boolean := false;


   canToBBB : CAN_Defs.CAN_Message;
   bNewCanMsg : boolean := false;
   bUartCheckSumOk : boolean := false;

   pingPsuTime : ada.Real_Time.Time;
   pingPsuPeriod : ada.Real_Time.Time_Span := ada.Real_Time.Milliseconds(1000);


   procedure get_data_to_can(nr : integer) is
      str : string := "b1";
      int : integer;
   begin
      Ada.Text_IO.Put_Line("In data to can");
      for i in 1.. nr loop
         Ada.Text_IO.Put_Line("Get_data_to_can i = " & i'Img);
         str(2) := Character'Val(Character'pos('0') + i);
         int := jsonToCan.get(str);
         messageOut.Data(can_defs.DLC_TYPE(i)) := interfaces.unsigned_8(int);

      end loop;
      Ada.Text_IO.Put_Line("done Data to can");
   end get_data_to_can;




   procedure init is
   begin
      tcp_client.Set_IP_And_Port(sIP   => "192.168.1.1",
                                 iPort => "can");
      tcp_client.SetTimeout(0.0005);
      BBB_CAN.Init(sPort => "ttyO4", baud  => UartWrapper.B115200);
      declare
      begin
         INS_JSON.Set_Field("posz", 0);
         INS_JSON.Set_Field("accx", 0.0);
         INS_JSON.Set_Field("accy", 0.0);
         INS_JSON.Set_Field("accz", 0.0);
         INS_JSON.Set_Field("roll", 0.0);
         INS_JSON.Set_Field("pitch", 0.0);
         INS_JSON.Set_Field("yaw", 0.0);
      exception
         when E : others =>
            Ada.Text_IO.Put_Line("init Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
      end;

   end init;

   procedure send_to_can (xJson : GNATCOLL.JSON.JSON_Value) is
      ethID : integer;
      len : integer;
   begin
      declare
      begin
         ethID := jsonToCan.get("ethid");
         messageOut.ID := (can_defs.CAN_identifier(ethID), false);
         Len := jsonToCan.get("len");
         messageOut.Len := CAN_Defs.DLC_Type(Len);
         get_data_to_can(integer(messageOut.Len));
         BBB_CAN.Send(msg => messageOut);
      exception
         when E : others =>
            Ada.Text_IO.Put_Line("send to can Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
      end;
   end send_to_can;

   procedure send_to_tcp is
      bSendSucess : Boolean;
      canToBBB_JSON : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   begin
      --        canToBBB_JSON := GNATCOLL.JSON.JSON_Null;
      ada.Text_IO.Put_Line("YEY");
      case canToBBB.ID.Identifier is
         when 1591 => --fog
            null;

         when 1593 => --depth
            declare
            begin
               INS_JSON.Set_Field("posz", integer(byte_conv.Byte2ToUsign16(canToBBB.Data,1)));
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("1593 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
            --send to SNS- sensor fusion
         when 1594 => --imu Yaw and Pitch
            declare
            begin
               INS_JSON.Set_Field("yaw", byte_conv.Byte4ToFloat(canToBBB.Data,1));
               INS_JSON.Set_Field("pitch", byte_conv.Byte4ToFloat(canToBBB.Data,5));
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("1594 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when 1595 => --imu Roll and AccZ
            declare
            begin
               INS_JSON.Set_Field("roll", byte_conv.Byte4ToFloat(canToBBB.Data,1));
               INS_JSON.Set_Field("accz", byte_conv.Byte4ToFloat(canToBBB.Data,5));
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("1595 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when 1596 => --imu AccX and AccY, 1591, 1593, 1594, 1595 is compiled into the same package.
            declare
            begin
               INS_JSON.Set_Field("ethid",1);
               INS_JSON.Set_Field("target","sns");
               INS_JSON.Set_Field("accx", byte_conv.Byte4ToFloat(canToBBB.Data,1));
               INS_JSON.Set_Field("accy", byte_conv.Byte4ToFloat(canToBBB.Data,5));

               Ada.text_io.put_line("innan INS_JSON.write");
               ada.Text_IO.Put_Line(INS_JSON.Write);

               Ada.text_io.put_line("efter INS_JSON.write");
               tcp_client.Send(canToBBB_JSON, bSendSucess);

               Ada.text_io.put_line("can skickat");
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("1596 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when others => null;

            Ada.text_io.put_line("OTHERS.----- ID : "  &  integer'image(integer(canToBBB.ID.Identifier)) );
      end case;

      ada.Text_IO.Put_Line("WOOHOO");
   end send_to_tcp;





begin


   init;

   pingPsuTime := Ada.Real_Time.Clock;

   loop

      ada.Text_IO.Put_Line("TCP GET");
      tcp_client.Get(xJson    => jsonToCan,
                     bSuccess => bNewMessage);

      ada.Text_IO.Put_Line("CAN GET");
      BBB_CAN.Get(msg             => canToBBB,
                  bMsgReceived    => bNewCanMsg,
                  bUARTChecksumOK => bUartCheckSumOk);


      if bNewMessage then
         declare
            sSender :string (1..3);
         begin
            sSender := jsonToCan.get("sender");
            ada.Text_IO.Put_Line("TCC NEW from" & sSender);
            bNewMessage := false;
            send_to_can(jsonToCan);
         end;
      end if;


      if bNewCanMsg then
         declare
            ID : integer;
         begin
            ID := integer(canToBBB.ID.Identifier);
            ada.Text_IO.Put_Line("CAN NEW ID: " & ID'img);
            bNewCanMsg := false;
            send_to_tcp;
         end;
      end if;


      ada.Text_IO.Put_Line("TIME STUFF!");

      if Ada.Real_Time.Clock > pingPsuTime then -- alive ping
         pingPsuTime := pingPsuTime + pingPsuPeriod;
         messageOut.ID := (504, false);
         messageOut.Len := 0;
         ada.Text_IO.Put_Line("sending can ping");
         BBB_CAN.Send(msg => messageOut);
         ada.Text_IO.Put_Line("sending can ping done");

         --           declare
         --              jsona : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
         --           begin
         --
         --              ada.Text_IO.Put_Line("JSON STUFF");
         --              jsona.Set_Field("target","msn");
         --              jsona.Set_Field("posx",30.0);
         --              jsona.Set_Field("posy",0.0);
         --              jsona.Set_Field("posz",0.0);
         --              jsona.Set_Field("roll",0.0);
         --              jsona.Set_Field("pitch",0.0);
         --              jsona.Set_Field("yaw",0.0);
         --              jsona.Set_Field("sender",0.0);
         --              jsona.Set_Field("ethid",2);
         --
         --              ada.Text_IO.Put_Line("sending TCP");
         --              tcp_client.Send(jsona,bNewMessage);
         --              ada.Text_IO.Put_Line("sending TCP done");
         --
         --              jsona.Set_Field("posx",0.0);
         --              jsona.Set_Field("target","sns");
         --              tcp_client.Send(jsona,bNewMessage);
         --
         --
         --
         --           end;



      end if;


      delay(0.05);
   end loop;
end Main;
