with Ada.Text_IO; use Ada.Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
with PID_Utils;
with Serial_Net;


procedure test is
   con : Serial_Net.Connection;
   tmp_arr : PID_Utils.byte_arr (1..6) := (128,128,128,128,128,128);
   c : Integer := 0;
begin
   --     Serial_Net.Open(con,"127.0.0.1",314);

   Serial_Net.Open(con,"192.168.1.1",315);

   loop
      Ada.Text_IO.Put_Line("Motor %:" & c'Img);

      PID_Utils.Send_Server_Message(ethId => 0,
                                  canId => 623,
                                  extended => false,
                                  b => 0 + c * 10);

      for i in 1..6 loop
         tmp_arr(i) := 150;

         PID_Utils.Send_Server_Message(ethId => 0,
                                     canId => 616,
                                     extended => false,
                                     b => tmp_arr);

         tmp_arr := (128,128,128,128,128,128);
         delay(1.0);
      end loop;

      if c >= 5 then
         exit;
      end if;

      c := c + 1;
   end loop;

--     loop
--        for i in 1..6 loop
--           tmp_arr(i) := tmp_arr(i) + 1;
--        end loop;
--
--        PID_Utils.Send_Server_Message(ethId => 0,
--                                    canId => 616,
--                                    extended => false,
--                                    b => tmp_arr);
--
--        Ada.Text_IO.Put_Line("Motor value:" & tmp_arr(1)'Img);
--        delay(2.0);
--
--        if tmp_arr(1) >= 170 then
--           exit;
--        end if;
--     end loop;

--       Serial_Net.Write_Buffer(con,"{'b1':1, 'b2':2, 'b3':3, 'b4':4, 'b5':5, 'b6':6, 'size':6, 'unique':0, 'extended':false, 'ethId':0, 'canId':616}"); --SERVER
--  Serial_Net.Write_Buffer(PID_Utils.con,""); --SERVER

--  Serial_Net.Write(PID_Utils.con,'y'); --SERVER

--     PID_Utils.Send_Server_Message(ethId => 0,
--                                 canId => 616,
--                                 extended => false,
--                                 b => (1,2,3,4,5,6));

end test;
