#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct impr{
    char msg[50];
};

tImpr* CriaTarefaImprimir(char *msg){

    tImpr* imprime = (tImpr*) calloc(1, sizeof(tImpr));

    if (imprime == NULL){
        printf("ERRO: falha na alocacao de imprime");
        exit(0);
    }

    strcpy(imprime->msg, msg);

    return imprime;
}

void ExecutaTarefaImprimir(void *imp){

    tImpr* tarefa = (tImpr*)imp;
    printf("\n%s", tarefa->msg);
}

void DestroiTarefaImprimir(void *imp){
    
    if (imp != NULL){
        free(imp);
    }
}
