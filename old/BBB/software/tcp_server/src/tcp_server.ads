--  pragma Profile (Ravenscar);
with Server_net;
--  with json_conversion;
with GNATCOLL;
with gnatcoll.JSON;
--  with GNATCOLL.JSON.Utility;
with ada.Exceptions; use ada.Exceptions;
with ada.Real_Time; use ada.Real_Time;
with ada.Calendar;
with ada.Text_IO;
--  with ada.Calendar;







package tcp_server is

type pConPtr is access Server_net.Connection;


   --     type TcpOutBufferArray is array (Natural range <>) of string(1..256);
   --
   --     TcpOutBuffer : TcpOutBufferArray(1..10);

   --     grek : Json_conversion.json_wrapper


   task type Server_Task(Cx : pConPtr; Port : integer) is
      --        entry Get (Item : out Json_conversion.json_wrapper; Success : out Boolean);
      --        entry Send (Item : in Json_conversion.json_wrapper);
      --        entry Init_Server;
   end Server_Task;


   procedure Send_Tcp(Cx : access Server_net.Connection; sBuffer : in string; bSuccess : out Boolean);
   procedure Get_Tcp(Cx : access Server_net.Connection; sBuffer : out string; bSuccess : out Boolean);



     --
     --     task Fusion_Tcp_in is
     --        entry Get_Fusion_Data (Item : out Json_conversion.json_wrapper; Success : out Boolean);
     --     end Fusion_Tcp_in;

end tcp_server;
