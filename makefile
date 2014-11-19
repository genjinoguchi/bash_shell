all: main.o gdigenji.o
	gcc -o we.out main.o gdigenji.o

main.o: main.c bashell.h
	gcc -c main.c

gdigenji.o: gdigenji.c bashell.h
	gcc -c gdigenji.c
