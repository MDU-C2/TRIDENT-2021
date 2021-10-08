with Path_Planner;
package body Mission_control is
   procedure Get_New_Mission;
   procedure Get_New_Action;



   procedure Get_New_Mission is
      use Mission_Control_Utils;
   begin

      --fetch if new, add to linked list

               temp_mission := (Mission_Control_Utils.mission_type_list'val(receivedMsg.Get("mission_type")),
                                false,
                                (receivedMsg.Get("px"),receivedMsg.Get("py"), receivedMsg.Get("pz")),
                                (receivedMsg.Get("or"),receivedMsg.Get("op"), receivedMsg.Get("oy")),
                                null);
      if mission_list_start = null then
         mission_list_start := new mission'(temp_mission);
         mission_list_current := mission_list_start;
         mission_list_last := mission_list_start;
         Mission_Control_Utils.print_list(mission_list_start);
      else
         mission_list_last.next_mission := new mission'(temp_mission);
         mission_list_last := mission_list_last.next_mission;
         Mission_Control_Utils.print_list(mission_list_start);
      end if;
   end Get_New_Mission;


   procedure get_new_Action is
      use Mission_Control_Utils;
   begin
      --action := receivedMsg.Get("action");
      case action is
      when release_marker =>
         Mission_Handler.sendServerMessage(ethId    => 0,
                                           canId    => 404,--set
                                           extended => false); --send can messages for each
      when fire_torpedo =>
         Mission_Handler.sendServerMessage(ethId    => 0,
                                           canId    => 404,--set
                                           extended => false);
      when close_grip =>
         Mission_Handler.sendServerMessage(ethId    => 0,
                                           canId    => 404,--set
                                           extended => false);
      when open_grip =>
         Mission_Handler.sendServerMessage(ethId    => 0,
                                           canId    => 404,--set
                                           extended => false);
      when others => null;
      end case;


   end Get_New_Action;



   procedure main is
      use Mission_Control_Utils;
      finished : boolean := false;
   begin
      while not finished loop
         Get_New_mission;
         --     if New_action then
         --        Get_New_Action;
         --     end if;

         case mission_list_current.mission_type is
         --when find_light     => mission_list_current.finished := find_lost_object(this => mission_list_current);
         when follow_light   => mission_list_current.finished := follow_light(this => mission_list_current);
         when others         =>  NULL;
         end case;
         if mission_list_current.finished then
            mission_list_current := mission_list_current.next_mission;
         end if;


         if mission_list_current = mission_list_last then
            finished := true;
            null;
         end if;
      end loop;

   end main;







--     function find_lost_object (this : Mission_Control_Utils.mission_ptr) return boolean is
--        use Ada.Real_Time;
--     begin
--        if ada.Real_Time.Clock >= Mission_Control.last_time_object_seen + ada.Real_Time.Seconds(1) then
--           Path_Planner.Add_New_Coordinates(Mission_Control_Utils.go_to_position,
--                                            false,
--                                            (0.0, 0.0, 0.1), --find better values
--                                            (0.0, 0.0, 5.0),
--                                            null);
--        else
--           if Mission_Control.Object_last_seen_information.orientation.yaw > PID.currentYaw then
--              PID.setDesiredRelativeState(x     => 0.0,
--                                          y     => 0.0,
--                                          z     => 0.0,
--                                          roll  => 0.0,
--                                          pitch => 0.0,
--                                          yaw   => 10.0); -- - ?
--           else
--              PID.setDesiredRelativeState(x     => 0.0,
--                                          y     => 0.0,
--                                          z     => 0.0,
--                                          roll  => 0.0,
--                                          pitch => 0.0,
--                                          yaw   => 10.0); -- + ?
--           end if;
--        end if;
--        return false; -- fix
--     end find_lost_object;



   function follow_light (this : Mission_Control_Utils.mission_ptr) return boolean is
   begin
      Path_Planner.Add_New_Coordinates(specs       => Mission_Control_Utils.go_to_relative_position,
                                       position    => (0.0, 0.0, -this.position.X*Mission_Control_Utils.Math.Sin(this.orientation.pitch)),
                                       orientation => (0.0, 0.0, this.orientation.yaw));
--        Mission_Control.Object_last_seen_information.position := (0.0, 0.0, Path_Planner.PID.currentPosZ-this.position.X*Mission_Control_Utils.Math.Sin(this.orientation.pitch));
--        Mission_Control.Object_last_seen_information.orientation := (0.0, 0.0, PID.currentYaw+this.orientation.yaw);
      Mission_Control.Object_last_seen_information.finished := TRUE; -- object seen;
      Mission_Control.last_time_object_seen := ada.Real_Time.Clock;
      return Path_Planner.Are_We_There_Yet;
   end follow_light;



--     function go_to_position (this : Mission_Control_Utils.mission_ptr) return boolean is
--        temp : Mission_Control_Utils.position_type;
--     begin
--        desiredPosition := this.position;
--        if calculate_absolute_distance_to(this.position) > maxDistance then
--           --breakdown to smaller movement to make more stable path.
--           temp := movement_splitter(this);
--           PID.setDesiredState(x     => temp.X,
--                               y     => temp.Y,
--                               z     => temp.Z,
--                               roll  => this.orientation.roll,
--                               pitch => this.orientation.pitch,
--                               yaw   => this.orientation.yaw);
--        else
--           PID.setDesiredState(x     => this.position.X,
--                               y     => this.position.Y,
--                               z     => this.position.Z,
--                               roll  => this.orientation.roll,
--                               pitch => this.orientation.pitch,
--                               yaw   => this.orientation.yaw);
--        end if;
--        return Are_We_There_Yet;
--     end go_to_position;


end Mission_Control;
