package radix is

   function Practical_Radix(this : string) return integer;
   --radix with 27 as base for assigning port number. a = 0, b = 1 ... y = 25, z = 26.

   function Radical_Pradix(this : integer) return string;
   -- Reverts a integer value back to a string.
end radix;
