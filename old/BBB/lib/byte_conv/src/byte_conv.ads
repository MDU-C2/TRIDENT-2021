
with Interfaces;
with ada.Unchecked_Conversion;
with CAN_Defs;

package byte_conv is





   function Byte2ToUsign16  (Data : CAN_Defs.Byte8; StartByte : CAN_Defs.DLC_Type) return Interfaces.Unsigned_16;
   function Byte4ToFloat  (Data : CAN_Defs.Byte8; StartByte : CAN_Defs.DLC_Type) return Float;
   function Byte4ToInt  (Data : CAN_Defs.Byte8; StartByte : CAN_Defs.DLC_Type) return integer;
   function Byte4ToUnsign32  (Data : CAN_Defs.Byte8; StartByte : CAN_Defs.DLC_Type) return Interfaces.Unsigned_32;


   function IntToByte4  (Data : integer; StartByte : CAN_Defs.DLC_Type) return CAN_Defs.Byte8;
   function FloatToByte4  (Data : float; StartByte : CAN_Defs.DLC_Type) return CAN_Defs.Byte8;
   function Unsign16ToByte2  (Data : Interfaces.Unsigned_16; StartByte : CAN_Defs.DLC_Type) return CAN_Defs.Byte8;
   function Unsign32ToByte4  (Data : Interfaces.Unsigned_32; StartByte : CAN_Defs.DLC_Type) return CAN_Defs.Byte8;


end byte_conv;
