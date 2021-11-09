
package body Path_Planner is

   --     task msgHandler;
   function calculate_distance_to(wanted : General.position_type) return General.position_type;
   function calculate_absolute_distance_to(wanted : General.position_type) return float;
   function movement_splitter(wanted : General.mission) return General.position_type;
   function calculate_Yaw_To (wanted : General.position_type) return float;
--     procedure send_json_to_PID (specs : General.mission_type_list;
--                                 position : General.position_type;
--                                 orientation : General.orientation_type);
   --     procedure Add_New_Coordinates (specs : General.mission_type_list;
   --                                    position : General.position_type;
   --                                    orientation : General.orientation_type);
   --     procedure Add_New_Coordinates_Current (specs : General.mission_type_list;
   --                                            position : General.position_type;
   --                                            orientation : General.orientation_type;
   --                                            finished : Boolean);
   function Are_We_There_Yet return boolean;



   --     task body msgHandler is
   --        bNewMessage : boolean := false;
   --        receivedMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   --        sender : string (1..3);
   --     begin
   --
   --        --readMessage
   --        if bNewMessage then
   --           bNewMessage := false;
   --           sender  := receivedMsg.get("sender");
   --           if sender = "msn" then --if ethid = ? to current or last
   --              Add_New_Coordinates_current(specs       => general.mission_type_list'Val(receivedMsg.get("ethid")),
   --                                          position    => (receivedMsg.get("posx"),receivedMsg.get("posy"),receivedMsg.get("posz")),
   --                                          orientation => (receivedMsg.get("pitch"),receivedMsg.get("roll"),receivedMsg.get("yaw")),
   --                                          finished    => false);
   --              --           Add_New_Coordinates
   --           elsif sender = "pid" then
   --              currentPos.position    := (receivedMsg.get("posx"),receivedMsg.get("posy"),receivedMsg.get("posz"));
   --              currentPos.orientation := (receivedMsg.get("roll"),receivedMsg.get("pitch"),receivedMsg.get("yaw"));
   --           end if;
   --        end if;
   --
   --     end msgHandler;


   function calculate_distance_to(wanted : General.position_type) return General.position_type is
   begin
      return ((wanted.X - currentPos.position.X),(wanted.Y - currentPos.position.Y),(wanted.Z - currentPos.position.Z));
   end calculate_distance_to;


   function calculate_absolute_distance_to(wanted : General.position_type) return float is
   begin
      return General.Math.sqrt((wanted.X - currentPos.position.X)**2 + (wanted.Y - currentPos.position.Y)**2 +(wanted.Z - currentPos.position.Z)**2);
   end calculate_absolute_distance_to;


   function movement_splitter(wanted : General.mission) return General.position_type is
      temp : float;
   begin
      temp := calculate_absolute_distance_to(wanted.position);
      return ( (maxDistance*(wanted.position.X/temp)), (maxDistance*(wanted.position.Y/temp)), (maxDistance*(wanted.position.Z/temp)));
   end movement_splitter;

   function Are_We_There_yet return boolean is
   begin
      if
      abs(currentPos.position.X - wantedPos.position.X)  <= errorLimit and
      abs(currentPos.position.Y - wantedPos.position.Y)  <= errorLimit and
      abs(currentPos.position.Z - wantedPos.position.Z)  <= errorLimit  then
         return true;
      else return false;
      end if;
   end Are_We_There_yet;


