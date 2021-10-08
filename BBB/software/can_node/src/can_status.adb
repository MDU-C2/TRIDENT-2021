with Interfaces;
with ada.Unchecked_Conversion;
with tcp_client;

package body can_status is

   xConnectedCanNodes : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   iNrConnectedNodes : integer := 0;
   iMaxNodes : constant integer := 16;

   sNodeArray : array (1 .. iMaxNodes) of string(1 .. 8) := (others => "        ");

   type BoolArray is array (1 .. iMaxNodes) of Boolean;
   pragma pack(BoolArray);

   bPingSuccess : BoolArray := (others => false);

   bConnected : BoolArray := (others => false);
--     u8checksum : Interfaces.Unsigned_16;

   function Get_Checksum is new ada.Unchecked_Conversion(Source => BoolArray, Target => Interfaces.Unsigned_16);

   procedure Send_Node_list is
      bSuccess : Boolean := false;
      sNodeList : string (1 .. iNrConnectedNodes * 9);
      begin
         for i in 1..iNrConnectedNodes - 1 loop
            sNodeList((i - 1) * 9 + 1 .. i * 9) := sNodeArray(i) & ',';
         end loop;
      sNodeList((iNrConnectedNodes - 1) * 9 .. iNrConnectedNodes * 9) := sNodeArray(iNrConnectedNodes) & '.';

      xConnectedCanNodes.Set_Field("nodes",sNodeList);
      tcp_client.Send(xConnectedCanNodes,bSuccess);
      xConnectedCanNodes := GNATCOLL.JSON.JSON_Null;
   end Send_Node_list;



   procedure Add_Node(xCanMsg : CAN_Defs.CAN_Message) is
      sNameHolder : string (1 .. 8) := (others => ' ');
      bInlist : Boolean := false;
   begin
      for i in 1..8 loop
         sNameHolder(i) := Character'val(xCanMsg.Data(CAN_Defs.DLC_Type(i)));
      end loop;

      for i in 1 .. iMaxNodes loop
         if sNameHolder = sNodeArray(i) then
            bPingSuccess(i) := true;
            bInlist := true;
            exit;
         end if;
      end loop;

      if bInlist = false then
         for i in 1 .. iMaxNodes loop
            if bConnected(i) = false then
               if iNrConnectedNodes <= iMaxNodes then
                  bConnected(i) := true;
                  sNodeArray(i) := sNameHolder;
                  bPingSuccess(i) := true;
               end if;
            end if;
         end loop;
      end if;

   end;

end can_status;
