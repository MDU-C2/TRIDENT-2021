with ada.Real_Time;
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
--with Ada.Calendar;
with Ada.Long_Float_Text_IO;use Ada.Long_Float_Text_IO;
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

package sensor is

   procedure main;

private
   x, y, roll, pitch, yaw, accx, accy, Accz : float;
   maxZCounter : integer := 4; -- 20; -- CARL
   z : array (1..maxZCounter) of integer := (others => 0);
--     Z : Integer;
end sensor;
