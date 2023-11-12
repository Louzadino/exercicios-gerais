#include <stdio.h>
#include <string.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos){

    scanf(" %[^\n]", eventos[*numEventos].nome);
    scanf("%d %d %d", &eventos[*numEventos].dia, 
                        &eventos[*numEventos].mes, 
                        &eventos[*numEventos].ano);

    (*numEventos)++;
}

void exibirEventos(Evento* eventos, int* numEventos){
    int i;

    for (i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, 
                                                eventos[i].dia, 
                                                eventos[i].mes, 
                                                eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int indiceParaTrocar;

    scanf("%d", &indiceParaTrocar);

    //Vericacao da existencia do indice
    if (indiceParaTrocar > *numEventos-1 || indiceParaTrocar < 0){
        printf("Indice invalido!\n");
    } else {
        scanf("%d %d %d", &eventos[indiceParaTrocar].dia,
                    &eventos[indiceParaTrocar].mes,
                    &eventos[indiceParaTrocar].ano);
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento eventoTemp;

    if (*indiceA > *numEventos - 1 || *indiceA < 0 || *indiceB > *numEventos - 1 || *indiceB < 0){
        printf("Indices invalidos!\n");

    } else {
        strcpy(eventoTemp.nome, eventos[*indiceA].nome);
        eventoTemp.dia = eventos[*indiceA].dia;
        eventoTemp.mes = eventos[*indiceA].mes;
        eventoTemp.ano = eventos[*indiceA].ano;

        strcpy(eventos[*indiceA].nome, eventos[*indiceB].nome);
        eventos[*indiceA].dia = eventos[*indiceB].dia;
        eventos[*indiceA].mes = eventos[*indiceB].mes;
        eventos[*indiceA].ano = eventos[*indiceB].ano;

        strcpy(eventos[*indiceB].nome, eventoTemp.nome);
        eventos[*indiceB].dia = eventoTemp.dia;
        eventos[*indiceB].mes = eventoTemp.mes;
        eventos[*indiceB].ano = eventoTemp.ano;

        printf("Eventos trocados com sucesso!\n");
    }
}
