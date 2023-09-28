#include <stdio.h>
#include "candidato.h"

int main(){
    tCandidato candidato;
    
    int qtd_Candidatos;
    scanf("%d", &qtd_Candidatos);

    int i = 0;
    while(i < qtd_Candidatos){
        candidato = LeCandidato();

        if (ObtemCargo(candidato) == 'P'){

        } else if (ObtemCargo(candidato) == 'G'){
            
        }

        i++;
    }

    


    return 0;
}
