main: read_line.o words.o
	gcc -g -o main read_line.o words.o

read_line.o: read_line.c read_line.h
	gcc -g -c read_line.c

words.o: words.c read_line.h
	gcc -g -c words.c
