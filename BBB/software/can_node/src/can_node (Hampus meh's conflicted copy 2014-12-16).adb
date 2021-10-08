with ada.Real_Time; use ada.Real_Time;
with BBB_CAN;
with CAN_Defs;
with ada.Text_IO;
with Interfaces; use interfaces;
with ada.Unchecked_Conversion;
with GNATCOLL.JSON;
with tcp_client;
with byte_conv;
with UartWrapper;
with Ada.Exceptions; use Ada.Exceptions;
with can_log;
with can_status;

package body can_node is
   INS_JSON : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   bInitEnabled : Boolean := false;

   procedure init is
   begin
      tcp_client.Set_IP_And_Port(sIP   => "127.0.0.1",
                                 sPort => "can");
      BBB_CAN.Init(sPort => "ttyO4", baud  => UartWrapper.B115200);

      INS_JSON.Set_Field("posz", 0.0);
      INS_JSON.Set_Field("accx", 0.0);
      INS_JSON.Set_Field("accy", 0.0);
      INS_JSON.Set_Field("accz", 0.0);
      INS_JSON.Set_Field("roll", 0.0);
      INS_JSON.Set_Field("pitch", 0.0);
      INS_JSON.Set_Field("yaw", 0.0);
      INS_JSON.Set_Field("posx", 0.0);
      INS_JSON.Set_Field("posy", 0.0);
      bInitEnabled := true;
   end init;

   procedure send_to_can (xJson : GNATCOLL.JSON.JSON_Value) is
      iEthID : integer;
      iCanDataLen : integer;
      iByteValue : integer := 0;
      xMessageOut : CAN_Defs.CAN_Message;
   begin

      iEthID := xJson.get("ethid");
      xMessageOut.ID := (can_defs.CAN_identifier(iEthID), false);
      iCanDataLen := xJson.get("len");
      xMessageOut.Len := CAN_Defs.DLC_Type(iCanDataLen);

      -- loop to transfer all the bytes (b1 -> b8) from the JSON object to a CAN message.
      for i in 1..iCanDataLen loop
         iByteValue := xJson.get('b' & Character'Val(Character'pos('0') + i));
         xMessageOut.Data(can_defs.DLC_TYPE(i)) := interfaces.unsigned_8(iByteValue);
      end loop;

      BBB_CAN.Send(msg => xMessageOut);
   end send_to_can;



   procedure send_to_tcp (xCanMsg : CAN_Defs.CAN_Message) is
      bSendSucess : Boolean;
      canToBBB_JSON : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   begin
      --        canToBBB_JSON := GNATCOLL.JSON.JSON_Null;
      case xCanMsg.ID.Identifier is

         when 400 =>
            canToBBB_JSON.Set_Field("ethid", integer(xCanMsg.ID.Identifier));
            canToBBB_JSON.Set_Field("target", "msn");
            canToBBB_JSON.Set_Field("sender", "can");

         when 404 =>
            canToBBB_JSON.Set_Field("ethid", integer(xCanMsg.ID.Identifier));
            canToBBB_JSON.Set_Field("target", "msn");
            canToBBB_JSON.Set_Field("sender", "can");

         when 1591 => --fog
            null;

         when 1593 => --depth
            declare
            begin
               INS_JSON.Set_Field("posz", integer(byte_conv.Byte2ToUsign16(xCanMsg.Data,1)));
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("1593 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
            --send to SNS- sensor fusion
         when 1594 => --imu Yaw and Pitch
            declare
            begin
               INS_JSON.Set_Field("yaw", byte_conv.Byte4ToFloat(xCanMsg.Data,1));
               INS_JSON.Set_Field("pitch", byte_conv.Byte4ToFloat(xCanMsg.Data,5));
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("1594 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when 1595 => --imu Roll and AccZ
            declare
            begin
               INS_JSON.Set_Field("roll", byte_conv.Byte4ToFloat(xCanMsg.Data,1));
               INS_JSON.Set_Field("accz", byte_conv.Byte4ToFloat(xCanMsg.Data,5));
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("1595 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when 1596 => --imu AccX and AccY, 1591, 1593, 1594, 1595, 1596 is compiled into the same package.
            declare
            begin

               INS_JSON.Set_Field("ethid",1);
               INS_JSON.Set_Field("target","sns");
               INS_JSON.Set_Field("accx", byte_conv.Byte4ToFloat(xCanMsg.Data,1));
               INS_JSON.Set_Field("accy", byte_conv.Byte4ToFloat(xCanMsg.Data,5));

               tcp_client.Send(INS_JSON, bSendSucess);

            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when others => null;
      end case;

   end send_to_tcp;





   task Tcp_to_Can_task;
   task body Tcp_to_Can_task is
      bNewMessage : boolean := false;
      xJsonToCan : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   begin
      while not bInitEnabled loop
         delay 1.0;
      end loop;
      loop
         tcp_client.Get(xJson    => xJsonToCan,
                        bSuccess => bNewMessage);
         if bNewMessage then
            bNewMessage := false;
            send_to_can(xJsonToCan);
         end if;
      end loop;
   end Tcp_to_Can_task;



   task Can_to_Tcp_task;
   task body Can_to_Tcp_task is
      xCanToTCP : CAN_Defs.CAN_Message;
      bNewCanMsg : boolean := false;
      bUartCheckSumOk : boolean := false;
   begin
      while not bInitEnabled loop
         delay 1.0;
      end loop;
      loop
         BBB_CAN.Get(msg             => xCanToTCP,
                     bMsgReceived    => bNewCanMsg,
                     bUARTChecksumOK => bUartCheckSumOk);
         if bNewCanMsg then
            bNewCanMsg := false;
            send_to_tcp(xCanToTCP);
         else
            delay (0.01);
         end if;
      end loop;

   end Can_to_Tcp_task;



   procedure main_loop is
      xCanPingMsg : CAN_Defs.CAN_Message;
      pingPsuTime : ada.Real_Time.Time;
      pingPsuPeriod : ada.Real_Time.Time_Span := ada.Real_Time.Milliseconds(1000);
   begin

      init;
      xCanPingMsg.ID := (504, false);
      xCanPingMsg.Len := 0;
      pingPsuTime := Ada.Real_Time.Clock;
      loop
         pingPsuTime := pingPsuTime + pingPsuPeriod;
         BBB_CAN.Send(msg => xCanPingMsg);
         Delay Until(pingPsuTime);
      end loop;
   end main_loop;




end can_node;
