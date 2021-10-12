with Server_net;
with GNATCOLL.JSON;
with GNATCOLL;
with ada.Exceptions; use ada.Exceptions;
with tcp_server;
with ada.Text_IO;

package net_com is

   type TcpHandle is private;
   type HandlePnt is access TcpHandle;


   task type ConnectionTask(Handle : HandlePnt) ;
   procedure Main_Loop;

private

   type TcpHandle is record
      Con : tcp_server.pConPtr := new Server_net.Connection;
      bToUser : Boolean := false;
      bToSim : Boolean := false;
      bDisabled : Boolean := false;
      sName : string(1..3) := "   ";
      iThreadNumber : integer := 0;
   end record;


end net_com;
