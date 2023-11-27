#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

struct pacote{
    void *vetor;
    int tam;
    Type tipo;
    int soma;
};

tPacote* CriaPacote(Type type, int numElem){

    tPacote* pacote = (tPacote*) calloc(1, sizeof(tPacote));

    pacote->tipo = type;
    pacote->tam = numElem;
    pacote->soma = 0;

    switch (type){
        case INT:
            pacote->vetor = (int*) calloc(1, sizeof(int) * numElem);
            break;
        case CHAR:
            pacote->vetor = (char*) calloc(1, (sizeof(char) * numElem) + 1);
            break;
        default:
            break;
    }

    return pacote;
}

void DestroiPacote(tPacote* pac){

    if (pac != NULL){
        if (pac->vetor){
            free(pac->vetor);
        }

        free(pac);
    }
}

void LePacote(tPacote* pac){

    printf("Digite o conteúdo do vetor/mensagem: \n");
    if (pac->tipo == INT){
        for (int i = 0; i < pac->tam;i++){
            scanf("%d", &((int*)pac->vetor)[i]);
        }
    } else {
        scanf("%s", (char*)pac->vetor);
    }
}

void ImprimePacote(tPacote* pac){

    if (pac->tipo == INT){
        for (int i = 0; i < pac->tam;i++){
            printf("%d", ((int*)pac->vetor)[i]);

            if (i < pac->tam - 1){
                printf(" ");
            }
        }
    } else {
        printf("%s", (char*)pac->vetor);
    }
}

void CalculaSomaVerificacaoPacote(tPacote* pac){

    for (int i = 0; i < pac->tam; i++){
        if (pac->tipo == INT){
            pac->soma += ((int*)pac->vetor)[i];
        } else {
            pac->soma += ((char*)pac->vetor)[i];
        }
    }
}
