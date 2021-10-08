package body radix is

   function Practical_Radix(this : string) return integer is
      iCounter : integer := 0;
      iValue : integer := 0;
   begin
      for i in reverse 1..this'last loop
         iValue := iValue + (Character'Pos(this(i)) - 97)*(26**iCounter);
         iCounter := iCounter + 1;
      end loop;
      return iValue;
   end Practical_Radix;


   function Radical_Pradix(this : integer) return string is

      holder : String := this'img;
      sReturn: string := this'img;
      iCharValue : integer := this;
      iOldValue : integer := this;


   begin
      if this < 0 then
         return "a";
      end if;

      for i in holder'Range loop

         iCharValue := (iOldValue mod 26);
         iOldValue := integer(iOldValue / 26);
         holder(i) := Character'val(iCharValue + 97);
         if iOldValue = 0 then
            for j in reverse 1 .. i loop
               sReturn(j) := holder(i - j + 1);
            end loop;
            return sReturn(1..i);
         end if;
      end loop;

      return "a";

   end Radical_Pradix;

end radix;
