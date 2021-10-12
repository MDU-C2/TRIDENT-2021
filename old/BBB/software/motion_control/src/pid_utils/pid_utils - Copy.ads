with Ada.Text_IO;
with Ada.Calendar;
with Ada.IO_Exceptions;
with Serial_Net;
with GNATCOLL.JSON;
with GNAT.Sockets;
with PID;

package PID_Utils is

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

   type pidValue is
      record
         P : float;
         I : float;
         D : float;
      end record;

   type pidArray is array (Positive range <>) of pidValue;

   type pidDesired is
      record
         x : float;
         y : float;
         z : float;
         roll : float;
         pitch : float;
         yaw: float;
      end record;

   procedure Update_Desired_State;
--     function Update_Scalings return pidArray;
   procedure connectToServer(ip : String; port : Integer);
   procedure Send_Server_Message(ethId, canId : Integer; extended : Boolean; b : byte_arr);
   procedure Send_Server_Message(ethId, canId : Integer; extended : Boolean; b : byte);
   procedure Send_Server_Message(ethId, canId : Integer; extended : Boolean);
   procedure Read_From_Server;
   procedure Update_PID_Data;

   procedure Log_Data;

end PID_Utils;
