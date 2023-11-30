#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

struct soma{
    float num1;
    float num2;
};

tSoma* CriaTarefaSoma(float n1, float n2){

    tSoma* soma = (tSoma*) calloc(1, sizeof(tSoma));

    if (soma == NULL){
        printf("ERRO: falha na alocacao de tSoma");
        exit(0);
    }

    soma->num1 = n1;
    soma->num2 = n2;

    return soma;
}

void ExecutaTarefaSoma(void *sum){

    tSoma* tarefa = (tSoma*)sum;
    float resultado = tarefa->num1 + tarefa->num2;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", tarefa->num1, tarefa->num2, resultado);
}

void DestroiTarefaSoma(void *sum){

    if (sum != NULL){
        free(sum);
    }
}
