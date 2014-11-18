all: main.o
	gcc -o supershell main.o

main.o: main.c bashell.h
	gcc -c main.c
