#include "utils.h"
#include <stdio.h>

void LeNumeros(int *array, int tamanho){

    for (int i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){

    *maior = array[0]; //Maior é o primeiro
    *menor = array[0]; //Menor é o primeio
    *media = 0;

    for (int i = 0; i < tamanho; i++){
        if (array[i] > *maior){
            *maior = array[i];
        }

        if (array[i] < *menor){
            *menor = array[i];
        }

        *media = *media + array[i];
    }

    *media = *media / tamanho;
}
