#include "data.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
} tData;

int main(){
    tData data1, data2;

    //Leitura das datas
    scanf("%d/%d/%d\n", &data1.dia, &data1.mes, &data1.ano);
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

    //Verificação da validade das datas
    if (!verificaDataValida(data1.dia, data1.mes, data1.ano) || 
    !verificaDataValida(data2.dia, data2.mes, data2.ano)) {
        printf("A primeira e/ou segunda data(s) invalida(s)");
        exit(1);
    }

    //Impressao em extenso das datas
    printf("Primeira data: ");
    imprimeDataExtenso(data1.dia, data1.mes, data1.ano);

    printf("Segunda data: ");
    imprimeDataExtenso(data2.dia, data2.mes, data2.ano);

    //Compara as datas
    if (comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) == 1){
        printf("A primeira data eh mais antiga\n");
    } else if (comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) == -1){
        printf("A segunda data eh mais antiga\n");
    } else {
        printf("As datas sao iguais\n");
    }

    //Imprime a diferenca em dias entra as datas
    printf("A diferenca em dias entre as datas eh: %02d dias", calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano));
    return 0;
}
