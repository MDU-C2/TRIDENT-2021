with Ada.Real_Time;
with Ada.Text_IO;
with Ada.Float_Text_IO;

with MotionControl.Dispatcher;
with MotionControl.Thrusters;
with MotionControl.PID_Controller;

with Math.Matrices;
with Math.Vectors;
with Math.Angles;

with PID;

--Added
with Serial_Net;
with GNATCOLL.JSON;
with Ada.IO_Exceptions;
with GNAT.Sockets;

--ETHERNET IDS--
--0: Messages that will be sent to the CAN-bus
--1: Acc-data
--1: Gyro-data
--1: Roll Pitch Yaw-data

procedure Main is
   use Ada.Real_Time;
   use Math.Matrices;
   use Math.Vectors;

   fDeltaTime : float := 0.0;
   xTimeStart : Ada.Real_Time.Time := Ada.Real_Time.Clock;
   xTimeStop : Ada.Real_Time.Time;
   xTimeSpan : Ada.Real_Time.Time_Span := Ada.Real_Time.Time_Span_Zero;
   iMilliSeconds : integer;

   tfThrusterValues : MotionControl.Thrusters.TThrusterValuesArray;
   --pxDispatcher : MotionControl.Dispatcher.pCDispatcher;

   xPosition : Math.Vectors.CVector;
   xVelocity : Math.Vectors.CVector;
   xAcceleration : Math.Vectors.CVector;
   xWantedPosition : Math.Vectors.CVector;

   xOrientation : Math.Matrices.CMatrix;
   xWantedOrientation : Math.Matrices.CMatrix;
   xMatrixMultiplier : Math.Matrices.CMatrix;

   --Server settings--
   con : Serial_Net.Connection; --SERVER
   read_c : Character := 'b';
   raw_imu_data : String (1..256);
   space_filler : String (1..256) := (others => ' ');
   str_iterator : Integer;

   loopCounter : Integer := 0;
   nrOfLoops : Integer := 5;

   --JSON--
   receivedMsg : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   thrusterMsgToSend : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   jsonObj : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   newPidArray : PID.pidArray (1..6);

   --Accelerometer--
   ethId : Integer := 0;
   accX : Float := 0.0;
   accY : Float := 0.0;
   accZ : Float := 0.0;
   gyrX : Float := 0.0;
   gyrY : Float := 0.0;
   gyrZ : Float := 0.0;
   roll : Float := 0.0;
   pitch : Float := 0.0;
   yaw : Float := 0.0;
   depth : Integer := 0;

   counter : Integer := 0;



   newPidScalings : MotionControl.PID_Controller.TPIDComponentScalings := (0.0,0.0,0.0);
   testPidScalings : MotionControl.PID_Controller.TPIDComponentScalings := (0.0,0.0,0.0);

begin

--     test_jsonObj.Set_Field("accX",13);
--     test_jsonObj.Set_Field("accY",37);
--     test_jsonObj.Set_Field("accZ",1337);
--
--     Ada.Text_IO.Put_Line(test_jsonObj.Write);

   xPosition := Math.Vectors.xCreate(fX => 0.0,
                                     fY => 0.0,
                                     fZ => 0.0);
   xWantedPosition := Math.Vectors.xCreate(fX => 0.0,
                                           fY => 0.0,
                                           fZ => 0.0);
   xVelocity := Math.Vectors.xCreate(fX => 0.0,
                                     fY => 0.0,
                                     fZ => 0.0);
   xAcceleration := Math.Vectors.xCreate(fX => 0.0,
                                         fY => 0.0,
                                         fZ => 0.0);

   xOrientation := Math.Matrices.xCreate_Rotation_Around_X_Axis(tfAngleInDegrees => Math.Angles.TAngle(0.0));
   xWantedOrientation := Math.Matrices.xCreate_Rotation_Around_X_Axis(tfAngleInDegrees => Math.Angles.TAngle(0.0));
   xMatrixMultiplier := Math.Matrices.xCreate_Rotation_Around_Y_Axis(tfAngleInDegrees => Math.Angles.TAngle(0.0));
   pxDispatcher := MotionControl.Dispatcher.pxCreate;

   pxDispatcher.Update_Current_Absolute_Position(xNewCurrentAbsolutePosition => xPosition);
   pxDispatcher.Update_Wanted_Absolute_Position(xNewWantedAbsolutePosition => xWantedPosition);
   pxDispatcher.Update_Current_Absolute_Orientation(xNewCurrentAbsoluteOrientation => xOrientation);
   pxDispatcher.Update_Wanted_Absolute_Orientation(xNewWantedAbsoluteOrientation => xWantedOrientation);



