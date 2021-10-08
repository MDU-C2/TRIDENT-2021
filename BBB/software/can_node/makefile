this:
	gcc -c ../../firmware/UartWrapper/src/uartlib.c -o ../../firmware/UartWrapper/obj/uartlib.o
	gnatmake -P can_node.gpr
all:
	gnat clean -r -P can_node.gpr
	gcc -c ../../firmware/UartWrapper/src/uartlib.c -o ../../firmware/UartWrapper/obj/uartlib.o
	gnatmake -P can_node.gpr
clean:
	gnat clean -c -r -P can_node.gpr
  

