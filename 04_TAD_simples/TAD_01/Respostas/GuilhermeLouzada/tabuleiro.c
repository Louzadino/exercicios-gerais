#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro(){

    tTabuleiro tabuleiro;
    tabuleiro.peca1 = 'x';
    tabuleiro.peca2 = 'o';
    tabuleiro.pecaVazio = '-';

    for (int i = 0; i < TAM_TABULEIRO; i++){
        for (int j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    
    if (peca == PECA_1){
        tabuleiro.posicoes[x][y] = tabuleiro.peca1;
    } else if (peca == PECA_2){
        tabuleiro.posicoes[x][y] = tabuleiro.peca2;
    }

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){

    for (int i = 0; i < TAM_TABULEIRO; i++){
        for (int j = 0; j < TAM_TABULEIRO; j++){
            if (tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                return 1; // Há pelo menos uma posição livre
            }
        }
    }

    return 0; // Não há posições livres
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){

    char pecaJogador;

    if (peca == PECA_1){
        pecaJogador = tabuleiro.peca1;
    } else if (peca == PECA_2){
        pecaJogador = tabuleiro.peca2;
    }

    return tabuleiro.posicoes[x][y] == pecaJogador;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    return tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    return (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO);
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    for (int i = 0; i < TAM_TABULEIRO; i++){
        for (int j = 0; j < TAM_TABULEIRO; j++){
            printf("%c ", tabuleiro.posicoes[i][j]);
        }

        printf("\n");
    }
}
