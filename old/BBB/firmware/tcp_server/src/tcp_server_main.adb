with net_com;
with Server_net;
with ada.Text_IO;
with ada.Real_Time; use ada.Real_Time;

procedure main is

   xCurTime : Ada.Real_Time.Time := Ada.Real_Time.Clock;


   Interval :  constant ada.Real_Time.Time_Span :=  ada.Real_Time.Milliseconds(500);

   type con is access server_net.Connection ;
   type con2 is access server_net.Connection ;

--     hej : con;
--     hej1 : con;
--
--     grek : tcp_server.server_task(1, hej);
--     grek1 : tcp_server.server_task(2, hej1);

begin









   loop

      xCurTime := ada.Real_Time.Clock;
      xCurTime := xCurTime + Interval;
--        ada.Text_IO.Put_Line("yey");

      Delay until(xCurTime);


   end loop;



--     task grek is
--     end grek;
--
--     con : Boolean := false;
--     con1 : Boolean := false;
--
--     task body grek is
--        test1 : Server_net.Connection;
--     begin
--        loop
--        if con then
--           test1.Open("192.168.42.70",3);
--              --           ada.Text_IO.Put_Line("YAA!");
--              loop
--                 if con1 then
--                    test1.Write_Buffer("hej!");
--                    con := False;
--                    exit;
--
--              end if;
--           end loop;
--
--           end if;
--
--
--        end loop;
--
--     end grek;
--
--     test : Server_net.Connection;
--     buffer : string(1..4);
--     yey : Boolean;
--  begin
--
--
--     test.open_server(3);
--     ada.Text_IO.Put_Line("open");
--     con := true;
--     test.Accept_Connections;
--     ada.Text_IO.Put_Line("con!");
--     con1 := true;
--
--     test.Set_Timeout(0.0);
--
--     delay(2.0);
--
--     test.Read_Buffer(buffer, yey);
--     ada.Text_IO.Put_Line(buffer);
--     test.Close;


end main;
