with Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;
with GNATCOLL.JSON;

package first_gate is
   procedure main(msgIn : in GNATCOLL.JSON.JSON_Value; msgOut : out GNATCOLL.JSON.JSON_Value; cont : out boolean);
   currentState :integer := 1;
   finished : boolean := false;
end first_gate;
