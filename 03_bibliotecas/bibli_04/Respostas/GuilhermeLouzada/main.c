#include "data.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
} tData;

int main(){
    tData data;

    //Leitura da data
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

    //Verificação da validade da data
    if (!verificaDataValida(data.dia, data.mes, data.ano)){
        printf("A data informada eh invalida");
        exit(1);
    }

    //Data informada pelo usuario
    printf("Data informada: ");
    imprimeDataExtenso(data.dia, data.mes, data.ano);

    //Informa ao usuario se o ano informado eh bissexto ou nao
    if (verificaBissexto(data.ano)){
        printf("O ano informado eh bissexto\n");
    } else {
        printf("O ano informado nao eh bissexto\n");
    }

    //Informa a quantidade de dias do mes inserido na data
    int qtd_Dias_Mes = numeroDiasMes(data.mes, data.ano);
    printf("O mes informado possui %d dias\n", qtd_Dias_Mes);

    //Informa a data seguinte
    printf("A data seguinte eh: ");
    imprimeProximaData(data.dia, data.mes, data.ano);

    return 0;
}
