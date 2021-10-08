with Ada.Text_IO;
with Ada.Calendar;
with Ada.IO_Exceptions;
--with Serial_Net;
with GNATCOLL.JSON;
with GNAT.Sockets;
with PID;
with tcp_client;
with Interfaces;
with Ada.Numerics; use Ada.Numerics;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

package PID_Utils is

      relRoll : Float := 0.0;
      relPitch : Float := 0.0;
      relYaw : Float := 0.0;

      relX : Float := 0.0;
      relY : Float := 0.0;
      relDepth : Float := 0.0;

	bRunMode : Boolean := False;

   receivedMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;

   counter : Integer := 0;

   bFile_Created : boolean := false;
   xOutput : Ada.Text_IO.File_type;

   sender : String (1..3) := "nul";

   type byte_arr is array (natural range <>) of Interfaces.Unsigned_8;
   counterForSend : integer := 0;
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

   procedure Filter_Desired_Yaw(yawToConvert : in out Float);
   --Recalculates the yaw value into a more proper value

   procedure Update_Desired_State;
   --Updates the desired state based on values from pid_desired.json file that can be set from the web application.

--     function Update_Scalings return pidArray;
--Sets the P,I and D constants for each individual controller
--These values sets in the web application

   procedure Send_Server_Message(ethId : Integer; extended : Boolean; b : byte_arr);
   --Sends ethId, canId, extended bit and multiple bytes to the server


   procedure Send_Desired_To_User;
   procedure Send_Motors_To_User;
   procedure Send_P_Error;
procedure Send_Current_To_User;

   procedure Send_Server_Message(ethId : Integer; extended : Boolean; b : Interfaces.Unsigned_8);
   --Sends ethId, canId, extended bit and one byte to the server

   procedure Send_Server_Message(ethId : Integer; extended : Boolean);
   --Sends ethId, canId and extended bit

   procedure Read_From_Server;
   --Waits for an incoming json string from the server

   procedure Update_PID_Data;
   --Filters the messages based on the unique sender string
   --and sets proper values

   procedure Log_Data;
   --Logs

end PID_Utils;
