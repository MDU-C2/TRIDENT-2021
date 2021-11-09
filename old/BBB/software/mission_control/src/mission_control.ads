with ada.Real_Time;
with Ada.Text_IO;
--with Ada.Calendar;
with Ada.IO_Exceptions;
with Ada.Exceptions; use Ada.Exceptions;
with Server_Net;
with GNATCOLL.JSON;
with GNAT.Sockets;
--with general;
with tcp_client;
--------------------------------------------------------------------------------
--                           MISSION HANDLER                                  --
--   purpose to update all of the mission objectives                          --
--   Pneumatics                                                               --
--   update pathplanner with new wanted coordinates and positions             --
--   handles vision data for objects
--------------------------------------------------------------------------------

package Mission_Control is

   procedure main;

end Mission_Control;
