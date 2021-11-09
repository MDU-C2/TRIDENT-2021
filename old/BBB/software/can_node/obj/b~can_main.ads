pragma Ada_95;
with System;
package ada_main is
   pragma Warnings (Off);

   gnat_argc : Integer;
   gnat_argv : System.Address;
   gnat_envp : System.Address;

   pragma Import (C, gnat_argc);
   pragma Import (C, gnat_argv);
   pragma Import (C, gnat_envp);

   gnat_exit_status : Integer;
   pragma Import (C, gnat_exit_status);

   GNAT_Version : constant String :=
                    "GNAT Version: GPL 2013 (20130314)" & ASCII.NUL;
   pragma Export (C, GNAT_Version, "__gnat_version");

   Ada_Main_Program_Name : constant String := "_ada_can_main" & ASCII.NUL;
   pragma Export (C, Ada_Main_Program_Name, "__gnat_ada_main_program_name");

   procedure adainit;
   pragma Export (C, adainit, "adainit");

   procedure adafinal;
   pragma Export (C, adafinal, "adafinal");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer;
   pragma Export (C, main, "main");

   type Version_32 is mod 2 ** 32;
   u00001 : constant Version_32 := 16#7af87294#;
   pragma Export (C, u00001, "can_mainB");
   u00002 : constant Version_32 := 16#3935bd10#;
   pragma Export (C, u00002, "system__standard_libraryB");
   u00003 : constant Version_32 := 16#51a8eec5#;
   pragma Export (C, u00003, "system__standard_libraryS");
   u00004 : constant Version_32 := 16#e7022273#;
   pragma Export (C, u00004, "can_nodeB");
   u00005 : constant Version_32 := 16#8ed1b513#;
   pragma Export (C, u00005, "can_nodeS");
   u00006 : constant Version_32 := 16#3ffc8e18#;
   pragma Export (C, u00006, "adaS");
   u00007 : constant Version_32 := 16#45724809#;
   pragma Export (C, u00007, "ada__calendar__delaysB");
   u00008 : constant Version_32 := 16#474dd4b1#;
   pragma Export (C, u00008, "ada__calendar__delaysS");
   u00009 : constant Version_32 := 16#8ba0787e#;
   pragma Export (C, u00009, "ada__calendarB");
   u00010 : constant Version_32 := 16#e791e294#;
   pragma Export (C, u00010, "ada__calendarS");
   u00011 : constant Version_32 := 16#5ea2bd7b#;
   pragma Export (C, u00011, "ada__exceptionsB");
   u00012 : constant Version_32 := 16#6380a30f#;
   pragma Export (C, u00012, "ada__exceptionsS");
   u00013 : constant Version_32 := 16#16173147#;
   pragma Export (C, u00013, "ada__exceptions__last_chance_handlerB");
   u00014 : constant Version_32 := 16#1f42fb5e#;
   pragma Export (C, u00014, "ada__exceptions__last_chance_handlerS");
   u00015 : constant Version_32 := 16#5fc8ae56#;
   pragma Export (C, u00015, "systemS");
   u00016 : constant Version_32 := 16#0071025c#;
   pragma Export (C, u00016, "system__soft_linksB");
   u00017 : constant Version_32 := 16#3293d48b#;
   pragma Export (C, u00017, "system__soft_linksS");
   u00018 : constant Version_32 := 16#27940d94#;
   pragma Export (C, u00018, "system__parametersB");
   u00019 : constant Version_32 := 16#e92aa296#;
   pragma Export (C, u00019, "system__parametersS");
   u00020 : constant Version_32 := 16#17775d6d#;
   pragma Export (C, u00020, "system__secondary_stackB");
   u00021 : constant Version_32 := 16#4ba689f8#;
   pragma Export (C, u00021, "system__secondary_stackS");
   u00022 : constant Version_32 := 16#ace32e1e#;
   pragma Export (C, u00022, "system__storage_elementsB");
   u00023 : constant Version_32 := 16#a505d3ce#;
   pragma Export (C, u00023, "system__storage_elementsS");
   u00024 : constant Version_32 := 16#4f750b3b#;
   pragma Export (C, u00024, "system__stack_checkingB");
   u00025 : constant Version_32 := 16#fc6a127a#;
   pragma Export (C, u00025, "system__stack_checkingS");
   u00026 : constant Version_32 := 16#7b9f0bae#;
   pragma Export (C, u00026, "system__exception_tableB");
   u00027 : constant Version_32 := 16#cea672f3#;
   pragma Export (C, u00027, "system__exception_tableS");
   u00028 : constant Version_32 := 16#5665ab64#;
   pragma Export (C, u00028, "system__htableB");
   u00029 : constant Version_32 := 16#dc60e058#;
   pragma Export (C, u00029, "system__htableS");
   u00030 : constant Version_32 := 16#8b7dad61#;
   pragma Export (C, u00030, "system__string_hashB");
   u00031 : constant Version_32 := 16#795476c2#;
   pragma Export (C, u00031, "system__string_hashS");
   u00032 : constant Version_32 := 16#aad75561#;
   pragma Export (C, u00032, "system__exceptionsB");
   u00033 : constant Version_32 := 16#533666e1#;
   pragma Export (C, u00033, "system__exceptionsS");
   u00034 : constant Version_32 := 16#010db1dc#;
   pragma Export (C, u00034, "system__exceptions_debugB");
   u00035 : constant Version_32 := 16#67b88b82#;
   pragma Export (C, u00035, "system__exceptions_debugS");
   u00036 : constant Version_32 := 16#b012ff50#;
   pragma Export (C, u00036, "system__img_intB");
   u00037 : constant Version_32 := 16#5d134e94#;
   pragma Export (C, u00037, "system__img_intS");
   u00038 : constant Version_32 := 16#dc8e33ed#;
   pragma Export (C, u00038, "system__tracebackB");
   u00039 : constant Version_32 := 16#3e4f7a23#;
   pragma Export (C, u00039, "system__tracebackS");
   u00040 : constant Version_32 := 16#907d882f#;
   pragma Export (C, u00040, "system__wch_conB");
   u00041 : constant Version_32 := 16#e023806b#;
   pragma Export (C, u00041, "system__wch_conS");
   u00042 : constant Version_32 := 16#22fed88a#;
   pragma Export (C, u00042, "system__wch_stwB");
   u00043 : constant Version_32 := 16#cd32ac6a#;
   pragma Export (C, u00043, "system__wch_stwS");
   u00044 : constant Version_32 := 16#617a40f2#;
   pragma Export (C, u00044, "system__wch_cnvB");
   u00045 : constant Version_32 := 16#fedd06bd#;
   pragma Export (C, u00045, "system__wch_cnvS");
   u00046 : constant Version_32 := 16#cb4a8015#;
   pragma Export (C, u00046, "interfacesS");
   u00047 : constant Version_32 := 16#75729fba#;
   pragma Export (C, u00047, "system__wch_jisB");
   u00048 : constant Version_32 := 16#aaaf9da9#;
   pragma Export (C, u00048, "system__wch_jisS");
   u00049 : constant Version_32 := 16#ada34a87#;
   pragma Export (C, u00049, "system__traceback_entriesB");
   u00050 : constant Version_32 := 16#0de94017#;
   pragma Export (C, u00050, "system__traceback_entriesS");
   u00051 : constant Version_32 := 16#769e25e6#;
   pragma Export (C, u00051, "interfaces__cB");
   u00052 : constant Version_32 := 16#29899d4e#;
   pragma Export (C, u00052, "interfaces__cS");
   u00053 : constant Version_32 := 16#d950d226#;
   pragma Export (C, u00053, "system__os_primitivesB");
   u00054 : constant Version_32 := 16#ef19227f#;
   pragma Export (C, u00054, "system__os_primitivesS");
   u00055 : constant Version_32 := 16#863f9596#;
   pragma Export (C, u00055, "system__task_lockB");
   u00056 : constant Version_32 := 16#3e429938#;
   pragma Export (C, u00056, "system__task_lockS");
   u00057 : constant Version_32 := 16#ee4e202b#;
   pragma Export (C, u00057, "system__win32S");
   u00058 : constant Version_32 := 16#48cfbab9#;
   pragma Export (C, u00058, "system__win32__extS");
   u00059 : constant Version_32 := 16#ee80728a#;
   pragma Export (C, u00059, "system__tracesB");
   u00060 : constant Version_32 := 16#add5c6fc#;
   pragma Export (C, u00060, "system__tracesS");
   u00061 : constant Version_32 := 16#28c4f46d#;
   pragma Export (C, u00061, "ada__real_timeB");
   u00062 : constant Version_32 := 16#41de19c7#;
   pragma Export (C, u00062, "ada__real_timeS");
   u00063 : constant Version_32 := 16#aa574b29#;
   pragma Export (C, u00063, "system__arith_64B");
   u00064 : constant Version_32 := 16#d4cf8bb1#;
   pragma Export (C, u00064, "system__arith_64S");
   u00065 : constant Version_32 := 16#91dfc027#;
   pragma Export (C, u00065, "system__taskingB");
   u00066 : constant Version_32 := 16#d83d5e83#;
   pragma Export (C, u00066, "system__taskingS");
   u00067 : constant Version_32 := 16#4ff85dba#;
   pragma Export (C, u00067, "system__task_primitivesS");
   u00068 : constant Version_32 := 16#cf49590f#;
   pragma Export (C, u00068, "system__os_interfaceS");
   u00069 : constant Version_32 := 16#507533cc#;
   pragma Export (C, u00069, "interfaces__c__stringsB");
   u00070 : constant Version_32 := 16#603c1c44#;
   pragma Export (C, u00070, "interfaces__c__stringsS");
   u00071 : constant Version_32 := 16#07176fd5#;
   pragma Export (C, u00071, "system__task_primitives__operationsB");
   u00072 : constant Version_32 := 16#074ed32a#;
   pragma Export (C, u00072, "system__task_primitives__operationsS");
   u00073 : constant Version_32 := 16#6f001a54#;
   pragma Export (C, u00073, "system__exp_unsB");
   u00074 : constant Version_32 := 16#08e5518a#;
   pragma Export (C, u00074, "system__exp_unsS");
   u00075 : constant Version_32 := 16#3529f220#;
   pragma Export (C, u00075, "system__unsigned_typesS");
   u00076 : constant Version_32 := 16#1b28662b#;
   pragma Export (C, u00076, "system__float_controlB");
   u00077 : constant Version_32 := 16#bf34ed6a#;
   pragma Export (C, u00077, "system__float_controlS");
   u00078 : constant Version_32 := 16#1826115c#;
   pragma Export (C, u00078, "system__interrupt_managementB");
   u00079 : constant Version_32 := 16#a0a25a36#;
   pragma Export (C, u00079, "system__interrupt_managementS");
   u00080 : constant Version_32 := 16#f65595cf#;
   pragma Export (C, u00080, "system__multiprocessorsB");
   u00081 : constant Version_32 := 16#67643125#;
   pragma Export (C, u00081, "system__multiprocessorsS");
   u00082 : constant Version_32 := 16#5052be8c#;
   pragma Export (C, u00082, "system__task_infoB");
   u00083 : constant Version_32 := 16#3ffea91d#;
   pragma Export (C, u00083, "system__task_infoS");
   u00084 : constant Version_32 := 16#1692df3b#;
   pragma Export (C, u00084, "system__tasking__debugB");
   u00085 : constant Version_32 := 16#f32cb5c6#;
   pragma Export (C, u00085, "system__tasking__debugS");
   u00086 : constant Version_32 := 16#39591e91#;
   pragma Export (C, u00086, "system__concat_2B");
   u00087 : constant Version_32 := 16#a4185caa#;
   pragma Export (C, u00087, "system__concat_2S");
   u00088 : constant Version_32 := 16#ae97ef6c#;
   pragma Export (C, u00088, "system__concat_3B");
   u00089 : constant Version_32 := 16#29e2ac3c#;
   pragma Export (C, u00089, "system__concat_3S");
   u00090 : constant Version_32 := 16#c9fdc962#;
   pragma Export (C, u00090, "system__concat_6B");
   u00091 : constant Version_32 := 16#98025b42#;
   pragma Export (C, u00091, "system__concat_6S");
   u00092 : constant Version_32 := 16#def1dd00#;
   pragma Export (C, u00092, "system__concat_5B");
   u00093 : constant Version_32 := 16#4ff160f7#;
   pragma Export (C, u00093, "system__concat_5S");
   u00094 : constant Version_32 := 16#3493e6c0#;
   pragma Export (C, u00094, "system__concat_4B");
   u00095 : constant Version_32 := 16#5d974de8#;
   pragma Export (C, u00095, "system__concat_4S");
   u00096 : constant Version_32 := 16#36e568f7#;
   pragma Export (C, u00096, "system__crtlS");
   u00097 : constant Version_32 := 16#1eab0e09#;
   pragma Export (C, u00097, "system__img_enum_newB");
   u00098 : constant Version_32 := 16#d8cf65a6#;
   pragma Export (C, u00098, "system__img_enum_newS");
   u00099 : constant Version_32 := 16#194ccd7b#;
   pragma Export (C, u00099, "system__img_unsB");
   u00100 : constant Version_32 := 16#aaddced7#;
   pragma Export (C, u00100, "system__img_unsS");
   u00101 : constant Version_32 := 16#083296f2#;
   pragma Export (C, u00101, "system__stack_usageB");
   u00102 : constant Version_32 := 16#7ccb26a7#;
   pragma Export (C, u00102, "system__stack_usageS");
   u00103 : constant Version_32 := 16#d7aac20c#;
   pragma Export (C, u00103, "system__ioB");
   u00104 : constant Version_32 := 16#c18a5919#;
   pragma Export (C, u00104, "system__ioS");
   u00105 : constant Version_32 := 16#3befce8e#;
   pragma Export (C, u00105, "ada__real_time__delaysB");
   u00106 : constant Version_32 := 16#6becaccd#;
   pragma Export (C, u00106, "ada__real_time__delaysS");
   u00107 : constant Version_32 := 16#afd62b40#;
   pragma Export (C, u00107, "ada__tagsB");
   u00108 : constant Version_32 := 16#f6fc5406#;
   pragma Export (C, u00108, "ada__tagsS");
   u00109 : constant Version_32 := 16#79817c71#;
   pragma Export (C, u00109, "system__val_unsB");
   u00110 : constant Version_32 := 16#25811f1b#;
   pragma Export (C, u00110, "system__val_unsS");
   u00111 : constant Version_32 := 16#aea309ed#;
   pragma Export (C, u00111, "system__val_utilB");
   u00112 : constant Version_32 := 16#f36818a8#;
   pragma Export (C, u00112, "system__val_utilS");
   u00113 : constant Version_32 := 16#b7fa72e7#;
   pragma Export (C, u00113, "system__case_utilB");
   u00114 : constant Version_32 := 16#f2d4cede#;
   pragma Export (C, u00114, "system__case_utilS");
   u00115 : constant Version_32 := 16#421d3150#;
   pragma Export (C, u00115, "ada__text_ioB");
   u00116 : constant Version_32 := 16#152cee1e#;
   pragma Export (C, u00116, "ada__text_ioS");
   u00117 : constant Version_32 := 16#1358602f#;
   pragma Export (C, u00117, "ada__streamsS");
   u00118 : constant Version_32 := 16#e0b7a7e8#;
   pragma Export (C, u00118, "interfaces__c_streamsB");
   u00119 : constant Version_32 := 16#95ad191f#;
   pragma Export (C, u00119, "interfaces__c_streamsS");
   u00120 : constant Version_32 := 16#228a5436#;
   pragma Export (C, u00120, "system__file_ioB");
   u00121 : constant Version_32 := 16#ce89cf71#;
   pragma Export (C, u00121, "system__file_ioS");
   u00122 : constant Version_32 := 16#8cbe6205#;
   pragma Export (C, u00122, "ada__finalizationB");
   u00123 : constant Version_32 := 16#22e22193#;
   pragma Export (C, u00123, "ada__finalizationS");
   u00124 : constant Version_32 := 16#95817ed8#;
   pragma Export (C, u00124, "system__finalization_rootB");
   u00125 : constant Version_32 := 16#103addc6#;
   pragma Export (C, u00125, "system__finalization_rootS");
   u00126 : constant Version_32 := 16#b46168d5#;
   pragma Export (C, u00126, "ada__io_exceptionsS");
   u00127 : constant Version_32 := 16#d6bc4ecc#;
   pragma Export (C, u00127, "system__crtl__runtimeS");
   u00128 : constant Version_32 := 16#f6ee85e9#;
   pragma Export (C, u00128, "system__os_libB");
   u00129 : constant Version_32 := 16#89dce9aa#;
   pragma Export (C, u00129, "system__os_libS");
   u00130 : constant Version_32 := 16#4cd8aca0#;
   pragma Export (C, u00130, "system__stringsB");
   u00131 : constant Version_32 := 16#e822e492#;
   pragma Export (C, u00131, "system__stringsS");
   u00132 : constant Version_32 := 16#782cc428#;
   pragma Export (C, u00132, "system__file_control_blockS");
   u00133 : constant Version_32 := 16#91d2300e#;
   pragma Export (C, u00133, "system__finalization_mastersB");
   u00134 : constant Version_32 := 16#353d027a#;
   pragma Export (C, u00134, "system__finalization_mastersS");
   u00135 : constant Version_32 := 16#57a37a42#;
   pragma Export (C, u00135, "system__address_imageB");
   u00136 : constant Version_32 := 16#fe24336c#;
   pragma Export (C, u00136, "system__address_imageS");
   u00137 : constant Version_32 := 16#7268f812#;
   pragma Export (C, u00137, "system__img_boolB");
   u00138 : constant Version_32 := 16#aa11dfbd#;
   pragma Export (C, u00138, "system__img_boolS");
   u00139 : constant Version_32 := 16#a7a37cb6#;
   pragma Export (C, u00139, "system__storage_poolsB");
   u00140 : constant Version_32 := 16#8c66b13b#;
   pragma Export (C, u00140, "system__storage_poolsS");
   u00141 : constant Version_32 := 16#ba5d60c7#;
   pragma Export (C, u00141, "system__pool_globalB");
   u00142 : constant Version_32 := 16#d56df0a6#;
   pragma Export (C, u00142, "system__pool_globalS");
   u00143 : constant Version_32 := 16#742a8355#;
   pragma Export (C, u00143, "system__memoryB");
   u00144 : constant Version_32 := 16#95431243#;
   pragma Export (C, u00144, "system__memoryS");
   u00145 : constant Version_32 := 16#1fd820b1#;
   pragma Export (C, u00145, "system__storage_pools__subpoolsB");
   u00146 : constant Version_32 := 16#951e0de9#;
   pragma Export (C, u00146, "system__storage_pools__subpoolsS");
   u00147 : constant Version_32 := 16#1777d351#;
   pragma Export (C, u00147, "system__storage_pools__subpools__finalizationB");
   u00148 : constant Version_32 := 16#12aaf1de#;
   pragma Export (C, u00148, "system__storage_pools__subpools__finalizationS");
   u00149 : constant Version_32 := 16#72cda066#;
   pragma Export (C, u00149, "bbb_canB");
   u00150 : constant Version_32 := 16#b00e873c#;
   pragma Export (C, u00150, "bbb_canS");
   u00151 : constant Version_32 := 16#47413db7#;
   pragma Export (C, u00151, "can_utilsB");
   u00152 : constant Version_32 := 16#fc26d1dd#;
   pragma Export (C, u00152, "can_utilsS");
   u00153 : constant Version_32 := 16#6ac5142e#;
   pragma Export (C, u00153, "can_defsS");
   u00154 : constant Version_32 := 16#eec6f546#;
   pragma Export (C, u00154, "exception_handlingB");
   u00155 : constant Version_32 := 16#651b46a7#;
   pragma Export (C, u00155, "exception_handlingS");
   u00156 : constant Version_32 := 16#fd2ad2f1#;
   pragma Export (C, u00156, "gnatS");
   u00157 : constant Version_32 := 16#2648146e#;
   pragma Export (C, u00157, "gnat__tracebackB");
   u00158 : constant Version_32 := 16#20845b9b#;
   pragma Export (C, u00158, "gnat__tracebackS");
   u00159 : constant Version_32 := 16#25f70bc7#;
   pragma Export (C, u00159, "ada__exceptions__tracebackB");
   u00160 : constant Version_32 := 16#1e536c8b#;
   pragma Export (C, u00160, "ada__exceptions__tracebackS");
   u00161 : constant Version_32 := 16#ee4c63a8#;
   pragma Export (C, u00161, "gnat__traceback__symbolicB");
   u00162 : constant Version_32 := 16#171ff1f9#;
   pragma Export (C, u00162, "gnat__traceback__symbolicS");
   u00163 : constant Version_32 := 16#828eb862#;
   pragma Export (C, u00163, "system__dwarf_linesB");
   u00164 : constant Version_32 := 16#5dfe1bf7#;
   pragma Export (C, u00164, "system__dwarf_linesS");
   u00165 : constant Version_32 := 16#af50e98f#;
   pragma Export (C, u00165, "ada__stringsS");
   u00166 : constant Version_32 := 16#35b254f4#;
   pragma Export (C, u00166, "ada__strings__boundedB");
   u00167 : constant Version_32 := 16#366f64db#;
   pragma Export (C, u00167, "ada__strings__boundedS");
   u00168 : constant Version_32 := 16#96e9c1e7#;
   pragma Export (C, u00168, "ada__strings__mapsB");
   u00169 : constant Version_32 := 16#24318e4c#;
   pragma Export (C, u00169, "ada__strings__mapsS");
   u00170 : constant Version_32 := 16#d7ba84a5#;
   pragma Export (C, u00170, "system__bit_opsB");
   u00171 : constant Version_32 := 16#c30e4013#;
   pragma Export (C, u00171, "system__bit_opsS");
   u00172 : constant Version_32 := 16#12c24a43#;
   pragma Export (C, u00172, "ada__charactersS");
   u00173 : constant Version_32 := 16#051b1b7b#;
   pragma Export (C, u00173, "ada__characters__latin_1S");
   u00174 : constant Version_32 := 16#ddb66c1c#;
   pragma Export (C, u00174, "ada__strings__superboundedB");
   u00175 : constant Version_32 := 16#ae699a5f#;
   pragma Export (C, u00175, "ada__strings__superboundedS");
   u00176 : constant Version_32 := 16#b490d2ed#;
   pragma Export (C, u00176, "ada__strings__searchB");
   u00177 : constant Version_32 := 16#b5a8c1d6#;
   pragma Export (C, u00177, "ada__strings__searchS");
   u00178 : constant Version_32 := 16#c4857ee1#;
   pragma Export (C, u00178, "system__compare_array_unsigned_8B");
   u00179 : constant Version_32 := 16#85f3589b#;
   pragma Export (C, u00179, "system__compare_array_unsigned_8S");
   u00180 : constant Version_32 := 16#9d3d925a#;
   pragma Export (C, u00180, "system__address_operationsB");
   u00181 : constant Version_32 := 16#9fb647c1#;
   pragma Export (C, u00181, "system__address_operationsS");
   u00182 : constant Version_32 := 16#5b00f4eb#;
   pragma Export (C, u00182, "system__object_readerB");
   u00183 : constant Version_32 := 16#f9f2ce44#;
   pragma Export (C, u00183, "system__object_readerS");
   u00184 : constant Version_32 := 16#a6e358bc#;
   pragma Export (C, u00184, "system__stream_attributesB");
   u00185 : constant Version_32 := 16#e89b4b3f#;
   pragma Export (C, u00185, "system__stream_attributesS");
   u00186 : constant Version_32 := 16#d3757657#;
   pragma Export (C, u00186, "system__val_lliB");
   u00187 : constant Version_32 := 16#c5ec48f6#;
   pragma Export (C, u00187, "system__val_lliS");
   u00188 : constant Version_32 := 16#25c21d28#;
   pragma Export (C, u00188, "system__val_lluB");
   u00189 : constant Version_32 := 16#4fdba552#;
   pragma Export (C, u00189, "system__val_lluS");
   u00190 : constant Version_32 := 16#ce0e2acb#;
   pragma Export (C, u00190, "system__strings__stream_opsB");
   u00191 : constant Version_32 := 16#8453d1c6#;
   pragma Export (C, u00191, "system__strings__stream_opsS");
   u00192 : constant Version_32 := 16#9d848be4#;
   pragma Export (C, u00192, "ada__streams__stream_ioB");
   u00193 : constant Version_32 := 16#31db4e88#;
   pragma Export (C, u00193, "ada__streams__stream_ioS");
   u00194 : constant Version_32 := 16#5de653db#;
   pragma Export (C, u00194, "system__communicationB");
   u00195 : constant Version_32 := 16#aae38b10#;
   pragma Export (C, u00195, "system__communicationS");
   u00196 : constant Version_32 := 16#7f5206df#;
   pragma Export (C, u00196, "gnat__serial_communicationsB");
   u00197 : constant Version_32 := 16#066119d0#;
   pragma Export (C, u00197, "gnat__serial_communicationsS");
   u00198 : constant Version_32 := 16#c674770c#;
   pragma Export (C, u00198, "system__os_constantsS");
   u00199 : constant Version_32 := 16#08db7400#;
   pragma Export (C, u00199, "queueB");
   u00200 : constant Version_32 := 16#24f8d719#;
   pragma Export (C, u00200, "queueS");
   u00201 : constant Version_32 := 16#2b717539#;
   pragma Export (C, u00201, "uartwrapperB");
   u00202 : constant Version_32 := 16#d6fcfb68#;
   pragma Export (C, u00202, "uartwrapperS");
   u00203 : constant Version_32 := 16#96cfb790#;
   pragma Export (C, u00203, "byte_convB");
   u00204 : constant Version_32 := 16#57cd4bdf#;
   pragma Export (C, u00204, "byte_convS");
   u00205 : constant Version_32 := 16#6a5da479#;
   pragma Export (C, u00205, "gnatcollS");
   u00206 : constant Version_32 := 16#ff04ac08#;
   pragma Export (C, u00206, "gnatcoll__jsonB");
   u00207 : constant Version_32 := 16#4e9520ed#;
   pragma Export (C, u00207, "gnatcoll__jsonS");
   u00208 : constant Version_32 := 16#6239f067#;
   pragma Export (C, u00208, "ada__characters__handlingB");
   u00209 : constant Version_32 := 16#3006d996#;
   pragma Export (C, u00209, "ada__characters__handlingS");
   u00210 : constant Version_32 := 16#7a69aa90#;
   pragma Export (C, u00210, "ada__strings__maps__constantsS");
   u00211 : constant Version_32 := 16#261c554b#;
   pragma Export (C, u00211, "ada__strings__unboundedB");
   u00212 : constant Version_32 := 16#2bf53506#;
   pragma Export (C, u00212, "ada__strings__unboundedS");
   u00213 : constant Version_32 := 16#5073d598#;
   pragma Export (C, u00213, "system__machine_codeS");
   u00214 : constant Version_32 := 16#8d43fb6a#;
   pragma Export (C, u00214, "system__atomic_countersB");
   u00215 : constant Version_32 := 16#1554c2e2#;
   pragma Export (C, u00215, "system__atomic_countersS");
   u00216 : constant Version_32 := 16#1991fbe4#;
   pragma Export (C, u00216, "gnatcoll__json__utilityB");
   u00217 : constant Version_32 := 16#ae413593#;
   pragma Export (C, u00217, "gnatcoll__json__utilityS");
   u00218 : constant Version_32 := 16#f64b89a4#;
   pragma Export (C, u00218, "ada__integer_text_ioB");
   u00219 : constant Version_32 := 16#f1daf268#;
   pragma Export (C, u00219, "ada__integer_text_ioS");
   u00220 : constant Version_32 := 16#f6fdca1c#;
   pragma Export (C, u00220, "ada__text_io__integer_auxB");
   u00221 : constant Version_32 := 16#b9793d30#;
   pragma Export (C, u00221, "ada__text_io__integer_auxS");
   u00222 : constant Version_32 := 16#cd6ba629#;
   pragma Export (C, u00222, "ada__text_io__generic_auxB");
   u00223 : constant Version_32 := 16#a6c327d3#;
   pragma Export (C, u00223, "ada__text_io__generic_auxS");
   u00224 : constant Version_32 := 16#ef6c8032#;
   pragma Export (C, u00224, "system__img_biuB");
   u00225 : constant Version_32 := 16#f30b7a6d#;
   pragma Export (C, u00225, "system__img_biuS");
   u00226 : constant Version_32 := 16#10618bf9#;
   pragma Export (C, u00226, "system__img_llbB");
   u00227 : constant Version_32 := 16#b2cc6a93#;
   pragma Export (C, u00227, "system__img_llbS");
   u00228 : constant Version_32 := 16#9777733a#;
   pragma Export (C, u00228, "system__img_lliB");
   u00229 : constant Version_32 := 16#4e87fb87#;
   pragma Export (C, u00229, "system__img_lliS");
   u00230 : constant Version_32 := 16#f931f062#;
   pragma Export (C, u00230, "system__img_llwB");
   u00231 : constant Version_32 := 16#1ba04905#;
   pragma Export (C, u00231, "system__img_llwS");
   u00232 : constant Version_32 := 16#b532ff4e#;
   pragma Export (C, u00232, "system__img_wiuB");
   u00233 : constant Version_32 := 16#9d4afdff#;
   pragma Export (C, u00233, "system__img_wiuS");
   u00234 : constant Version_32 := 16#c31442ce#;
   pragma Export (C, u00234, "system__val_intB");
   u00235 : constant Version_32 := 16#176d8469#;
   pragma Export (C, u00235, "system__val_intS");
   u00236 : constant Version_32 := 16#914b496f#;
   pragma Export (C, u00236, "ada__strings__fixedB");
   u00237 : constant Version_32 := 16#dc686502#;
   pragma Export (C, u00237, "ada__strings__fixedS");
   u00238 : constant Version_32 := 16#509ed097#;
   pragma Export (C, u00238, "gnat__decode_utf8_stringB");
   u00239 : constant Version_32 := 16#868d95c5#;
   pragma Export (C, u00239, "gnat__decode_utf8_stringS");
   u00240 : constant Version_32 := 16#d005f14c#;
   pragma Export (C, u00240, "gnat__encode_utf8_stringB");
   u00241 : constant Version_32 := 16#107345fb#;
   pragma Export (C, u00241, "gnat__encode_utf8_stringS");
   u00242 : constant Version_32 := 16#6d0081c3#;
   pragma Export (C, u00242, "system__img_realB");
   u00243 : constant Version_32 := 16#9860ffb4#;
   pragma Export (C, u00243, "system__img_realS");
   u00244 : constant Version_32 := 16#80f37066#;
   pragma Export (C, u00244, "system__fat_llfS");
   u00245 : constant Version_32 := 16#06417083#;
   pragma Export (C, u00245, "system__img_lluB");
   u00246 : constant Version_32 := 16#7ce0f2e3#;
   pragma Export (C, u00246, "system__img_lluS");
   u00247 : constant Version_32 := 16#0fb8c821#;
   pragma Export (C, u00247, "system__powten_tableS");
   u00248 : constant Version_32 := 16#8ff77155#;
   pragma Export (C, u00248, "system__val_realB");
   u00249 : constant Version_32 := 16#a1e1d947#;
   pragma Export (C, u00249, "system__val_realS");
   u00250 : constant Version_32 := 16#0be1b996#;
   pragma Export (C, u00250, "system__exn_llfB");
   u00251 : constant Version_32 := 16#de4cb0b9#;
   pragma Export (C, u00251, "system__exn_llfS");
   u00252 : constant Version_32 := 16#5e196e91#;
   pragma Export (C, u00252, "ada__containersS");
   u00253 : constant Version_32 := 16#654e2c4c#;
   pragma Export (C, u00253, "ada__containers__hash_tablesS");
   u00254 : constant Version_32 := 16#c24eaf4d#;
   pragma Export (C, u00254, "ada__containers__prime_numbersB");
   u00255 : constant Version_32 := 16#6d3af8ed#;
   pragma Export (C, u00255, "ada__containers__prime_numbersS");
   u00256 : constant Version_32 := 16#bd084245#;
   pragma Export (C, u00256, "ada__strings__hashB");
   u00257 : constant Version_32 := 16#fe83f2e7#;
   pragma Export (C, u00257, "ada__strings__hashS");
   u00258 : constant Version_32 := 16#b3acec93#;
   pragma Export (C, u00258, "system__tasking__stagesB");
   u00259 : constant Version_32 := 16#79eb9051#;
   pragma Export (C, u00259, "system__tasking__stagesS");
   u00260 : constant Version_32 := 16#386436bc#;
   pragma Export (C, u00260, "system__restrictionsB");
   u00261 : constant Version_32 := 16#fd243b13#;
   pragma Export (C, u00261, "system__restrictionsS");
   u00262 : constant Version_32 := 16#a4cc7b44#;
   pragma Export (C, u00262, "system__tasking__initializationB");
   u00263 : constant Version_32 := 16#9468d5af#;
   pragma Export (C, u00263, "system__tasking__initializationS");
   u00264 : constant Version_32 := 16#1151ce70#;
   pragma Export (C, u00264, "system__soft_links__taskingB");
   u00265 : constant Version_32 := 16#6ac0d6d0#;
   pragma Export (C, u00265, "system__soft_links__taskingS");
   u00266 : constant Version_32 := 16#17d21067#;
   pragma Export (C, u00266, "ada__exceptions__is_null_occurrenceB");
   u00267 : constant Version_32 := 16#d832eaef#;
   pragma Export (C, u00267, "ada__exceptions__is_null_occurrenceS");
   u00268 : constant Version_32 := 16#7b8939c7#;
   pragma Export (C, u00268, "system__tasking__queuingB");
   u00269 : constant Version_32 := 16#5b69ac57#;
   pragma Export (C, u00269, "system__tasking__queuingS");
   u00270 : constant Version_32 := 16#bb8952df#;
   pragma Export (C, u00270, "system__tasking__protected_objectsB");
   u00271 : constant Version_32 := 16#09cb1bb5#;
   pragma Export (C, u00271, "system__tasking__protected_objectsS");
   u00272 : constant Version_32 := 16#8b7a9f50#;
   pragma Export (C, u00272, "system__tasking__protected_objects__entriesB");
   u00273 : constant Version_32 := 16#4d64e3b6#;
   pragma Export (C, u00273, "system__tasking__protected_objects__entriesS");
   u00274 : constant Version_32 := 16#195cdc00#;
   pragma Export (C, u00274, "system__tasking__rendezvousB");
   u00275 : constant Version_32 := 16#592e9c02#;
   pragma Export (C, u00275, "system__tasking__rendezvousS");
   u00276 : constant Version_32 := 16#3b094f8a#;
   pragma Export (C, u00276, "system__tasking__entry_callsB");
   u00277 : constant Version_32 := 16#837d42fa#;
   pragma Export (C, u00277, "system__tasking__entry_callsS");
   u00278 : constant Version_32 := 16#47da7ff7#;
   pragma Export (C, u00278, "system__tasking__protected_objects__operationsB");
   u00279 : constant Version_32 := 16#a9cb954d#;
   pragma Export (C, u00279, "system__tasking__protected_objects__operationsS");
   u00280 : constant Version_32 := 16#11a73c38#;
   pragma Export (C, u00280, "system__tasking__utilitiesB");
   u00281 : constant Version_32 := 16#53d3f317#;
   pragma Export (C, u00281, "system__tasking__utilitiesS");
   u00282 : constant Version_32 := 16#bd6fc52e#;
   pragma Export (C, u00282, "system__traces__taskingB");
   u00283 : constant Version_32 := 16#55cf3c43#;
   pragma Export (C, u00283, "system__traces__taskingS");
   u00284 : constant Version_32 := 16#24bbf092#;
   pragma Export (C, u00284, "tcp_clientB");
   u00285 : constant Version_32 := 16#f77fc556#;
   pragma Export (C, u00285, "tcp_clientS");
   u00286 : constant Version_32 := 16#6d27965d#;
   pragma Export (C, u00286, "radixB");
   u00287 : constant Version_32 := 16#7f4d8f0b#;
   pragma Export (C, u00287, "radixS");
   u00288 : constant Version_32 := 16#b602a99c#;
   pragma Export (C, u00288, "system__exn_intB");
   u00289 : constant Version_32 := 16#1d44b20a#;
   pragma Export (C, u00289, "system__exn_intS");
   u00290 : constant Version_32 := 16#ed9604d5#;
   pragma Export (C, u00290, "server_netB");
   u00291 : constant Version_32 := 16#65880f38#;
   pragma Export (C, u00291, "server_netS");
   u00292 : constant Version_32 := 16#276453b7#;
   pragma Export (C, u00292, "system__img_lldB");
   u00293 : constant Version_32 := 16#aceaa73f#;
   pragma Export (C, u00293, "system__img_lldS");
   u00294 : constant Version_32 := 16#8da1623b#;
   pragma Export (C, u00294, "system__img_decB");
   u00295 : constant Version_32 := 16#f1e5a78d#;
   pragma Export (C, u00295, "system__img_decS");
   u00296 : constant Version_32 := 16#ba30556c#;
   pragma Export (C, u00296, "gnat__socketsB");
   u00297 : constant Version_32 := 16#c1654bca#;
   pragma Export (C, u00297, "gnat__socketsS");
   u00298 : constant Version_32 := 16#01027cb8#;
   pragma Export (C, u00298, "gnat__sockets__linker_optionsS");
   u00299 : constant Version_32 := 16#e41c2dad#;
   pragma Export (C, u00299, "gnat__sockets__thinB");
   u00300 : constant Version_32 := 16#e6561a98#;
   pragma Export (C, u00300, "gnat__sockets__thinS");
   u00301 : constant Version_32 := 16#0a2632e6#;
   pragma Export (C, u00301, "gnat__sockets__thin_commonB");
   u00302 : constant Version_32 := 16#a458fed4#;
   pragma Export (C, u00302, "gnat__sockets__thin_commonS");
   u00303 : constant Version_32 := 16#17f3840e#;
   pragma Export (C, u00303, "system__pool_sizeB");
   u00304 : constant Version_32 := 16#43063bbf#;
   pragma Export (C, u00304, "system__pool_sizeS");
   --  BEGIN ELABORATION ORDER
   --  ada%s
   --  ada.characters%s
   --  ada.characters.handling%s
   --  ada.characters.latin_1%s
   --  gnat%s
   --  interfaces%s
   --  system%s
   --  system.address_operations%s
   --  system.address_operations%b
   --  system.arith_64%s
   --  system.atomic_counters%s
   --  system.case_util%s
   --  system.case_util%b
   --  system.exn_int%s
   --  system.exn_int%b
   --  system.exn_llf%s
   --  system.exn_llf%b
   --  system.float_control%s
   --  system.float_control%b
   --  system.htable%s
   --  system.img_bool%s
   --  system.img_bool%b
   --  system.img_dec%s
   --  system.img_enum_new%s
   --  system.img_enum_new%b
   --  system.img_int%s
   --  system.img_int%b
   --  system.img_dec%b
   --  system.img_lld%s
   --  system.img_lli%s
   --  system.img_lli%b
   --  system.img_lld%b
   --  system.img_real%s
   --  system.io%s
   --  system.io%b
   --  system.machine_code%s
   --  system.atomic_counters%b
   --  system.multiprocessors%s
   --  system.os_primitives%s
   --  system.parameters%s
   --  system.parameters%b
   --  system.crtl%s
   --  interfaces.c_streams%s
   --  interfaces.c_streams%b
   --  system.powten_table%s
   --  system.restrictions%s
   --  system.restrictions%b
   --  system.standard_library%s
   --  system.exceptions_debug%s
   --  system.exceptions_debug%b
   --  system.storage_elements%s
   --  system.storage_elements%b
   --  system.stack_checking%s
   --  system.stack_checking%b
   --  system.stack_usage%s
   --  system.stack_usage%b
   --  system.string_hash%s
   --  system.string_hash%b
   --  system.htable%b
   --  system.strings%s
   --  system.strings%b
   --  system.os_lib%s
   --  system.task_lock%s
   --  system.traceback_entries%s
   --  system.traceback_entries%b
   --  ada.exceptions%s
   --  system.arith_64%b
   --  ada.exceptions.is_null_occurrence%s
   --  ada.exceptions.is_null_occurrence%b
   --  system.soft_links%s
   --  system.task_lock%b
   --  system.traces%s
   --  system.traces%b
   --  system.unsigned_types%s
   --  system.exp_uns%s
   --  system.exp_uns%b
   --  system.fat_llf%s
   --  system.img_biu%s
   --  system.img_biu%b
   --  system.img_llb%s
   --  system.img_llb%b
   --  system.img_llu%s
   --  system.img_llu%b
   --  system.img_llw%s
   --  system.img_llw%b
   --  system.img_uns%s
   --  system.img_uns%b
   --  system.img_real%b
   --  system.img_wiu%s
   --  system.img_wiu%b
   --  system.val_int%s
   --  system.val_lli%s
   --  system.val_llu%s
   --  system.val_real%s
   --  system.val_uns%s
   --  system.val_util%s
   --  system.val_util%b
   --  system.val_uns%b
   --  system.val_real%b
   --  system.val_llu%b
   --  system.val_lli%b
   --  system.val_int%b
   --  system.wch_con%s
   --  system.wch_con%b
   --  system.wch_cnv%s
   --  system.wch_jis%s
   --  system.wch_jis%b
   --  system.wch_cnv%b
   --  system.wch_stw%s
   --  system.wch_stw%b
   --  ada.exceptions.last_chance_handler%s
   --  ada.exceptions.last_chance_handler%b
   --  ada.exceptions.traceback%s
   --  system.address_image%s
   --  system.bit_ops%s
   --  system.bit_ops%b
   --  system.compare_array_unsigned_8%s
   --  system.compare_array_unsigned_8%b
   --  system.concat_2%s
   --  system.concat_2%b
   --  system.concat_3%s
   --  system.concat_3%b
   --  system.concat_4%s
   --  system.concat_4%b
   --  system.concat_5%s
   --  system.concat_5%b
   --  system.concat_6%s
   --  system.concat_6%b
   --  system.exception_table%s
   --  system.exception_table%b
   --  ada.containers%s
   --  ada.containers.hash_tables%s
   --  ada.containers.prime_numbers%s
   --  ada.containers.prime_numbers%b
   --  ada.io_exceptions%s
   --  ada.strings%s
   --  ada.strings.hash%s
   --  ada.strings.hash%b
   --  ada.strings.maps%s
   --  ada.strings.fixed%s
   --  ada.strings.maps.constants%s
   --  ada.strings.search%s
   --  ada.strings.search%b
   --  ada.strings.superbounded%s
   --  ada.strings.bounded%s
   --  ada.strings.bounded%b
   --  ada.tags%s
   --  ada.streams%s
   --  interfaces.c%s
   --  system.multiprocessors%b
   --  interfaces.c.strings%s
   --  system.communication%s
   --  system.communication%b
   --  system.crtl.runtime%s
   --  system.exceptions%s
   --  system.exceptions%b
   --  system.finalization_root%s
   --  system.finalization_root%b
   --  ada.finalization%s
   --  ada.finalization%b
   --  system.os_constants%s
   --  system.storage_pools%s
   --  system.storage_pools%b
   --  system.finalization_masters%s
   --  system.storage_pools.subpools%s
   --  system.storage_pools.subpools.finalization%s
   --  system.storage_pools.subpools.finalization%b
   --  system.stream_attributes%s
   --  system.stream_attributes%b
   --  system.win32%s
   --  system.os_interface%s
   --  system.interrupt_management%s
   --  system.interrupt_management%b
   --  system.task_info%s
   --  system.task_info%b
   --  system.task_primitives%s
   --  system.tasking%s
   --  system.task_primitives.operations%s
   --  system.tasking%b
   --  system.tasking.debug%s
   --  system.tasking.debug%b
   --  system.traces.tasking%s
   --  system.traces.tasking%b
   --  system.win32.ext%s
   --  system.task_primitives.operations%b
   --  system.os_primitives%b
   --  ada.calendar%s
   --  ada.calendar%b
   --  ada.calendar.delays%s
   --  ada.calendar.delays%b
   --  system.memory%s
   --  system.memory%b
   --  system.standard_library%b
   --  system.pool_global%s
   --  system.pool_global%b
   --  system.file_control_block%s
   --  ada.streams.stream_io%s
   --  system.file_io%s
   --  ada.streams.stream_io%b
   --  gnat.serial_communications%s
   --  gnat.sockets%s
   --  gnat.sockets.linker_options%s
   --  system.object_reader%s
   --  system.dwarf_lines%s
   --  system.pool_size%s
   --  system.pool_size%b
   --  system.secondary_stack%s
   --  system.file_io%b
   --  system.storage_pools.subpools%b
   --  system.finalization_masters%b
   --  interfaces.c.strings%b
   --  interfaces.c%b
   --  ada.tags%b
   --  ada.strings.superbounded%b
   --  ada.strings.fixed%b
   --  ada.strings.maps%b
   --  system.soft_links%b
   --  system.os_lib%b
   --  ada.characters.handling%b
   --  system.secondary_stack%b
   --  system.dwarf_lines%b
   --  system.object_reader%b
   --  gnat.serial_communications%b
   --  system.address_image%b
   --  ada.exceptions.traceback%b
   --  ada.strings.unbounded%s
   --  ada.strings.unbounded%b
   --  gnat.decode_utf8_string%s
   --  gnat.decode_utf8_string%b
   --  gnat.encode_utf8_string%s
   --  gnat.encode_utf8_string%b
   --  gnat.sockets.thin_common%s
   --  gnat.sockets.thin_common%b
   --  gnat.sockets.thin%s
   --  gnat.sockets.thin%b
   --  gnat.sockets%b
   --  system.soft_links.tasking%s
   --  system.soft_links.tasking%b
   --  system.strings.stream_ops%s
   --  system.strings.stream_ops%b
   --  system.tasking.entry_calls%s
   --  system.tasking.initialization%s
   --  system.tasking.initialization%b
   --  system.tasking.protected_objects%s
   --  system.tasking.protected_objects%b
   --  system.tasking.utilities%s
   --  system.traceback%s
   --  ada.exceptions%b
   --  system.traceback%b
   --  ada.real_time%s
   --  ada.real_time%b
   --  ada.real_time.delays%s
   --  ada.real_time.delays%b
   --  ada.text_io%s
   --  ada.text_io%b
   --  ada.text_io.generic_aux%s
   --  ada.text_io.generic_aux%b
   --  ada.text_io.integer_aux%s
   --  ada.text_io.integer_aux%b
   --  ada.integer_text_io%s
   --  ada.integer_text_io%b
   --  gnat.traceback%s
   --  gnat.traceback%b
   --  gnat.traceback.symbolic%s
   --  gnat.traceback.symbolic%b
   --  system.tasking.protected_objects.entries%s
   --  system.tasking.protected_objects.entries%b
   --  system.tasking.queuing%s
   --  system.tasking.queuing%b
   --  system.tasking.utilities%b
   --  system.tasking.rendezvous%s
   --  system.tasking.protected_objects.operations%s
   --  system.tasking.protected_objects.operations%b
   --  system.tasking.rendezvous%b
   --  system.tasking.entry_calls%b
   --  system.tasking.stages%s
   --  system.tasking.stages%b
   --  gnatcoll%s
   --  can_defs%s
   --  byte_conv%s
   --  byte_conv%b
   --  can_node%s
   --  can_main%b
   --  can_utils%s
   --  can_utils%b
   --  exception_handling%s
   --  exception_handling%b
   --  gnatcoll.json%s
   --  gnatcoll.json.utility%s
   --  gnatcoll.json.utility%b
   --  gnatcoll.json%b
   --  queue%s
   --  queue%b
   --  radix%s
   --  radix%b
   --  server_net%s
   --  server_net%b
   --  tcp_client%s
   --  tcp_client%b
   --  uartwrapper%s
   --  uartwrapper%b
   --  bbb_can%s
   --  bbb_can%b
   --  can_node%b
   --  END ELABORATION ORDER


end ada_main;
