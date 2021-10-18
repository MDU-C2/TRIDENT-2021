from pid import PID


class PIDUtils():

    relRoll = 0.0
    relPitch = 0.0
    relYaw = 0.0

    relX = 0.0
    relY = 0.0
    relDepth = 0.0

    runMode = False
    counter = 0

    pidValue = {
        "P": 0.0,
        "I": 0.0,
        "D": 0.0
    }

    pidDesired = {
        "x": 0.0,
        "y": 0.0,
        "z": 0.0,
        "roll": 0.0,
        "pitch": 0.0,
        "yaw": 0.0
    }

    def updateDesiredState():
        d = PIDUtils.pidDesired

        #Insert real input values here!!
        d["x"] = 0.0
        d["y"] = 0.0
        d["z"] = 0.0
        d["roll"] = 0.0
        d["pitch"] = 0.0
        d["yaw"] = 0.0


    def filterDesiredYaw(yawToConvert):

        if PID.startYaw + yawToConvert > 180.0:
            yawToConvert = -180.0 + (-180.0 + PID.startYaw + yawToConvert)
        elif PID.startYaw + yawToConvert < -180.0:
            yawToConvert  =  180.0 + ( 180.0 + PID.startYaw + yawToConvert)
        else:
            yawToConvert = PID.startYaw + yawToConvert

    def updatePIDData():
        depth = 0.0 #receivedMsg.Get("posz")
        absX = 0.0
        absY = 0.0
        absZ = 0.0

        absRoll = 0.0
        absPitch = 0.0
        absYaw = 0.0

        ethid = 0
        depth = ((depth*3059.0)/1024.0)/100.0 #Needs to be calibrated to give proper depth value, this is not good enough.
        sender = 0#receivedMsg.Get("sender")
        ethid =  0#receivedMsg.Get("ethid");

        if sender == "sns": # sensor
             if (PID.firstRun):
                #--PID.fDesiredYaw := PID.fCurrentYaw;
                counterForSend = 0
                PID.fRollIValue = 0.0
                PID.fPitchIValue = 0.0
                PID.fYawIValue = 0.0
                PID.fPosXIValue = 0.0
                PID.fPosYIValue = 0.0
                PID.fPosZIValue = 0.0
                PID.bFirstRun = False
                PID.fStartYaw = 0 #receivedMsg.Get("yaw")
                PID.fCurrentYaw = PID.startYaw
                PID.fStartPosZ = depth
                PID.fCurrentPosZ = 0.0 #--depth - PID.fStartPosZ;
                PID.surfacePosZ = PID.currentPosZ
                PID.Set_Desired_State(0.0,0.0,PID.currentPosZ,0.0,0.0,0.0)
                if PID.debugText:
                    print("First run, setting desired to current.")

         PID.fCurrentYaw := receivedMsg.Get("yaw")-PID.fStartYaw;
         PID.fCurrentPitch := receivedMsg.Get("pitch");
         PID.fCurrentRoll := receivedMsg.Get("roll");

         if PID.bSimulation then
            PID.fCurrentAccX := receivedMsg.Get("accx");
            PID.fCurrentAccY := receivedMsg.Get("accy");
            PID.fCurrentAccZ := receivedMsg.Get("accz");
         else
            PID.fCurrentAccX := 0.0;
            PID.fCurrentAccY := 0.0;
            PID.fCurrentAccZ := 0.0;

            if PID.bGetFilteredPosition then
               PID.fCurrentPosX := receivedMsg.Get("posx");
               PID.fCurrentPosY := receivedMsg.Get("posy");
            end if;
         end if;

         --Gyro data might be added later to get better estimation on the derivative part.
         PID.fCurrentGyroX := 0.0; --receivedMsg.Get("gyrX");
         PID.fCurrentGyroY := 0.0; --receivedMsg.Get("gyrY");
         PID.fCurrentGyroZ := 0.0; --receivedMsg.Get("gyrZ");
         PID.fCurrentPosZ :=  depth - PID.fStartPosZ;--float(depth)/100.0 - PID.fStartPosZ;


      elsif sender = "msn" then -- mission control
         null;
      elsif sender = "pth" then -- path planner
          if ethid = 1 then
            absRoll := receivedMsg.Get("roll");
            absPitch := receivedMsg.Get("pitch");
            absYaw := receivedMsg.Get("yaw");
            absX := receivedMsg.Get("posx");
            absY := receivedMsg.Get("posy");
            absZ := receivedMsg.Get("posz");

            PID.Set_Desired_State(absX,absY,absZ,absRoll,absPitch,absYaw);
         elsif ethid = 2 then
		--ada.text_io.put_line("pth ethid 2------------------------------");
            relRoll := receivedMsg.Get("roll");
            relPitch := receivedMsg.Get("pitch");
            relYaw := receivedMsg.Get("yaw");
            relX := -receivedMsg.Get("posx");
            relY := receivedMsg.Get("posy");
            relDepth := receivedMsg.Get("posz");

            --relPitch := 0.0; --commented out by ludde 160816
            --relRoll := 0.0; --commented out by ludde 160816
            PID.Set_Desired_Relative_State(relX,relY,relDepth,relRoll,relPitch,relYaw);
         elsif ethid = 3 then
            PID.Go_To_Surface;
         end if;

      elsif sender = "usr" then
         if ethid = 1 then
            declare
               sDim : string := receivedMsg.Get("pid");
               sAxis : string := receivedMsg.Get("axis");
               iDim : integer := 0;
               iAxis : integer := 0;

            begin
               if sDim = "p" then
                  iDim := 1;
               elsif sDim = "i" then
                  iDim := 2;
               elsif sDim = "d" then
                  iDim := 3;
               end if;

               if sAxis = "x" then
                  iAxis := 1;
--		ada.text_io.put_line("asdfasdf");
               elsif sAxis = "y" then
                  iAxis := 2;
               elsif sAxis = "z" then
                  iAxis := 3;
               elsif sAxis = "roll" then
                  iAxis := 4;
               elsif sAxis = "pitch" then
                  iAxis := 5;
               elsif sAxis = "yaw" then
                  iAxis := 6;
               end if;

               if PID.bDebugText then
                  for i in 1..3 loop

                     for j in 1..6 loop
                        ada.text_io.put(pid.xpidconfig(i,j)'img);
                        --ada.text_io.new_line();
                        ada.text_io.put(",");

                     end loop;

                     ada.text_io.new_line;
                  end loop;
               end if;




                  pid.xPIDconfig(iDim, iAxis) := receivedMsg.Get("value");
            end;

         end if;
      elsif sender = "can" then
		ada.text_io.put("sender=can !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"); --ludde 160816
		ada.text_io.new_line; --ludde 160816
         Delay 3.0;
         PID.bFirstRun := True;
	elsif sender = "m_0" then
		bRunMode:=False;
		--pid.bFirstRun:=True;
		PID.fDesiredRoll:=PID.fCurrentRoll;
		PID.fDesiredPitch:=PID.fCurrentPitch;
		--ada.text_io.put_line("motor offfffffffffffffffff!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	elsif sender = "m_1" then
		bRunMode:=True;
		--ada.text_io.put_line("motor on!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

      end if;


   end Update_PID_Data;