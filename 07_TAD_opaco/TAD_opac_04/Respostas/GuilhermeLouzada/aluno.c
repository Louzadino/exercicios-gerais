#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    char *nome;
    int matricula;
    int n1, n2, n3;
};

tAluno* CriaAluno(){

    tAluno *aluno = (tAluno*) malloc(sizeof(tAluno));

    if (aluno == NULL){
        printf("ERRO: FALHA NA ALOCACAO DO ALUNO");
        return 0;
    }

    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    aluno->nome = NULL;

    return aluno;
}

void ApagaAluno(tAluno *aluno){

    if (aluno != NULL){
        if (aluno->nome != NULL){
            free(aluno->nome);
        }

        free(aluno);
    }
}

void LeAluno(tAluno *aluno){

    aluno->nome = (char*) malloc(50 * sizeof(char));

    scanf("%s", aluno->nome);
    scanf("%d", &aluno->matricula);
    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){

    if (aluno1->matricula > aluno2->matricula)
        return 1;
    else if (aluno1->matricula < aluno2->matricula)
        return -1;
    else
        return 0;
}

int CalculaMediaAluno(tAluno* aluno){

    int soma = aluno->n1 + aluno->n2 + aluno->n3;
    int media = soma / 3;

    return media;
}

int VerificaAprovacao(tAluno* aluno){

    int media = CalculaMediaAluno(aluno);

    if (media >= 7)
        return 1;
    else if (media < 7){
        return 0;
    }
}

void ImprimeAluno(tAluno* aluno){

    printf("%s\n", aluno->nome);
}
