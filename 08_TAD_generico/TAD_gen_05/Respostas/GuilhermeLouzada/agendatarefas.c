#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int prioridade;
    int tarefaOcupada;
    void* tarefa;
    void (*executa)(void*);
    void (*destroi)(void*);
} tTarefa;


struct agendatarefas{
    tTarefa** tarefas;
    int numElem;
};


tAgendaTarefas* CriaAgendaDeTarefas(int numElem){

    tAgendaTarefas* agenda = (tAgendaTarefas*) calloc(1, sizeof(tAgendaTarefas));

    if (agenda == NULL){
        printf("ERRO: falha na alocacao da agenda");
        exit(0);
    }

    agenda->tarefas = (tTarefa**) calloc(1, sizeof(tTarefa*) * numElem);

    if (agenda->tarefas == NULL){
        printf("ERRO: falha na alocacao das tarefas");
        exit(0);
    }

    for (int i = 0; i < numElem; i++){
        agenda->tarefas[i] = (tTarefa*) calloc(1, sizeof(tTarefa));

        if (agenda->tarefas[i] == NULL){
            printf("ERRO: falha na alocacao da tarefa");
            exit(0);
        }
    }

    agenda->numElem = numElem;
    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    if (tar != NULL) {
        for (int i = 0; i < tar->numElem; i++) {
            if (tar->tarefas[i] != NULL) {
                if (tar->tarefas[i]->destroi != NULL) {
                    tar->tarefas[i]->destroi(tar->tarefas[i]->tarefa);
                }
                free(tar->tarefas[i]);
            }
        }
        free(tar->tarefas);
        free(tar);
    }
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*)){

    for (int i = 0; i < tar->numElem; i++){
        if (!tar->tarefas[i]->tarefaOcupada){
            tar->tarefas[i]->destroi = destroi;
            tar->tarefas[i]->executa = executa;
            tar->tarefas[i]->prioridade = prioridade;
            tar->tarefas[i]->tarefa = tarefa;
            tar->tarefas[i]->tarefaOcupada = 1;
            return;
        }
    }
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){

    // Ordenacao de acordo com a prioridade
    for (int i = 0; i < tar->numElem; i++){
        for (int j = i + 1; i < tar->numElem; j++){
            
        }
    }

    // Execucao das tarefas
    for (int i = 0; i < tar->numElem; i++){
        if (tar->tarefas[i]->executa != NULL)
            tar->tarefas[i]->executa(tar->tarefas[i]->tarefa);
    }
}
