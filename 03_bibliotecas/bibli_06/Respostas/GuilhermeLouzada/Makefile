all: geraos main

main: main.o temperature_conversor.o
	gcc main.o temperature_conversor.o -o main -lm

geraos: main.c temperature_conversor.c
	gcc -c main.c temperature_conversor.c

clean:
	rm -rf *.o main