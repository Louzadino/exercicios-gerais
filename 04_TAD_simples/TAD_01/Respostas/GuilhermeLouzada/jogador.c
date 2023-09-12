#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    jogada.sucesso = 0;

    while(jogada.sucesso = 0){
        printf("Jogador %d\n", jogador.id);
        printf("Digite uma posicao (x e y):");
        jogada = LeJogada();

        if (!EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y)){
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y);
        } else if (!EhPosicaoValidaTabuleiro(jogada.x, jogada.y)){
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", jogada.x, jogada.y);
        }
    }

    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, jogada.x, jogada.y);
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    
}