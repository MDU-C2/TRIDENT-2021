with radix;

package body tcp_server is





   --------------------
   -- Fusion_Tcp --
   --------------------
--     TcpHandle : Server_net.Connection;
--     sBuffer : string(1..TcpHandle.Get_Buffer_Size);
--     bNewMsg : Boolean := false;




   task body Server_Task is

      xJson : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      sPingMsg : String (1..cx.get_buffer_size) := (others => ' ');
      bPingSuc : Boolean := false;



      bRecievedMsg : Boolean := false;
      bSentMsg : Boolean := false;
      bInit : Boolean := false;




      xCurTime : Ada.Real_Time.Time := Ada.Real_Time.Clock;
      xInterval :  constant ada.Real_Time.Time_Span :=  ada.Real_Time.Milliseconds(100);




   begin


--        xJson.Set_Field("ethid", 0);
--        sPingMsg(1 .. xJson.Write'Length) := xJson.Write;


      Cx.Open_Server(Port => port, bDisableTimeout => true);
--        Cx.Set_Timeout(Seconds => 0.4);


      loop
         declare

         begin

            ada.Text_IO.Put_Line("Waiting - " & radix.Radical_Pradix(port));
            Cx.Accept_Connections;
            ada.Text_IO.Put_Line("Connected - " & radix.Radical_Pradix(port));
            while Cx.Is_Connected loop



               --                 Cx.Read_Buffer(sBuffer,bRecievedMsg);
--                 cx.Write_buffer(sPingMsg, bPingSuc);



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
--        sBuffer : string(1..Cx.Get_Buffer_Size) :=  (others => ' ');
--        sHolder : string := xJson.Write;
   begin


      if sBuffer'Length > cx.Get_Buffer_Size then
         bSuccess := false;
      else
--           sBuffer (1 .. sHolder'Length) := sHolder;
         Cx.Write_Buffer(sBuffer, bSuccess);
      end if;
   exception
      when E : others =>
         bSuccess := false;


   end Send_Tcp;



   procedure Get_Tcp(Cx : access Server_net.Connection; sBuffer : out string; bSuccess : out Boolean) is
--        sBuffer : string (1 .. Cx.Get_Buffer_Size);
   begin
      Cx.Read_Buffer(sBuffer, bSuccess);
--        xJson := GNATCOLL.JSON.Read(sBuffer,"json.errors");
      bSuccess := true;

   exception
      when E : others =>
         bSuccess := false;


   end Get_Tcp;


end tcp_server;









