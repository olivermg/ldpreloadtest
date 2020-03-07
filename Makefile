all: libfoo.so libbar.so prg wrapper wrapper32


foo.o: foo.c
	gcc -Wall -shared -g -c foo.c

libfoo.so: foo.o
	gcc -Wall -shared -g -o libfoo.so foo.o


bar.o: bar.c
	gcc -Wall -shared -g -c bar.c

libbar.so: bar.o
	gcc -Wall -shared -g -o libbar.so bar.o


prg.o: prg.c
	gcc -Wall -g -I. -c prg.c

prg: prg.o
	gcc -Wall -g -L. -lfoo -o prg prg.o


wrapper.o: wrapper.c
	gcc -Wall -g -c wrapper.c

wrapper: wrapper.o
	gcc -Wall -g -o wrapper wrapper.o

wrapper32.o: wrapper.c
	gcc -Wall -m32 -g -c -o wrapper32.o wrapper.c

wrapper32: wrapper32.o
	gcc -Wall -m32 -g -o wrapper32 wrapper32.o


clean:
	rm -f *.o libfoo.so libbar.so prg wrapper wrapper32


.PHONY: all clean
