#include "jogo.h"
#include <stdio.h>

int main(){

    tJogo jogo = CriaJogo();
    int jogando = 1;

    while (jogando){

        ComecaJogo(jogo);
        while(!AcabouJogo(jogo)){
            JogaJogador(jogo.jogador1, jogo.tabuleiro);
        }

        jogando = ContinuaJogo(jogo);
    }

    return 0;
}
