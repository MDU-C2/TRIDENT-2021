with Serial_Net;
with GNATCOLL.JSON;
with GNAT.Sockets;
--  with general;
with ada.real_time;
with PID;
--------------------------------------------------------------------------------
-- 		 Recives sns and pth                                          --
--		 on pth : ethid 1 => setDesiredState                          --
--  		          ethid 2 => setDesiredRelativeState                  --
--------------------------------------------------------------------------------
procedure Main is

   --     bb : PID_Utils.byte_arr := (2);
   bNewMessage : boolean := false;
   receivedMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   sender : string (1..3) := "nul";
   tempInt : integer := 0;
begin
   loop
      if bNewMessage then
         bNewMessage := false;
         if sender = "sns" then -- sensor
            PID.currentRoll := receivedMsg.get("roll");
            PID.currentPitch := receivedMsg.get("pitch");
            PID.currentYaw := receivedMsg.get("yaw");
            PID.currentPosX := receivedMsg.get("x");
            PID.currentPosY := receivedMsg.get("y");
            PID.currentPosZ := receivedMsg.get("depth");
         elsif sender = "pth" then --path planner
            tempInt := receivedMsg.get("ethid");
            if tempInt = 1 then
               PID.setDesiredState(x     => receivedMsg.get("x"),
                                   y     => receivedMsg.get("y"),
                                   z     => receivedMsg.get("z"),
                                   roll  => receivedMsg.get("roll"),
                                   pitch => receivedMsg.get("pitch"),
                                   yaw   => receivedMsg.get("yaw"));
            elsif  tempInt = 2 then
               PID.setDesiredRelativeState(x     => receivedMsg.get("x"),
                                           y     => receivedMsg.get("y"),
                                           z     => receivedMsg.get("z"),
                                           roll  => receivedMsg.get("roll"),
                                           pitch => receivedMsg.get("pitch"),
                                           yaw   => receivedMsg.get("yaw"));
            end if;
            PID.Go_To_Desired_Position_And_Orientation;
         end if;
      end if;
   end loop;
end Main;
