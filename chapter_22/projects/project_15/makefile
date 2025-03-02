justify: justify.o word.o line.o readline.o
	gcc -g -o justify justify.o word.o line.o readline.o

justify.o: justify.c word.h line.h readline.h
	gcc -g -c justify.c 

word.o: word.c word.h 
	gcc -g -c word.c 

line.o: line.c line.h 
	gcc -g -c line.c

readline.o: readline.c readline.h
	gcc -g -c readline.c
