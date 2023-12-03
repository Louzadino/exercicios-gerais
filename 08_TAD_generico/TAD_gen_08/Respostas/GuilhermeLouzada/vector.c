#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector{

    void** dados;
    int tam;
};

Vector *VectorConstruct(){

    Vector* dados = (Vector*) calloc(1, sizeof(Vector));

    if (dados == NULL){
        printf("ERRO: falha na alocacao do dados");
        exit(0);
    }

    return dados;
}

void VectorPushBack(Vector *v, DataType val){

    v->dados = realloc(v->dados, sizeof(Vector*) * (v->tam + 1));

    v->dados[v->tam] = val;
    v->tam++;
}

DataType VectorPopFront(Vector *v){

    DataType primeiroElem = v->dados[0];

    for (int i = 0; i < v->tam - 1; i++){
        v->dados[i] = v->dados[i + 1];
    }

    v->tam--;

    return primeiroElem;
}

DataType VectorGet(Vector *v, int i){

    if (v != NULL){
        return v->dados[i];
    }
}

int VectorSize(Vector *v){

    if (v != NULL){
        return v->tam;
    }
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){

    if (v != NULL){
        for (int i = 0; i < VectorSize(v); i++){
            if (v->dados[i] != NULL){
                destroy(v->dados[i]);
            }
        }

        free(v->dados);
        free(v);
    }
}
