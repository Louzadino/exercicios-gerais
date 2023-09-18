#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"
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
        } else {
            jogada.sucesso = 1;
        }
    }

    if (FoiJogadaBemSucedida(jogada)){
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, jogada.x, jogada.y);
    }
    
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    int i, j;
    int linhaVencedora, colunaVencedora;
    char pecaJogador;

    if (jogador.id == ID_JOGADOR_1){
        pecaJogador = tabuleiro.peca1;
    } else if (jogador.id == ID_JOGADOR_2){
        pecaJogador = tabuleiro.peca2;
    }

    for (i = 0; i < TAM_TABULEIRO; i++){
        linhaVencedora = 1;
        for (j = 0; j < TAM_TABULEIRO; j++){
            if (tabuleiro.posicoes[i][j] != pecaJogador){
                linhaVencedora = 0;
                break;
            }
        }

        if (linhaVencedora){
            return 1;
        }
    }

    for (j = 0; j < TAM_TABULEIRO; j++){
        colunaVencedora = 1;
        for (i = 0; i < TAM_TABULEIRO; i++){
            if (tabuleiro.posicoes[i][j] != pecaJogador){
                colunaVencedora = 0;
                break;
            }
        }

        if (colunaVencedora){
            return 1;
        }
    }

    return 0;
}
