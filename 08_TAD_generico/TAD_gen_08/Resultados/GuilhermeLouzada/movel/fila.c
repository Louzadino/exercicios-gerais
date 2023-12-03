#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct Fila{

    Vector* vetor;
};

Fila *FilaConstruct(){

    Fila* fila = (Fila*) calloc(1, sizeof(Fila));

    if (fila == NULL){
        printf("ERRO: falha na alocacao da fila");
        exit(0);
    }

    fila->vetor = VectorConstruct();

    return fila;
}

void FilaDestroy(Fila *f, void (*destroy)(DataType)){

    if (f != NULL){
        VectorDestroy(f->vetor, destroy);
        free(f);
    }
}

int FilaSize(Fila *f){

    return VectorSize(f->vetor);
}

DataType FilaPop(Fila *f){

    return VectorPopFront(f->vetor);
}

void FilaPush(Fila *f, DataType val){

    return VectorPushBack(f->vetor, val);
}
