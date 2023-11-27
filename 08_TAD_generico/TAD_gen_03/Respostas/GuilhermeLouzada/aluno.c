#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    char nome[50];
    float nota;
    char genero;
};

tAluno *CriaAluno(){

    tAluno* aluno = (tAluno*) calloc(1, sizeof(tAluno));
    
    if (aluno == NULL){
        printf("ERRO: falha na alocacao do aluno\n");
        exit(0);
    }

    return aluno;
}

void DestroiAluno(data_type aluno){

    if (aluno != NULL){
        free((tAluno*)aluno);
    }
}

void LeAluno(tAluno *aluno){

    scanf("%[^;];%c;%f", aluno->nome, &aluno->genero, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno){

    if (aluno != NULL){
        return aluno->genero;
    }
}

float GetNotaAluno(tAluno *aluno){

    if (aluno != NULL){
        return aluno->nota;
    }
}
