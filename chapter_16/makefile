main: inventory.o part.o 
	gcc -g -o main inventory.o part.o 

inventory.o: inventory.c inventory.h part.h
	gcc -g -c inventory.c

part.o: part.c part.h 
	gcc -g -c part.c 
