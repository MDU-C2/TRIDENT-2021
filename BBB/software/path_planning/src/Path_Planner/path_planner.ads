with ada.Real_Time;
with Ada.Text_IO;
--with Ada.Calendar;
with Ada.IO_Exceptions;
with Ada.Exceptions; use Ada.Exceptions;
with Server_Net;
with GNATCOLL.JSON;
with GNAT.Sockets;
with general;
with tcp_client;

--------------------------------------------------------------------------------
--                           PATH PLANNER                                     --
--   All Movement and Movement related actions should be handled here         --
--                   does NOT handle pneumatics                               --
--------------------------------------------------------------------------------

package Path_Planner is


   procedure main;
private
   xCurrentPos            : general.mission;
   xWantedPos		 : general.mission;
   xTempPos		 : general.mission;
   bCoordinate           : boolean := true; --if true xWantedPos is position, if false xWantedPos is speed
   fMaxDistance           : float := 5.0;
--     movement_list_start   : General.mission_ptr := null;
--     movement_list_current : General.mission_ptr := null;
--     temp_ptr              : General.mission_ptr := null;
--     movement_list_last    : General.mission_ptr := null;
   xTempMovement         : General.mission;
   xNullPosition          : constant General.position_type := (0.0, 0.0, 0.0);
   xNullOrientation        : constant General.orientation_type := (0.0, 0.0, 0.0);
   fErrorLimit            : float := 1.0; --how close is close enough to be in a position and orientation


end Path_Planner;
