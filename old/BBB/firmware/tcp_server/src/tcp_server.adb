with radix;

package body tcp_server is


   task body Server_Task is

--        xJson : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
--        sPingMsg : String (1..cx.get_buffer_size) := (others => ' ');
--        bPingSuc : Boolean := false;

--        bRecievedMsg : Boolean := false;
--        bSentMsg : Boolean := false;
--        bInit : Boolean := false;

      xCurTime : Ada.Real_Time.Time := Ada.Real_Time.Clock;
      xInterval :  constant ada.Real_Time.Time_Span :=  ada.Real_Time.Milliseconds(100);
      sPortName : string := "   ";
      bSuccess : Boolean := false;
      xInitCon : Server_net.Connection;

   begin

      -- Initial communication with the main thread to know which port it should host on.
      xInitCon.Open_Server(iThreadNumber);
      xInitCon.Accept_Connections;
      xInitCon.Read_Buffer(sPortName, bSuccess);
      xInitCon.Close;


      -- Opens a server on the desired port.
      Cx.Open_Server(Port => radix.Practical_Radix(sPortName), bDisableTimeout => true);

      loop
         declare
         begin
            ada.Text_IO.Put_Line("Waiting - " & sPortName);
            Cx.Accept_Connections;
            ada.Text_IO.Put_Line("Connected - " & sPortName);

            -- Sleeps while connected
            while Cx.Is_Connected loop
               xCurTime := xCurTime + xInterval;
               Delay until(xCurTime);
            end loop;
         exception
            when E : others =>
               Null;
         end;
      end loop;
   end Server_Task;


   procedure Send_Tcp(Cx : access Server_net.Connection;  sBuffer : in string;  bSuccess : out Boolean) is
   begin
      if sBuffer'Length > cx.Get_Buffer_Size then
         bSuccess := false;
      else
         Cx.Write_Buffer(sBuffer, bSuccess);
      end if;
   exception
      when E : others =>
         bSuccess := false;
   end Send_Tcp;



   procedure Get_Tcp(Cx : access Server_net.Connection; sBuffer : out string; bSuccess : out Boolean) is
   begin
      Cx.Read_Buffer(sBuffer, bSuccess);
      bSuccess := true;
   exception
      when E : others =>
         bSuccess := false;
   end Get_Tcp;
end tcp_server;









