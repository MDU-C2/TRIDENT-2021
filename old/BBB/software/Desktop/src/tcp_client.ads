
---------------------------------------------------------------------------
-- This code handles communication between the message bouncer and a client.

-- Written by Hampus Carlsson for the Naiad AUV project
-- Last changed (yyyy-mm-dd): 2014-11-06
---------------------------------------------------------------------------





with Server_net;
with GNATCOLL;
with GNATCOLL.JSON;
with ada.Text_IO;
with ada.strings.Fixed;


package tcp_client is
-- Including this package will create a thread that will try to establish
-- a connection to the desired IP and port stated with the Set_IP_And_Port procedure.
-- Format is "X.X.X.X", "Y"
-- where X is 0 - 255 and Y 0 - 65536
-- You can only run one instance of this for each executable.

   task Client_task is
   end Client_task;



   procedure Send(xJson : in GNATCOLL.JSON.JSON_Value; bSuccess : out Boolean);
   -- Converts the JSON object into a string of 256 bytes and sends
   -- it to the TCP socket. The boolean will be false if the procedure
   -- is unsuccessful. This procedure will block if the receiver TCP buffer is full.

   procedure Get(xJson : out GNATCOLL.JSON.JSON_Value; bSuccess : out Boolean);
   -- Gets the latest TCP package and converts it to a JSON object.
   -- The boolean returns false when there is no message available or if the connection
   -- is broken.

   function TimeWithoutMsg return integer;
   -- Returns the number of miliseconds the buffer have been empty.
   -- Only got 50 ms resolution.

   procedure SetTimeout (Seconds : float);
   -- Sets the timeout duration. "Get" will wait this long for a message
   -- before returning if there is no message. Can be set to 0.0.

   procedure Set_IP_And_Port (sIP : string; iPort : string);
   -- Sets the IP and Port to connect to. The client will not try to connect before
   -- this is set.
   -- Format is "X.X.X.X", Y
   -- where X is 0 - 255 and Y 0 - 65536





end tcp_client;
