with Ada.Real_Time; use Ada.Real_Time;
with BBB_CAN;
with CAN_Defs;
with Ada.Text_IO;
with Interfaces; use Interfaces;
with Ada.Unchecked_Conversion;
with GNATCOLL.JSON;
with Tcp_Client;
with Byte_Conv;
with UartWrapper;
with Ada.Exceptions; use Ada.Exceptions;
with Can_Log;
with Can_Status;
with Queue;
with Ada.Exceptions;

use Ada.Exceptions;

package body Can_Node is
   INS_JSON : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   BInitEnabled : Boolean := False;
   FRoll, FPitch, FYaw, FX, FY, FZ : Float := 0.0;


   procedure Init is
   begin
--        Ada.Text_Io.Put_Line("CARL: can_node.adb: init; start");
      Tcp_Client.Set_IP_And_Port (SIP   => "127.0.0.1", SPort => "can");
      BBB_CAN.Init (SPort => "ttyO4", Baud  => UartWrapper.B115200);
      BBB_CAN.Init_Imu (Baud => UartWrapper.B115200);

      INS_JSON.Set_Field ("posz", 0.0);
      INS_JSON.Set_Field ("accx", 0.0);
      INS_JSON.Set_Field ("accy", 0.0);
      INS_JSON.Set_Field ("accz", 0.0);
      INS_JSON.Set_Field ("roll", 0.0);
      INS_JSON.Set_Field ("pitch", 0.0);
      INS_JSON.Set_Field ("yaw", 0.0);
      INS_JSON.Set_Field ("posx", 0.0);
      INS_JSON.Set_Field ("posy", 0.0);
      BInitEnabled := True;
