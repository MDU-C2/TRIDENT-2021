
package body Path_Planner is

   function CalculateDistanceTo(wanted : General.position_type) return General.position_type;
   function CalculateAbsoluteDistanceTo(wanted : General.position_type) return float;
   function MovementSplitter(wanted : General.mission) return General.position_type;
   function CalculateYawTo (wanted : General.position_type) return float;

   function AreWeThereYet return boolean;



   function CalculateDistanceTo(wanted : General.position_type) return General.position_type is
      --Return distance vector in x y z in form of position_type from current to wanted position
   begin
      return ((wanted.X - xCurrentPos.position.X),(wanted.Y - xCurrentPos.position.Y),(wanted.Z - xCurrentPos.position.Z));
   end CalculateDistanceTo;


   function CalculateAbsoluteDistanceTo(wanted : General.position_type) return float is
      --Return distance to wanted position as float
   begin
      return General.Math.sqrt((wanted.X - xCurrentPos.position.X)**2 + (wanted.Y - xCurrentPos.position.Y)**2 +(wanted.Z - xCurrentPos.position.Z)**2);
   end CalculateAbsoluteDistanceTo;


   function MovementSplitter(wanted : General.mission) return General.position_type is
      --scales down movement so that the motors will not go at max speed, which would give problem with balancing etc.
      fTemp : float;
   begin
      fTemp := CalculateAbsoluteDistanceTo(wanted.position);
      return ( (fMaxDistance*(wanted.position.X/fTemp)), (fMaxDistance*(wanted.position.Y/fTemp)), (fMaxDistance*(wanted.position.Z/fTemp)));
   end MovementSplitter;

   function AreWeThereYet return boolean is
      --returns true if position in fErrorLimit range ow wanted position in x y z
   begin
      if
      abs(xCurrentPos.position.X - xWantedPos.position.X)  <= fErrorLimit and
      abs(xCurrentPos.position.Y - xWantedPos.position.Y)  <= fErrorLimit and
      abs(xCurrentPos.position.Z - xWantedPos.position.Z)  <= fErrorLimit  then
         return true;
      else return false;
      end if;
   end AreWeThereYet;


   function CalculateYawTo (wanted : General.position_type) return float is
      --returns in float how much rotation needed to point towards wanted position
   begin
      return General.Math.Arctan((wanted.y-xCurrentPos.position.Y)/(wanted.x - xCurrentPos.position.X));
   end CalculateYawTo;






   procedure Movement is
      xJsonIn : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      xJsonOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      bNewMessage : boolean := false;
      bSent : boolean := false;
   begin
      if bCoordinate then
         declare
         begin
            xJsonOut.Set_Field("ethid", 1);
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;

         if CalculateAbsoluteDistanceTo(wanted => xWantedPos.position) > fMaxDistance then

            xTempPos.position := MovementSplitter(wanted => xWantedPos);
            declare
            begin
               xJsonOut.Set_Field("posx", xTempPos.position.X);
               xJsonOut.Set_Field("posy", xTempPos.position.Y);
               xJsonOut.Set_Field("posz", xTempPos.position.Z);
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         else
            declare
            begin
               xJsonOut.Set_Field("posx", xWantedPos.position.X);
               xJsonOut.Set_Field("posy", xWantedPos.position.Y);
               xJsonOut.Set_Field("posz", xWantedPos.position.Z);
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         end if;
      else
         declare
         begin
            xJsonOut.Set_Field("ethid", 2);
            xJsonOut.Set_Field("posx", xWantedPos.position.X);
            xJsonOut.Set_Field("posy", xWantedPos.position.Y);
            xJsonOut.Set_Field("posz", xWantedPos.position.Z);
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;
      end if;




      declare
      begin
         xJsonOut.Set_Field("target", "pid"); --pid
         xJsonOut.Set_Field("sender", "pth");

         xJsonOut.Set_Field("roll", xWantedPos.orientation.roll);
         xJsonOut.Set_Field("pitch", xWantedPos.orientation.pitch);
         xJsonOut.Set_Field("yaw", xWantedPos.orientation.yaw);
      exception
         when E : others =>
            Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
      end;
      tcp_client.Send(xJson    => xJsonOut,
                      bSuccess => bSent);

      xJsonOut := GNATCOLL.JSON.JSON_Null;



   end Movement;









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
      tcp_client.Set_IP_And_Port(sIP   => "192.168.1.1", --to host
                                 sPort => "pth");
      tcp_client.SetTimeout(1.0);--could be forever, no idea to do anything new if no new data or mission has arrived.
      xWantedPos.orientation := xNullOrientation; --staying still enjoying fresh air is pretty nice to start with
      xWantedPos.position    := xNullPosition;
      xCurrentPos := xWantedPos;
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
            if sSender = "sns" then
               --sensor update
               declare
               begin
                  xCurrentPos.position.X := xJsonIn.Get(Field => "posx");
                  xCurrentPos.position.Y := xJsonIn.Get(Field => "posy");
                  xCurrentPos.position.Z := xJsonIn.Get(Field => "posz");

                  xCurrentPos.orientation.roll  := xJsonIn.Get(Field => "roll");
                  xCurrentPos.orientation.pitch := xJsonIn.Get(Field => "pitch");
                  xCurrentPos.orientation.yaw   := xJsonIn.Get(Field => "yaw");
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;
--                 Movement;--since sensor has been updated we want to update pid
            elsif sSender = "msn" then
               --update mission/wanted coordinate

               if iEthId = 1 then --set coordinate
                  bCoordinate := true;
               elsif iEthId = 2 then --set speed/absolute position(when x-y position implemented)
                  bCoordinate := false;
               else
                  null; --error in value, handle in someway
               end if;
               declare
               begin
                  xWantedPos.position.X := xJsonIn.Get(Field => "posx");
                  xWantedPos.position.Y := xJsonIn.Get(Field => "posy");
                  xWantedPos.position.Z := xJsonIn.Get(Field => "posz");

                  xWantedPos.orientation.roll  := xJsonIn.Get(Field => "roll");
                  xWantedPos.orientation.pitch := xJsonIn.Get(Field => "pitch");
                  xWantedPos.orientation.yaw   := xJsonIn.Get(Field => "yaw");
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;
               Movement;
            else
               --other
               null;
            end if;
         end if;

         --           if AreWeThereYet then
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
