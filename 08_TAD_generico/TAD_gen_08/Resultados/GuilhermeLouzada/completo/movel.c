#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movel.h"

struct Movel{

    char nome[31];
};

tMovel *CriaMovel(char *nome){

    tMovel* movel = (tMovel*) calloc(1, sizeof(tMovel));

    if (movel == NULL){
        printf("ERRO: falha na alocacao do movel");
        exit(0);
    }

    strcpy(movel->nome, nome);

    return movel;
}

tMovel *LeMovel(){

    char nome[31];

    scanf("%s", nome);

    return CriaMovel(nome);
}

void DestroiMovel(tMovel *m){

    if (m != NULL){
        free(m);
    }
}

void ImprimeMovel(tMovel *m){

    printf("%s\n", m->nome);
}
