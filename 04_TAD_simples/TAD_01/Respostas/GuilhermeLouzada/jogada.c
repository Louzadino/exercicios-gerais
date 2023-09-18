#include "jogada.h"
#include <stdio.h>

tJogada LeJogada(){
    tJogada jogada;

    jogada.x = ObtemJogadaX(jogada);
    jogada.y = ObtemJogadaY(jogada);

    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    scanf("%d", &jogada.x);
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    scanf("%d", &jogada.y);
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    if (jogada.sucesso){
        return 1;
    }

    return 0;
}
