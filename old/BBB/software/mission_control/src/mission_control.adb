with marker; --10
with custom_mission; --5
with first_gate; --1
with first_gate_qualification; --101
package body Mission_control is




   procedure main is
      use Ada.Real_Time;
      bSent : boolean := false;
      sSender : string(1..3);
      bNewMessage : boolean := false;
      xJsonIn : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      xJsonOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      tTime : Ada.Real_Time.Time;
      tStartTime : Ada.Real_Time.Time;
      bMissionSwitch : boolean :=  true;
      --x, y, z, roll, pitch, yaw :  float;
      iEthId : integer := 0; --no mission at 0
      iMissionId : integer := 0; --no mission at 0
      missionSequence : array (1..9) of integer := (others => 0);
      numberOfMissions : integer := 0;
      activeMission : integer := 0;
      run : boolean := false;






      msgState : boolean := true;

      procedure incMsg is
         msgOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      begin
         msgOut.set_Field("sender", "msn");
         msgOut.set_Field("target", "can");
         msgOut.set_Field("ethid", 758);

         msgOut.set_Field("len", 6);
         msgOut.set_Field("b1", 3);
         msgOut.set_Field("b3", 4);
         msgOut.set_Field("b5", 5);
         if msgState then
            msgOut.set_Field("b2", 1);
            msgOut.set_Field("b4", 1);
            msgOut.set_Field("b6", 0);
         else
            msgOut.set_Field("b2", 0);
            msgOut.set_Field("b4", 1);
            msgOut.set_Field("b6", 1);
         end if;
         msgState := not msgState;
         tcp_client.Send(xJson => msgOut, bSuccess => bSent);
      end incMsg;

      procedure setState(state : in integer) is
         msgOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      begin
         msgOut.set_Field("sender", "msn");
         msgOut.set_Field("target", "can");
         msgOut.set_Field("ethid", 758);

         msgOut.set_Field("len", 6);
         msgOut.set_Field("b1", 11);
         msgOut.set_Field("b3", 12);
         msgOut.set_Field("b5", 13);
         case state is
            when 1 =>
               msgOut.set_Field("b2", 1); --g
               msgOut.set_Field("b4", 0); --r
               msgOut.set_Field("b6", 0); --b
            when 2 =>
               msgOut.set_Field("b2", 0);
               msgOut.set_Field("b4", 1);
               msgOut.set_Field("b6", 0);
            when 3 =>
               msgOut.set_Field("b2", 0);
               msgOut.set_Field("b4", 0);
               msgOut.set_Field("b6", 1);
            when others =>
               msgOut.set_Field("b2", 1);
               msgOut.set_Field("b4", 1);
               msgOut.set_Field("b6", 1);
         end case;

         msgState := not msgState;
         tcp_client.Send(xJson => msgOut, bSuccess => bSent);
      end setState;


      procedure shutOfBlinkingPart is
         msgOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      begin
         msgOut.set_Field("sender", "msn");
         msgOut.set_Field("target", "can");
         msgOut.set_Field("ethid", 758);
         msgOut.set_Field("len", 6);
         msgOut.set_Field("b1", 6);
         msgOut.set_Field("b2", 0);
         msgOut.set_Field("b3", 7);
         msgOut.set_Field("b4", 0);
         msgOut.set_Field("b5", 8);
         msgOut.set_Field("b6", 0);
         tcp_client.Send(xJson => msgOut, bSuccess => bSent);
         msgOut.set_Field("b1", 14);
         msgOut.set_Field("b3", 15);
         msgOut.set_Field("b5", 16);
         tcp_client.Send(xJson => msgOut, bSuccess => bSent);
      end shutOfBlinkingPart;

      procedure startblink is
         msgOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      begin
         msgOut.set_Field("sender", "msn");
         msgOut.set_Field("target", "can");
         msgOut.set_Field("ethid", 754);
         msgOut.set_Field("len", 0);
         tcp_client.Send(xJson => msgOut, bSuccess => bSent);
      end startblink;

      procedure stopblink is
         msgOut : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
      begin
         msgOut.set_Field("sender", "msn");
         msgOut.set_Field("target", "can");
         msgOut.set_Field("ethid", 755);
         msgOut.set_Field("len", 0);
         tcp_client.Send(xJson => msgOut, bSuccess => bSent);
         shutOfBlinkingPart;
      end stopblink;


      procedure stopMission is
      begin
         run := false;
         --skicka noll till pid
         stopblink;
      end stopMission;

      procedure startMission is
      begin
         delay 0.1;
         run := true;
         activeMission := 1;
         Ada.Text_IO.Put("Mission is starting by demand of mission switch, will execute missions in following order: ");
         for i in 1..numberOfMissions loop
            Ada.Text_IO.Put(missionSequence(i)'img);
            Ada.Text_IO.Put("  ");
         end loop;
         Ada.Text_IO.Put_line("!");
         startblink;
      end startMission;

      procedure missionCompleted is
      begin
         if activeMission = numberOfMissions then
            stopMission;
         else
            activeMission := activeMission + 1;
         end if;
      end missionCompleted;
   begin

      Ada.Text_IO.Put_line("mission node started");
      tStartTime := Ada.Real_Time.Clock;
      tcp_client.Set_IP_And_Port(sIP   => "127.0.0.1",
                                 sPort => "msn");
      tcp_client.SetTimeout(1.0);
      stopblink;
      incMsg;
      loop

         Ada.Text_IO.Put_line("Waiting for msg...");
         tcp_client.Get(xJson    => xJsonIn,
                        bSuccess => bNewMessage);
         if bNewMessage then
            incMsg;
            --              tLastMessage := Ada_05.Real_Time.clock;
            Ada.Text_IO.Put_Line(xJsonIn.Write);
            declare
            begin
               sSender := xJsonIn.get("sender");
            exception
               when E : others =>
                  Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
            end;

            if sSender = "usr" then
               setState(3);--b
               declare
                  msgSeq : string := "nr_0";
               begin
                  iEthId := xJsonIn.get("ethid");--number of mission
                  numberOfMissions := iEthId;
                  Ada.Text_IO.Put("mission order : ");
                  for i in 1..iEthId loop
                     msgSeq(4) := Character'Val(48+i); --nr_1..numberOfMission
                     missionSequence(i) := xJsonIn.get(msgSeq);
                     Ada.Text_IO.Put(missionSequence(i)'img);
                     Ada.Text_IO.Put("   ");
                  end loop;
                  Ada.Text_IO.Put_line("!");
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;





            elsif sSender = "vsf" then --Vision front
               setState(1);--g
               case missionSequence(activeMission) is
                  when 1 =>
                     declare
                        cont : boolean := true;
                        xJsonOutTemp : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
                     begin
                        while cont loop
                           first_gate.main(xJsonIn, xJsonOutTemp, cont);
                           tcp_client.Send(xJson => xJsonOutTemp, bSuccess => bSent);
                        end loop;
                     end;
                  when 2 =>
                     --mission 2
                     null; --for now
                  when others => null;
               end case;





            elsif sSender = "vsb" then --vision bot, for markers
               setState(2);--r
               case missionSequence(activeMission) is
               when 1312 => --cant happen for now
                  null;
               when -11 => --others when rest is working
                  declare
                     cont : boolean := true;
                     xJsonOutTemp : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
                  begin
                     while cont loop
                        marker.main(xJsonIn, xJsonOutTemp, cont);
                        tcp_client.Send(xJson => xJsonOutTemp, bSuccess => bSent);
                     end loop;
                  end;
               when 1 => --FIRST GATE
                  declare
                     cont : boolean := true;
                     xJsonOutTemp : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
                  begin
                     while cont loop
                        first_gate.main(xJsonIn, xJsonOutTemp, cont);
                        Ada.Text_IO.Put_Line("sending : " & xJsonOutTemp.write);
                        tcp_client.Send(xJson => xJsonOutTemp, bSuccess => bSent);
                        if first_gate.finished then
                           missionCompleted;
                        end if;
                     end loop;
                  end;
                  when 10 => --marker
                     declare
                        cont : boolean := true;
                        xJsonOutTemp : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
                     begin
                        while cont loop
                           marker.main(xJsonIn, xJsonOutTemp, cont);
                           Ada.Text_IO.Put_Line("sending : " & xJsonOutTemp.write);
                           tcp_client.Send(xJson => xJsonOutTemp, bSuccess => bSent);
                           if marker.finished then
                              missionCompleted;
                           end if;
                        end loop;
                     end;
                  when others => null;
               end case;
               --currentMission done when getting info from this, start mission when not






            elsif sSender = "can" then
               declare
               begin
                  iEthId := xJsonIn.get("ethid");
                  if iEthId = 400 then
                     bMissionSwitch := true; -- mission switch is attatched dont run
                     stopMission;
                     stopMission;
                  elsif iEthId = 404 then
                     bMissionSwitch := false; -- mission switch is not attatched
                     startMission;
                  end if;
               exception
                  when E : others =>
                     Ada.Text_IO.Put_Line("Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
               end;
            end if;


            if run then --if not based on vision to act
               Ada.Text_IO.Put_Line("in run mission");
               case missionSequence(activeMission) is
                  when 5 => --custom mission needs to run here
                     if not custom_mission.finished then
                        Ada.Text_IO.Put_Line("custom mission");


                        declare
                           cont : boolean := true;
                           xJsonOutTemp : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
                        begin
                           while cont loop
                              custom_mission.main(xJsonIn, xJsonOutTemp, cont);
                              Ada.Text_IO.Put_Line("sending : " & xJsonOutTemp.write);
                              tcp_client.Send(xJson => xJsonOutTemp, bSuccess => bSent);
                           end loop;
                        end;
                     end if;
                  when 101 =>
                     if not first_gate_qualification.finished then
                        Ada.Text_IO.Put_Line("custom mission");
                        declare
                           cont : boolean := true;
                           xJsonOutTemp : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
                        begin
                           while cont loop
                              first_gate_qualification.main(xJsonIn, xJsonOutTemp, cont);
                              Ada.Text_IO.Put_Line("sending : " & xJsonOutTemp.write);
                              tcp_client.Send(xJson => xJsonOutTemp, bSuccess => bSent);
                           end loop;
                        end;
                     end if;
                  when others => null;



               end case;

            end if;

         end if;


         if activeMission > numberOfMissions then
            declare
               xJsonOutTemp : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
            begin
               xJsonOutTemp.set_Field("sender", "pth");
               xJsonOutTemp.set_Field("target", "pid");
               xJsonOutTemp.set_Field("ethid", 3);
               Ada.Text_IO.Put_Line("sending : " & xJsonOutTemp.write);
               tcp_client.Send(xJson => xJsonOutTemp, bSuccess => bSent);
            end;
         end if;
         --end if;
      end loop;
   end main;



end Mission_Control;