--   pxDispatcher.Set_PID_Scalings('p','x',newPidScalings);
--     Serial_Net.Open_Server(con,314);


   Serial_Net.Open(con,"192.168.1.1",314); --SERVER
   --Serial_Net.Write_Buffer(con,space_filler);
   loop
      newPidArray := PID.Update_Scalings;

      --testPidScalings := jsonObj.Get("p_pids");

      --Ada.Text_IO.Put_Line();

      xTimeStop := Ada.Real_Time.Clock;
      xTimeSpan := xTimeSpan + (xTimeStop - xTimeStart);

      iMilliSeconds := xTimeSpan / Ada.Real_Time.Milliseconds(1);
      xTimeSpan := xTimeSpan - (Ada.Real_Time.Milliseconds(1) * iMilliSeconds);

      fDeltaTime := float(iMilliSeconds)*0.001;

      str_iterator := raw_imu_data'First;
      --Ada.Text_IO.Put("fDeltaTime: ");
      Ada.Float_Text_IO.Put(fDeltaTime, AFT=>0, EXP=>0);

      raw_imu_data := (others => ' ');
      raw_imu_data(1..2) := "{}";

      --raw_imu_data(1 .. test_jsonObj.write'Length) := test_jsonObj.write;-- & space_filler(22..space_filler'Length);

      declare

      begin
         loop --SERVER
            Serial_Net.Read(con,read_c);

            raw_imu_data(str_iterator) := read_c;


            --Ada.Float_Text_IO.Put(float(str_iterator), AFT=>0, EXP=>0);

            str_iterator := str_iterator + 1;


            exit when str_iterator > raw_imu_data'Length + raw_imu_data'First -1;
         end loop; --SERVER
      exception

         when ADA.IO_Exceptions.End_Error =>
            null;
      end;

      Ada.Text_IO.Put_line(raw_imu_data);

      --Ada.Text_IO.Put_line("HEHEHEHEH");

      --Ada.Text_IO.New_Line;
      --Ada.Text_IO.Put_line(raw_imu_data);
      counter := counter + 1;
      Ada.Text_IO.Put_line("Update: " & counter'Img);
      receivedMsg := GNATCOLL.JSON.Read(raw_imu_data, "json.errors");

      ethId := receivedMsg.Get("ethId");
      accX := receivedMsg.Get("accX");
      accY := receivedMsg.Get("accY");
      accZ := receivedMsg.Get("accZ");
      gyrX := receivedMsg.Get("gyrX");
      gyrY := receivedMsg.Get("gyrY");
      gyrZ := receivedMsg.Get("gyrZ");
      roll := receivedMsg.Get("roll");
      pitch := receivedMsg.Get("pitch");
      yaw := receivedMsg.Get("yaw");
      depth := receivedMsg.Get("depth");


--        Ada.Text_IO.Put_Line("ethId: " & ethId'Img & " ");
--        Ada.Text_IO.Put_Line("accX: " & accX'Img & " ");
--        Ada.Text_IO.Put_Line("accY: " & accY'Img & " ");
--        Ada.Text_IO.Put_Line("accZ: " & accZ'Img);


      if fDeltaTime > 0.0 then
         --Ada.Float_Text_IO.Put(xPosition.fGet_X);
         pxDispatcher.Get_Thruster_Values(fDeltaTime => fDeltaTime,
                                          tfValues   => tfThrusterValues);

         thrusterMsgToSend.Set_Field("ethId",0);
         thrusterMsgToSend.Set_Field("canId",616);
         thrusterMsgToSend.Set_Field("size",6);
         thrusterMsgToSend.Set_Field("extended",false);
         thrusterMsgToSend.Set_Field("b 1",Integer(tfThrusterValues (1) + 128.0));
         thrusterMsgToSend.Set_Field("b 2",Integer(tfThrusterValues (2) + 128.0));
         thrusterMsgToSend.Set_Field("b 3",Integer(tfThrusterValues (3) + 128.0));
         thrusterMsgToSend.Set_Field("b 4",Integer(tfThrusterValues (4) + 128.0));
         thrusterMsgToSend.Set_Field("b 5",Integer(tfThrusterValues (5) + 128.0));
         thrusterMsgToSend.Set_Field("b 6",Integer(tfThrusterValues (6) + 128.0));

         Serial_Net.Write_Buffer(con,thrusterMsgToSend.Write & space_filler(thrusterMsgToSend.Write'length+1..space_filler'Length)); --SERVER


         for i in newPidArray'Range loop
            newPidScalings.fProportionalScale := newPidArray(i).P;
            newPidScalings.fIntegralScale := newPidArray(i).I;
            newPidScalings.fDerivativeScale := newPidArray(i).D;

            case i is
               when 1 => pxDispatcher.Set_PID_Scalings('p','x',newPidScalings);
               when 2 => pxDispatcher.Set_PID_Scalings('p','y',newPidScalings);
               when 3 => pxDispatcher.Set_PID_Scalings('p','z',newPidScalings);
               when 4 => pxDispatcher.Set_PID_Scalings('o','x',newPidScalings);
               when 5 => pxDispatcher.Set_PID_Scalings('o','y',newPidScalings);
               when 6 => pxDispatcher.Set_PID_Scalings('o','z',newPidScalings);
               when others => Ada.Text_IO.Put_Line("No axis choosen.");
            end case;
         end loop;

--           if loopCounter > nrOfLoops then
--              --newPidScalings(1)
--              Ada.Text_IO.Put_Line("dsad");
--              Serial_Net.Close(con); --SERVER
--           end if;

--            i in tfThrusterValues'Range loop
--              Ada.Float_Text_IO.Put(tfThrusterValues (i) + 128.0, AFT=>0, EXP=>0);
--              Ada.Text_IO.Put(" ");
--           end loop;

         Ada.Text_IO.Put_Line(thrusterMsgToSend.Write);
         --Ada.Text_IO.Put_Line("Time in seconds since last iteration: ");
         --Ada.Float_Text_IO.Put(fDeltaTime, AFT=>18, EXP=>0);
         Ada.Text_IO.New_Line;

         xAcceleration := Math.Vectors.xCreate(fX => float(accX),
                                               fY => float(accY),
                                               fZ => float(accZ));

         xVelocity := xVelocity + xAcceleration * fDeltaTime;
         xPosition := xPosition + xVelocity * fDeltaTime;

         --Ada.Text_IO.Put("X Position: ");
         --Ada.Float_Text_IO.Put(xPosition.fGet_X, AFT=>0, EXP=>0);

         xOrientation := xOrientation * xMatrixMultiplier;
         xWantedOrientation := xWantedOrientation * xMatrixMultiplier;

         xWantedPosition := xWantedPosition;-- + xVectorChanger;

         xOrientation := Math.Matrices.xCreate_Rotation_Around_X_Axis(tfAngleInDegrees => Math.Angles.TAngle(roll));
         xOrientation := xOrientation * Math.Matrices.xCreate_Rotation_Around_Y_Axis(tfAngleInDegrees => Math.Angles.TAngle(pitch));
         xOrientation := xOrientation * Math.Matrices.xCreate_Rotation_Around_Z_Axis(tfAngleInDegrees => Math.Angles.TAngle(yaw));

         xPosition := Math.Vectors.xCreate(fX => xPosition.fGet_X,
                                           fY => xPosition.fGet_Y,
                                           fZ => float(depth)/100.0);

         pxDispatcher.Update_Current_Absolute_Position(xNewCurrentAbsolutePosition => xPosition);
         pxDispatcher.Update_Wanted_Absolute_Position(xNewWantedAbsolutePosition => xWantedPosition);
         pxDispatcher.Update_Current_Absolute_Orientation(xNewCurrentAbsoluteOrientation => xOrientation);
         pxDispatcher.Update_Wanted_Absolute_Orientation(xNewWantedAbsoluteOrientation => xWantedOrientation);

         xTimeStart := xTimeStop;
         fDeltaTime := 0.0;
      end if;

      Ada.Text_IO.Put_Line("X: " & xPosition.fGet_X'Img & " Y: " & xPosition.fGet_Y'Img & " Z: "  & xPosition.fGet_Z'Img);
      Ada.Text_IO.Put_Line("Roll: " & xOrientation.fGet_X'Img & " Pitch: " & xPosition.fGet_Y'Img & " Yaw: "  & xPosition.fGet_Z'Img);

      loopCounter := loopCounter + 1;

      --delay(0.1);
   end loop;
exception
   when GNAT.Sockets.Socket_Error =>
      Ada.Text_IO.Put_Line("GNAT Errors.");
end Main;
