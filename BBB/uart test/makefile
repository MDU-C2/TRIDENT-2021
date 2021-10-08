clean:
	gnat clean -r -P uart_test.gpr
  
all:	
	gnat clean -r -P uart_test.gpr
	gcc -c ../firmware/uartwrapper/src/uartlib.c -o ../firmware/uartwrapper/obj/uartlib.o
	gnatmake -c -P  ../firmware/uartwrapper/uartwrapper.gpr
	gnatmake -c -P  ../lib/can_utils/can_utils.gpr
	gnatmake -c -P  ../lib/can_defs/can_defs.gpr
	gnatmake -c -P  ../lib/exception_handling/exception_handling.gpr
	gnatmake -c -P  ../lib/queue/queue.gpr
	gnatmake -c -P  ../firmware/bbb_can/bbb_can.gpr


	 gnatbind obj/main.ali  -I../firmware/UartWrapper/obj/ -I../lib/can_utils/build/ -I../lib/can_defs/build/ -I../lib/exception_handling/obj/ -I../lib/queue/build/ -I../firmware/bbb_can/build/ 
	gnatlink obj/main.ali ../firmware/UartWrapper/obj/uartlib.o

