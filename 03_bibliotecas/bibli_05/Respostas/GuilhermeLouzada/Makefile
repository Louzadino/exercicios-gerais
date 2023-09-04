all: geraos main

main: main.o string_utils.o
	gcc main.o string_utils.o -o main -lm

geraos: main.c string_utils.c
	gcc -c main.c string_utils.c

clean:
	rm -rf *.o main