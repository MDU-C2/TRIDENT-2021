clean:
	rm -f obj/i2cdepth.so
this:
	gcc -fPIC -shared src/i2cdepth.c -o obj/i2cdepth.so
run:
	python depth_sensor.py
all: clean this run