--        Ada.Text_Io.Put_Line ("CARL: can_node.adb: init; stop" & BInitEnabled'img);
   end Init;

   procedure Send_To_Can (XJson : GNATCOLL.JSON.JSON_Value) is
      IEthID : Integer;
      ICanDataLen : Integer;
      IByteValue : Integer := 0;
      XMessageOut : CAN_Defs.CAN_Message;
   begin

      IEthID := XJson.Get ("ethid");
      XMessageOut.ID := (Can_Defs.CAN_Identifier (IEthID), False);
      --xMessageOut.ID := (can_defs.CAN_identifier(12),false);
      ICanDataLen := XJson.Get ("len");
      XMessageOut.Len := CAN_Defs.DLC_Type (ICanDataLen);

      -- loop to transfer all the bytes (b1 -> b8) from the JSON object to a CAN message.
      for I in 1 .. ICanDataLen loop
	 IByteValue := XJson.Get ('b' & Character'Val (Character'Pos ('0') + I));
	 XMessageOut.Data (Can_Defs.DLC_TYPE (I)) := Interfaces.Unsigned_8 (IByteValue);
      end loop;

      BBB_CAN.Send (Msg => XMessageOut);
   end Send_To_Can;



   procedure Send_To_Tcp (XCanMsg : CAN_Defs.CAN_Message) is
      BSendSucess : Boolean;
      CanToBBB_JSON : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   begin
      --        canToBBB_JSON := GNATCOLL.JSON.JSON_Null;
      --Ada.Text_IO.New_Line;
      --Ada.Text_IO.Put_Line (xCanMsg.ID.Identifier'img);
      --Ada.Text_IO.Put_Line ("Queue:                " & Queue.iFirst'Img & ", " & Queue.iLast'Img);
      --Ada.Text_IO.Put_Line ("Queue.iDataAvailable: " & Queue.iDataAvailable'Img);
      --Ada.Text_IO.Put_Line("xCanMsg.Data " & integer(byte_conv.Byte2ToUsign16(xCanMsg.Data,1))'Img);

      if XCanMsg.ID.Identifier not in 0 .. 1599 then --luddes fulhack 050916
	 Ada.Text_IO.Put_Line ("unknown id; " & XCanMsg.ID.Identifier'Img);
	 Queue.IFirst := 1;
	 Queue.ILast := 1;
	 return;
      end if;
      case XCanMsg.ID.Identifier is
      when 400 =>
	 CanToBBB_JSON.Set_Field ("ethid", Integer (XCanMsg.ID.Identifier));
	 CanToBBB_JSON.Set_Field ("target", "msn");
	 CanToBBB_JSON.Set_Field ("sender", "can");
	 Tcp_Client.Send (CanToBBB_JSON, BSendSucess);
      when 404 =>
	 CanToBBB_JSON.Set_Field ("ethid", Integer (XCanMsg.ID.Identifier));
	 CanToBBB_JSON.Set_Field ("target", "msn");
	 CanToBBB_JSON.Set_Field ("sender", "can");
	 Tcp_Client.Send (CanToBBB_JSON, BSendSucess);
	 CanToBBB_JSON.Set_Field ("target", "pid");
	 Tcp_Client.Send (XJson    => CanToBBB_JSON, BSuccess => BsendSucess);
      when 1000 =>
	 Can_Status.Add_Node (XCanMsg);
      when 1001 =>
	 Can_Status.Send_Node_List;
	 null;
      when 1337 =>
	 --motor response, please ignore (ludde 160914)
	 null;
      when 1591 => --fog
	 null;

      when 1593 => --depth
	 declare
	    Tmp1 : Interfaces.Unsigned_8 := XCanMsg.Data (1);
	    Tmp2 : Interfaces.Unsigned_8 := XCanMsg.Data (2);
	    Sum : Interfaces.Unsigned_16 := Interfaces.Unsigned_16(Tmp2) * 256 + Interfaces.Unsigned_16(Tmp1);
	 begin
	    --  	       Ada.Text_IO.Put_Line ("received");
	    INS_JSON.Set_Field ("posz", Integer (Byte_Conv.Byte2ToUsign16 (XCanMsg.Data, 1)));
--  	    Ada.Text_IO.Put_Line ("Carl: can_node.adb: send_to_tcp: id 1593 posz: " & Integer (Byte_Conv.Byte2ToUsign16 (XCanMsg.Data, 1))'Img & Tmp1'Img & Tmp2'Img & Sum'img);

	    --  	       INS_JSON.Set_Field ("ethid", 1);
	    --  	       INS_JSON.Set_Field ("target", "sns");

	    Tcp_Client.Send (INS_JSON, BSendSucess);
	 exception
	    when E : others =>
	       Ada.Text_IO.Put_Line ("1593 Exception: " & Ada.Exceptions.Exception_Name (E) & ": " & Ada.Exceptions.Exception_Message (E));
	 end;
	 --send to SNS- sensor fusion
      when 1594 => --imu Yaw and Pitch
	 declare
	 begin
	    INS_JSON.Set_Field ("yaw", Byte_Conv.Byte4ToFloat (XCanMsg.Data, 1));
	    INS_JSON.Set_Field ("pitch", Byte_Conv.Byte4ToFloat (XCanMsg.Data, 5));
	 exception
	    when E : others =>
	       Ada.Text_IO.Put_Line ("1594 Exception: " & Ada.Exceptions.Exception_Name (E) & ": " & Ada.Exceptions.Exception_Message (E));
	 end;
      when 1595 => --imu Roll and AccZ
	 declare
	 begin
	    INS_JSON.Set_Field ("roll", Byte_Conv.Byte4ToFloat (XCanMsg.Data, 1));
	    INS_JSON.Set_Field ("accz", Byte_Conv.Byte4ToFloat (XCanMsg.Data, 5));
	 exception
	    when E : others =>
	       Ada.Text_IO.Put_Line ("1595 Exception: " & Ada.Exceptions.Exception_Name (E) & ": " & Ada.Exceptions.Exception_Message (E));
	 end;
      when 1596 => --imu AccX and AccY, 1591, 1593, 1594, 1595, 1596 is compiled into the same package.
	 declare
	 begin

	    INS_JSON.Set_Field ("ethid", 1);
	    INS_JSON.Set_Field ("target", "sns");
	    INS_JSON.Set_Field ("accx", Byte_Conv.Byte4ToFloat (XCanMsg.Data, 1));
	    INS_JSON.Set_Field ("accy", Byte_Conv.Byte4ToFloat (XCanMsg.Data, 5));

	    Tcp_Client.Send (INS_JSON, BSendSucess);

	 exception
	    when E : others =>
	       Ada.Text_IO.Put_Line ("Exception: " & Ada.Exceptions.Exception_Name (E) & ": " & Ada.Exceptions.Exception_Message (E));
	 end;
      when others =>
	 Ada.Text_IO.Put_Line ("Unknown message id");
      end case;

   exception
      when others =>
	 Ada.Text_IO.Put_Line ("Ignore exception.");
   end Send_To_Tcp;


   task Imu_Task;
   task body Imu_Task is
      BSendSucess : Boolean;
      --canToBBB_JSON : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   begin
      while not BInitEnabled loop
	 delay 1.0;
      end loop;
      --ada.text_io.put_line("imu_task");
      loop
	 begin
	    Ada.Text_Io.Put_Line ("imu_task: loop");
	    BBB_CAN.Read_Imu (FRoll, FPitch, FYaw, FX, FY, FZ);
	    Ada.Text_Io.Put_Line ("imu_task: after read_imu");
	    INS_JSON.Set_Field ("roll", FRoll);
	    INS_JSON.Set_Field ("yaw", FYaw);
	    INS_JSON.Set_Field ("pitch", FPitch);
	    INS_JSON.Set_Field ("accx", FX);
	    INS_JSON.Set_Field ("accy", FY);
	    INS_JSON.Set_Field ("accz", FZ);
	    INS_JSON.Set_Field ("ethid", 1);
	    INS_JSON.Set_Field ("target", "sns");

	    Tcp_Client.Send (INS_JSON, BSendSucess);
	    delay 0.0;
	 exception
	    when E : others =>
	       Ada.Text_Io.Put_Line ("imu_task ignored exception");
	       Ada.Text_Io.Put_Line (Exception_Message (E));
	 end;
      end loop;
   end Imu_Task;


   task Tcp_To_Can_Task;
   task body Tcp_To_Can_Task is
      BNewMessage : Boolean := False;
      XJsonToCan : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   begin
      while not BInitEnabled loop
	 delay 1.0;
      end loop;
      loop
	 Tcp_Client.Get (XJson    => XJsonToCan,
		  BSuccess => BNewMessage);
	 if BNewMessage then
	    BNewMessage := False;
	    Send_To_Can (XJsonToCan);
	 end if;
	 delay 0.01;
      end loop;
   end Tcp_To_Can_Task;



   task Can_To_Tcp_Task;
   task body Can_To_Tcp_Task is
      XCanToTCP : CAN_Defs.CAN_Message;
      BNewCanMsg : Boolean := False;
      BUartCheckSumOk : Boolean := False;
   begin
      while not BInitEnabled loop
	 delay 1.0;
      end loop;
      loop
--  	 Ada.Text_IO.Put_Line ("can2tcp");
	 BBB_CAN.Get (Msg             => XCanToTCP,
	       BMsgReceived    => BNewCanMsg,
	       BUARTChecksumOK => BUartCheckSumOk);
	 if BNewCanMsg then
	    BNewCanMsg := False;
--  	    Ada.Text_IO.Put_Line ("Carl: can_node.adb: can_to_tcp_task: new message");
	    Send_To_Tcp (XCanToTCP);
	 else
	    --Ada.Text_IO.Put_Line ("No message");
	    delay (0.01);
	 end if;
      end loop;

   end Can_To_Tcp_Task;



   procedure Main_Loop is
      XCanPingMsg : CAN_Defs.CAN_Message;
      PingPsuTime : Ada.Real_Time.Time;
      PingPsuPeriod : Ada.Real_Time.Time_Span := Ada.Real_Time.Milliseconds (1000);
   begin

      Init;
      XCanPingMsg.ID := (504, False);
      XCanPingMsg.Len := 0;
      PingPsuTime := Ada.Real_Time.Clock;
      loop
	 --BBB_CAN.usart_write_imu("hej",3);
	 --ADA.Text_IO.Put_Line("main");
	 PingPsuTime := PingPsuTime + PingPsuPeriod;
	 BBB_CAN.Send (Msg => XCanPingMsg);
	 delay until (PingPsuTime);
      end loop;
   end Main_Loop;




end Can_Node;
