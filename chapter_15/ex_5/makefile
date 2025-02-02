demo: main.o f1.o f2.o
	gcc -g -o demo main.o f1.o f2.o

main.o: main.c f1.h 
	gcc -g -c main.c

f1.o: f1.c f1.h f2.h 
	gcc -g -c f1.c

f2.o: f2.c f1.h f2.h 
	gcc -g -c f2.c
