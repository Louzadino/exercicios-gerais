#include "jogo.h"
#include <stdio.h>

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}

void ComecaJogo(tJogo jogo){
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
}

int AcabouJogo(tJogo jogo){
    if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro) ||
    VenceuJogador(jogo.jogador1, jogo.tabuleiro) || 
    VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
        return 1;
    }

    return 0;
}

int ContinuaJogo(){
    char resposta;

    printf("Jogar novamente? (s,n)");
    scanf("%c", &resposta);

    if (resposta == 's' || resposta == 'S'){
        return 1;
    }

    return 0;
}
