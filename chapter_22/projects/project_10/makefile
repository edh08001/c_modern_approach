main: inventory2.o readline.o
	gcc -g -o main inventory2.o readline.o

inventory2.o: inventory2.c readline.h 
	gcc -g -c inventory2.c 

readline.o: readline.c readline.h 
	gcc -g -c readline.c
