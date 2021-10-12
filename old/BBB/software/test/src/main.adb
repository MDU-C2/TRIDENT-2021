with Server_net;

procedure main is

   Cx : Server_net.Connection;
begin
   Cx.Open_Server(10,true);

   cx.Accept_Connections;

end;
