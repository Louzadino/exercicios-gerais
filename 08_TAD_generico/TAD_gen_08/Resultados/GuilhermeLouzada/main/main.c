#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "movel.h"
#include "vector.h"

int main(){

    Fila* fila = FilaConstruct();
    int qtdOperacoes;
    char operacao[10];

    scanf("%d", &qtdOperacoes);

    for (int i = 0; i < qtdOperacoes; i++){
        scanf("%s", operacao);

        if (strcmp(operacao, "ENTRADA") == 0){
            tMovel* novoMovel = LeMovel();
            FilaPush(fila, novoMovel);
        } else if (strcmp(operacao, "PRODUZIR") == 0){
            tMovel* proximoMovel = (tMovel*) FilaPop(fila);
            ImprimeMovel(proximoMovel);
            DestroiMovel(proximoMovel);
        }
    }

    FilaDestroy(fila, (void(*)(DataType)) DestroiMovel);

    return 0;
}
