with Ada.Text_IO;
with Ada.Calendar;
with Ada.IO_Exceptions;
with Serial_Net;
with GNATCOLL.JSON;
with GNAT.Sockets;
with PID;
--  with Mission_utils;

package Mission_Handler is

   con : Serial_Net.Connection;

   --JSON--
   receivedMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;

   --Unique Messages--
   counter : Integer := 0;



   --Log File--
   bFile_Created : boolean := false;
   xOutput : Ada.Text_IO.File_type;
   subtype byte is integer range 0..255;
   type byte_arr is array (natural range <>) of byte;
   procedure connectToServer(ip : String; port : Integer);
   procedure sendServerMessage(ethId, canId : Integer; extended : Boolean; b : byte_arr);
   procedure sendServerMessage (ethId, canId : Integer; extended : Boolean; b : byte);
   procedure sendServerMessage(ethId, canId : Integer; extended : Boolean);
   procedure readFromServer;
   procedure updatePIDData;
   procedure Log_Data;

end Mission_Handler;
