with Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;


package body marker is
   procedure main(msgIn : in GNATCOLL.JSON.JSON_Value; msgOut : out GNATCOLL.JSON.JSON_Value; cont : out boolean) is
   begin
      cont := false;
      case currentState is
         when 1 =>
            declare
               x : float := msgIn.get("posx");
               y : float := msgIn.get("posy");
               yaw : float := msgIn.get("yaw");
            begin
               if abs(x) < 1.0 and abs(y) < 1.0 then
                  currentState := currentState + 1;
               else
                  msgOut.set_Field("sender", "pth");
                  msgOut.set_Field("target", "pid");
                  msgOut.set_Field("ethid", 2);-- relative positions
                  msgOut.set_Field("posx", x*5.0);
                  msgOut.set_Field("posy", y*5.0);
                  msgOut.set_Field("posz", 0.0);
                  msgOut.set_Field("roll", 0.0);
                  msgOut.set_Field("pitch", 0.0);
                  msgOut.set_Field("yaw", yaw);
               end if;
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when 2 =>
            declare
               yaw : float := msgIn.get("yaw");
            begin
               if abs(yaw) < 3.0 then
                  currentState := currentState + 1;
               else
                  msgOut.set_Field("sender", "pth");
                  msgOut.set_Field("target", "pid");
                  msgOut.set_Field("ethid", 2);-- relative positions
                  msgOut.set_Field("posx", 0.0);
                  msgOut.set_Field("posy", 0.0);
                  msgOut.set_Field("posz", 0.0);
                  msgOut.set_Field("roll", 0.0);
                  msgOut.set_Field("pitch", 0.0);
                  msgOut.set_Field("yaw", yaw);
                  cont := true;
               end if;
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when 3 =>
            declare
               yaw : float := msgIn.get("yaw");
            begin
               msgOut.set_Field("sender", "pth");
               msgOut.set_Field("target", "pid");
               msgOut.set_Field("ethid", 2);-- relative positions
               msgOut.set_Field("posx", -10.0);
               msgOut.set_Field("posy", 0.0);
               msgOut.set_Field("posz", 0.0);
               msgOut.set_Field("roll", 0.0);
               msgOut.set_Field("pitch", 0.0);
               msgOut.set_Field("yaw", yaw);
               finished := true;
               currentState := 1;
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;
         when others => null;
      end case;

   end main;

end marker;
