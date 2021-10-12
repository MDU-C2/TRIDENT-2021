pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b__motion_control_main.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b__motion_control_main.adb");

with System.Restrictions;
with Ada.Exceptions;

package body ada_main is
   pragma Warnings (Off);

   E015 : Short_Integer; pragma Import (Ada, E015, "system__soft_links_E");
   E123 : Short_Integer; pragma Import (Ada, E123, "system__fat_flt_E");
   E111 : Short_Integer; pragma Import (Ada, E111, "system__fat_llf_E");
   E025 : Short_Integer; pragma Import (Ada, E025, "system__exception_table_E");
   E226 : Short_Integer; pragma Import (Ada, E226, "ada__containers_E");
   E080 : Short_Integer; pragma Import (Ada, E080, "ada__io_exceptions_E");
   E136 : Short_Integer; pragma Import (Ada, E136, "ada__numerics_E");
   E178 : Short_Integer; pragma Import (Ada, E178, "ada__strings_E");
   E180 : Short_Integer; pragma Import (Ada, E180, "ada__strings__maps_E");
   E183 : Short_Integer; pragma Import (Ada, E183, "ada__strings__maps__constants_E");
   E063 : Short_Integer; pragma Import (Ada, E063, "ada__tags_E");
   E061 : Short_Integer; pragma Import (Ada, E061, "ada__streams_E");
   E050 : Short_Integer; pragma Import (Ada, E050, "interfaces__c_E");
   E082 : Short_Integer; pragma Import (Ada, E082, "interfaces__c__strings_E");
   E031 : Short_Integer; pragma Import (Ada, E031, "system__exceptions_E");
   E079 : Short_Integer; pragma Import (Ada, E079, "system__finalization_root_E");
   E077 : Short_Integer; pragma Import (Ada, E077, "ada__finalization_E");
   E098 : Short_Integer; pragma Import (Ada, E098, "system__storage_pools_E");
   E090 : Short_Integer; pragma Import (Ada, E090, "system__finalization_masters_E");
   E104 : Short_Integer; pragma Import (Ada, E104, "system__storage_pools__subpools_E");
   E159 : Short_Integer; pragma Import (Ada, E159, "system__task_info_E");
   E008 : Short_Integer; pragma Import (Ada, E008, "ada__calendar_E");
   E006 : Short_Integer; pragma Import (Ada, E006, "ada__calendar__delays_E");
   E100 : Short_Integer; pragma Import (Ada, E100, "system__pool_global_E");
   E249 : Short_Integer; pragma Import (Ada, E249, "gnat__sockets_E");
   E088 : Short_Integer; pragma Import (Ada, E088, "system__file_control_block_E");
   E235 : Short_Integer; pragma Import (Ada, E235, "ada__streams__stream_io_E");
   E075 : Short_Integer; pragma Import (Ada, E075, "system__file_io_E");
   E256 : Short_Integer; pragma Import (Ada, E256, "system__pool_size_E");
   E019 : Short_Integer; pragma Import (Ada, E019, "system__secondary_stack_E");
   E185 : Short_Integer; pragma Import (Ada, E185, "ada__strings__unbounded_E");
   E254 : Short_Integer; pragma Import (Ada, E254, "gnat__sockets__thin_common_E");
   E252 : Short_Integer; pragma Import (Ada, E252, "gnat__sockets__thin_E");
   E085 : Short_Integer; pragma Import (Ada, E085, "system__os_lib_E");
   E233 : Short_Integer; pragma Import (Ada, E233, "system__strings__stream_ops_E");
   E265 : Short_Integer; pragma Import (Ada, E265, "system__tasking__initialization_E");
   E273 : Short_Integer; pragma Import (Ada, E273, "system__tasking__protected_objects_E");
   E143 : Short_Integer; pragma Import (Ada, E143, "ada__real_time_E");
   E060 : Short_Integer; pragma Import (Ada, E060, "ada__text_io_E");
   E275 : Short_Integer; pragma Import (Ada, E275, "system__tasking__protected_objects__entries_E");
   E271 : Short_Integer; pragma Import (Ada, E271, "system__tasking__queuing_E");
   E261 : Short_Integer; pragma Import (Ada, E261, "system__tasking__stages_E");
   E173 : Short_Integer; pragma Import (Ada, E173, "gnatcoll__json_E");
   E198 : Short_Integer; pragma Import (Ada, E198, "gnatcoll__json__utility_E");
   E125 : Short_Integer; pragma Import (Ada, E125, "pid_E");
   E239 : Short_Integer; pragma Import (Ada, E239, "radix_E");
   E243 : Short_Integer; pragma Import (Ada, E243, "server_net_E");
   E169 : Short_Integer; pragma Import (Ada, E169, "tcp_client_E");
   E167 : Short_Integer; pragma Import (Ada, E167, "pid_utils_E");

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
   begin
      E167 := E167 - 1;
      declare
         procedure F1;
         pragma Import (Ada, F1, "pid_utils__finalize_spec");
      begin
         F1;
      end;
      E243 := E243 - 1;
      declare
         procedure F2;
         pragma Import (Ada, F2, "server_net__finalize_spec");
      begin
         F2;
      end;
      E173 := E173 - 1;
      declare
         procedure F3;
         pragma Import (Ada, F3, "gnatcoll__json__finalize_spec");
      begin
         F3;
      end;
      E275 := E275 - 1;
      declare
         procedure F4;
         pragma Import (Ada, F4, "system__tasking__protected_objects__entries__finalize_spec");
      begin
         F4;
      end;
      E060 := E060 - 1;
      declare
         procedure F5;
         pragma Import (Ada, F5, "ada__text_io__finalize_spec");
      begin
         F5;
      end;
      declare
         procedure F6;
         pragma Import (Ada, F6, "gnat__sockets__finalize_body");
      begin
         E249 := E249 - 1;
         F6;
      end;
      declare
         procedure F7;
         pragma Import (Ada, F7, "system__file_io__finalize_body");
      begin
         E075 := E075 - 1;
         F7;
      end;
      E185 := E185 - 1;
      declare
         procedure F8;
         pragma Import (Ada, F8, "ada__strings__unbounded__finalize_spec");
      begin
         F8;
      end;
      E090 := E090 - 1;
      E104 := E104 - 1;
      E256 := E256 - 1;
      declare
         procedure F9;
         pragma Import (Ada, F9, "system__pool_size__finalize_spec");
      begin
         F9;
      end;
      E235 := E235 - 1;
      declare
         procedure F10;
         pragma Import (Ada, F10, "ada__streams__stream_io__finalize_spec");
      begin
         F10;
      end;
      declare
         procedure F11;
         pragma Import (Ada, F11, "system__file_control_block__finalize_spec");
      begin
         E088 := E088 - 1;
         F11;
      end;
      declare
         procedure F12;
         pragma Import (Ada, F12, "gnat__sockets__finalize_spec");
      begin
         F12;
      end;
      E100 := E100 - 1;
      declare
         procedure F13;
         pragma Import (Ada, F13, "system__pool_global__finalize_spec");
      begin
         F13;
      end;
      declare
         procedure F14;
         pragma Import (Ada, F14, "system__storage_pools__subpools__finalize_spec");
      begin
         F14;
      end;
      declare
         procedure F15;
         pragma Import (Ada, F15, "system__finalization_masters__finalize_spec");
      begin
         F15;
      end;
      declare
         procedure Reraise_Library_Exception_If_Any;
            pragma Import (Ada, Reraise_Library_Exception_If_Any, "__gnat_reraise_library_exception_if_any");
      begin
         Reraise_Library_Exception_If_Any;
      end;
   end finalize_library;

   procedure adafinal is
      procedure s_stalib_adafinal;
      pragma Import (C, s_stalib_adafinal, "system__standard_library__adafinal");
   begin
      if not Is_Elaborated then
         return;
      end if;
      Is_Elaborated := False;
      s_stalib_adafinal;
   end adafinal;

   type No_Param_Proc is access procedure;

   procedure adainit is
      Main_Priority : Integer;
      pragma Import (C, Main_Priority, "__gl_main_priority");
      Time_Slice_Value : Integer;
      pragma Import (C, Time_Slice_Value, "__gl_time_slice_val");
      WC_Encoding : Character;
      pragma Import (C, WC_Encoding, "__gl_wc_encoding");
      Locking_Policy : Character;
      pragma Import (C, Locking_Policy, "__gl_locking_policy");
      Queuing_Policy : Character;
      pragma Import (C, Queuing_Policy, "__gl_queuing_policy");
      Task_Dispatching_Policy : Character;
      pragma Import (C, Task_Dispatching_Policy, "__gl_task_dispatching_policy");
      Priority_Specific_Dispatching : System.Address;
      pragma Import (C, Priority_Specific_Dispatching, "__gl_priority_specific_dispatching");
      Num_Specific_Dispatching : Integer;
      pragma Import (C, Num_Specific_Dispatching, "__gl_num_specific_dispatching");
      Main_CPU : Integer;
      pragma Import (C, Main_CPU, "__gl_main_cpu");
      Interrupt_States : System.Address;
      pragma Import (C, Interrupt_States, "__gl_interrupt_states");
      Num_Interrupt_States : Integer;
      pragma Import (C, Num_Interrupt_States, "__gl_num_interrupt_states");
      Unreserve_All_Interrupts : Integer;
      pragma Import (C, Unreserve_All_Interrupts, "__gl_unreserve_all_interrupts");
      Zero_Cost_Exceptions : Integer;
      pragma Import (C, Zero_Cost_Exceptions, "__gl_zero_cost_exceptions");
      Detect_Blocking : Integer;
      pragma Import (C, Detect_Blocking, "__gl_detect_blocking");
      Default_Stack_Size : Integer;
      pragma Import (C, Default_Stack_Size, "__gl_default_stack_size");
      Leap_Seconds_Support : Integer;
      pragma Import (C, Leap_Seconds_Support, "__gl_leap_seconds_support");

      procedure Install_Handler;
      pragma Import (C, Install_Handler, "__gnat_install_handler");

      Handler_Installed : Integer;
      pragma Import (C, Handler_Installed, "__gnat_handler_installed");

      Finalize_Library_Objects : No_Param_Proc;
      pragma Import (C, Finalize_Library_Objects, "__gnat_finalize_library_objects");
   begin
      if Is_Elaborated then
         return;
      end if;
      Is_Elaborated := True;
      Main_Priority := -1;
      Time_Slice_Value := -1;
      WC_Encoding := 'b';
      Locking_Policy := ' ';
      Queuing_Policy := ' ';
      Task_Dispatching_Policy := ' ';
      System.Restrictions.Run_Time_Restrictions :=
        (Set =>
          (False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False, False, False, False),
         Value => (0, 0, 0, 0, 0, 0, 0),
         Violated =>
          (False, False, True, True, False, False, False, True, 
           False, True, True, True, True, False, False, True, 
           False, False, True, True, False, True, True, True, 
           True, True, True, False, False, True, False, True, 
           False, False, True, False, False, True, False, True, 
           False, True, False, False, True, False, True, False, 
           False, False, False, True, False, True, True, True, 
           False, False, True, False, False, True, False, True, 
           False, False, True, True, True, False, True, False, 
           False, False, True, False, False, False),
         Count => (0, 0, 0, 1, 0, 0, 0),
         Unknown => (False, False, False, False, False, False, False));
      Priority_Specific_Dispatching :=
        Local_Priority_Specific_Dispatching'Address;
      Num_Specific_Dispatching := 0;
      Main_CPU := -1;
      Interrupt_States := Local_Interrupt_States'Address;
      Num_Interrupt_States := 0;
      Unreserve_All_Interrupts := 0;
      Zero_Cost_Exceptions := 1;
      Detect_Blocking := 0;
      Default_Stack_Size := -1;
      Leap_Seconds_Support := 0;

      if Handler_Installed = 0 then
         Install_Handler;
      end if;

      Finalize_Library_Objects := finalize_library'access;

      System.Soft_Links'Elab_Spec;
      System.Fat_Flt'Elab_Spec;
      E123 := E123 + 1;
      System.Fat_Llf'Elab_Spec;
      E111 := E111 + 1;
      System.Exception_Table'Elab_Body;
      E025 := E025 + 1;
      Ada.Containers'Elab_Spec;
      E226 := E226 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E080 := E080 + 1;
      Ada.Numerics'Elab_Spec;
      E136 := E136 + 1;
      Ada.Strings'Elab_Spec;
      E178 := E178 + 1;
      Ada.Strings.Maps'Elab_Spec;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E183 := E183 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Streams'Elab_Spec;
      E061 := E061 + 1;
      Interfaces.C'Elab_Spec;
      Interfaces.C.Strings'Elab_Spec;
      System.Exceptions'Elab_Spec;
      E031 := E031 + 1;
      System.Finalization_Root'Elab_Spec;
      E079 := E079 + 1;
      Ada.Finalization'Elab_Spec;
      E077 := E077 + 1;
      System.Storage_Pools'Elab_Spec;
      E098 := E098 + 1;
      System.Finalization_Masters'Elab_Spec;
      System.Storage_Pools.Subpools'Elab_Spec;
      System.Task_Info'Elab_Spec;
      E159 := E159 + 1;
      Ada.Calendar'Elab_Spec;
      Ada.Calendar'Elab_Body;
      E008 := E008 + 1;
      Ada.Calendar.Delays'Elab_Body;
      E006 := E006 + 1;
      System.Pool_Global'Elab_Spec;
      E100 := E100 + 1;
      Gnat.Sockets'Elab_Spec;
      System.File_Control_Block'Elab_Spec;
      E088 := E088 + 1;
      Ada.Streams.Stream_Io'Elab_Spec;
      E235 := E235 + 1;
      System.Pool_Size'Elab_Spec;
      E256 := E256 + 1;
      E104 := E104 + 1;
      System.Finalization_Masters'Elab_Body;
      E090 := E090 + 1;
      E082 := E082 + 1;
      E050 := E050 + 1;
      Ada.Tags'Elab_Body;
      E063 := E063 + 1;
      E180 := E180 + 1;
      System.Soft_Links'Elab_Body;
      E015 := E015 + 1;
      System.Secondary_Stack'Elab_Body;
      E019 := E019 + 1;
      Ada.Strings.Unbounded'Elab_Spec;
      E185 := E185 + 1;
      Gnat.Sockets.Thin_Common'Elab_Spec;
      E254 := E254 + 1;
      Gnat.Sockets.Thin'Elab_Body;
      E252 := E252 + 1;
      System.Os_Lib'Elab_Body;
      E085 := E085 + 1;
      System.File_Io'Elab_Body;
      E075 := E075 + 1;
      System.Strings.Stream_Ops'Elab_Body;
      E233 := E233 + 1;
      Gnat.Sockets'Elab_Body;
      E249 := E249 + 1;
      System.Tasking.Initialization'Elab_Body;
      E265 := E265 + 1;
      System.Tasking.Protected_Objects'Elab_Body;
      E273 := E273 + 1;
      Ada.Real_Time'Elab_Spec;
      Ada.Real_Time'Elab_Body;
      E143 := E143 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E060 := E060 + 1;
      System.Tasking.Protected_Objects.Entries'Elab_Spec;
      E275 := E275 + 1;
      System.Tasking.Queuing'Elab_Body;
      E271 := E271 + 1;
      System.Tasking.Stages'Elab_Body;
      E261 := E261 + 1;
      GNATCOLL.JSON'ELAB_SPEC;
      E198 := E198 + 1;
      E173 := E173 + 1;
      PID'ELAB_SPEC;
      E125 := E125 + 1;
      E239 := E239 + 1;
      Server_Net'Elab_Spec;
      E243 := E243 + 1;
      tcp_client'elab_spec;
      tcp_client'elab_body;
      E169 := E169 + 1;
      Pid_Utils'Elab_Spec;
      Pid_Utils'Elab_Body;
      E167 := E167 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_motion_control_main");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer
   is
      procedure Initialize (Addr : System.Address);
      pragma Import (C, Initialize, "__gnat_initialize");

      procedure Finalize;
      pragma Import (C, Finalize, "__gnat_finalize");
      SEH : aliased array (1 .. 2) of Integer;

      Ensure_Reference : aliased System.Address := Ada_Main_Program_Name'Address;
      pragma Volatile (Ensure_Reference);

   begin
      gnat_argc := argc;
      gnat_argv := argv;
      gnat_envp := envp;

      Initialize (SEH'Address);
      adainit;
      Ada_Main_Program;
      adafinal;
      Finalize;
      return (gnat_exit_status);
   end;

--  BEGIN Object file/option list
   --   C:\Users\cag01\Desktop\BBB\lib\json\obj\gnatcoll.o
   --   C:\Users\cag01\Desktop\BBB\lib\json\obj\gnatcoll-json-utility.o
   --   C:\Users\cag01\Desktop\BBB\lib\json\obj\gnatcoll-json.o
   --   C:\Users\cag01\Desktop\BBB\software\motion_control\obj\pid.o
   --   C:\Users\cag01\Desktop\BBB\lib\radix\obj\radix.o
   --   C:\Users\cag01\Desktop\BBB\lib\server_net\obj\server_net.o
   --   C:\Users\cag01\Desktop\BBB\firmware\tcp_client\obj\tcp_client.o
   --   C:\Users\cag01\Desktop\BBB\software\motion_control\obj\pid_utils.o
   --   C:\Users\cag01\Desktop\BBB\software\motion_control\obj\motion_control_main.o
   --   -LC:\Users\cag01\Desktop\BBB\software\motion_control\obj\
   --   -LC:\Users\cag01\Desktop\BBB\lib\json\obj\
   --   -LC:\Users\cag01\Desktop\BBB\firmware\tcp_client\obj\
   --   -LC:\Users\cag01\Desktop\BBB\lib\server_net\obj\
   --   -LC:\Users\cag01\Desktop\BBB\lib\radix\obj\
   --   -LC:/gnat/2012/lib/gcc/i686-pc-mingw32/4.5.4/adalib/
   --   -static
   --   -lgnarl
   --   -lgnat
   --   -lws2_32
   --   -Xlinker
   --   --stack=0x200000,0x1000
   --   -mthreads
   --   -Wl,--stack=0x2000000
--  END Object file/option list   

end ada_main;
