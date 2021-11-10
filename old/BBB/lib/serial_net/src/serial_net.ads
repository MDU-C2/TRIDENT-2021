
with Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;

with GNAT.Sockets; use GNAT.Sockets;

package Serial_Net is

   NetWork_Error : exception; -- all kinds of socket errors

   type Connection is limited private;
   procedure Open(Cx : in out Connection; IP : String; Port : Natural);
   procedure Open_Server (Cx: in out Connection; Port : Natural);

   procedure Close(Cx : in out Connection);

   procedure Write(Cx : in out Connection; C : Character);
   procedure Write(Cx : in out Connection; I : Integer);
   procedure Write(Cx : in out Connection; F : Float);
   procedure Write(Cx : in out Connection; B : Boolean);

--   function Data_Valid (Cx : Connection) return Boolean;

   procedure Read (Cx : in out Connection; C : out Character; Success : out Boolean; Timeout : Duration := 1.0);

   procedure Read (Cx : in out Connection; I : out Integer);
   procedure Read (Cx : in out Connection; I : out Character);
   procedure Read (Cx : in out Connection; F : out Float);
   procedure Read (Cx : in out Connection; B : out Boolean);


   procedure Write_Buffer (Cx : in out Connection; Buffer : String);
   function Stream   (Socket : Connection) return Stream_Access;

private
   type Connection is record

      Address : Sock_Addr_Type;
      Caller : Sock_Addr_Type;
      Socket,server : Socket_Type;
      Channel : Stream_Access;

      Selector : Selector_Type;

      RSet : Socket_Set_Type;
      WSet : Socket_Set_Type;

      Status : Selector_Status;

   end record;

end Serial_Net;
