#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    tJogo* jogo = CriaJogo();

    ComecaJogo(jogo);

    free(jogo);

    return 0;
}
