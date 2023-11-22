#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(){

    int qtdAlunos;

    scanf("%d", &qtdAlunos);

    tAluno **alunos = (tAluno**) malloc(qtdAlunos * sizeof(tAluno*));

    for (int i = 0; i < qtdAlunos; i++){

        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    for (int i = 0; i < qtdAlunos - 1; i++){
        for (int j = i + 1; j < qtdAlunos; j++){

            if (ComparaMatricula(alunos[i], alunos[j]) == 1){
                tAluno* temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    for (int i = 0; i < qtdAlunos; i++){
        
        if (VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
    }

    for (int i = 0; i < qtdAlunos; i++){

        ApagaAluno(alunos[i]);
    }
    free(alunos);

    return 0;
}
