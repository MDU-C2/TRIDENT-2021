pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b~can_main.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b~can_main.adb");

with System.Restrictions;
with Ada.Exceptions;

package body ada_main is
   pragma Warnings (Off);

   E129 : Short_Integer; pragma Import (Ada, E129, "system__os_lib_E");
   E017 : Short_Integer; pragma Import (Ada, E017, "system__soft_links_E");
   E244 : Short_Integer; pragma Import (Ada, E244, "system__fat_llf_E");
   E027 : Short_Integer; pragma Import (Ada, E027, "system__exception_table_E");
   E252 : Short_Integer; pragma Import (Ada, E252, "ada__containers_E");
   E126 : Short_Integer; pragma Import (Ada, E126, "ada__io_exceptions_E");
   E165 : Short_Integer; pragma Import (Ada, E165, "ada__strings_E");
   E169 : Short_Integer; pragma Import (Ada, E169, "ada__strings__maps_E");
   E210 : Short_Integer; pragma Import (Ada, E210, "ada__strings__maps__constants_E");
   E108 : Short_Integer; pragma Import (Ada, E108, "ada__tags_E");
   E117 : Short_Integer; pragma Import (Ada, E117, "ada__streams_E");
   E052 : Short_Integer; pragma Import (Ada, E052, "interfaces__c_E");
   E070 : Short_Integer; pragma Import (Ada, E070, "interfaces__c__strings_E");
   E033 : Short_Integer; pragma Import (Ada, E033, "system__exceptions_E");
   E125 : Short_Integer; pragma Import (Ada, E125, "system__finalization_root_E");
   E123 : Short_Integer; pragma Import (Ada, E123, "ada__finalization_E");
   E140 : Short_Integer; pragma Import (Ada, E140, "system__storage_pools_E");
   E134 : Short_Integer; pragma Import (Ada, E134, "system__finalization_masters_E");
   E146 : Short_Integer; pragma Import (Ada, E146, "system__storage_pools__subpools_E");
   E083 : Short_Integer; pragma Import (Ada, E083, "system__task_info_E");
   E010 : Short_Integer; pragma Import (Ada, E010, "ada__calendar_E");
   E008 : Short_Integer; pragma Import (Ada, E008, "ada__calendar__delays_E");
   E142 : Short_Integer; pragma Import (Ada, E142, "system__pool_global_E");
   E132 : Short_Integer; pragma Import (Ada, E132, "system__file_control_block_E");
   E193 : Short_Integer; pragma Import (Ada, E193, "ada__streams__stream_io_E");
   E121 : Short_Integer; pragma Import (Ada, E121, "system__file_io_E");
   E197 : Short_Integer; pragma Import (Ada, E197, "gnat__serial_communications_E");
   E297 : Short_Integer; pragma Import (Ada, E297, "gnat__sockets_E");
   E183 : Short_Integer; pragma Import (Ada, E183, "system__object_reader_E");
   E164 : Short_Integer; pragma Import (Ada, E164, "system__dwarf_lines_E");
   E304 : Short_Integer; pragma Import (Ada, E304, "system__pool_size_E");
   E021 : Short_Integer; pragma Import (Ada, E021, "system__secondary_stack_E");
   E212 : Short_Integer; pragma Import (Ada, E212, "ada__strings__unbounded_E");
   E302 : Short_Integer; pragma Import (Ada, E302, "gnat__sockets__thin_common_E");
   E300 : Short_Integer; pragma Import (Ada, E300, "gnat__sockets__thin_E");
   E191 : Short_Integer; pragma Import (Ada, E191, "system__strings__stream_ops_E");
   E263 : Short_Integer; pragma Import (Ada, E263, "system__tasking__initialization_E");
   E271 : Short_Integer; pragma Import (Ada, E271, "system__tasking__protected_objects_E");
   E062 : Short_Integer; pragma Import (Ada, E062, "ada__real_time_E");
   E116 : Short_Integer; pragma Import (Ada, E116, "ada__text_io_E");
   E273 : Short_Integer; pragma Import (Ada, E273, "system__tasking__protected_objects__entries_E");
   E269 : Short_Integer; pragma Import (Ada, E269, "system__tasking__queuing_E");
   E259 : Short_Integer; pragma Import (Ada, E259, "system__tasking__stages_E");
   E153 : Short_Integer; pragma Import (Ada, E153, "can_defs_E");
   E204 : Short_Integer; pragma Import (Ada, E204, "byte_conv_E");
   E005 : Short_Integer; pragma Import (Ada, E005, "can_node_E");
   E152 : Short_Integer; pragma Import (Ada, E152, "can_utils_E");
   E155 : Short_Integer; pragma Import (Ada, E155, "exception_handling_E");
   E207 : Short_Integer; pragma Import (Ada, E207, "gnatcoll__json_E");
   E217 : Short_Integer; pragma Import (Ada, E217, "gnatcoll__json__utility_E");
   E200 : Short_Integer; pragma Import (Ada, E200, "queue_E");
   E287 : Short_Integer; pragma Import (Ada, E287, "radix_E");
   E291 : Short_Integer; pragma Import (Ada, E291, "server_net_E");
   E285 : Short_Integer; pragma Import (Ada, E285, "tcp_client_E");
   E202 : Short_Integer; pragma Import (Ada, E202, "uartwrapper_E");
   E150 : Short_Integer; pragma Import (Ada, E150, "bbb_can_E");

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
   begin
      declare
         procedure F1;
         pragma Import (Ada, F1, "can_node__finalize_body");
      begin
         E005 := E005 - 1;
         F1;
      end;
      E202 := E202 - 1;
      declare
         procedure F2;
         pragma Import (Ada, F2, "uartwrapper__finalize_spec");
      begin
         F2;
      end;
      E291 := E291 - 1;
      declare
         procedure F3;
         pragma Import (Ada, F3, "server_net__finalize_spec");
      begin
         F3;
      end;
      E207 := E207 - 1;
      declare
         procedure F4;
         pragma Import (Ada, F4, "gnatcoll__json__finalize_spec");
      begin
         F4;
      end;
      E155 := E155 - 1;
      declare
         procedure F5;
         pragma Import (Ada, F5, "exception_handling__finalize_spec");
      begin
         F5;
      end;
      E273 := E273 - 1;
      declare
         procedure F6;
         pragma Import (Ada, F6, "system__tasking__protected_objects__entries__finalize_spec");
      begin
         F6;
      end;
      E116 := E116 - 1;
      declare
         procedure F7;
         pragma Import (Ada, F7, "ada__text_io__finalize_spec");
      begin
         F7;
      end;
      declare
         procedure F8;
         pragma Import (Ada, F8, "gnat__sockets__finalize_body");
      begin
         E297 := E297 - 1;
         F8;
      end;
      E212 := E212 - 1;
      declare
         procedure F9;
         pragma Import (Ada, F9, "ada__strings__unbounded__finalize_spec");
      begin
         F9;
      end;
      E197 := E197 - 1;
      declare
         procedure F10;
         pragma Import (Ada, F10, "system__object_reader__finalize_body");
      begin
         E183 := E183 - 1;
         F10;
      end;
      E134 := E134 - 1;
      E146 := E146 - 1;
      declare
         procedure F11;
         pragma Import (Ada, F11, "system__file_io__finalize_body");
      begin
         E121 := E121 - 1;
         F11;
      end;
      E304 := E304 - 1;
      declare
         procedure F12;
         pragma Import (Ada, F12, "system__pool_size__finalize_spec");
      begin
         F12;
      end;
      declare
         procedure F13;
         pragma Import (Ada, F13, "system__object_reader__finalize_spec");
      begin
         F13;
      end;
      declare
         procedure F14;
         pragma Import (Ada, F14, "gnat__sockets__finalize_spec");
      begin
         F14;
      end;
      declare
         procedure F15;
         pragma Import (Ada, F15, "gnat__serial_communications__finalize_spec");
      begin
         F15;
      end;
      E193 := E193 - 1;
      declare
         procedure F16;
         pragma Import (Ada, F16, "ada__streams__stream_io__finalize_spec");
      begin
         F16;
      end;
      declare
         procedure F17;
         pragma Import (Ada, F17, "system__file_control_block__finalize_spec");
      begin
         E132 := E132 - 1;
         F17;
      end;
      E142 := E142 - 1;
      declare
         procedure F18;
         pragma Import (Ada, F18, "system__pool_global__finalize_spec");
      begin
         F18;
      end;
      declare
         procedure F19;
         pragma Import (Ada, F19, "system__storage_pools__subpools__finalize_spec");
      begin
         F19;
      end;
      declare
         procedure F20;
         pragma Import (Ada, F20, "system__finalization_masters__finalize_spec");
      begin
         F20;
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
           False, False, False, False, False, True, False, False, 
           False, False, False, False, False, False, False, False, 
           False, False, False),
         Value => (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
         Violated =>
          (False, False, False, True, True, False, False, False, 
           False, False, True, True, True, True, False, False, 
           True, False, False, True, True, False, True, True, 
           True, True, True, True, False, False, True, False, 
           True, False, False, True, False, False, True, False, 
           True, False, True, False, False, False, True, False, 
           True, False, False, False, False, True, False, True, 
           True, True, False, False, True, False, False, True, 
           False, True, True, False, True, True, True, False, 
           True, False, False, False, False, False, False, True, 
           False, False, False),
         Count => (0, 0, 0, 0, 0, 0, 3, 0, 0, 0),
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
      System.Fat_Llf'Elab_Spec;
      E244 := E244 + 1;
      System.Exception_Table'Elab_Body;
      E027 := E027 + 1;
      Ada.Containers'Elab_Spec;
      E252 := E252 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E126 := E126 + 1;
      Ada.Strings'Elab_Spec;
      E165 := E165 + 1;
      Ada.Strings.Maps'Elab_Spec;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E210 := E210 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Streams'Elab_Spec;
      E117 := E117 + 1;
      Interfaces.C'Elab_Spec;
      Interfaces.C.Strings'Elab_Spec;
      System.Exceptions'Elab_Spec;
      E033 := E033 + 1;
      System.Finalization_Root'Elab_Spec;
      E125 := E125 + 1;
      Ada.Finalization'Elab_Spec;
      E123 := E123 + 1;
      System.Storage_Pools'Elab_Spec;
      E140 := E140 + 1;
      System.Finalization_Masters'Elab_Spec;
      System.Storage_Pools.Subpools'Elab_Spec;
      System.Task_Info'Elab_Spec;
      E083 := E083 + 1;
      Ada.Calendar'Elab_Spec;
      Ada.Calendar'Elab_Body;
      E010 := E010 + 1;
      Ada.Calendar.Delays'Elab_Body;
      E008 := E008 + 1;
      System.Pool_Global'Elab_Spec;
      E142 := E142 + 1;
      System.File_Control_Block'Elab_Spec;
      E132 := E132 + 1;
      Ada.Streams.Stream_Io'Elab_Spec;
      E193 := E193 + 1;
      Gnat.Serial_Communications'Elab_Spec;
      Gnat.Sockets'Elab_Spec;
      System.Object_Reader'Elab_Spec;
      System.Dwarf_Lines'Elab_Spec;
      System.Pool_Size'Elab_Spec;
      E304 := E304 + 1;
      System.File_Io'Elab_Body;
      E121 := E121 + 1;
      E146 := E146 + 1;
      System.Finalization_Masters'Elab_Body;
      E134 := E134 + 1;
      E070 := E070 + 1;
      E052 := E052 + 1;
      Ada.Tags'Elab_Body;
      E108 := E108 + 1;
      E169 := E169 + 1;
      System.Soft_Links'Elab_Body;
      E017 := E017 + 1;
      System.Os_Lib'Elab_Body;
      E129 := E129 + 1;
      System.Secondary_Stack'Elab_Body;
      E021 := E021 + 1;
      System.Dwarf_Lines'Elab_Body;
      E164 := E164 + 1;
      System.Object_Reader'Elab_Body;
      E183 := E183 + 1;
      E197 := E197 + 1;
      Ada.Strings.Unbounded'Elab_Spec;
      E212 := E212 + 1;
      Gnat.Sockets.Thin_Common'Elab_Spec;
      E302 := E302 + 1;
      Gnat.Sockets.Thin'Elab_Body;
      E300 := E300 + 1;
      Gnat.Sockets'Elab_Body;
      E297 := E297 + 1;
      System.Strings.Stream_Ops'Elab_Body;
      E191 := E191 + 1;
      System.Tasking.Initialization'Elab_Body;
      E263 := E263 + 1;
      System.Tasking.Protected_Objects'Elab_Body;
      E271 := E271 + 1;
      Ada.Real_Time'Elab_Spec;
      Ada.Real_Time'Elab_Body;
      E062 := E062 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E116 := E116 + 1;
      System.Tasking.Protected_Objects.Entries'Elab_Spec;
      E273 := E273 + 1;
      System.Tasking.Queuing'Elab_Body;
      E269 := E269 + 1;
      System.Tasking.Stages'Elab_Body;
      E259 := E259 + 1;
      Can_Defs'Elab_Spec;
      E153 := E153 + 1;
      E204 := E204 + 1;
      E152 := E152 + 1;
      Exception_Handling'Elab_Spec;
      E155 := E155 + 1;
      GNATCOLL.JSON'ELAB_SPEC;
      E217 := E217 + 1;
      E207 := E207 + 1;
      E200 := E200 + 1;
      E287 := E287 + 1;
      Server_Net'Elab_Spec;
      Server_Net'Elab_Body;
      E291 := E291 + 1;
      tcp_client'elab_spec;
      tcp_client'elab_body;
      E285 := E285 + 1;
      Uartwrapper'Elab_Spec;
      E202 := E202 + 1;
      E150 := E150 + 1;
      can_node'elab_body;
      E005 := E005 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_can_main");

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
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\json\obj\gnatcoll.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\can_defs\build\can_defs.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\byte_conv\obj\byte_conv.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\software\can_node\obj\can_main.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\can_utils\build\can_utils.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\exception_handling\obj\exception_handling.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\json\obj\gnatcoll-json-utility.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\json\obj\gnatcoll-json.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\queue\build\queue.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\radix\obj\radix.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\server_net\obj\server_net.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\software\tcp_client\obj\tcp_client.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\firmware\UartWrapper\obj\uartwrapper.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\firmware\bbb_can\build\bbb_can.o
   --   C:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\software\can_node\obj\can_node.o
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\software\can_node\obj\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\software\can_node\obj\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\json\obj\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\firmware\bbb_can\build\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\firmware\UartWrapper\obj\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\exception_handling\obj\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\queue\build\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\can_utils\build\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\can_defs\build\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\software\tcp_client\obj\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\server_net\obj\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\radix\obj\
   --   -LC:\Users\jonkos\Dropbox\Robotics project\Naiad\BBB\lib\byte_conv\obj\
   --   -LC:/GNAT/2013/lib/gcc/i686-pc-mingw32/4.7.4/adalib/
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
