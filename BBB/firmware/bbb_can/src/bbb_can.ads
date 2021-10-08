with CAN_Defs;
--  with AVR.AT90CAN128;
--  with AVR.AT90CAN128.CAN;
with UartWrapper;
with GNAT.Serial_Communications;
with Interfaces;

package BBB_CAN is
   iHANDSHAKE_WAIT_TIME_MS : constant Integer := 200;
   procedure read_imu (fRoll, fPitch, fYaw, fX, fY, fZ : in out Float);
   procedure Usart_Read_imu(handle : in UartWrapper.pCUartHandler; sBuffer : out String; iSize : Integer; bBytesRead : out integer);
   procedure Usart_Write_imu (handle : in UartWrapper.pCUartHandler; sBuffer : String; iSize : Integer);
   procedure Init (sPort : String; baud : UartWrapper.BaudRates);
   procedure init_imu (baud : UartWrapper.BaudRates);

   -- Tries a handshake, if no answer is received after iHANDSHAKE_WAIT_TIME_MS it returns false
   -- if handshake was successful, true is returned
   -- function Handshake return Boolean;
   procedure Send (msg : CAN_Defs.CAN_Message);

   -- Tries to return a CAN message
   -- bUARTChecksumOK returns false if there was an error in the data transfer over the UART
   procedure Get(msg : out CAN_Defs.CAN_Message; bMsgReceived : out Boolean; bUARTChecksumOK : out Boolean);
private
   procedure Usart_Read(sBuffer : out String; iSize : Integer; bBytesRead : out Boolean);
   procedure Usart_Write (sBuffer : String; iSize : Integer);
   procedure Usart_Read_Inf_Block (sBuffer : out String; iSize : Integer);
end BBB_CAN;
