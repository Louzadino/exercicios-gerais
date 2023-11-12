all: geraos main

main: main.o jogo.o jogada.o jogador.o tabuleiro.o
	gcc main.o jogo.o jogada.o jogador.o tabuleiro.o -o main -lm

geraos: main.c jogo.c jogada.c jogador.c tabuleiro.c
	gcc -c main.c jogo.c jogada.c jogador.c tabuleiro.c

clean:
	rm -rf *.o main