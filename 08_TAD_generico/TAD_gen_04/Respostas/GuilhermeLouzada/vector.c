#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector{
    void** vetor;
    int tam;
};

Vector *VectorConstruct(){

    Vector* vetor = (Vector*) calloc(1, sizeof(Vector));

    return vetor;
}

void VectorPushBack(Vector *v, DataType val){

    v->vetor = realloc(v->vetor, sizeof(Vector*) * (v->tam + 1));

    v->vetor[v->tam] = val;
    v->tam++;
}

DataType VectorGet(Vector *v, int i){

    if (v != NULL){
        return v->vetor[i];
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
            if (v->vetor[i] != NULL){
                destroy(v->vetor[i]);
            }
        }

        free(v->vetor);
        free(v);
    }
}
