#include "eleicao.h"
#include <stdio.h>

tEleicao InicializaEleicao(){
    tEleicao eleicao;
    tCandidato candidato;
    int qtd_Candidatos = 0;
    int i = 0;
    char cargo;

    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;
    eleicao.totalEleitores = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    
    scanf("%d", &qtd_Candidatos);

    while(i < qtd_Candidatos){
        candidato = LeCandidato();
        cargo = ObtemCargo(candidato);

        if (cargo == 'P'){
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        } else if (cargo == 'G'){
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }

        i++;
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    int i = 0, j;
    int votoP, votoG;
    int presidenteInexistente;
    int governadorInexistente;

    //Leitura dos eleitores
    scanf("%d", &eleicao.totalEleitores);
    while (i < eleicao.totalEleitores){
        eleicao.eleitores[i] = LeEleitor();
        i++;
    }

    //Contagem dos votos;
    for (i = 0; i < eleicao.totalEleitores; i++){
        presidenteInexistente = 1;
        governadorInexistente = 1;

        votoP = ObtemVotoPresidente(eleicao.eleitores[i]);
        votoG = ObtemVotoGovernador(eleicao.eleitores[i]);

        if (votoP == 0){ //Se o voto for branco, incrementa e segue adiante
            eleicao.votosBrancosPresidente++;
        } else {
        //Analisa voto para presidente do eleitor atual
            for (j = 0; j < eleicao.totalPresidentes; j++){
                if (VerificaIdCandidato(eleicao.presidentes[j], votoP)){
                    eleicao.presidentes[i].votos++;
                    presidenteInexistente = 0;
                    break;
                }
            }

            if (presidenteInexistente){
                eleicao.votosNulosPresidente++;
            }
        }

        if (votoG == 0){ //Se o voto for branco, incrementa e segue adiante
            eleicao.votosBrancosGovernador++;
        } else {
            //Analisa voto para governador do eleitor atual
            for (j = 0; j < eleicao.totalGovernadores; j++){
                if (VerificaIdCandidato(eleicao.governadores[j], votoP)){
                    eleicao.governadores[i].votos++;
                    governadorInexistente = 0;
                }
            }

            if (governadorInexistente){
                eleicao.votosNulosGovernador++;
            }
        }
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){
    int i;
    int qtdVotosAtualP = 0, qtdVotosAtualG = 0;
    int candidatoVencedorP = 0, candidatoVencedorG = 0;

    //Encontrando presidente e governador vencedores
    for (i = 0; i < eleicao.totalPresidentes; i++){
        qtdVotosAtualP = ObtemVotos(eleicao.presidentes[i]); //qtd votos do presidente analisado no momento
        
        if (qtdVotosAtualP > eleicao.presidentes[candidatoVencedorP].votos){
            candidatoVencedorP = i;
        }
    }

    for (i = 0; i < eleicao.totalGovernadores; i++){
        qtdVotosAtualG = ObtemVotos(eleicao.governadores[i]); //qtd votos do governador analisado no momento
        
        if (qtdVotosAtualG > eleicao.governadores[candidatoVencedorG].votos){
            candidatoVencedorG = i;
        }
    }

    printf("- PRESIDENTE ELEITO: %s, (%d)\n", eleicao.presidentes[candidatoVencedorP].nome, eleicao.presidentes[candidatoVencedorP].votos);
    printf("- GOVERNADOR ELEITO: %s, (%d)\n", eleicao.governadores[candidatoVencedorG].nome, eleicao.governadores[candidatoVencedorG].votos);
}
