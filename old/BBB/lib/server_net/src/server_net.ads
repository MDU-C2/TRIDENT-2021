
---------------------------------------------------------------------------
-- This code is a wrapper for TCP communication.
-- The code is based on serial_net from the VASA project

-- Written by Hampus Carlsson for the Naiad AUV project
-- Last changed (yyyy-mm-dd): 2014-11-06
---------------------------------------------------------------------------




with Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;

with GNAT.Sockets; use GNAT.Sockets;

package Server_net is




   NetWork_Error : exception; -- all kinds of socket errors
   ServerCrach_Error : exception; -- For bad descriptor


   type Connection is tagged limited private;
   -- This type is what all the functions use in this pacakge.
   -- It contains information about the connection.


   procedure Open(Cx : in out Connection; IP : String; Port : Natural);
   --  Opens a connection to a server from this client.
   --  Raises NetWork_Error on exception.


   procedure Open_Server (Cx: in out Connection; Port : Natural; bDisableTimeout: in Boolean := false);
   --  Creates a server socket and binds the socket with default options.
   --  Set bUseTimeout to true to enable timeout.

   procedure Accept_Connections(Cx: in out Connection);
   --  Waits for a incomming connection. This will only timeout if bUseTimeout is
   --  set to true when calling Open_Server.

   Function Is_Connected (Cx :in Connection) return boolean;
   --  WARNING FUNCTION IS FULLY IMPLEMENTED --


   procedure Close(Cx : in out Connection);
   --  Closes the sockets.
   --  Required to free the recource after the connection is closed.

   function Get_Buffer_Size(Cx : in Connection) return integer;
   --  Returns the total buffer size

   procedure Set_Timeout(Cx : in out Connection; Seconds : in float);
   --  Sets the timeout time in seconds for the Accept_Connections
   --  (when bUseTimeout is true) and the string buffer read function, Read.
   --  A negative value will disable the timeout.

   procedure Write(Cx : in out Connection; C : Character);
   --  Writes a single character to the stream that is binded to the socket.

   procedure Write(Cx : in out Connection; I : Integer);
   --  Writes a single integer to the stream that is binded to the socket.

   procedure Write(Cx : in out Connection; F : Float);
   --  Writes a single float to the stream that is binded to the socket.

   procedure Write(Cx : in out Connection; B : Boolean);
   --  Writes a single boolean to the stream that is binded to the socket.


--   function Data_Valid (Cx : Connection) return Boolean;

   procedure Read (Cx : in out Connection; C : out Character; Success : out Boolean; Timeout : Duration := 1.0);
   procedure Read (Cx : in out Connection; I : out Integer);
   procedure Read (Cx : in out Connection; I : out Character);
   procedure Read (Cx : in out Connection; F : out Float);
   procedure Read (Cx : in out Connection; B : out Boolean);

   procedure Read_Buffer (Cx : in out Connection; buffer : in out string; Success : out Boolean);
   --  Reades an entire string from the socket in the connection.
   --  This will always timeout if there is no message to read.
   --  The timeout time can be set with Set_Timeout.
   --  Recomended to use connection.BufferSize as size of the buffers.



   procedure Write_Buffer (Cx : in out Connection; Buffer : in String; Success : out Boolean);
   --  Writes an entire string to the socket.
   --  Recomended to use connection.BufferSize as size of the buffers.

   procedure Set_Buffer_Size(Cx : in Connection; Bytes : in integer);
   --  Just sets a variable to be used when deciding the size of a string used for a buffer.

    procedure Data_Available(Cx : in out Connection; Available : in out Boolean);
   -- Returns true if it is some data available in the TCP buffer.

   function Stream   (Socket : Connection) return Stream_Access;


private
   type Connection  is tagged limited record

      Address : Sock_Addr_Type := No_Sock_Addr;
      Caller : Sock_Addr_Type := No_Sock_Addr;
      Socket,server : Socket_Type := No_Socket;
      Channel,channel2: Stream_Access;

      Selector : Selector_Type;

      RSet : Socket_Set_Type;
      WSet : Socket_Set_Type;
      ESet : Socket_Set_Type;

      Status : Selector_Status;

      timeout: Selector_Duration:= 0.4;
      BufferSize : Natural := 256;
      EnableTimeout : Boolean := true;
      Connected : Boolean := false;

   end record;

end Server_net;
