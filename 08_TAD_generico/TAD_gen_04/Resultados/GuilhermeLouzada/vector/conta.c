#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct Conta{

    int num;
    char nome[50];
    float saldo;
};

tConta *CriaConta(){

    tConta* conta = (tConta*) calloc(1, sizeof(tConta));

    if (conta == NULL){
        printf("ERRO: falha na alocacao da conta");
    }

    return conta;
}

void DestroiConta(DataType conta){

    tConta* c = (tConta*)conta;

    if (c != NULL){
        free(c);
    }
}

void LeConta(tConta *conta){

    scanf("%d;%[^;];%f", &conta->num, conta->nome, &conta->saldo);
}

float GetSaldoConta(tConta *conta){

    if (conta != NULL){
        return conta->saldo;
    }
}
