with ada.Numerics.Generic_Elementary_Functions;
with ada.Unchecked_Deallocation;
--------------------------------------------------------------------------------
--                           Mission_Control_Utils                            --
--   contains all special types for missions and closly related stuff         --
--------------------------------------------------------------------------------

package general is

   package Math is new ada.Numerics.Generic_Elementary_Functions(float);


   type mission;
   type mission_ptr is access mission;
   type mission_type_list is (find_light, follow_light, go_to_position, go_to_relative_position, return_to_start);
   type action_type_list is (fire_torpedo, release_marker, close_grip, open_grip);

   type position_type is
      record
         X       : float;
         Y       : float;
         Z       : float;
      end record;

   type orientation_type is
      record
         roll    : float;
         pitch   : float;
         yaw     : float;
      end record;

   type mission is
      record
         mission_type : mission_type_list;
         finished     : boolean;
         position     : position_type;         --use also x for distance to object
         orientation  : orientation_type;      --use also for angles to object
         next_mission : mission_ptr;
      end record;

procedure Free is new Ada.Unchecked_Deallocation(mission, mission_ptr);
   procedure print_list(this : mission_ptr);
end general;
