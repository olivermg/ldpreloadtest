all: libfoo.so libbar.so prg wrapper


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
	gcc -Wall -g -I. -c wrapper.c

wrapper: wrapper.o
	gcc -Wall -g -L. -lbar -o wrapper wrapper.o


clean:
	rm -f *.o libfoo.so libbar.so prg wrapper


.PHONY: all clean
