#include "tabuleiro.h"
#include <stdlib.h>
#include <stdio.h>

tTabuleiro* CriaTabuleiro(){

    tTabuleiro* tabuleiro = (tTabuleiro*) malloc (sizeof(tTabuleiro));

    return tabuleiro;
}
