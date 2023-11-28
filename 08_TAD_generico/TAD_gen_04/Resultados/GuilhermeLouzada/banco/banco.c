#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

struct Banco{
    char nome[50];
    Vector* agencias;
};

tBanco *CriaBanco(){

    tBanco* banco = (tBanco*) calloc(1, sizeof(tBanco));
    banco->agencias = VectorConstruct();

    return banco;
}

void DestroiBanco(tBanco *banco){

    if (banco != NULL){
        VectorDestroy(banco->agencias, (void(*)(DataType))DestroiAgencia);
        free(banco);
    }
}

void LeBanco(tBanco *banco){

    scanf("%[^\n]\n", banco->nome);
}

void AdicionaAgencia(tBanco *banco, tAgencia *agencia){

    VectorPushBack(banco->agencias, agencia);
}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){

    for (int i = 0; i < VectorSize(banco->agencias); i++){
        tAgencia* agencia = (tAgencia*) VectorGet(banco->agencias, i);

        if (ComparaAgencia(numAgencia, agencia)){
            AdicionaConta(agencia, cliente);
            return;
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco){

    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");

    for (int i = 0; i < VectorSize(banco->agencias); i++){
        tAgencia* agencia = (tAgencia*) VectorGet(banco->agencias, i);
        ImprimeDadosAgencia(agencia);
    }
}
