#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){

    if (dia < 1 || mes < 1 || ano < 1 || mes > 12){
        return 0;
    }

    int diasNoMes = numeroDiasMes(mes, ano);

    return (dia <= diasNoMes);
}

int numeroDiasMes(int mes, int ano) {

    switch (mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return (verificaBissexto(ano) ? 29 : 28);
        default:
            return 31;
    }
}

int verificaBissexto(int ano) {

    return (ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0));
}

void imprimeDataExtenso(int dia, int mes, int ano){

    printf("%02d de ", dia);

    switch (mes){
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

    printf(" de %04d\n", ano);
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {

    if (ano1 > ano2) {
        return -1;
    } else if (ano1 < ano2) {
        return 1;
    } else { // Os anos são iguais, verifique os meses
        if (mes1 > mes2) {
            return -1;
        } else if (mes1 < mes2) {
            return 1;
        } else { // Os anos e meses são iguais, verifique os dias
            if (dia1 > dia2) {
                return -1;
            } else if (dia1 < dia2) {
                return 1;
            } else { // As datas são iguais
                return 0;
            }
        }
    }
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    int totalDias1 = ano1 * 365 + calculaDiasAteMes(mes1, ano1) + dia1;
    int totalDias2 = ano2 * 365 + calculaDiasAteMes(mes2, ano2) + dia2;

    return totalDias2 - totalDias1;
}

int calculaDiasAteMes(int mes, int ano){

    int dias = 0;
    int i;
    for (i = 1; i < mes; i++){
        dias += numeroDiasMes(i, ano);
    }
    return dias;
}
