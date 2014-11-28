all: main.o gdigenji.o stringsep.o
	gcc -o we.out main.o gdigenji.o stringsep.o

main.o: main.c bashell.h
	gcc -c main.c

gdigenji.o: gdigenji.c bashell.h
	gcc -c gdigenji.c

stringsep.o: stringsep.c bashell.h
	gcc -c stringsep.c

clean:
	rm *.o
