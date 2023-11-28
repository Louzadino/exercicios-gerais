#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"

struct Agencia{
    Vector* contas;
    int num;
    char nome[50];
};

tAgencia *CriaAgencia(){

    tAgencia* agencia = (tAgencia*) calloc(1, sizeof(tAgencia));

    agencia->contas = VectorConstruct();
    return agencia;
}

void DestroiAgencia(DataType agencia){

    if (agencia != NULL){
        tAgencia* a = (tAgencia*)agencia;
        VectorDestroy(a->contas, (void(*)(DataType))DestroiConta);
        free(a);
    }
}

void LeAgencia(tAgencia *agencia){

    scanf("%d;%[^\n]\n", &agencia->num, agencia->nome);
}

void AdicionaConta(tAgencia *agencia, tConta *conta){

    VectorPushBack(agencia->contas, conta);
}

int ComparaAgencia(int numAgencia, tAgencia *agencia2){

    if (numAgencia == agencia2->num)
        return 1;
    
    return 0;
}

float GetSaldoMedioAgencia (tAgencia *agencia){

    float saldoTotal = 0;

    for (int i = 0; i < VectorSize(agencia->contas); i++){
        tConta* conta = (tConta*) VectorGet(agencia->contas, i);
        saldoTotal += GetSaldoConta(conta);
    }

    return saldoTotal / VectorSize(agencia->contas);
}

void ImprimeDadosAgencia(tAgencia *agencia){

    printf("\n	Nome: %s\n", agencia->nome);
    printf("	Numero: %d\n", agencia->num);
    printf("	Numero de contas cadastradas: %d\n", VectorSize(agencia->contas));
    printf("	Saldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}
