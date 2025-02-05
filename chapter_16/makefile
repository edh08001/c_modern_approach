main: inventory.o part.o readline.o
	gcc -g -o main inventory.o part.o readline.o

inventory.o: inventory.c inventory.h part.h readline.h
	gcc -g -c inventory.c

part.o: part.c part.h readline.h
	gcc -g -c part.c 

readline.o: readline.c readline.h 
	gcc -g -c readline.c
