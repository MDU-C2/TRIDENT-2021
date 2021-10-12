
with Server_net;
with GNATCOLL;
with gnatcoll.JSON;
with ada.Exceptions; use ada.Exceptions;
with ada.Real_Time; use ada.Real_Time;
with ada.Text_IO;







package tcp_server is

type pConPtr is access Server_net.Connection;

   task type Server_Task(Cx : pConPtr; iThreadNumber : integer) is
   end Server_Task;


   procedure Send_Tcp(Cx : access Server_net.Connection; sBuffer : in string; bSuccess : out Boolean);
   procedure Get_Tcp(Cx : access Server_net.Connection; sBuffer : out string; bSuccess : out Boolean);


end tcp_server;
