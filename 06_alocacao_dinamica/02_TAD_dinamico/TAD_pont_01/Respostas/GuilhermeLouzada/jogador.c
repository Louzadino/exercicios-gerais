#include "jogador.h"
#include <stdlib.h>
#include <stdio.h>

tJogador* CriaJogador(int idJogador){

    tJogador* jogador = (tJogador*) malloc (sizeof(tJogador));

    jogador->id = idJogador;

    return jogador;
}
