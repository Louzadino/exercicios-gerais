#include <stdio.h>
#include "eleicao.h"

int main(){
    tCandidato candidato;
    tEleicao eleicao;

    int i = 0;
    int qtd_Candidatos;

    scanf("%d", &qtd_Candidatos);

    while(i < qtd_Candidatos){
        eleicao.totalPresidentes = 0;
        eleicao.totalGovernadores = 0;
        candidato = LeCandidato();

        if (ObtemCargo(candidato) == 'P'){
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
        } else if (ObtemCargo(candidato) == 'G'){
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
        }

        i++;
    }

    return 0;
}
