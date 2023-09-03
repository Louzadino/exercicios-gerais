all: geraos main

main: main.o matrix_utils.o
	gcc main.o matrix_utils.o -o main -lm

geraos: main.c matrix_utils.c
	gcc -c main.c matrix_utils.c

clean:
	rm -rf *.o main
