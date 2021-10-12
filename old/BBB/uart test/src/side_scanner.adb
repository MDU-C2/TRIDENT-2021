
package body side_scanner is

   REG_COMMAND : constant Interfaces.Unsigned_16 :=  16#01#;
   C_COMMAND_SHOOT : constant Interfaces.Unsigned_16 := 16#01#;
   C_COMMAND_RESET : constant Interfaces.Unsigned_16 := 16#02#;
   C_COMMAND_GET_VERSION : constant Interfaces.Unsigned_16 := 16#03#;

   REG_PULSER_1_A : constant Interfaces.Unsigned_16 := 16#11#;
   REG_PULSER_2_A : constant Interfaces.Unsigned_16 := 16#12#;

   REG_POW_DET_0_A: constant Interfaces.Unsigned_16 := 16#20#;
   REG_POW_DET_1_A: constant Interfaces.Unsigned_16 := 16#21#;
   REG_POW_DET_2_A: constant Interfaces.Unsigned_16 := 16#22#;
   REG_POW_DET_3_A: constant Interfaces.Unsigned_16 := 16#23#;
   REG_POW_DET_4_A: constant Interfaces.Unsigned_16 := 16#24#;
   REG_POW_DET_5_A: constant Interfaces.Unsigned_16 := 16#25#;
   REG_POW_DET_6_A: constant Interfaces.Unsigned_16 := 16#26#;


   procedure setPort(sPort : string; baudrate : Interfaces.Unsigned_32) is
   begin
      case baudrate is
         when 9600 =>
            port := pxCreate(sPort, B9600, Interfaces.C.int(0), 2000, Interfaces.C.int(0));
         when 115200 =>
            port := pxCreate(sPort, B115200, Interfaces.C.int(0), 10000, Interfaces.C.int(0));
         when others => --error
            null;
      end case;
   end setPort;


   function u8ToHex(val : Interfaces.Unsigned_8) return string is
      use Interfaces;
      str : string(1..2);
      function u4ToHex(val2 : Interfaces.Unsigned_8) return Character is
      begin
         case val2 is
            when 10 => return 'A';
            when 11 => return 'B';
            when 12 => return 'C';
            when 13 => return 'D';
            when 14 => return 'E';
            when 15 => return 'F';
            when others => return Character'Val(48+val2);
         end case;
      end u4ToHex;
   begin
      str(1) := u4ToHex(val2 => val/16);
      str(2) := u4ToHex(val2 => val mod 16);
      return str;
   end u8ToHex;

   procedure SetReg(reg : interfaces.unsigned_16; value : interfaces.unsigned_32);

   procedure SetReg(reg : interfaces.unsigned_16; value : interfaces.unsigned_32) is
      use Interfaces;
      i  : integer := 0;
      --        type u8arr is  array (0..7) of interfaces.unsigned_8;
      txBuff : u8arr(0..7);
   begin
      ada.text_io.put_line("");--setReg :" & value'img);

      txBuff(0) := 16#F5#;

      txBuff(1) := interfaces.unsigned_8(Interfaces.shift_right(reg,8)) and Interfaces.Unsigned_8(16#FF#);
      txBuff(2) := interfaces.unsigned_8(reg) and Interfaces.Unsigned_8(16#FF#) ;
      txBuff(3) := interfaces.unsigned_8(shift_right(value,24) and 16#FF#) ;
      txBuff(4) := interfaces.unsigned_8(shift_right(value,16) and 16#FF#);
      txBuff(5) := interfaces.unsigned_8(shift_right(value,8) and 16#FF#) ;
      txBuff(6) := interfaces.unsigned_8(value and 16#FF#);
      txBuff(7) := 0;


      for j in 0..6 loop
         txBuff(7)  := txBuff(7) + txBuff(j);
      end loop;
      ada.text_io.put("Sending : ");
      for j in 0..7 loop
         Ada.Text_IO.put(u8ToHex(txBuff(j)));
         ada.text_io.put("  ");
         --           Ada.Text_IO.put(txBuff(j)'img);

         declare
            s : string(1..1);
         begin
            s(1) := Character'Val(txBuff(j));
            Uart_Write(this              => port.all,
                       stringToBeWritten => s);
         end;

      end loop;
      ada.text_io.put_line("");
   end SetReg;



   procedure SetPulse( nPeriods : interfaces.unsigned_32; StartFreq, deltaFreq : in out float) is
      --  nPeriods     - Number of periods
      --  StartFreq  - Start frequency in [Hz]
      --  DeltaFreq  - Chirp delta frequency in [Hz], must be positive, DeltaFreq=(StopFreq-StartFreq)
      use interfaces;
      chirpDown : interfaces.unsigned_32 := 0;
      F0 : interfaces.unsigned_32 := 0;
      dfr : interfaces.unsigned_32 := 0;
      temp1, temp2 : float;
   begin

      if deltaFreq < 0.0 then
         deltaFreq := -deltaFreq;
         chirpDown := 16#80000000#;
      end if;

      F0 := interfaces.unsigned_32(StartFreq * 0.0131072);-- + 0.5);
      temp1 := StartFreq * 0.0131072;

      dfr := interfaces.unsigned_32(DeltaFreq * 1.666667 / float(nPeriods));-- + 0.5 );
      temp2 := DeltaFreq * 1.666667 / float(nPeriods);

      ada.text_io.put_line("f0 : " & F0'img & temp1'img);
      ada.text_io.put_line("dfr : " & dfr'img & temp2'img);

      SetReg(reg   => REG_PULSER_1_A,
             value => Interfaces.Unsigned_32(Shift_left(dfr, 16) or (16#FFFF# and F0)));

      SetReg(reg   => REG_PULSER_2_A,
             value => chirpDown or Interfaces.Unsigned_32(Shift_Left((16#03FF# and nPeriods), 16)));
   end setpulse;


   procedure SetSampling(nSamples : Interfaces.Unsigned_32;                     -- Number of samples
                         decimation : Interfaces.Unsigned_32;  			-- Sample resolution = 0.1781303[mm] * decimation, min TBD, max TBD
                         left : boolean; right : boolean; onePing : boolean) is --onePing false if continuous ping
      use Interfaces;
      pd_mode : Interfaces.Unsigned_32  := 1;
      pd_nSamples : Interfaces.Unsigned_32 := decimation;
      PD_ActiveChannels : Interfaces.Unsigned_8  := 0;

   begin

      if( left ) then
         PD_ActiveChannels := PD_ActiveChannels or 16#01#;
      end if;
      if( right ) then
         PD_ActiveChannels := PD_ActiveChannels or 16#02#;
      end if;

      SetReg(reg   => Interfaces.Unsigned_16(REG_POW_DET_1_A),
             value =>  Interfaces.Unsigned_32(Shift_Left(PD_nSamples, 16) or Interfaces.Unsigned_32(Shift_Left(PD_ActiveChannels ,3)) or (PD_Mode)));
      SetReg( Interfaces.Unsigned_16(REG_POW_DET_5_A), Interfaces.Unsigned_32(nSamples));
      if( onePing ) then
         SetReg( Interfaces.Unsigned_16(REG_POW_DET_0_A), Shift_Left(1, 16));
      end if;
   end SetSampling;

   procedure reset is-- Set baudrate to 9600 before Reset command
   begin
      SetReg(16#AB#, 16#05060708#);
   end reset;


   procedure run(baudrate : Interfaces.Unsigned_32) is
   begin

      case baudrate is
         when 115200  => setReg(16#01#, 694);
         when 230400  => SetReg(16#01#, 16#15B#);
         when 460800  => SetReg(16#01#, 16#AD#);
         when 921600  => SetReg(16#01#, 16#56#);
         when 1000000 => SetReg(16#01#, 16#50#);
         when others => --error
            null;
      end case;
   end run;

   function readStart return boolean is
      use Interfaces;
      txBuff : u8arr(1..4);
      function checkCrc return boolean is
      begin
         Ada.text_io.Put("Start package : ");
         for i in 1..4 loop
            Ada.Text_IO.put(u8ToHex(txBuff(i)));
            ada.text_io.put("  ");
         end loop;
         typeOfSensor := txBuff(3);
         Ada.text_io.New_Line;
         return true;
      end checkCrc;
      inMsg : string(1..8);
      bytesRecived : integer := 0;
      counter : integer := 1;
      startByte : boolean := false;
   begin
      Ada.Text_IO.Put_Line("fetching startbytes");
      loop
         declare
         begin
            UartRead(this          => port.all,
                     sStringRead   => inMsg,
                     iNumBytesRead => bytesRecived);
            if bytesRecived > 0 then
               for i in 1..bytesRecived loop
                  if inMsg(i) = Character'val(16#A5#) then
                     startByte := true;
                     Ada.Text_IO.Put_Line("byte A5 found!");
                  end if;
                  if startByte then
                     txBuff(counter) := Character'pos(inMsg(i));
                     counter := counter + 1;
                  end if;
                  if counter > 4 then
                     if checkCrc then
                        return true;
                     else return false;
                     end if;
                  end if;
               end loop;
            end if;
         exception
            when Constraint_Error => Ada.Text_IO.Put_Line("constraint error ignored");
         end;
      end loop;



   end readStart;

   function read return boolean is
      use Interfaces;
      inMsg : string(1..msgSize);
      bytesRecived : integer := 0;
      counter : integer := 1;
      startByte : boolean := false;
   begin
      loop
         UartRead(this          => port.all,
                  sStringRead   => inMsg,
                  iNumBytesRead => bytesRecived);
         if bytesRecived > 0 then
            for i in 1..bytesRecived loop
               if inMsg(i) = Character'val(16#FE#) then
                  counter := 0;
                  startByte := true;
               end if;
               if startByte then
                  counter := counter + 1;
                  val(counter) := Character'pos(inMsg(i));
                  if counter = 1010 then
                     startByte := false;
                     data.SOP1 := val(1);
                     data.SOP2 := val(2);
                     data.high := val(3);
                     data.low := val(4);
                     data.sequence := val(5);
                     data.activeSides := val(6);
                     data.tHigh := val(7);
                     data.tLow := val(8);
                     data.dataType := val(9);
                     data.IDhigh := val(10);
                     data.IDlow := val(11);
                     for k in 1..999 loop
                        data.D_ch(k) := val(k+11);
                     end loop;
                     return true;
                  end if;
               end if;
            end loop;
         end if;
      end loop;
      return true;
   end read;


end side_scanner;
