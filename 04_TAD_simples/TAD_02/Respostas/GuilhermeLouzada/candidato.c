#include <stdio.h>
#include <string.h>
#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;

    return candidato;
}

tCandidato LeCandidato(){
    char nome[50], partido[50], cargo;
    int id;

    scanf(" %[^,], %[^,], %c, %d", nome, partido, &cargo, &id);

    return CriaCandidato(nome, partido, cargo, id);
}

int VerificaIdCandidato(tCandidato candidato, int id){
    return (candidato.id == id);
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    if (strcmp(candidato1.nome, candidato2.nome) == 0){
        return 1;
    }

    return 0;
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    float percentual;
    
    percentual = (candidato.votos / totalVotos) * 100;

    return percentual;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s, (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, 
                                            candidato.votos, percentualVotos);
}
