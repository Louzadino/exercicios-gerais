#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector{
    void** alunos;
    int tam;
};

Vector *VectorConstruct(){

    Vector* vetor = (Vector*) calloc(1, sizeof(Vector));

    return vetor;
}

void VectorPushBack(Vector *v, data_type val){

    v->alunos = realloc(v->alunos, sizeof(Vector*) * (v->tam + 1));

    v->alunos[v->tam] = val;
    v->tam++; 
}

data_type VectorGet(Vector *v, int i){

    if (v != NULL){
        return v->alunos[i];
    }
}

int VectorSize(Vector *v){

    if (v != NULL){
        return v->tam;
    }
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){

    if (v != NULL){
        for (int i = 0; i < VectorSize(v); i++){
            if (v->alunos[i] != NULL){
                destroy(v->alunos[i]);
            }
        }

        free(v->alunos);
        free(v);
    }
}
