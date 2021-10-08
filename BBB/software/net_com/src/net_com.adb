with radix;


package body net_com is


   xAllHandles : array (1..20) of HandlePnt := (others => new TcpHandle);
   iUserThreadNumber : integer := 0;
   iSimThreadNumber : integer := 0;
   iNumberOfClients : integer := 0;


   function Get_Target (sBuffer : in string) return string is
      sTarget : string := "NUL";
   begin
      for i in sBuffer'First .. (sBuffer'Last - 12)loop
         if sBuffer(i .. i + 5) = "target" then
            sTarget := sBuffer(i + 9 .. i + 11);
            exit;
         end if;
      end loop;
      return sTarget;
   end Get_Target;
-- Parse the input JSON string to get the desired TCP target.


   procedure Bounce_Message(sBuffer : in string; bSuccess : out Boolean) is

      xJson : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      sTarget : String := "NUL";

   begin
      bSuccess := false;
      sTarget := Get_Target(sBuffer);

      for i in 1.. iNumberOfClients loop
         if sTarget = xAllHandles(i).sName and xAllHandles(i).bDisabled = false then
            tcp_server.Send_Tcp(xAllHandles(i).Con, sBuffer, bSuccess);

            exit;
         elsif  sTarget = "bgw" then
            bSuccess := true;

            declare
            begin
               xJson := GNATCOLL.JSON.Read(sBuffer,"Json Error");
               for j in 1 .. iNumberOfClients loop
                  declare
                  begin
                     -- Sending eathid 2 enables (true) / disables (false) data to stream to the user
                     -- the data should be the names of the data you want e.g. "pid", "msn".
                     if xJson.Get("ethid") = 2 then
                        xAllHandles(j).bToUser := xJson.Get(xAllHandles(j).sName);
                        -- Sending eathid 3 disables (true) / enables (false) data to flow internaly
                        -- the data should be the names of the data you want e.g. "pid", "msn".
                     elsif xJson.Get("ethid") = 3 then
                        xAllHandles(j).bToSim := xJson.Get(xAllHandles(j).sName);

                     elsif xJson.Get("ethid") = 4 then
                        xAllHandles(j).bDisabled := xJson.Get(xAllHandles(j).sName);
                     end if;

                  exception
                     when others =>
                        null;
                  end;
               end loop;
            exception
               when others =>
                  ada.Text_IO.Put_Line("Error in parsing bouncer settings");
            end;
            exit;
         elsif sTarget = "NUL" then
            bSuccess := true;
            ada.Text_IO.Put_Line("PING");
            exit;
         end if;
      end loop;

      --if bSuccess = false then --ludde 160819
         --ada.Text_IO.Put_Line("Failed to send to " & sTarget);
      --end if;
   end Bounce_Message;









   task body ConnectionTask is
      sBuffer : string(1 .. Handle.Con.Get_Buffer_Size);
      bGotNewMsg : Boolean := false;
      bSentNewMsg : Boolean := false;
   begin
      declare
         HostTask : tcp_server.server_task(handle.Con,handle.iThreadNumber);
      begin
         loop
            declare
            begin

               while Handle.Con.is_connected loop
                  bGotNewMsg := false;
                  tcp_server.Get_Tcp(Handle.con, sBuffer, bGotNewMsg);
                  if bGotNewMsg then
                     --ada.Text_IO.Put_Line(sBuffer);
                     Bounce_Message(sBuffer, bSentNewMsg);
                     if Handle.bToUser then
                        tcp_server.Send_Tcp(xAllHandles(iUserThreadNumber).con, sBuffer, bSentNewMsg);
                     end if;
                     if Handle.bToSim then
                        tcp_server.Send_Tcp(xAllHandles(iSimThreadNumber).con, sBuffer, bSentNewMsg);
                     end if;

                  end if;
               end loop;

               -- Sleep while not connected.
               delay(1.0);
            exception
               when others => null;

            end;
         end loop;
      end;
   end ConnectionTask;
   -- This task handles all the incomming messages and sends them to the desired target.




   procedure Main_Loop is

      xMainCon : Server_net.Connection;
      sClientName : string(1 .. 3);
      bSuccess : Boolean := false;

      bPortTaken : Boolean := false;


   begin

      for i in xAllHandles'Range loop
         xAllHandles(i).iThreadNumber := i;
      end loop;
      declare
         Server1 : ConnectionTask(xAllHandles(1));
         Server2 : ConnectionTask(xAllHandles(2));
         Server3 : ConnectionTask(xAllHandles(3));
         Server4 : ConnectionTask(xAllHandles(4));
         Server5 : ConnectionTask(xAllHandles(5));
         Server6 : ConnectionTask(xAllHandles(6));
         Server7 : ConnectionTask(xAllHandles(7));
         Server8 : ConnectionTask(xAllHandles(8));
         Server9 : ConnectionTask(xAllHandles(9));
         Server10 : ConnectionTask(xAllHandles(10));
         Server11 : ConnectionTask(xAllHandles(11));
         Server12 : ConnectionTask(xAllHandles(12));
         Server13 : ConnectionTask(xAllHandles(13));
         Server14 : ConnectionTask(xAllHandles(14));
         Server15 : ConnectionTask(xAllHandles(15));
         Server16 : ConnectionTask(xAllHandles(16));
         Server17 : ConnectionTask(xAllHandles(17));
         Server18 : ConnectionTask(xAllHandles(18));
         Server19 : ConnectionTask(xAllHandles(19));
         Server20 : ConnectionTask(xAllHandles(20));
      begin
         xMainCon.Open_Server(radix.Practical_Radix("bgw"));
         loop
            declare
            begin


--               xMainCon.Open("127.0.0.1",1);
--               xMainCon.Write_Buffer("vsf",bSuccess);
--               xMainCon.Close;
--               iNumberOfClients := iNumberOfClients + 1;
--               xAllHandles(1).sName := "vsf";




               xMainCon.Accept_Connections;
               while xMainCon.Is_Connected loop
                  xMainCon.Read_Buffer(sClientName, bSuccess);
                  for i in xAllHandles'range loop
                     if sClientName = xAllHandles(i).sName then
                        bPortTaken := true;
                        exit;
                     end if;
                  end loop;
                  if bPortTaken = false then
                     iNumberOfClients := iNumberOfClients + 1;
                     if iNumberOfClients <= xAllHandles'Length then
                        xAllHandles(iNumberOfClients).sName := sClientName;
                        if sClientName = "usr" then
                           iUserThreadNumber := iNumberOfClients;
                        elsif sClientName = "sim" then
                           iSimThreadNumber := iNumberOfClients;
                        end if;

                     end if;
                  end if;
                  xMainCon.close;
               end loop;
               if bPortTaken = false then
                  xMainCon.Open("127.0.0.1",iNumberOfClients);
                  xMainCon.Write_Buffer(sClientName,bSuccess);
                  xMainCon.Close;
               end if;

               bPortTaken := false;

            exception
               when E : others =>
                  Null;
            end;
         end loop;
      end;
   end Main_Loop;
end net_com;
