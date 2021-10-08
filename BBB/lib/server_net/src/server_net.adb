
---------------------------------------------------------------------------
-- This code is a wrapper for TCP communication.
-- The code is based on serial_net from the VASA project

-- Written by Hampus Carlsson for the Naiad AUV project
-- Last changed (yyyy-mm-dd): 2014-11-06
---------------------------------------------------------------------------

package body Server_net is








   procedure Open(Cx : in out Connection; IP : String; Port : Natural) is
   begin



      Cx.Address.Addr := Inet_Addr(IP);
      Cx.Address.Port := Port_Type(Port);


      Create_Socket(Cx.Socket);
      GNAT.Sockets.Set_Socket_Option
        (Socket => Cx.Socket,
         Option => (Name    => GNAT.Sockets.Keep_Alive, Enabled => true));

      Connect_Socket(Cx.Socket, Cx.Address);


      Empty(Cx.RSet);
      Empty(Cx.WSet);

      Set(Cx.Rset, Cx.Socket);
      Create_Selector(Cx.Selector);
      Cx.Channel := Stream(Cx.Socket);
      Cx.EnableTimeout := false;
      Cx.Connected := true;


   exception
      when E : others =>
         if "[111] Connection refused" = Exception_Message(E) then
            Ada.Text_IO.Put_Line("No host found!");
            Close_Socket(cx.Socket);

         else
            Close_Socket(cx.Socket);
            Cx.Connected := false;
            Ada.Text_IO.Put_Line("Error in Open");
            Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         end if;

   end Open;



   procedure Open_Server (Cx: in out Connection; Port : in Natural; bDisableTimeout: in Boolean := false) is
   begin

      Cx.Address.Port := Port_Type(Port);
      Create_Socket(Cx.Server);
      Set_Socket_Option (Cx.Server, Socket_Level, (reuse_Address,True));


      GNAT.Sockets.Set_Socket_Option
        (Socket => Cx.Server,
         Option => (Name    => GNAT.Sockets.Keep_Alive, Enabled => true));


      --  Enables timeout
      if bDisableTimeout then
         cx.EnableTimeout := false;
--           GNAT.Sockets.Set_Socket_Option
--             (Socket => Cx.Server,
--              Option => (Name    => GNAT.Sockets.Receive_Timeout, timeout =>cx.timeout));
      else
         cx.EnableTimeout := true;
      end if;

      Bind_Socket (Cx.Server,Cx.Address);
      Listen_Socket (Cx.Server);


   exception
      when E : others =>
         if "[13] Permission denied" = Exception_Message(E) then
            Ada.Text_IO.Put_Line("Permission denied, missing sudo!");
         else
            ada.Text_IO.Put_Line("Could not start the server");
            Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         end if;

         loop
            delay(5.0);
         end loop;


   end Open_Server;


   procedure Accept_Connections(Cx: in out Connection) is

   begin

      Cx.Connected := false;
      Accept_Socket (Cx.Server,Cx.Socket,Cx.Caller);

      Empty(Cx.RSet);
      Empty(Cx.WSet);
      Set(Cx.Rset, Cx.Socket);
      Create_Selector(Cx.Selector);
      Cx.Channel := Stream(Cx.Socket);
      Cx.Connected := true;

   exception
      when E : others =>
         null;

      end Accept_Connections;


   function Data_Valid (Cx : Connection) return Boolean is
   begin
      return not Is_Empty (Cx.Rset);
   end Data_Valid;


   procedure Close (Cx : in out Connection) is
      use ada.Exceptions;
   begin

      cx.Connected := false;
      Empty(cx.RSet);
      Empty(cx.WSet);
      Close_Selector(cx.Selector);
      Close_Socket(Cx.Socket);


   exception
      when E : others =>

         Ada.Text_IO.Put_Line("Error in closing the socket");
         Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));

--           ada.Text_IO.Put_Line(Exception_Identity(E));
--           if "[9] Bad file descriptor" = Exception_Message(E) then
--              raise ServerCrach_Error;
--           else
--              raise NetWork_Error;
--           end if;

   end Close;


   function Get_Buffer_Size(Cx : in Connection) return integer is
   begin
      return cx.BufferSize;
   end Get_Buffer_Size;

   procedure Set_Timeout(Cx : in out Connection; seconds : float) is
   begin


      if seconds < 0.0 then
         ada.Text_IO.Put_Line("Can't have a negative timeout, using old value: " & cx.timeout'img);
      else
         cx.timeout := Selector_Duration(seconds);
--           cx.EnableTimeout := true;
      end if;


   end Set_Timeout;


   Function Is_Connected (Cx :in Connection) return boolean is
   begin

      return cx.Connected;

   end Is_Connected;






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


   procedure Write_Buffer(Cx : in out Connection; Buffer : in String; Success : out Boolean) is
   begin
      Success := false;

      if cx.Connected then
         if Buffer'Length > 0 then
            String'Write(Cx.Channel, Buffer);
            Success := true;
         end if;
      end if;

   exception when E : others =>
         Success := false;
         cx.Connected := false;
         Ada.Text_IO.Put_Line("Error in writing buffer to TCP");
         Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         cx.close;
         if "[9] Bad file descriptor" = Exception_Message(E) then
            raise ServerCrach_Error;
         else
            raise NetWork_Error;
         end if;

   end Write_Buffer;






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
         cx.Connected := false;
         Ada.Text_IO.Put_Line("Error in reading from TCP");
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



   procedure Read_buffer(Cx : in out Connection; buffer : in out string; Success : out Boolean) is
   begin

      Success := False;
      if cx.Connected then
         Empty(cx.RSet);
         set(cx.RSet,cx.Socket);
         Empty(Cx.ESet);
         if cx.EnableTimeout then
            Check_Selector(Cx.Selector, Cx.RSet, Cx.ESet, Cx.Status, cx.timeout);
            if Cx.Status /= Expired then
               string'Read(Cx.Channel, buffer);
               Success := True;
            end if;
         else
            string'Read(Cx.Channel, buffer);
            Success := True;
         end if;
      end if;


   exception
      when E : others =>
         Success := false;

         Ada.Text_IO.Put_Line("Error in reading buffer from TCP");
         if cx.Connected then
            Close_Selector(Cx.Selector);
         end if;

         cx.Connected := false;
         Ada.Text_IO.Put_Line("Exception: " & Exception_Name(E) & ": " & Exception_Message(E));
         if "[9] Bad file descriptor" = Exception_Message(E) then
            raise ServerCrach_Error;
         else
            raise NetWork_Error;
         end if;

   end Read_buffer;


   procedure Set_Buffer_Size(Cx : in Connection; Bytes : in integer) is

   begin
      if Bytes > 0 then
         Null;
      end if;

   end Set_Buffer_Size;


   procedure Data_Available(Cx : in out Connection; Available : in out Boolean) is
      nullSet : Socket_Set_Type;
   begin

      Empty(nullSet);
      Check_Selector(Cx.Selector, Cx.RSet, nullSet, Cx.Status, cx.timeout);
      if cx.Status /= Expired then
         Available := true;
      else
         Available := false;
      end if;
   end Data_Available;


   function Stream   (Socket : Connection) return Stream_Access is
   begin
      return Socket.Channel;
   end Stream;


--  begin
--       gnat.Sockets.Initialize (Process_Blocking_IO => False);

end Server_net;
