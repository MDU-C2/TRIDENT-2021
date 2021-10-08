with ada.Real_Time;
with Ada.Text_IO;
--with Ada.Calendar;
with Ada.IO_Exceptions;
with Serial_Net;
with GNATCOLL.JSON;
with GNAT.Sockets;
with Mission_Handler;
with Mission_Control_Utils;
with Path_Planner;

--------------------------------------------------------------------------------
--                           MISSION HANDLER                                  --
--   purpose to update all of the mission objectives                          --
--   Pneumatics                                                               --
--   update pathplanner with new wanted coordinates and positions             --
--------------------------------------------------------------------------------

package Mission_Control is


   mission_list_start   : Mission_Control_Utils.mission_ptr := null;
   mission_list_current : Mission_Control_Utils.mission_ptr := null;
   mission_list_last    : Mission_Control_Utils.mission_ptr := null;
   temp_mission         : Mission_Control_Utils.mission;

   has_object_been_seen         : boolean := false;
   Object_last_seen_information : Mission_Control_Utils.mission;
   last_time_object_seen        : ada.Real_Time.Time;

   action : Mission_Control_Utils.action_type_list;
   maxDistance : float := 5.0;
   desiredPosition : Mission_Control_Utils.position_type;
   receivedMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;

   procedure main;
   --function find_lost_object (this : Mission_Control_Utils.mission_ptr) return boolean;
   function follow_light (this : Mission_Control_Utils.mission_ptr) return boolean;

end Mission_Control;
