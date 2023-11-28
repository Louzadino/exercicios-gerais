#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int prioridade;
    void* tarefa;
    void (*executa)(void*);
    void (*destroi)(void*);
} tTarefa;


struct agendatarefas{
    tTarefa** tarefas;
    int numElem;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem){

    tAgendaTarefas* agenda = (tAgendaTarefas*) malloc(sizeof(tAgendaTarefas));

    if (agenda == NULL){
        printf("ERRO: falha na alocacao da agenda");
        exit(0);
    }

    agenda->tarefas = (tTarefa**) malloc(sizeof(tTarefa*) * numElem);
    if (agenda->tarefas == NULL){
        printf("ERRO: falha na alocacao das tarefas");
        exit(0);
    }

    agenda->numElem = numElem;
    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar){

    if (tar != NULL){
        if (tar->tarefas != NULL){
            for (int i = 0; i < tar->numElem; i++){
                if (tar->tarefas[i] != NULL){
                    tar->tarefas[i]->destroi(tar->tarefas[i]->tarefa);
                    free(tar->tarefas[i]);
                }
            }
            free(tar->tarefas);
        }
        free(tar);
    }
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*)){

    tTarefa* novaTarefa = (tTarefa*) calloc(1, sizeof(tTarefa));

    novaTarefa->destroi = destroi;
    novaTarefa->executa = executa;
    novaTarefa->prioridade = prioridade;
    novaTarefa->tarefa = tarefa;

    for (int i = 0; )

}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){

}