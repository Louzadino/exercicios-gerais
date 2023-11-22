#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic{
    void *vetor;
    int tam;
    Type tipo;
};

tGeneric* CriaGenerico(Type type, int numElem){

    tGeneric* generico = (tGeneric*) malloc(sizeof(tGeneric));

    generico->tam = numElem;
    generico->tipo = type;

    switch (generico->tipo){
    case INT:
        generico->vetor = (int*) malloc(numElem * sizeof(int));
        break;
    case FLOAT:
        generico->vetor = (float*) malloc(numElem * sizeof(float));
        break;
    default:
        break;
    }

    return generico;
}

void DestroiGenerico(tGeneric* gen){

    if (gen != NULL){
        if (gen->vetor != NULL){
            free(gen->vetor);
        }

        free(gen);
    }
}

void LeGenerico(tGeneric* gen){

    printf("\nDigite o vetor:\n");
    for (int i = 0; i < gen->tam; i++){
        if (gen->tipo == INT){
            scanf("%d", &((int*)gen->vetor)[i]);
        } else {
            scanf("%f", &((float*)gen->vetor)[i]);
        }
    }
}

void ImprimeGenerico(tGeneric* gen){

    for (int i = 0; i < gen->tam; i++){
        if (gen->tipo == INT){
            printf("%d", ((int*)gen->vetor)[i]);
        } else {
            printf("%.2f", ((float*)gen->vetor)[i]);
        }

        if (i < gen->tam - 1){
            printf(" ");
        }
    }
}
