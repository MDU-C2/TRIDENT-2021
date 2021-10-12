with CAN_Defs;
with GNATCOLL.JSON;
with GNATCOLL;

package can_status is


   procedure Add_Node(xCanMsg : CAN_Defs.CAN_Message);
   procedure Send_Node_list;


end can_status;
