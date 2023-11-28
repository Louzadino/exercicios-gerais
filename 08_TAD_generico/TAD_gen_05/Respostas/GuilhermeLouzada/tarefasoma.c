#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

struct soma{
    float num1;
    float num2;
    int prioridade;
};

tSoma* CriaTarefaSoma(float n1, float n2){

    tSoma* soma = (tSoma*) malloc(sizeof(tSoma));

    if (soma == NULL){
        printf("ERRO: falha na alocacao de tSoma");
        exit(0);
    }

    soma->num1 = n1;
    soma->num2 = n2;

    return soma;
}

void ExecutaTarefaSoma(void *sum){

    
}

void DestroiTarefaSoma(void *sum){


}