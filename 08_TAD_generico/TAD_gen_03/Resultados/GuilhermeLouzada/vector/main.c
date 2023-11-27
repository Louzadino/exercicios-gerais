#include <stdio.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

int main(){

    Vector* vetor = VectorConstruct();
    int tamVetor;

    scanf("%d", &tamVetor);

    for (int i = 0; i < tamVetor; i++){
        tAluno* aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vetor, (data_type)aluno);
    }

    ImprimeRelatorio(vetor);

    VectorDestroy(vetor, (void(*)(data_type))DestroiAluno);
    return 0;
}
