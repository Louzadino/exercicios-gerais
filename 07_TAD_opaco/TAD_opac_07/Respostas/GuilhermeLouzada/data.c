#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct Data{
    int dia, mes, ano;
};

tData* CriaData(){

    tData* data = (tData*) malloc(sizeof(tData));

    data->dia = -1;
    data->mes = -1;
    data->ano = -1;

    if (data == NULL){
        printf("ERRO: falha na alocacao da data");
        return 0;
    }

    return data;
}

void LeData(tData* data){

    scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);

    if (data == NULL){
        printf("ERRO: falha na leitura da data");
        exit(0);
    }
}

void LiberaData(tData* data){

    if (data != NULL){
        free(data);
    }
}

int VerificaDataValida(tData* data){

    if (data->dia < 1 || data->mes < 1 || data->mes > 12 || data->ano < 1){
        return 0;
    }

    if (data->dia > NumeroDiasMes(data)){
        return 0;
    }

    return 1;
}

void ImprimeMesExtenso(tData* data){

    switch (data->mes){
        case 1:
            printf("Janeiro");
            break;
        case 2: 
            printf("Fevereiro");
            break;
        case 3: 
            printf("Marco");
            break;
        case 4: 
            printf("Abril");
            break;
        case 5: 
            printf("Maio");
            break;
        case 6: 
            printf("Junho");
            break;
        case 7: 
            printf("Julho");
            break;
        case 8: 
            printf("Agosto");
            break;
        case 9: 
            printf("Setembro");
            break;
        case 10: 
            printf("Outubro");
            break;
        case 11: 
            printf("Novembro");
            break;
        case 12: 
            printf("Dezembro");
            break;
        default:
            break;
    }
}

void ImprimeDataExtenso(tData* data){

    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

int VerificaBissexto(tData* data){

    if ((data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0)) {
        return 1;
    }
    return 0;
}

int NumeroDiasMes(tData* data){

    switch (data->mes){
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if (VerificaBissexto(data))
                return 29;
            else
                return 28;
        
        default:
            return 31;
            break;
    }

    return 0;
}

int ComparaData(tData* data1, tData* data2){

    if (data1->ano > data2->ano){
        return 1;
    } else if (data1 < data2->ano){
        return -1;
    } else {

        if (data1->mes > data2->mes){
            return 1;
        } else if (data1->mes < data2->mes){
            return -1;
        } else {

            if (data1->dia > data2->dia){
                return 1;
            } else if (data1 < data2->dia){
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int CalculaDiasAteMes(tData* data){

    
}