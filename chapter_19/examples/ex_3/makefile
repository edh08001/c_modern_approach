main: main.o queue_link.o
	gcc -g -o main main.o queue_link.o

main.o: main.c queue.h
	gcc -g -c main.c 

queue_link.o: queue_link.c queue.h
	gcc -g -c queue_link.c