--     procedure send_json_to_PID (specs : General.mission_type_list;
--                                 position : General.position_type;
--                                 orientation : General.orientation_type) is
--        use general;
--        use GNATCOLL.JSON;
--        msg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
--     begin
--        if specs = general.go_to_position then
--           msg.Set_Field("ethid", 1);
--        elsif specs = general.go_to_relative_position then
--           msg.Set_Field("ethid", 2);
--        end if;
--        msg.Set_Field("sender", "pth");
--        msg.Set_Field("target", "pid");
--        msg.Set_Field("posx", position.X);
--        msg.Set_Field("posy", position.Y);
--        msg.Set_Field("posz", position.Z);
--        msg.Set_Field("roll", orientation.roll);
--        msg.Set_Field("pitch", orientation.pitch);
--        msg.Set_Field("yaw", orientation.yaw);
--     end send_json_to_PID;



   --     procedure Add_New_Coordinates (specs : General.mission_type_list;
   --                                    position : General.position_type;
   --                                    orientation : General.orientation_type) is
   --        use general;
   --     begin
   --        if movement_list_start = null then
   --           movement_list_start := new mission'((specs, FALSE, position, orientation, null));
   --           movement_list_current := movement_list_start;
   --           movement_list_last := movement_list_start;
   --        else
   --           movement_list_last.next_mission := new mission'((specs, FALSE, position, orientation, null));
   --           movement_list_last := movement_list_last.next_mission;
   --        end if;
   --        General.print_list(movement_list_start);
   --     end Add_New_Coordinates;
   --
   --     procedure Add_New_Coordinates_Current (specs : General.mission_type_list;
   --                                            position : General.position_type;
   --                                            orientation : General.orientation_type;
   --                                            finished : boolean) is
   --        use general;
   --     begin
   --        if movement_list_start = null then
   --           movement_list_start := new mission'((specs, FALSE, position, orientation, null));
   --           movement_list_current := movement_list_start;
   --           movement_list_last := movement_list_start;
   --        else
   --           temp_ptr := movement_list_current.next_mission;
   --           movement_list_current.next_mission := new mission'((specs, FALSE, position, orientation, temp_ptr));
   --           movement_list_current.finished := finished;
   --        end if;
   --        General.print_list(movement_list_start);
   --     end Add_New_Coordinates_current;



   function calculate_Yaw_To (wanted : General.position_type) return float is
   begin
      return General.Math.Arctan((wanted.y-currentPos.position.Y)/(wanted.x - currentPos.position.X));
   end calculate_Yaw_To;






   --     procedure movement is
   --        use general;
   --        errorLimitYaw : float := 15.0;
   --        temp : float;
   --     begin
   --        null;
   --        temp := float(integer(currentPos.orientation.yaw - calculate_Yaw_To(wanted => movement_list_current.position)) mod 360);
   --        if abs(temp) > errorLimitYaw then--rotate towards wanted position
   --           send_json_to_PID(specs       => general.go_to_relative_position,
   --                            position    => nullPosition,
   --                            orientation => (temp, 0.0, 0.0));
   --        elsif Are_We_There_yet then -- if at wanted postion, rotate to wanted orientation
   --           send_json_to_PID(specs       => general.go_to_position,
   --                            position    => movement_list_current.position,
   --                            orientation => movement_list_current.orientation);
   --           if abs(movement_list_current.orientation.yaw - currentPos.orientation.yaw) < errorLimit then
   --              movement_list_current.finished := true;
   --           end if;
   --        else -- if rotated towards destination and not at destination
   --           temp := calculate_absolute_distance_to(wanted => movement_list_current.position);
   --           if temp > maxDistance then --split up movment to not get to high P and I values
   --              send_json_to_PID(specs       => general.go_to_relative_position,
   --                               position    => movement_splitter(wanted => movement_list_current),
   --                               orientation => nullOrentation);
   --           else                       -- within maximum range of wanted position
   --              send_json_to_PID(specs       => general.go_to_position,
   --                               position    => movement_list_current.position,
   --                               orientation => currentPos.orientation);
   --           end if;
   --        end if;
   --     end movement;
   --
   --
   --
   --
   --
   --     procedure main is
   --        use general;
   --        finished : boolean := false;
   --     begin
   --        tcp_client.Set_IP_And_Port(sIP   => "192.168.7.1",
   --                                   iPort => "pth");
   --        tcp_client.SetTimeout(0.0);
   --        loop
   --           while movement_list_current /= null loop
   --              movement;
   --              if movement_list_current.finished then
   --                 if movement_list_current = movement_list_last then
   --                    general.Free(movement_list_current);
   --                    movement_list_current := null;
   --                    movement_list_last    := null;
   --                    movement_list_start   := null;
   --                 else
   --                    temp_ptr := movement_list_current;
   --                    movement_list_current := movement_list_current.next_mission;
   --                    general.free(temp_ptr);
   --                    temp_ptr := null;
   --                 end if;
   --              end if;
   --           end loop;
   --           --add start/home coordinate and go there
   --
   --           Add_New_Coordinates(specs       => General.go_to_position,
   --                               position    => (0.0, 0.0, 0.0),
   --                               orientation => (0.0, 0.0, 0.0));
   --           while not Are_We_There_yet and movement_list_current = movement_list_last  loop
   --              movement;
   --           end loop;
   --        end loop;
   --     end main;









   procedure movement is
      --sSender : string(1..3);
      xJsonIn : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      xJsonOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      bNewMessage : boolean := false;
      bSent : boolean := false;
      -- iEthId : integer;

   begin
      if bCoordinate then
         declare
         begin
            xJsonOut.Set_Field("ethid", 1);
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;

         if calculate_absolute_distance_to(wanted => wantedPos.position) > maxDistance then

            tempPos.position := movement_splitter(wanted => wantedPos);
            declare
            begin
               xJsonOut.Set_Field("posx", tempPos.position.X);
               xJsonOut.Set_Field("posy", tempPos.position.Y);
               xJsonOut.Set_Field("posz", tempPos.position.Z);
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         else
            declare
            begin
               xJsonOut.Set_Field("posx", wantedPos.position.X);
               xJsonOut.Set_Field("posy", wantedPos.position.Y);
               xJsonOut.Set_Field("posz", wantedPos.position.Z);
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         end if;
      else
         declare
         begin
            xJsonOut.Set_Field("ethid", 2);
            xJsonOut.Set_Field("posx", wantedPos.position.X);
            xJsonOut.Set_Field("posy", wantedPos.position.Y);
            xJsonOut.Set_Field("posz", wantedPos.position.Z);
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;
      end if;




      declare
      begin
         xJsonOut.Set_Field("target", "pid"); --pid
         xJsonOut.Set_Field("sender", "pth");

         xJsonOut.Set_Field("roll", wantedPos.orientation.roll);
         xJsonOut.Set_Field("pitch", wantedPos.orientation.pitch);
         xJsonOut.Set_Field("yaw", wantedPos.orientation.yaw);
      exception
         when E : others =>
            Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
      end;
      tcp_client.Send(xJson    => xJsonOut,
                      bSuccess => bSent);

