#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    tAluno* aluno = CriaAluno();

    if (aluno == NULL){
        printf("ERRO NA ALOCACAO DE MEMORIA!!!\n");
        return 1;
    }

    int qtdAlunos;
    printf("Quantidade de alunos: ");
    scanf("%d", &qtdAlunos);

    for (int i = 0; i < qtdAlunos; i++){
        LeAluno(&aluno[i]);
    }

    for (int i = 0; i < qtdAlunos - 1; i++){
        for (int j = 0; j < qtdAlunos - i - 1; j++){
            if (ComparaMatricula(&aluno[j], &aluno[j + 1]) == 1){
                tAluno temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < qtdAlunos; i++){
        if (VerificaAprovacao(&aluno[i])){
            ImprimeAluno(&aluno[i]);
        }
    }
    
    ApagaAluno(aluno);

    return 0;
}
