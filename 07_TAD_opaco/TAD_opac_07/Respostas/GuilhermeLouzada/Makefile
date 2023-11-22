all: geraos main

main: main.o data.o
	gcc main.o data.o -o main -lm

geraos: main.c data.c
	gcc -c -g main.c data.c

clean:
	rm -rf *.o main