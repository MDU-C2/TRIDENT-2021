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
with ada.real_time;


package can_id is


   procedure can_to_bbb;
   procedure bbb_to_can(msg : GNATCOLL.JSON.Create_Object);
   can_to_json : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   messageOut : can_defs.can_message;
   messageIn : can_defs.can_message;
   messageID, ethid : integer;
   target : string(1..3);
end can_id;
