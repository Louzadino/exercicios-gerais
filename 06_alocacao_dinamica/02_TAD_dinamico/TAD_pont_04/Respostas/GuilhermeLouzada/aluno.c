#include "aluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

tAluno* CriaAluno(){
    tAluno* aluno = (tAluno*) malloc(sizeof(tAluno));

    if (aluno != NULL){
        aluno->nome = NULL;
        aluno->matricula = -1;
        aluno->n1 = -1;
        aluno->n2 = -1;
        aluno->n3 = -1;
    }

    return aluno;
}

void ApagaAluno(tAluno *aluno){

    if (aluno != NULL){
        free(aluno->nome);
        free(aluno);
    }
}

void LeAluno(tAluno *aluno){

    printf("Nome do aluno: ");
    char nomeBuffer[100];  // Supondo que os nomes tenham no máximo 100 caracteres
    scanf(" %99[^\n]", nomeBuffer);
    
    aluno->nome = (char*)malloc(strlen(nomeBuffer) + 1);
    strcpy(aluno->nome, nomeBuffer);

    printf("Matricula: ");
    scanf("%d", &aluno->matricula);

    printf("Notas: ");
    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){

    if (aluno1->matricula > aluno2->matricula){
        return 1;
    } else if (aluno1->matricula < aluno2->matricula){
        return -1;
    } 
    
    return 0;
}

int CalculaMediaAluno(tAluno* aluno){

    int media = 0;

    media = aluno->n1 + aluno->n2 + aluno->n3;
    media = media / 3;

    return media;
}

int VerificaAprovacao(tAluno* aluno){
    int mediaAluno = CalculaMediaAluno(aluno);

    if (mediaAluno >= 7){
        return 1;
    }

    return 0;
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}
