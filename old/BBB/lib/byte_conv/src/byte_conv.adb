with CAN_Defs; use CAN_Defs;
with Ada.Exceptions; use Ada.Exceptions;
With Ada.Text_IO;
package body byte_conv is

   type Byte2 is record
      one : Interfaces.Unsigned_8;
      two : Interfaces.Unsigned_8;
   end record;

   type Byte4 is record
      one : Interfaces.Unsigned_8;
      two : Interfaces.Unsigned_8;
      three : Interfaces.Unsigned_8;
      four : Interfaces.Unsigned_8;
   end record;

   function ConvByte2ToUn16 is new ada.Unchecked_Conversion(Source => Byte2, Target => Interfaces.Unsigned_16);
   function ConvByte4ToUn32 is new ada.Unchecked_Conversion(Source => Byte4, Target => Interfaces.Unsigned_32);
   function ConvByte4ToFloat is new ada.Unchecked_Conversion(Source => Byte4, Target => float);
   function ConvByte4ToInt is new ada.Unchecked_Conversion(Source => Byte4, Target => integer);

   function ConvUn16ToByte2 is new ada.Unchecked_Conversion(Target => Byte2, Source => Interfaces.Unsigned_16);
   function ConvUn32ToByte4 is new ada.Unchecked_Conversion(Target => Byte4, Source => Interfaces.Unsigned_32);
   function ConvFloatToByte4 is new ada.Unchecked_Conversion(Target => Byte4, Source => float);
   function ConvIntToByte4 is new ada.Unchecked_Conversion(Target => Byte4, Source => integer);



   function Byte2ToUsign16  (Data : CAN_Defs.Byte8; StartByte : CAN_Defs.DLC_Type) return Interfaces.Unsigned_16 is
      Holder : Byte2;
   begin
      if StartByte < 8 and StartByte > 0 then
         declare
         begin
            Holder.one := data(StartByte);
            Holder.two := data(StartByte + 1);
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Byte2ToUsign16 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;
         return ConvByte2ToUn16(holder);
      else
         return 0;
      end if;
   end Byte2ToUsign16;


   function Byte4ToUnsign32  (Data : CAN_Defs.Byte8; StartByte : CAN_Defs.DLC_Type) return Interfaces.Unsigned_32 is
      Holder : Byte4;
   begin
      if StartByte < 6 and StartByte > 0 then
         declare
         begin
            Holder.one := data(StartByte);
            Holder.two := data(StartByte + 1);
            Holder.three := data(StartByte + 2);
            Holder.four := data(StartByte + 3);
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Byte4ToUnsign32 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;
         return ConvByte4ToUn32(holder);
      else
         return 0;
      end if;


   end Byte4ToUnsign32;


   function Byte4ToFloat  (Data : CAN_Defs.Byte8; StartByte : CAN_Defs.DLC_Type) return Float is
      Holder : Byte4;
   begin
      if StartByte < 6 and StartByte > 0 then
         declare
         begin
            Holder.one := data(StartByte);
            Holder.two := data(StartByte + 1);
            Holder.three := data(StartByte + 2);
            Holder.four := data(StartByte + 3);
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Byte4ToFloat Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;
         return ConvByte4ToFloat(holder);
      else
         return 0.0;
      end if;

   end Byte4ToFloat;

   function Byte4ToInt  (Data : CAN_Defs.Byte8; StartByte : CAN_Defs.DLC_Type) return integer is
      Holder : Byte4;
   begin
      if StartByte < 6 and StartByte > 0 then
         declare
         begin
            Holder.one := data(StartByte);
            Holder.two := data(StartByte + 1);
            Holder.three := data(StartByte + 2);
            Holder.four := data(StartByte + 3);
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Byte4ToInt Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;
         return ConvByte4ToInt(holder);

      else
         return 0;
      end if;
   end Byte4ToInt;



   function IntToByte4  (Data : integer; StartByte : CAN_Defs.DLC_Type) return CAN_Defs.Byte8 is
      Holder : Byte4;
      ReturnData : CAN_Defs.Byte8 := (0, 0, 0, 0, 0, 0, 0, 0);
   begin

      if StartByte < 6 and StartByte > 0 then
         declare
         begin
            holder := ConvIntToByte4(Data);
            ReturnData(StartByte) := holder.one;
            ReturnData(StartByte + 1) := holder.two;
            ReturnData(StartByte + 2) := holder.three;
            ReturnData(StartByte + 3) := holder.four;
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("IntToByte4 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;

      end if;
      return ReturnData;

   end IntToByte4;



   function FloatToByte4  (Data : float; StartByte : CAN_Defs.DLC_Type) return CAN_Defs.Byte8 is
      Holder : Byte4;
      ReturnData : CAN_Defs.Byte8 := (0, 0, 0, 0, 0, 0, 0, 0);
   begin

      if StartByte < 6 and StartByte > 0 then
         declare
         begin
            holder := ConvFloatToByte4(Data);
            ReturnData(StartByte) := holder.one;
            ReturnData(StartByte + 1) := holder.two;
            ReturnData(StartByte + 2) := holder.three;
            ReturnData(StartByte + 3) := holder.four;
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("FloatToByte4 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;

      end if;
      return ReturnData;
   end FloatToByte4;

   function Unsign32ToByte4  (Data : Interfaces.Unsigned_32; StartByte : CAN_Defs.DLC_Type) return CAN_Defs.Byte8 is
      Holder : Byte4;
      ReturnData : CAN_Defs.Byte8 := (0, 0, 0, 0, 0, 0, 0, 0);
   begin

      if StartByte < 6 and StartByte > 0 then
         declare
         begin
            holder := ConvUn32ToByte4(Data);
            ReturnData(StartByte) := holder.one;
            ReturnData(StartByte + 1) := holder.two;
            ReturnData(StartByte + 2) := holder.three;
            ReturnData(StartByte + 3) := holder.four;
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Unsign32ToByte4 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;

      end if;
      return ReturnData;
   end Unsign32ToByte4;



   function Unsign16ToByte2  (Data : Interfaces.Unsigned_16; StartByte : CAN_Defs.DLC_Type) return CAN_Defs.Byte8 is
      Holder : Byte2;
      ReturnData : CAN_Defs.Byte8 := (0, 0, 0, 0, 0, 0, 0, 0);
   begin

      if StartByte < 8 and StartByte > 0 then
         declare
         begin
            holder := ConvUn16ToByte2(Data);
            ReturnData(StartByte) := holder.one;
            ReturnData(StartByte + 1) := holder.two;
         exception
            when E : others =>
               Ada.Text_IO.Put_Line("Unsign16ToByte2 Exception: " & Ada.Exceptions.Exception_Name(E) & ": " & Ada.Exceptions.Exception_Message(E));
         end;
      end if;
      return ReturnData;
   end Unsign16ToByte2;











end byte_conv;

