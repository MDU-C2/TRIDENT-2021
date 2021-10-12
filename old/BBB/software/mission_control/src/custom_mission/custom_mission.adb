with Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;


package body custom_mission is
   procedure main(msgIn : in GNATCOLL.JSON.JSON_Value; msgOut : out GNATCOLL.JSON.JSON_Value; cont : out boolean) is
   begin
      Ada.Text_IO.Put_Line("custom mission state = " & currentState'img);
      case currentState is
         when 1 =>
            declare
            begin
               msgOut.set_Field("sender", "pth");
               msgOut.set_Field("target", "pid");
               msgOut.set_Field("ethid", 2);-- relative positions
               msgOut.set_Field("posx", 0.0);
               msgOut.set_Field("posy", 0.0);
               msgOut.set_Field("posz", -0.7);
               msgOut.set_Field("roll", 0.0);
               msgOut.set_Field("pitch", 0.0);
               msgOut.set_Field("yaw", 0.0);
               cont := true;
               currentState := currentState + 1;
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when 2 =>
            delay 10.0;
            declare
            begin
               msgOut.set_Field("sender", "pth");
               msgOut.set_Field("target", "pid");
               msgOut.set_Field("ethid", 2);-- relative positions
               msgOut.set_Field("posx", 0.0);
               msgOut.set_Field("posy", 0.0);
               msgOut.set_Field("posz", 0.0);
               msgOut.set_Field("roll", 0.0);
               msgOut.set_Field("pitch", 0.0);
               msgOut.set_Field("yaw", 0.0);
               cont := true;
               currentState := currentState + 1; --done with this mission so reset incase of wanting to redo the mission sequence
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when 3 =>
            delay 10.0;
            declare
            begin
               msgOut.set_Field("sender", "pth");
               msgOut.set_Field("target", "pid");
               msgOut.set_Field("ethid", 3);-- surface
--                 msgOut.set_Field("posx", 0.0);
--                 msgOut.set_Field("posy", 0.0);
--                 msgOut.set_Field("posz", 0.7);
--                 msgOut.set_Field("roll", 0.0);
--                 msgOut.set_Field("pitch", 0.0);
--                 msgOut.set_Field("yaw", 0.0);
               cont := false;
               currentState := 1; --done with this mission so reset incase of wanting to redo the mission sequence
               finished := True;
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when others => cont := false;
      end case;

   end main;

end custom_mission;
