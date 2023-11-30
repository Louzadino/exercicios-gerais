#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>

struct mult{
    float n1;
    float n2;
};

tMult* CriaTarefaMultiplicar(float n1, float n2){

    tMult* multiplica = (tMult*) calloc(1, sizeof(tMult));

    if (multiplica == NULL){
        printf("ERRO: falha na alocacao de multiplica");
        exit(0);
    }

    multiplica->n1 = n1;
    multiplica->n2 = n2;

    return multiplica;
}

void ExecutaTarefaMultiplicar(void *mult){

    tMult* multiplica = (tMult*) mult;
    float resultado = multiplica->n1 * multiplica->n2;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", multiplica->n1, multiplica->n2, resultado);
}

void DestroiTarefaMultiplicar(void *mult){

    if (mult != NULL){
        free(mult);
    }
}
