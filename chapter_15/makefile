justify: justify.o word.o line.o
	gcc -g -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h 
	gcc -g -c justify.c 

word.o: word.c word.h 
	gcc -g -c word.c 

line.o: line.c line.h 
	gcc -g -c line.c

