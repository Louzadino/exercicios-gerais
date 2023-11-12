all: geraos main

main: main.o evento.o
	gcc main.o evento.o -o main -lm

geraos: main.c evento.c
	gcc -c main.c evento.c

clean:
	rm -rf *.o main