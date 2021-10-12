--  with Mission_Handler;
with Server_net;
with BBB_CAN;
with CAN_Defs;
with ada.Text_IO;
with UartWrapper;
with Interfaces; use interfaces;
with ada.Unchecked_Conversion;
with GNATCOLL.JSON;
with Ada.IO_Exceptions;
with gnat.Sockets;
with ada.Exceptions; use ada.Exceptions;
with CAN_Utils;
with ada.real_time; use Ada.Real_Time;
with tcp_client;
procedure Main is
   messageOut : CAN_Defs.CAN_Message;
   jsonToCan : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   bNewMessage : boolean := false;
   ethID : integer;
   len : integer;
   pingPsuTime : ada.Real_Time.Time;
   pingPsuPeriod : ada.Real_Time.Time_Span := ada.Real_Time.Milliseconds(1000);
   canToBBB : CAN_Defs.CAN_Message;
   canToBBB_JSON : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   bNewCanMsg : boolean := false;
   bUartCheckSumOk : boolean := false;
   procedure get_data_to_can(nr : integer) is
      str : string := "b1";
      int : integer;
   begin
      for i in 1.. nr loop
         str(2) := Character'Val(Character'pos('0') + i);
         int := jsonToCan.get(str);
         messageOut.Data(can_defs.DLC_TYPE(i)) := interfaces.unsigned_8(int);
      end loop;
   end get_data_to_can;

begin
   tcp_client.Set_IP_And_Port(sIP   => "127.0.0.1",
                              iPort => 42);

   tcp_client.SetTimeout(0.0);
   pingPsuTime := Ada.Real_Time.Clock;
   loop

      tcp_client.Get(xJson    => jsonToCan,
                     bSuccess => bNewMessage);
      BBB_CAN.Get(msg             => canToBBB,
                  bMsgReceived    => bNewCanMsg,
                  bUARTChecksumOK => bUartCheckSumOk);
      if bNewMessage then
         bNewMessage := false;
         ethID := jsonToCan.get("ethid");
         messageOut.ID := (can_defs.CAN_identifier(ethID), false);
         Len := jsonToCan.get("len");
         messageOut.Len := CAN_Defs.DLC_Type(Len);
         get_data_to_can(integer(messageOut.Len));
         BBB_CAN.Send(msg => messageOut);
      end if;




      if bNewCanMsg then
         case canToBBB.ID.Identifier is
            when 1592 => null;
            when others => null;
         end case;
      end if;




      if Ada.Real_Time.Clock > pingPsuTime then -- alive ping
         pingPsuTime := pingPsuTime + pingPsuPeriod;
         messageOut.ID := (504, false);
         messageOut.Len := 0;
         BBB_CAN.Send(msg => messageOut);
      end if;



   end loop;
end Main;
