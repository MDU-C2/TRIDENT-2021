package body sensor is

   procedure main is
      use Ada.Real_Time;
      sSender : string(1..3);
      bNewMessage : boolean := false;
      xJsonIn : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      xJsonOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      iEthId : integer := 0;
      bSent : boolean := false;
      tTime : Ada.Real_Time.Time;
       tTime1 : Ada.Real_Time.Time;
      tStartTime : Ada.Real_Time.Time;
       tStartTime1 : Ada.Real_Time.Time;

     -- Measure_Value:Float;
      Middle_Value : Float:=0.00;
      X_Last:Float:=0.0;
      X_Middle:Float;
      X_Now:Float;
      --x_error:Float;
     -- accxx:Float;
      y_Last:Float:=0.0;
      y_Middle:Float;
      y_Now:Float;

      Px_Last:Float:=1000.0;
      Px_Middle:Float;
      Px_Now:Float;

      Py_Last:Float:=100.0;
      Py_Middle:Float;
      Py_Now:Float;

      Kgx:Float:=0.00;
      Kgy:Float:=0.00;

      Process_Noise_Q:Float:= 0.01;
      Measure_Noise_R:Float:=0.1;

    --  Measure_Error:Float;
     -- KalmanF_Error:Float;
      middle_velocity : Float := 0.0;
      error_velocity : Float := 0.0;
      velocityx : Float := 0.0;
      velocityy : Float := 0.0;
      distance : Float := 0.0;
      ts:Float:=0.0;
      ave_err:Float:=0.0;
      counterZ : integer := 1;
   begin
     tTime := Ada.Real_Time.Clock;
      tTime1 := Ada.Real_Time.Clock;
      tStartTime := Ada.Real_Time.Clock;
      tStartTime1 := Ada.Real_Time.Clock;
--        tcp_client.Set_IP_And_Port(sIP   => "192.168.1.1",
--                                   sPort => "sns");
      tcp_client.Set_IP_And_Port(sIP   => "192.168.1.1",
                           sPort => "sns");
      tcp_client.SetTimeout(1.0);
      loop
         tcp_client.Get(xJson    => xJsonIn,
                        bSuccess => bNewMessage);
         if bNewMessage then
            bNewMessage := false;



            declare
            begin
               sSender := xJsonIn.get("sender");
               iEthId := xJsonIn.get("ethid");
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;



           -- tTime := Ada.Real_Time.Clock;
