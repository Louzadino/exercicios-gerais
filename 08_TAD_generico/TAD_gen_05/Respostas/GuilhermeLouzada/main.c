#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"

int main(){

    int numElem;
    int prioridade;
    char prefixo;

    scanf("%d", &numElem);
    tAgendaTarefas* agenda = CriaAgendaDeTarefas(numElem);

    for (int i = 0; i < numElem; i++){
        char msg[50];
        float n1, n2;

        scanf("%d %c", &prioridade, &prefixo);

        if (prefixo == 'I'){
            scanf(" %[^\n]\n", msg);
            tImpr* tarefaImprime = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(agenda, prioridade, tarefaImprime, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        } else if (prefixo == 'S'){
            scanf("%f %f", &n1, &n2);
            tSoma* tarefaSoma = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, tarefaSoma, ExecutaTarefaSoma, DestroiTarefaSoma);
        } else if (prefixo == 'M'){
            scanf("%f %f", &n1, &n2);
            tMult* tarefaMult = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, tarefaMult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}
