#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>

struct gerenciadorpacotes{
    tPacote** pacotes;
    int numPacs;
};


tGerenciador* CriaGerenciador(){

    tGerenciador* gerenciador = (tGerenciador*) malloc(sizeof(tGerenciador));
    gerenciador->pacotes = NULL;
    gerenciador->numPacs = 0;

    return gerenciador;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){

    geren->pacotes = realloc(geren->pacotes, (geren->numPacs + 1) * sizeof(tPacote*));

    geren->pacotes[geren->numPacs] = pac;
    geren->numPacs++;
}

void DestroiGerenciador(tGerenciador* geren){

    if (geren != NULL){
        if (geren->pacotes){
            for (int i = 0; i < geren->numPacs; i++){

                if (geren->pacotes[i])
                    DestroiPacote(geren->pacotes[i]);
            }

            free(geren->pacotes);
        }

        free(geren);
    }
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){

    if (geren != NULL)
        ImprimePacote(geren->pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren){

    for (int i = 0; i < geren->numPacs; i++){
        ImprimePacote(geren->pacotes[i]);
        printf("\n");
    }
}
