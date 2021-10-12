with uartwrapper; use uartwrapper;
with Interfaces.C; use Interfaces.C;
with interfaces;
with Ada.Text_IO;
use Ada.Text_IO;
with side_scanner; use side_scanner;
procedure Main is
   bytesRecived : integer := 0;
   startFreq : float := 330000.0;
   deltaFreq : float := 30000.0;
begin

   setPort(sPort    => "/dev/ttyO1",
           baudrate => 9600);

   reset;
   if readStart then
      Ada.Text_IO.Put_Line("correct startMessage");
   end if;
   SetPulse(nPeriods  => 32,
            StartFreq => startFreq,
            deltaFreq => deltaFreq);

   SetSampling(nSamples   => 1000,
               decimation => 140,
               left       => true,
               right      => false,
               onePing    => false);
   Run(baudrate => 115200);
   setPort(sPort    => "/dev/ttyO1",
           baudrate => 115200);

   loop
      if read then
         null;
         Ada.Text_IO.New_Line;
         Ada.Text_IO.Put_Line(u8ToHex(data.SOP1) & u8ToHex(data.SOP2) & u8ToHex(data.high) & u8ToHex(data.low) & " type " & u8ToHex(data.typ)
                              & " seq " & u8ToHex(data.sequence) & " as " & u8ToHex(data.activeSides)  & " tLow " & u8ToHex(data.tLow) & " tHigh " & u8ToHex(data.tHigh)
                               & " dtyp " & u8ToHex(data.dataType)  & " ih " & u8ToHex(data.IDhigh) & " il " & u8ToHex(data.IDlow));
        Ada.Text_IO.Put_Line("crc : " & u8ToHex(val(1010)));
         Ada.Text_IO.Put_Line("val 1-21 : ");
         for i in 1..21 loop
            Ada.Text_IO.Put( u8ToHex(data.D_ch(i))); Ada.Text_IO.Put(" ");
         end loop;

      end if;
      Ada.Text_IO.New_Line;


   end loop;
   --     Ada.Text_IO.Put_Line("main done");
end Main;
