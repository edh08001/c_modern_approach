main: main.o readline.o
	gcc -g -o main main.o readline.o

main.o: main.c readline.h
	gcc -g -c main.c

readline.o: readline.c readline.h 
	gcc -g -c readline.c
