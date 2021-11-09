with Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;

package body first_gate_qualification is
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
               msgOut.set_Field("posz", 1.0);
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
               msgOut.set_Field("posx", -10.0);
               msgOut.set_Field("posy", 0.0);
               msgOut.set_Field("posz", 1.5);
               msgOut.set_Field("roll", 0.0);
               msgOut.set_Field("pitch", 0.0);
               msgOut.set_Field("yaw", 0.0);
               cont := false;
               currentState := 1; --done with this mission so reset incase of wanting to redo the mission sequence

            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
--           when 3 =>
--              declare
--                 x : float := msgIn.get("posx");
--                 y : float := msgIn.get("posy");
--                 yaw : float := msgIn.get("yaw");
--                 s : string(1..3) := msgIn.get("sender");
--              begin
--              if s = "vsb" then
--                 if abs(yaw) < 3.0 then
--                    msgOut.set_Field("sender", "pth");
--                    msgOut.set_Field("target", "pid");
--                    msgOut.set_Field("ethid", 2);-- relative positions
--                    msgOut.set_Field("posx", -10.0);
--                    msgOut.set_Field("posy", 0.0);
--                    msgOut.set_Field("posz", 0.0);
--                    msgOut.set_Field("roll", 0.0);
--                    msgOut.set_Field("pitch", 0.0);
--                    msgOut.set_Field("yaw", yaw);
--                    currentState := 1;
--                    finished := True;
--                 else
--                    msgOut.set_Field("sender", "pth");
--                    msgOut.set_Field("target", "pid");
--                    msgOut.set_Field("ethid", 2);-- relative positions
--                    msgOut.set_Field("posx", x);
--                    msgOut.set_Field("posy", y);
--                    msgOut.set_Field("posz", 0.0);
--                    msgOut.set_Field("roll", 0.0);
--                    msgOut.set_Field("pitch", 0.0);
--                    msgOut.set_Field("yaw", yaw);
--                    end if;
--                    cont := false;
--                 end if;
--              end;
         when others => cont := false;
      end case;
   end main;

end first_gate_qualification;
