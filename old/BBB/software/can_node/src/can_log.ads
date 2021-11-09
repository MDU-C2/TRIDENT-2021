with CAN_Defs;
package can_log is

   procedure Log_Data_From_Can(isOutput : boolean; msg : can_defs.can_message);

end can_log;
