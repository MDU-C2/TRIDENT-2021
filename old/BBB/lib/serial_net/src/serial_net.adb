
package body Serial_Net is

   procedure Open(Cx : in out Connection; IP : String; Port : Natural) is
   begin

      --      Initialize; -- Init the socket package

      Cx.Address.Addr := Inet_Addr(IP);
      Cx.Address.Port := Port_Type(Port);

      Create_Socket(Cx.Socket);
      Connect_Socket(Cx.Socket, Cx.Address);

      Empty(Cx.RSet);
      Empty(Cx.WSet);

      Set(Cx.Rset, Cx.Socket);
      Create_Selector(Cx.Selector);

      Cx.Channel := Stream(Cx.Socket);

   exception when E : others =>
--         Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         raise NetWork_Error;
   end Open;

   procedure Open_Server (Cx: in out Connection; Port : Natural) is
   begin
      Cx.Address.Port := Port_Type(Port);
      Create_Socket(Cx.Server);

      Set_Socket_Option (Cx.Server, Socket_Level, (reuse_Address,True));

      Bind_Socket (Cx.Server,Cx.Address);
      Listen_Socket (Cx.Server);
      Accept_Socket (Cx.Server,Cx.Socket,Cx.Caller);
      Empty(Cx.RSet);
      Empty(Cx.WSet);
      close_Socket (Cx.server);
      Set(Cx.Rset, Cx.Socket);
--      Create_Selector(Cx.Selector);

      Cx.Channel := Stream(Cx.Socket);
   end Open_Server;


   function Data_Valid (Cx : Connection) return Boolean is
   begin
      return not Is_Empty (Cx.Rset);
   end Data_Valid;


   procedure Close (Cx : in out Connection) is
   begin
      Close_Socket(Cx.Socket);
--      Finalize;
   exception when E : others =>
         Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         raise NetWork_Error;
   end Close;


   procedure Write(Cx : in out Connection; C : Character) is
   begin
      Character'Write(Cx.Channel, C);

   exception when E : others =>
         Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         raise NetWork_Error;
   end Write;

   procedure Write (Cx : in out Connection; I : Integer) is
   begin
      Integer'Write (Cx.Channel, I);
   end Write;

   procedure Write (Cx : in out Connection; F : Float) is
   begin
      Float'Write (Cx.Channel, F);
   end Write;

   procedure Write (Cx : in out Connection; B : Boolean) is
   begin
      Boolean'Write (Cx.Channel, B);
   end Write;


   procedure Read(Cx : in out Connection; C : out Character; Success : out Boolean; Timeout : Duration := 1.0) is
   begin

      Check_Selector(Cx.Selector, Cx.RSet, Cx.WSet, Cx.Status, Timeout);

      if Cx.Status /= Expired then
         Character'Read(Cx.Channel, C);
         Success := True;
      else
         Set(Cx.RSet, Cx.Socket);
         Success := False;
      end if;

   exception when E : others =>
         Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         raise NetWork_Error;
   end Read;

   procedure Read (Cx : in out Connection; I : out Integer) is
   begin
      Integer'Read (Cx.Channel, I);
   end Read;
   procedure Read (Cx : in out Connection; I : out Character) is
   begin
      Character'Read (Cx.Channel, I);
   end Read;

   procedure Read (Cx : in out Connection; F : out Float) is
   begin
      Float'Read (Cx.Channel, F);
   end Read;

  procedure Read (Cx : in out Connection; B : out Boolean) is
   begin
      Boolean'Read (Cx.Channel, B);
   end Read;


   procedure Write_Buffer(Cx : in out Connection; Buffer : String) is
   begin

      if Buffer'Length > 0 then
         String'Write(Cx.Channel, Buffer);
      end if;

   exception when E : others =>
         Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         raise NetWork_Error;
   end Write_Buffer;

   function Stream   (Socket : Connection) return Stream_Access is
   begin
      return Socket.Channel;
   end Stream;


begin
     gnat.Sockets.Initialize (Process_Blocking_IO => False);

end Serial_Net;



