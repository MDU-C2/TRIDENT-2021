with Ada.Text_IO;

package body Mission_Control_Utils is


   procedure print_list(this : mission_ptr) is
   temp : mission_ptr;
   begin
      temp := this;
      while temp/=null loop
            Ada.Text_IO.Put_Line(mission_type_list'Image(temp.mission_type) & ' ' &
                                   boolean'Image(temp.finished) & " " &
                                   float'Image(temp.position.x) & " " & float'Image(temp.position.y) & " " & float'Image(temp.position.z) & " " &
                                   float'Image(temp.orientation.roll) & " " & float'Image(temp.orientation.pitch) & " " & float'Image(temp.orientation.yaw));
                                   temp := temp.next_mission;
      end loop;
   end print_list;


end Mission_Control_Utils;
