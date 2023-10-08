all: geraos main

main: main.o utils.o
	gcc main.o utils.o -o main -lm

geraos: main.c utils.c
	gcc -c main.c utils.c

clean:
	rm -rf *.o main