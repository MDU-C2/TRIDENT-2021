with Server_net;
with gnat.Sockets; use gnat.Sockets;
with Ada.Text_IO;     use Ada.Text_IO;
with ada.Exceptions;




procedure main is
   streamsocket : Server_net.Connection;
   stream_in:string(1..300) := (others => ' ');
   test : boolean ;
begin

   declare

   begin

--
      Server_net.Open_Server(streamsocket,314);
      Put_Line("{" & '"' & "hej" & '"' & ":2}");

      Server_net.Write_Buffer(streamsocket,"hejhej");
      Put_Line("test");
--
   loop

   Server_net.Read(streamsocket,stream_in,test);
   Put_Line("derp");
   end loop;
   exception

      when gnat.Sockets.Socket_Error =>
         Put_Line("bam");
      when E : others =>
         Put_Line (Ada.Exceptions.Exception_Information (E));
      null;

   end;



   Server_net.Close(streamsocket);

end main;