--        Ada.Text_IO.Put_Line("sending to : " & " pid " & " ethid : " & "2");

      xJsonOut := GNATCOLL.JSON.JSON_Null;



   end movement;









   procedure main is
      use Ada.Real_Time;
      sSender : string(1..3);
      xJsonIn : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      xJsonOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      bNewMessage : boolean := false;
      bSent : boolean := false;
      iEthId : integer;
       tTime : Ada.Real_Time.Time;
      tStartTime : Ada.Real_Time.Time;
   begin
      tcp_client.Set_IP_And_Port(sIP   => "127.0.0.1",
                                 sPort => "pth");
      tcp_client.SetTimeout(1.0);
      wantedPos.orientation := nullOrentation;
      wantedPos.position    := nullPosition;
      currentPos := wantedPos;
      loop
             tStartTime := Ada.Real_Time.Clock;
         tcp_client.Get(xJson    => xJsonIn,
                        bSuccess => bNewMessage);
         if bNewMessage then
            declare
            begin
               sSender := xJsonIn.Get(Field => "sender");
               iEthId := xJsonIn.Get(Field => "ethid");
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
                           tTime := Ada.Real_Time.Clock;
--                 Ada.Text_IO.Put_Line("recived from : " & sSender & " ethid : " & iEthId'Img & " at time : "
--                                      & integer'Image((tTime - tStartTime)/Ada.Real_Time.Seconds(1)));
            if sSender = "sns" then
               --sensor update
               declare
               begin
                  currentPos.position.X := xJsonIn.Get(Field => "posx");
                  currentPos.position.Y := xJsonIn.Get(Field => "posy");
                  currentPos.position.Z := xJsonIn.Get(Field => "posz");

                  currentPos.orientation.roll  := xJsonIn.Get(Field => "roll");
                  currentPos.orientation.pitch := xJsonIn.Get(Field => "pitch");
                  currentPos.orientation.yaw   := xJsonIn.Get(Field => "yaw");
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;
               movement;
            elsif sSender = "msn" then
               --update mission/wanted coordinate

               if iEthId = 1 then --set coordinate
                  bCoordinate := true;
               elsif iEthId = 2 then --set speed
                  bCoordinate := false;
               else
                  null; --error in value, handle in someway
               end if;
               declare
               begin
                  wantedPos.position.X := xJsonIn.Get(Field => "posx");
                  wantedPos.position.Y := xJsonIn.Get(Field => "posy");
                  wantedPos.position.Z := xJsonIn.Get(Field => "posz");

                  wantedPos.orientation.roll  := xJsonIn.Get(Field => "roll");
                  wantedPos.orientation.pitch := xJsonIn.Get(Field => "pitch");
                  wantedPos.orientation.yaw   := xJsonIn.Get(Field => "yaw");
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;
               movement;
            else
               --other
               null;
            end if;
         end if;

         --           if Are_We_There_yet then
         --              xJsonOut := GNATCOLL.JSON.JSON_Null;
         --              xJsonOut.Set_Field("target", "msn");
         --              xJsonOut.Set_Field("sender", "pth");
         --              xJsonOut.Set_Field("ethid", "0"); --done
         --              xJsonOut.Set_Field("done", TRUE);
         --              while not bSent loop
         --              tcp_client.Send(xJson    => xJsonOut,
         --                              bSuccess => bSent);
         --              end loop;
         --              bSent := false;
         --           end if;
--           delay 0.0005;
      end loop;

   end main;




end Path_Planner;
