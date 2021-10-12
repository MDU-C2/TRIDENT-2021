pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b__main.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b__main.adb");

with System.Restrictions;
with Ada.Exceptions;

package body ada_main is
   pragma Warnings (Off);

   E088 : Short_Integer; pragma Import (Ada, E088, "system__os_lib_E");
   E015 : Short_Integer; pragma Import (Ada, E015, "system__soft_links_E");
   E128 : Short_Integer; pragma Import (Ada, E128, "system__fat_flt_E");
   E116 : Short_Integer; pragma Import (Ada, E116, "system__fat_llf_E");
   E025 : Short_Integer; pragma Import (Ada, E025, "system__exception_table_E");
   E224 : Short_Integer; pragma Import (Ada, E224, "ada__containers_E");
   E062 : Short_Integer; pragma Import (Ada, E062, "ada__io_exceptions_E");
   E175 : Short_Integer; pragma Import (Ada, E175, "ada__strings_E");
   E177 : Short_Integer; pragma Import (Ada, E177, "ada__strings__maps_E");
   E180 : Short_Integer; pragma Import (Ada, E180, "ada__strings__maps__constants_E");
   E064 : Short_Integer; pragma Import (Ada, E064, "ada__tags_E");
   E061 : Short_Integer; pragma Import (Ada, E061, "ada__streams_E");
   E047 : Short_Integer; pragma Import (Ada, E047, "interfaces__c_E");
   E150 : Short_Integer; pragma Import (Ada, E150, "interfaces__c__strings_E");
   E027 : Short_Integer; pragma Import (Ada, E027, "system__exceptions_E");
   E084 : Short_Integer; pragma Import (Ada, E084, "system__finalization_root_E");
   E082 : Short_Integer; pragma Import (Ada, E082, "ada__finalization_E");
   E101 : Short_Integer; pragma Import (Ada, E101, "system__storage_pools_E");
   E093 : Short_Integer; pragma Import (Ada, E093, "system__finalization_masters_E");
   E107 : Short_Integer; pragma Import (Ada, E107, "system__storage_pools__subpools_E");
   E158 : Short_Integer; pragma Import (Ada, E158, "system__task_info_E");
   E008 : Short_Integer; pragma Import (Ada, E008, "ada__calendar_E");
   E006 : Short_Integer; pragma Import (Ada, E006, "ada__calendar__delays_E");
   E103 : Short_Integer; pragma Import (Ada, E103, "system__pool_global_E");
   E091 : Short_Integer; pragma Import (Ada, E091, "system__file_control_block_E");
   E233 : Short_Integer; pragma Import (Ada, E233, "ada__streams__stream_io_E");
   E080 : Short_Integer; pragma Import (Ada, E080, "system__file_io_E");
   E247 : Short_Integer; pragma Import (Ada, E247, "gnat__sockets_E");
   E254 : Short_Integer; pragma Import (Ada, E254, "system__pool_size_E");
   E019 : Short_Integer; pragma Import (Ada, E019, "system__secondary_stack_E");
   E182 : Short_Integer; pragma Import (Ada, E182, "ada__strings__unbounded_E");
   E252 : Short_Integer; pragma Import (Ada, E252, "gnat__sockets__thin_common_E");
   E250 : Short_Integer; pragma Import (Ada, E250, "gnat__sockets__thin_E");
   E231 : Short_Integer; pragma Import (Ada, E231, "system__strings__stream_ops_E");
   E261 : Short_Integer; pragma Import (Ada, E261, "system__tasking__initialization_E");
   E142 : Short_Integer; pragma Import (Ada, E142, "ada__real_time_E");
   E059 : Short_Integer; pragma Import (Ada, E059, "ada__text_io_E");
   E269 : Short_Integer; pragma Import (Ada, E269, "system__tasking__protected_objects_E");
   E271 : Short_Integer; pragma Import (Ada, E271, "system__tasking__protected_objects__entries_E");
   E267 : Short_Integer; pragma Import (Ada, E267, "system__tasking__queuing_E");
   E257 : Short_Integer; pragma Import (Ada, E257, "system__tasking__stages_E");
   E170 : Short_Integer; pragma Import (Ada, E170, "gnatcoll__json_E");
   E196 : Short_Integer; pragma Import (Ada, E196, "gnatcoll__json__utility_E");
   E130 : Short_Integer; pragma Import (Ada, E130, "pid_E");
   E237 : Short_Integer; pragma Import (Ada, E237, "radix_E");
   E241 : Short_Integer; pragma Import (Ada, E241, "server_net_E");
   E166 : Short_Integer; pragma Import (Ada, E166, "tcp_client_E");
   E164 : Short_Integer; pragma Import (Ada, E164, "pid_utils_E");

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
   begin
      E164 := E164 - 1;
      declare
         procedure F1;
         pragma Import (Ada, F1, "pid_utils__finalize_spec");
      begin
         F1;
      end;
      E241 := E241 - 1;
      declare
         procedure F2;
         pragma Import (Ada, F2, "server_net__finalize_spec");
      begin
         F2;
      end;
      E170 := E170 - 1;
      declare
         procedure F3;
         pragma Import (Ada, F3, "gnatcoll__json__finalize_spec");
      begin
         F3;
      end;
      E271 := E271 - 1;
      declare
         procedure F4;
         pragma Import (Ada, F4, "system__tasking__protected_objects__entries__finalize_spec");
      begin
         F4;
      end;
      E059 := E059 - 1;
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
         E247 := E247 - 1;
         F6;
      end;
      E182 := E182 - 1;
      declare
         procedure F7;
         pragma Import (Ada, F7, "ada__strings__unbounded__finalize_spec");
      begin
         F7;
      end;
      E093 := E093 - 1;
      E107 := E107 - 1;
      declare
         procedure F8;
         pragma Import (Ada, F8, "system__file_io__finalize_body");
      begin
         E080 := E080 - 1;
         F8;
      end;
      E254 := E254 - 1;
      declare
         procedure F9;
         pragma Import (Ada, F9, "system__pool_size__finalize_spec");
      begin
         F9;
      end;
      declare
         procedure F10;
         pragma Import (Ada, F10, "gnat__sockets__finalize_spec");
      begin
         F10;
      end;
      E233 := E233 - 1;
      declare
         procedure F11;
         pragma Import (Ada, F11, "ada__streams__stream_io__finalize_spec");
      begin
         F11;
      end;
      declare
         procedure F12;
         pragma Import (Ada, F12, "system__file_control_block__finalize_spec");
      begin
         E091 := E091 - 1;
         F12;
      end;
      E103 := E103 - 1;
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
           True, False, False, False, False, False, False, False, 
           False, False, False, False, False, False),
         Value => (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
         Violated =>
          (False, False, False, True, True, False, False, True, 
           False, False, True, True, True, True, False, False, 
           True, False, False, True, True, False, True, True, 
           False, True, True, True, True, False, False, True, 
           False, True, False, False, True, False, True, False, 
           False, True, False, True, False, True, False, False, 
           False, True, False, True, False, False, False, False, 
           True, False, True, True, True, False, False, True, 
           False, False, True, False, True, True, False, True, 
           True, True, False, True, False, False, False, False, 
           False, False, True, False, False, False),
         Count => (0, 0, 0, 0, 0, 0, 1, 0, 0, 0),
         Unknown => (False, False, False, False, False, False, False, False, False, False));
      Priority_Specific_Dispatching :=
        Local_Priority_Specific_Dispatching'Address;
      Num_Specific_Dispatching := 0;
      Main_CPU := -1;
      Interrupt_States := Local_Interrupt_States'Address;
      Num_Interrupt_States := 0;
      Unreserve_All_Interrupts := 0;
      Detect_Blocking := 0;
      Default_Stack_Size := -1;
      Leap_Seconds_Support := 0;

      if Handler_Installed = 0 then
         Install_Handler;
      end if;

      Finalize_Library_Objects := finalize_library'access;

      System.Soft_Links'Elab_Spec;
      System.Fat_Flt'Elab_Spec;
      E128 := E128 + 1;
      System.Fat_Llf'Elab_Spec;
      E116 := E116 + 1;
      System.Exception_Table'Elab_Body;
      E025 := E025 + 1;
      Ada.Containers'Elab_Spec;
      E224 := E224 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E062 := E062 + 1;
      Ada.Strings'Elab_Spec;
      E175 := E175 + 1;
      Ada.Strings.Maps'Elab_Spec;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E180 := E180 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Streams'Elab_Spec;
      E061 := E061 + 1;
      Interfaces.C'Elab_Spec;
      Interfaces.C.Strings'Elab_Spec;
      System.Exceptions'Elab_Spec;
      E027 := E027 + 1;
      System.Finalization_Root'Elab_Spec;
      E084 := E084 + 1;
      Ada.Finalization'Elab_Spec;
      E082 := E082 + 1;
      System.Storage_Pools'Elab_Spec;
      E101 := E101 + 1;
      System.Finalization_Masters'Elab_Spec;
      System.Storage_Pools.Subpools'Elab_Spec;
      System.Task_Info'Elab_Spec;
      E158 := E158 + 1;
      Ada.Calendar'Elab_Spec;
      Ada.Calendar'Elab_Body;
      E008 := E008 + 1;
      Ada.Calendar.Delays'Elab_Body;
      E006 := E006 + 1;
      System.Pool_Global'Elab_Spec;
      E103 := E103 + 1;
      System.File_Control_Block'Elab_Spec;
      E091 := E091 + 1;
      Ada.Streams.Stream_Io'Elab_Spec;
      E233 := E233 + 1;
      Gnat.Sockets'Elab_Spec;
      System.Pool_Size'Elab_Spec;
      E254 := E254 + 1;
      System.File_Io'Elab_Body;
      E080 := E080 + 1;
      E107 := E107 + 1;
      System.Finalization_Masters'Elab_Body;
      E093 := E093 + 1;
      E150 := E150 + 1;
      E047 := E047 + 1;
      Ada.Tags'Elab_Body;
      E064 := E064 + 1;
      E177 := E177 + 1;
      System.Soft_Links'Elab_Body;
      E015 := E015 + 1;
      System.Os_Lib'Elab_Body;
      E088 := E088 + 1;
      System.Secondary_Stack'Elab_Body;
      E019 := E019 + 1;
      Ada.Strings.Unbounded'Elab_Spec;
      E182 := E182 + 1;
      Gnat.Sockets.Thin_Common'Elab_Spec;
      E252 := E252 + 1;
      Gnat.Sockets.Thin'Elab_Body;
      E250 := E250 + 1;
      Gnat.Sockets'Elab_Body;
      E247 := E247 + 1;
      System.Strings.Stream_Ops'Elab_Body;
      E231 := E231 + 1;
      System.Tasking.Initialization'Elab_Body;
      E261 := E261 + 1;
      Ada.Real_Time'Elab_Spec;
      Ada.Real_Time'Elab_Body;
      E142 := E142 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E059 := E059 + 1;
      System.Tasking.Protected_Objects'Elab_Body;
      E269 := E269 + 1;
      System.Tasking.Protected_Objects.Entries'Elab_Spec;
      E271 := E271 + 1;
      System.Tasking.Queuing'Elab_Body;
      E267 := E267 + 1;
      System.Tasking.Stages'Elab_Body;
      E257 := E257 + 1;
      GNATCOLL.JSON'ELAB_SPEC;
      E196 := E196 + 1;
      E170 := E170 + 1;
      PID'ELAB_SPEC;
      E130 := E130 + 1;
      E237 := E237 + 1;
      Server_Net'Elab_Spec;
      Server_Net'Elab_Body;
      E241 := E241 + 1;
      tcp_client'elab_spec;
      tcp_client'elab_body;
      E166 := E166 + 1;
      Pid_Utils'Elab_Spec;
      Pid_Utils'Elab_Body;
      E164 := E164 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_main");

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
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\lib\json\obj\gnatcoll.o
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\lib\json\obj\gnatcoll-json-utility.o
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\lib\json\obj\gnatcoll-json.o
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\software\motioncontrol\obj\pid.o
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\lib\radix\obj\radix.o
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\lib\server_net\obj\server_net.o
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\software\tcp_client\obj\tcp_client.o
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\software\motioncontrol\obj\pid_utils.o
   --   C:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\software\motioncontrol\obj\main.o
   --   -LC:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\software\motioncontrol\obj\
   --   -LC:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\software\motioncontrol\obj\
   --   -LC:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\lib\json\obj\
   --   -LC:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\software\tcp_client\obj\
   --   -LC:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\lib\server_net\obj\
   --   -LC:\Users\Mr\Dropbox\Robotics project\Naiad\BBB\lib\radix\obj\
   --   -LC:/gnat/2014/lib/gcc/i686-pc-mingw32/4.7.4/adalib/
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
