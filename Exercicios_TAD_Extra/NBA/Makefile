all: geraos main

main: main.o partida.o torneio.o franquia.o
	gcc main.o partida.o torneio.o franquia.o -o main -lm

geraos: main.c partida.c torneio.c franquia.c
	gcc -c main.c partida.c torneio.c franquia.c

clean:
	rm -rf *.o main