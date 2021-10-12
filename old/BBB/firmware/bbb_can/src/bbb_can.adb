with Ada.Text_IO;
with GNAT.Serial_Communications;
with CAN_Utils;
with Exception_Handling;
with Queue;
with Queue2;
with Interfaces.C;
with Ada.Characters.Latin_1;
use Ada.Characters.Latin_1;

package body BBB_CAN is
   pragma Suppress (All_Checks);

   pxUart  : UartWrapper.pCUartHandler;
   pxUart1 : UartWrapper.pCUartHandler;

   procedure read_imu (fRoll, fPitch, fYaw, fX, fY, fZ : in out Float) is
      raw_string : String (1 .. 200) := (others => ' ');
      raw_size   : Integer           := 30;
      raw_read   : integer           := 0;
      iState : integer := 1;
      iStart : integer := 1;
      iEnd : integer := 1;
   begin
      --pxUart1.Uart_tcflush;
      --delay 0.01;
Ada.Text_IO.Put_Line ("read_imu...");
      Usart_Read_imu (pxUart1, raw_string, raw_size, raw_read);
Ada.Text_IO.Put_Line ("received: " & raw_string(1..raw_read));



      for i in 1.. raw_read loop
         if (raw_string(i)=',' or raw_string(i)='*') then
            iStart:=iEnd;
            iEnd:=i;
            case iState is
            when 1 =>
               --command
               iState:=2;
            when 2 =>
               iState:=3;
               --Ada.Text_IO.Put_Line("Yaw: "&raw_string(iStart+1..iEnd-1));
               fYaw:=Float'Value(raw_string(iStart+1..iEnd-1));
            when 3 =>
               iState:=4;
               --Ada.Text_IO.Put_Line("Pitch: "&raw_string(iStart+1..iEnd-1));
               fPitch:=Float'Value(raw_string(iStart+1..iEnd-1));
            when 4 =>
               iState:=5;
               --Ada.Text_IO.Put_Line("Roll: "&raw_string(iStart+1..iEnd-1));
               fRoll:=Float'Value(raw_string(iStart+1..iEnd-1));
            when 5 =>
               iState:=6;
               --Ada.Text_IO.Put_Line("X: "&raw_string(iStart+1..iEnd-1));
               fX:=Float'Value(raw_string(iStart+1..iEnd-1));
            when 6 =>
               iState:=7;
               --Ada.Text_IO.Put_Line("Y: "&raw_string(iStart+1..iEnd-1));
               fY:=Float'Value(raw_string(iStart+1..iEnd-1));
            when 7 =>
               iState:=8;
               --Ada.Text_IO.Put_Line("Z: "&raw_string(iStart+1..iEnd-1));
               fZ:=Float'Value(raw_string(iStart+1..iEnd-1));
            when others =>
               exit;
            end case;
         end if;
      end loop;
   end read_imu;

   procedure Usart_Write_imu (handle : in UartWrapper.pCUartHandler; sBuffer : String; iSize : Integer) is
      use Ada.Characters.Latin_1;
   begin
      --Ada.Text_IO.Put_Line("Usart_Write, iSize=" & iSize'Img);
      handle.Uart_Write (sBuffer, iSize, False);
   end Usart_Write_imu;

   procedure Usart_Read_imu (handle : in UartWrapper.pCUartHandler; sBuffer : out String; iSize : Integer; bBytesRead : out integer) is
      sTempBuffer    : String (1 .. 1);
      iTempBytesRead : Integer;
      --iInt : Integer:=1;
      --iTempSize : integer:=0;
      --bTempBool:boolean:=false;
      sNewBuffer : String (1..200);
      iIndex : integer:=0;
   begin
	--ada.text_io.put_line("usart_read_imu");
      sTempBuffer(1):='0';
      handle.UartReadSpecificAmount(sTempBuffer,1,iTempBytesRead);
      while(sTempBuffer(1) /= '$') loop
	delay 0.01;
         handle.UartReadSpecificAmount(sTempBuffer,1,iTempBytesRead);
	 --ada.text_io.put_line("usart_read_imu: "&sTempBuffer(1));
        -- ada.Text_IO.Put_Line("1: "&sTempBuffer(1));
      end loop;
      iIndex:=iIndex+1;
      sNewBuffer(iIndex):=sTempBuffer(1);
      while(sTempBuffer(1)/='*') loop
	--delay 0.01;
         --ada.Text_IO.Put_Line("2: "&sTempBuffer(1));
         handle.UartReadSpecificAmount(sTempBuffer,1,iTempBytesRead);

         if(iTempBytesRead>0) then
            iIndex:=iIndex+1;
            sNewBuffer(iIndex):=sTempBuffer(1);
         end if;
      end loop;
      --Ada.Text_IO.Put_Line("sNewBuffer: "&sNewBuffer(1..iIndex)&" iIndex: "&iIndex'img);

      sBuffer(sBuffer'first..iIndex+sBuffer'first-1):=sNewBuffer(1..iIndex);
      bBytesRead:=iIndex;
   end Usart_Read_imu;

   procedure Init (sPort : String; baud : UartWrapper.BaudRates) is
   begin
      --initiates UART commiunication:
      --  Ada.Text_IO.Put_Line("Opening " & "/dev/" & sPort & ", baudrate: " & baud'Img);
      --  pxUart := UartWrapper.pxCreate(GNAT.Serial_Communications.Port_Name("/dev/" & sPort), baud, 0.2, 100);
      pxUart := UartWrapper.pxCreate ("/dev/" & sPort, baud, Interfaces.C.int (0), 200, Interfaces.C.int (0));
      Ada.Text_IO.Put_Line ("bbb_can_init");
   end Init;


   procedure init_imu (baud : UartWrapper.BaudRates) is
      --imu_init_msg : String := "$VNWRG,06,16*XX";
      --imu_init_msg2 : String := "$VNRRG,07,02*XX";
      pause_msg : constant String := "$VNASY,0*XX"&CR&LF;
      resume_msg : constant String := "$VNASY,1*XX"&CR&LF;
      baud_msg : constant String := "$VNWRG,05,115200*5D"&CR&LF;
      type_msg : constant String := "$VNWRG,06,16*XX" & CR & LF;
      freq_msg : constant String := "$VNWRG,07,10*XX" & CR & LF;
	set_msg : constant String := "$VNWNV*57" & CR & LF;
      imu_init_msg : String :=resume_msg&type_msg&freq_msg&set_msg;
   begin
      pxUart1 := UartWrapper.pxCreate("/dev/ttyO1", baud, Interfaces.C.int (0), 200, Interfaces.C.int (0));
--loop
	Usart_Write_imu (pxUart1, imu_init_msg, imu_init_msg'Length);
--end loop;
      --Usart_Write_imu (imu_init_msg2, imu_init_msg2'Length);
      Ada.Text_IO.Put_Line ("IMU init: " & imu_init_msg & ", "&imu_init_msg'length'img);
   end init_imu;

   --     function Handshake return Boolean is
   --        sSend : String(1..5);
   --        sReceive : String(1..6);
   --        iBytesRead : Integer := 0;
   --     begin
   --        -- handshake message:
   --        sSend(1) := Character'Val(3);
   --        sSend(2) := Character'Val(0);
   --        sSend(3) := Character'Val(0);
   --        sSend(4) := Character'Val(0);
   --        sSend(5) := Character'Val(0);
   --
   --        --send handshake message and wait for reply while keeping a look at the clock
   --        sReceive := pxUart.sUartEcho(5, iBytesRead, sSend, Duration(iHANDSHAKE_WAIT_TIME_MS) / 1000);
   --
   --        if iBytesRead >= 5 then
   --           if sReceive(1) = Character'Val(3) and
   --              sReceive(2) = Character'Val(0) and
   --              sReceive(3) = Character'Val(0) and
   --              sReceive(4) = Character'Val(0) and
   --              sReceive(5) = Character'Val(0) then
   --              return true;
   --           end if;
   --        end if;
   --        return false;
   --     end Handshake;

   procedure Send (msg : CAN_Defs.CAN_Message) is
      sBuffer : String (1 .. (Integer (msg.Len) + CAN_Utils.HEADLEN));
   begin
      CAN_Utils.Message_To_Bytes (sBuffer, msg);
      Usart_Write (sBuffer, Integer (msg.Len) + CAN_Utils.HEADLEN);
   end Send;

   procedure Get (msg : out CAN_Defs.CAN_Message; bMsgReceived : out Boolean; bUARTChecksumOK : out Boolean) is
      use Interfaces;
      sHeadBuf           : String (1 .. CAN_Utils.HEADLEN);
      u8ActualChecksum   : Interfaces.Unsigned_8;
      u8ReceivedChecksum : Interfaces.Unsigned_8;
      bReadComplete      : Boolean;
   begin
      Usart_Read (sHeadBuf, CAN_Utils.HEADLEN, bReadComplete);
      --Ada.Text_IO.Put_Line("Usart_Read, head buffer, bReadComplete=" & bReadComplete'Img);
      if not bReadComplete then
         bMsgReceived    := False;
         bUARTChecksumOK := False;
         return;
      end if;
      --Ada.Text_IO.Put_Line("sHeadBuf: "&sHeadBuf);
      bMsgReceived := True;
      CAN_Utils.Bytes_To_Message_Header (sHeadBuf, msg, u8ReceivedChecksum);

      --Ada.Text_IO.Put_Line("Bytes_To_Message_Header: ID: " & Integer'Image(Integer(msg.ID.Identifier)) &
      -- " length:" & Integer'Image(Integer(msg.Len)));

      if Integer (msg.Len) /= 0 then
         declare
            sData : String (1 .. Integer (msg.Len));
         begin
            -- Ada.Text_IO.Put_Line("Usart_Read_Inf_Block begins");
            Usart_Read_Inf_Block (sData, Integer (msg.Len));
            --Ada.Text_IO.Put_Line("Usart_Read_Inf_Block done " & Integer'Image(Integer(msg.Len)) & " bytes read");
            CAN_Utils.Bytes_To_Message_Data (sData, msg, u8ActualChecksum);
         end;
         bUARTChecksumOK := (u8ActualChecksum = u8ReceivedChecksum);
      else
         bUARTChecksumOK := True; --if there is no data in the message, the checksum is defined as ok
      end if;

	--ada.text_io.put_line("bbb_can.get: Queue.iFirst: "&Queue.iFIrst'img&" Queue.iLast: "&Queue.iLast'img&" Queue.sbuffer: "&queue.sbuffer);
	--Queue.iFirst:=1; --ludde160915
	--Queue.iLast:=1; --ludde160915

   exception
      when E : others =>
         Exception_Handling.Reraise_Exception (E, "BBB_CAN.Get(msg : out AVR.AT90CAN128.CAN.CAN_Message; bMsgReceived : out Boolean; bUARTChecksumOK : out Boolean)");
   end Get;

   --------- private functions ------------------------------------

   procedure Usart_Write (sBuffer : String; iSize : Integer) is
   begin
      --Ada.Text_IO.Put_Line("Usart_Write, iSize=" & iSize'Img);
      pxUart.Uart_Write (sBuffer, iSize, False);
   end Usart_Write;

   procedure Usart_Read (sBuffer : out String; iSize : Integer; bBytesRead : out Boolean) is
      sTempBuffer    : String (1 .. Queue.iSIZE - Queue.iDataAvailable - 1);
      iTempBytesRead : Integer;
      iBytes         : Integer;
   begin
      pxUart.UartReadSpecificAmount (sTempBuffer, Queue.iSIZE - Queue.iDataAvailable - 1, iTempBytesRead);
      --Ada.Text_IO.Put_Line("pxUart.UartReadSpecificAmount iTempBytesRead=" & iTempBytesRead'Img);

      if iTempBytesRead > 0 then
         --           for i in 1..iTempBytesRead loop
         --              Ada.Text_IO.Put_Line("sTempBuffer(" & i'Img & ")=" & Integer'Image(Character'Pos(sTempBuffer(i))));
         --           end loop;

         Queue.Write (sTempBuffer (sTempBuffer'First .. sTempBuffer'Last), iTempBytesRead, iBytes);

         if iBytes /= iTempBytesRead then
            Exception_Handling.Raise_Exception(Exception_Handling.BufferOverflow'Identity, "BBB_CAN.Usart_Read(sBuffer : out String; iSize : Integer; iBytesRead : out Integer)");
         end if;
      end if;

      --Ada.Text_IO.Put_Line("Queue.iDataAvailable=" & Integer'Image(Queue.iDataAvailable));

      if Queue.iDataAvailable >= iSize then
         Queue.Read (sBuffer, iTempBytesRead, iSize);
         bBytesRead := True;
      else
         bBytesRead := False;
      end if;

   end Usart_Read;

   procedure Usart_Read_Inf_Block (sBuffer : out String; iSize : Integer) is
      bReadCompleate : Boolean := False;
   begin
      --Ada.Text_IO.Put_Line("Usart_Read_Inf_Block begins iSize=" & iSize'Img);
      while not bReadCompleate loop
         Usart_Read (sBuffer, iSize, bReadCompleate);
      end loop;
      --Ada.Text_IO.Put_Line("Usart_Read done in Usart_Read_Inf_Block");
   exception
      when E : others =>
         Exception_Handling.Reraise_Exception (E, "BBB_CAN.Usart_Read_Inf_Block(sBuffer : out String; iSize : Integer)");
   end Usart_Read_Inf_Block;

end BBB_CAN;
