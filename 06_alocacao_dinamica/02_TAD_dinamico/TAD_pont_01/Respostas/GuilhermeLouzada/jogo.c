#include "jogo.h"
#include <stdlib.h>
#include <stdio.h>

tJogo* CriaJogo(){

    tJogo* jogo = (tJogo*) malloc (sizeof(tJogo));

    if (jogo){
        printf("ALOCACAO DE MEMORIA FEITA COM SUCESSO\n");
    } else {
        printf("ERRO NA ALOCACAO DE MEMORIA\n");
        exit(1);
    }

    return jogo;
}

void ComecaJogo(tJogo* jogo){
    
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador2 = CriaJogador(ID_JOGADOR_2);
}