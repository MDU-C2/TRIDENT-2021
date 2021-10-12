
---------------------------------------------------------------------------
-- This code handles communication between the message bouncer and a client.

-- Written by Hampus Carlsson for the Naiad AUV project
-- Last changed (yyyy-mm-dd): 2014-11-06
---------------------------------------------------------------------------



with ada.Real_Time; use ada.Real_Time;
with radix;

package body tcp_client is


   Cx : Server_net.Connection;

   tCurrentTime : ada.Real_Time.Time;
   tLastMessageTime : ada.Real_Time.Time := Ada.Real_Time.Clock;

   bValidIP : Boolean;
   sInputIP : string(1 .. 15);
   iInputIPLen : integer := 0;
   iInputPort : integer := -1;
   sSenderName : string (1..3);

   bConnected :Boolean := false;


   task body Client_task is
      xCurTime : Ada.Real_Time.Time := Ada.Real_Time.Clock;
      xInterval :  constant ada.Real_Time.Time_Span :=  ada.Real_Time.Milliseconds(50);
      xSleepTime :  constant ada.Real_Time.Time_Span :=  ada.Real_Time.Milliseconds(1000);
      xWaitForServer : constant ada.Real_Time.Time_Span :=  ada.Real_Time.Milliseconds(5);
      IPingInterval : integer := 0;

      ConnectionFile : ada.Text_IO.File_Type;
      sTargetIp : string(1 .. 15) := (others => ' ');
      iTargetPort : integer := -1;
      bDataAvailable : Boolean := false;
      xPingMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   begin

--        ada.Text_IO.Put_Line(radix.Practical_Radix("bgw")'img);


      while iTargetPort = -1 loop
         while bValidIP = false loop
            xCurTime := Ada.Real_Time.Clock;
            xCurTime := xCurTime + xInterval;
            Delay until(xCurTime);
         end loop;
         declare
         begin
            sTargetIp := (others => ' ');
            sTargetIp(sTargetIp'First .. sTargetIp'First + iInputIPLen - 1) := sInputIP(sInputIP'First .. sInputIP'first + iInputIPLen - 1);
            iTargetPort := iInputPort;
         exception
            when E : others =>
               ada.Text_IO.Put_Line("Failed to store the IP and Port!");
               xCurTime := Ada.Real_Time.Clock;
               xCurTime := xCurTime + xInterval;
               Delay until(xCurTime);
         end;
      end loop;



      -- Enters the infinite loop after a valid IP and port number.
      loop
         declare
            bSucMsg : Boolean := false;
            InitCon : Server_net.Connection;
         begin
            bConnected := false;


            InitCon.Open(ada.Strings.Fixed.trim(sTargetIp, ada.Strings.Right), radix.Practical_Radix("bgw"));
            if InitCon.Is_Connected then
               InitCon.Write_Buffer(sSenderName,bSucMsg);
               bSucMsg := false;
               InitCon.Close;


               tLastMessageTime:= ada.Real_Time.Clock;
               xCurTime := Ada.Real_Time.Clock;
               xCurTime := xCurTime + xWaitForServer;
               Delay until(xCurTime);

               Cx.Open(ada.Strings.Fixed.trim(sTargetIp, ada.Strings.Right) ,iTargetPort);
               if cx.Is_Connected then
                  bConnected := true;
               end if;
               while Cx.Is_Connected loop
                  --                 Server_net.Data_Available(Cx, bDataAvailable);
                  tCurrentTime := ada.Real_Time.Clock;
                  --                 if bDataAvailable then
                  --                    tLastMessageTime := tCurrentTime;
                  --                 end if;
                  xCurTime := xCurTime + xInterval;
                  Delay until(xCurTime);
                  IPingInterval := IPingInterval + 1;
                  if IPingInterval = 20 then
                     IPingInterval := 0;
                     --                    Send(xPingMsg,bSucMsg);
                  end if;

               end loop;

            end if;

            xCurTime := xCurTime + xSleepTime;
            Delay until(xCurTime);

         exception
            when E : others =>
               bConnected := false;
               cx.Close;
               xCurTime := xCurTime + xInterval;
                  Delay until(xCurTime);


         end;
      end loop;

   end Client_task;




   procedure Send(xJson : in GNATCOLL.JSON.JSON_Value;  bSuccess : out Boolean) is
      sBuffer : string(1..Cx.Get_Buffer_Size) :=  (others => ' ');
      tmp : string (1..3);
   begin
      if cx.Is_Connected then

         -- Test to see if sender is set. If it is not, set it as client port name.
         declare
         begin
            tmp := xJson.Get("sender");
         exception
            when others =>
               xJson.Set_Field("sender",sSenderName);
         end;

         -- Moves the json object to a string to send it
         declare
            sHolder : string := GNATCOLL.JSON.Write(xJson);
         begin
            if sHolder'Length > cx.Get_Buffer_Size then
               bSuccess := false;
            else
               sBuffer (1 .. sHolder'Length) := sHolder;
               Cx.Write_Buffer(sBuffer, bSuccess);
            end if;
         end;
      else
         bSuccess := false;
      end if;

   exception
      when E : others =>
         bSuccess := false;
   end Send;




   procedure Get(xJson : out GNATCOLL.JSON.JSON_Value; bSuccess : out Boolean) is
      sBuffer : string (1 .. Cx.Get_Buffer_Size) := (others => ' ');
   begin
      Cx.Read_Buffer(sBuffer, bSuccess);
      if bSuccess = false then
         return;
      end if;

      xJson := GNATCOLL.JSON.Read(sBuffer,"json.errors");
      bSuccess := true;
      tLastMessageTime := tCurrentTime;

   exception
      when E : others =>
         bSuccess := false;
   end Get;



   function TimeWithoutMsg return integer is
   begin
      return (tLastMessageTime - tCurrentTime)/ada.Real_Time.Microseconds(1);
   end TimeWithoutMsg;


   procedure SetTimeout (Seconds : float) is
   begin
      cx.Set_Timeout(Seconds);
   end SetTimeout;


   procedure Set_IP_And_Port (sIP : string; sPort : string) is
      xCurTime : Ada.Real_Time.Time := Ada.Real_Time.Clock;
      xInterval :  constant ada.Real_Time.Time_Span :=  ada.Real_Time.Milliseconds(50);
   begin
      if sIP'Length <= sInputIP'Length then
         sInputIP (sInputIP'First .. sInputIP'First + sIP'Length - 1) := sIP;
         iInputIPLen := sIP'Length;
         iInputPort := radix.Practical_Radix(sPort);
         bValidIP := true;
         sSenderName := sPort;
         while bConnected = false loop
            xCurTime := Ada.Real_Time.Clock;
            xCurTime := xCurTime + xInterval;
            Delay until(xCurTime);
         end loop;
      end if;
   end;
end tcp_client;
