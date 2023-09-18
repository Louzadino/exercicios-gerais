all: geraos main

main: main.o jogo.o jogador.o jogada.o tabuleiro.o
	gcc main.o jogo.o jogador.o jogada.o tabuleiro.o -o main -lm

geraos: main.c jogo.c jogador.c jogada.c tabuleiro.c
	gcc -c main.c jogo.c jogador.c jogada.c tabuleiro.c

clean:
	rm -rf *.o main