with ada.Text_IO;

package body can_log is

procedure Log_Data_From_Can(isOutput : boolean; msg : can_defs.can_message) is
         use Ada.Text_IO;

         bFile_Created : boolean := false;
         xOutput : Ada.Text_IO.File_type;
         sFileName : string := "logdata001.txt";


         function Does_File_Exist (Name : String) return Boolean is
            The_File : Ada.Text_IO.File_Type;
         begin
            Open (The_File, In_File, Name);
            Close (The_File);
            return True;
         exception
            when Name_Error =>
               return False;
         end Does_File_Exist;

         procedure Open_File is
            n100 : integer := 0;
            n10  : integer := 0;
            n1   : integer := 1;
         begin
            while Does_File_Exist(Name => sFileName) loop
               Ada.Text_IO.Put_Line("file found");
               n1 := n1 + 1;
               if n1 = 10 then
                  n1 := 0;
                  n10 := n10 + 1;
                  if n10 = 10 then
                     n100 := n100 + 1;
                     n10 := 0;
                  end if;
               end if;
               sFileName(8) := Character'val(Character'pos('0') + n100);
               sFileName(9) := Character'val(Character'pos('0') + n10);
               sFileName(10) := Character'val(Character'pos('0') + n1);
            end loop;
            CREATE(xOutput, Out_File ,sFileName);
            bFile_Created := true;
         end Open_File;

      begin
         if not bFile_Created then
            Open_File;
         end if;
         if isOutput then
            Put(File => xOutput,
                Item => "out");
         else
            Put(File => xOutput,
                Item => "in ");
         end if;
         PUT(File => xOutput,
             Item => " ");
         PUT(File => xOutput,
             Item => msg.ID.identifier'img);
         PUT(File => xOutput,
             Item => " ");
         PUT(File => xOutput,
             Item => msg.ID.isExtended'img);
         PUT(File => xOutput,
             Item => " ");
         PUT(File => xOutput,
             Item => msg.Len'img);
         PUT(File => xOutput,
             Item => " ");
         for i in 1..8 loop
            PUT(File => xOutput,
                Item => msg.Data(can_defs.DLC_TYPE(i))'img);
            PUT(File => xOutput,
                Item => " ");
         end loop;
         PUT_LINE(File => xOutput,
                  Item => " ");

      end Log_Data_From_Can;
end can_log;
