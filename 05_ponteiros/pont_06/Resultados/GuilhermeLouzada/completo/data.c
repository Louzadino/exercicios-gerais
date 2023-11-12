#include "data.h"
#include <stdio.h>

void InicializaDataParam( int dia, int mes, int ano, tData *data){

    int qtdDiasMes = InformaQtdDiasNoMes(data);

    if (data->dia < 1){
        data->dia = 1;
    }

    if (data->mes < 1){
        data->mes = 1;
    }

    if (data->mes > 12){
        data->mes = 12;
    }

    if (data->ano < 1){
        data->ano = 1;
    }

    if (data->dia > qtdDiasMes){
        data->dia = qtdDiasMes;
    }
}

void LeData( tData *data ){

    scanf("%d %d %d", &data->dia, &data->mes, &data->ano);
    InicializaDataParam(data->dia, data->mes, data->ano, data);
}

void ImprimeData( tData *data ){

    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){

    if ((data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0)) {
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes( tData *data ){

    switch (data->mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (EhBissexto(data)){
            return 29;
        } else {
            return 28;
        }
    default:
        return 31;
        break;
    }
}

void AvancaParaDiaSeguinte( tData *data ){

    int qtdDiasMes = InformaQtdDiasNoMes(data);

    data->dia++;
    if (data->dia > qtdDiasMes){
        data->dia = 1;
        data->mes++;

        if (data->mes > 12){
            data->mes = 1;
            data->ano++;
        }
    }
}

int EhIgual( tData *data1, tData *data2 ){

    return (data1->dia == data2->dia && 
            data1->mes == data2->mes && 
            data1->ano == data2->ano);
}
