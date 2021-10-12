with tcp_client;
with GNATCOLL;
with GNATCOLL.JSON;
with ada.Text_IO;
with Interfaces;


with ada.Unchecked_Conversion;
with ada.Real_Time; use ada.Real_Time;




procedure tcp_client_main is

   function happ (meh : integer) return integer;
   pragma Import(c,happ,"test");


   type bool_array is array (1..16) of Boolean;

   type unint is record
      one : Interfaces.Unsigned_8;
      two : Interfaces.Unsigned_8;
   end record;
--     pragma pack (derp);
--     pragma pack bool_array);



   function yey is new ada.Unchecked_Conversion(Source => unint, Target => bool_array);

   test : unint;
   bool16 : bool_array;
   gah : integer;

   xjson : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   xjson2 : GNATCOLL.JSON.JSON_Value := GNATCOLL.JSON.Create_Object;
   datbool : Boolean := false;
   i : integer := 0;

begin

   loop

      delay 1.0;
   end loop;

   ada.Text_IO.Put_Line(happ(2)'img);
   tcp_client.Set_IP_And_Port("127.0.0.1","abc");




   xjson.Set_Field("target","cmp");
   tcp_client.SetTimeout(1.0);

   loop
xjson.Set_Field("derp",i);
      delay(1.0);
      tcp_client.Send(xJson,datbool);
      tcp_client.Get(xJson2,datbool);
      Ada.Text_IO.Put_Line(datbool'img);
      Ada.Text_IO.Put_Line(xJson2.Write);
      i := i + 1;
   end loop;


   gah := happ(2);
   ada.Text_IO.Put_Line(gah'img);

   test.one := 1;
   test.two := 1;

   bool16 := yey(test);
   for i in 1..16 loop
   ada.Text_IO.Put_Line(bool16(i)'img);
   end loop;



end tcp_client_main;
