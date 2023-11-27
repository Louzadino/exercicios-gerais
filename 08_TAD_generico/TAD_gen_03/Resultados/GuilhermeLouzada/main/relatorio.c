#include <stdio.h>
#include "relatorio.h"
#include "aluno.h"

void ImprimeRelatorio(Vector *alunos){

    int qtdAlunos = VectorSize(alunos);
    float somaNotas = 0.0;
    float mediaNotas = 0.0;
    int qtdAprovados = 0;
    int qtdMasculino = 0;
    int qtdFeminino = 0;
    int qtdOutro = 0;

    for (int i = 0; i < qtdAlunos; i++){

        tAluno* aluno = (tAluno*)VectorGet(alunos, i);

        somaNotas += GetNotaAluno(aluno);

        if (GetNotaAluno(aluno) >= 6){
            qtdAprovados++;
        }

        if (GetGeneroAluno(aluno) == 'M')
            qtdMasculino++;
        
        else if (GetGeneroAluno(aluno) == 'F')
            qtdFeminino++;
            
        else if (GetGeneroAluno(aluno) == 'O')
            qtdOutro++;
    }

    mediaNotas = somaNotas / qtdAlunos;
    float porcentagemAprovados = (float)qtdAprovados / qtdAlunos * 100;
    float porcentagemMasculino = (float)qtdMasculino / qtdAlunos * 100;
    float porcentagemFeminuno = (float)qtdFeminino / qtdAlunos * 100;
    float porcentagemOutro = (float)qtdOutro / qtdAlunos * 100;

    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", porcentagemAprovados);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", porcentagemMasculino);
    printf("Feminino: %.2f%%\n", porcentagemFeminuno);
    printf("Outro: %.2f%%", porcentagemOutro);
}