--              Ada.Text_IO.Put_Line("recived from : " & sSender & " ethid : " & iEthId'Img & " at time : "
--                                   & integer'Image((tTime - tStartTime)/Ada.Real_Time.Seconds(1)));
	    if sSender = "can" then
--  	       Ada.Text_Io.Put_Line("CARL: sensor.adb: received can " & xJsonIn.get("target"));


               declare
               begin
--                    x := xJsonIn.get("posx");
--                    y := xJsonIn.get("posy");
                  z(counterZ) := xJsonIn.get("posz");
                  counterZ :=  counterZ + 1;
		  if counterZ > maxZCounter then counterZ := 1; end if;
--  		  Z := xJsonIn.get("posz");
                  roll := xJsonIn.get("roll");
                  pitch := xJsonIn.get("pitch");
                  yaw := xJsonIn.get("yaw");
                  accx := xJsonIn.get("accx");
                  accy := xJsonIn.get("accy");
                  accz := xJsonIn.get("accz");
           --       ada.Text_IO.Put_Line("Yollo Z1: " & z'Img);
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;


--                 ada.Text_IO.Put_Line("Yollo Z2: " & z'Img);
--                    X_Middle:= X_Last;
--                    Px_Middle := Px_Last + Process_Noise_Q;
--                    Kgx:= Px_Middle/(Px_Middle + Measure_Noise_R);
--
--                    X_Now := X_Middle + Kgx * (accx - X_Middle);
--                    Px_Now := (1.00 - Kgx) * Px_Middle;
--                    if X_Now<0.0  then
--                       X_Now := X_Now + 1.0E-03;
--                     --  Put_Line("hahahahh");
--                    end if;
--                    if X_Now>0.0  then
--                        X_Now := X_Now - 1.0E-03;
--                    end if;
--
--  --                    Put("After the kalman filter accx value :");
--  --                   Put(X_Now);
--                 tStartTime := Ada.Real_Time.Clock;
--                 velocityx := velocityx + X_Now * 0.000001 * Float((tStartTime - tTime) /ada.Real_Time.Microseconds(1));
--
--                if velocityx < 0.0 then
--                  velocityx:= velocityx + 1.0E-03;
--                 end if;
--
--                if velocityx > 0.0 then
--                     velocityx:= velocityx - 1.0E-03;
--                 end if;
--
--                 if (0.0 < abs(velocityx) and abs(velocityx) < 0.5E-03)  then
--                     velocityx := 0.0;
--                 end if;
--                  if velocityx /= 0.0 and velocityx >0.0 then
--                      velocityx:=velocityx - 0.5E-03;
--                  end if;
--                 if velocityx /= 0.0 and velocityx <0.0 then
--                    velocityx:=velocityx + 0.5E-03;
--                  end if;
--
--                 x:=x + velocityx * 0.000001 * Float((tStartTime - tTime) /ada.Real_Time.Microseconds(1));
--                 tTime := Ada.Real_Time.Clock;
--                 New_Line;
--                 Put_Line("distance x is:"&x'img);
--                 New_Line;
--                 Put_Line("velocityx is:"&velocityx'img);
--                 New_Line;
--
--                 X_Last := X_Now;
--                 Px_Last := Px_Now;
--
--
--                 New_Line;
--                 y_Middle:= y_Last;
--                 Py_Middle := Py_Last + Process_Noise_Q;
--                 Kgy := Py_Middle/(Py_Middle + Measure_Noise_R);
--                 y_Now := y_Middle + Kgy * (accy - y_Middle);
--                 Py_Now := (1.00 - Kgy) * Py_Middle;
--                  if y_Now<0.0  then
--                       y_Now := y_Now + 5.0E-03;
--                     --  Put_Line("hahahahh");
--                    end if;
--                    if y_Now>0.0  then
--                        y_Now := y_Now - 5.0E-03;
--                    end if;
--  --                if (0.0 < abs(y_Now) and abs(y_Now) < 0.0150)  then
--  --                     y_Now := 0.0;
--  --                 end if;
--                   Put("After the kalman filter accy value :");
--                 Put(y_Now);
--                 New_Line;
--                tStartTime1:= Ada.Real_Time.Clock;
--                 velocityy := velocityy + y_Now * 0.000001 * Float((tStartTime1 - tTime1) /ada.Real_Time.Microseconds(1));
--                 Put("velocityy value :");
--                 Put_Line(velocityy'img);
--                if velocityy < 0.0 then
--                 velocityy:= velocityy + 3.55E-03;
--                  end if;
--                if velocityy > 0.0 then
--                    velocityy:= velocityy - 5.0E-03;
--                 end if;
--                 if (0.0 < abs(velocityy) and abs(velocityy) < 3.5E-03)  then
--                     velocityy := 0.0;
--                 end if;
--  --                 if velocityy /= 0.0 and velocityy > 0.0 then
--  --                    velocityy := velocityy - 3.5E-03;
--  --                 end if;
--  --                 if velocityy /= 0.0 and velocityy < 0.0 then
--  --                    velocityy := velocityy + 3.5E-03;
--  --                 end if;
--                 y:=y + velocityy * 0.000001 * Float((tStartTime1 - tTime1) /ada.Real_Time.Microseconds(1));
--                 tTime1 := Ada.Real_Time.Clock;
--                 New_Line;
--                 Put_Line("distance y is:"&y'img);
--                 New_Line;
--                 Put_Line("velocityy is:"&velocityy'img);
--                 New_Line;
--                 y_Last := y_Now;
--                 Py_Last := Py_Now;

               declare
                  midVal : integer := 0;
	       begin
--  		  Ada.Text_Io.Put_Line ("CARL: sensor.adb: main: creating json object " & Z'Img);
                  for i in 1..maxZCounter loop
                     midVal := midVal + z(i);
                  end loop;
                  midVal := midVal / maxZCounter;
                  xJsonOut.set_field("sender", "sns");
                  xJsonOut.set_field("posx", x);
                  xJsonOut.set_field("posy", y);
                  xJsonOut.set_field("posz", midVal);
--  		  XJsonOut.Set_Field ("posz", Z);
		  xJsonOut.set_field ("roll", roll);
                  xJsonOut.set_field("pitch", pitch);
                  xJsonOut.set_field("yaw", yaw);
                  xJsonOut.set_field("ethid", 1);
                  xJsonOut.set_field("target", "pid");
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;

--ada.Text_IO.Put_Line("Yollo Z3: " & z'Img);
               tcp_client.Send(xJson    => xJsonOut,
                               bSuccess => bSent);
              -- xJsonOut.set_field("target", "usr");
               --tcp_client.Send(xJson    => xJsonOut,
                 --              bSuccess => bSent);


               declare
               begin
                  xJsonOut.set_field("target", "pth");
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;

           --    ada.Text_IO.Put_Line("Yollo Z4: " & z'Img);
               tcp_client.Send(xJson    => xJsonOut,
                               bSuccess => bSent);

               xJsonOut := GNATCOLL.JSON.JSON_Null;
               xJsonOut := GNATCOLL.JSON.create_object;

            end if;
         end if;
--           declare
--           begin
--              xJsonOut.set_field("sender", "sns");
--              xJsonOut.set_field("posx", x);
--              xJsonOut.set_field("posy", y);
--              xJsonOut.set_field("posz", z);
--              xJsonOut.set_field("roll", roll);
--              xJsonOut.set_field("pitch", pitch);
--              xJsonOut.set_field("yaw", yaw);
--              xJsonOut.set_field("ethid", 1);
--              xJsonOut.set_field("target", "can");
--           exception
--              when E : others =>
--                 Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
--           end;
--
--
--                 Ada.Text_IO.Put_Line("sending");
--           tcp_client.Send(xJson    => xJsonOut,
--                           bSuccess => bSent);
--
--                 Ada.Text_IO.Put_Line("sent");


--         delay 0.05;
      end loop;
   end main;



end sensor;
