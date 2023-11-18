all: geraos main

main: main.o vetor.o
	gcc main.o vetor.o -o main -lm

geraos: main.c vetor.c
	gcc -c -g main.c vetor.c

clean:
	rm -rf *.o main