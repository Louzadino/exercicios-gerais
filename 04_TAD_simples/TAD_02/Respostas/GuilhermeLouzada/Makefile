all: geraos main

main: main.o candidato.o eleicao.o eleitor.o
	gcc main.o candidato.o eleicao.o eleitor.o -o main -lm

geraos: main.c candidato.c eleicao.c eleitor.c
	gcc -c main.c candidato.c eleicao.c eleitor.c

clean:
	rm -rf *.o main