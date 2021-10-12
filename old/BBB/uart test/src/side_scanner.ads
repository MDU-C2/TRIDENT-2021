with uartwrapper; use uartwrapper;
with Interfaces.C; use Interfaces.C;
with interfaces;
with Ada.Text_IO;
use Ada.Text_IO;
--------------------------------------------------------------------------------
--			Written by Jonatan Scharff Willners 		      --
--	Based on Deep Visions DSSPInterface(written by Fredrik Elmgren)	      --
--                      Interface to DSSP OEM				      --
--------------------------------------------------------------------------------

-- ********************************
-- ****     Received data      ****
-- ********************************
--
-- ** Ping Return Packet **
--  SOP1 0xFE
--  SOP2 0x05
--  Size High
--  Size Low
--  Type 0x11
--  Sequence nr 0-255, +1 per ping
--  Active Sides
--  Time High [ms]
--  Time Low  [ms]
--  D_Ch0[0] Channel 0
--  D_Ch1[1] Channel 1
--  ...
--  D_Ch0[nSamples-1]
--  D_Ch1[nSamples-1]
--  ChkSum
--
--  Next packet
--  If single side packet only data for that side is transmitted


package side_scanner is

   type u8arr is  array (integer range <>) of interfaces.unsigned_8;

   type sonarData is
      record
         SOP1, SOP2 : Interfaces.Unsigned_8;
         high, low  : Interfaces.Unsigned_8;
         typ        : Interfaces.Unsigned_8;
         sequence   : Interfaces.Unsigned_8;
         activeSides: Interfaces.Unsigned_8;
         tHigh, tLow: Interfaces.Unsigned_8;
         dataType   : Interfaces.Unsigned_8;
         IDhigh,IDlow:Interfaces.Unsigned_8;
         D_ch :u8arr(1..1000);
         checkSum:Interfaces.Unsigned_8;
      end record;



   port : pCUartHandler;
   procedure SetPulse( nPeriods : interfaces.unsigned_32; StartFreq, deltaFreq : in out float);
   procedure SetSampling(nSamples : Interfaces.Unsigned_32; decimation : Interfaces.Unsigned_32; left : boolean; right : boolean; onePing : boolean);
   procedure reset;
   procedure setPort(sPort : string; baudrate : Interfaces.Unsigned_32);
   procedure run(baudrate : Interfaces.Unsigned_32);
   function u8ToHex(val : Interfaces.Unsigned_8) return string;
   function readStart return boolean;
   function read return boolean;
   data : sonarData;
   val : u8Arr(1..1010);
private
   typeOfSensor : Interfaces.Unsigned_8 := 0;
   msgSize : integer := 2000;

end side_scanner;
