#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n){
    int inicio, fim;

    scanf("%d %d", &inicio, &fim);

    *m = inicio;
    *n = fim;
}

int EhPrimo(int n){
    int qtdDivisoes = 0;

    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            qtdDivisoes++;
        }
    }

    if (qtdDivisoes == 2){
        return 1;
    }

    return 0;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    int primeiroPrimo = 1;

    for (int i = m; i <= n; i++){
        if (EhPrimo(i)){
            if (primeiroPrimo){
                *maior = i;
                *menor = i;
                primeiroPrimo = 0;
            } else {
                if (i > *maior){
                    *maior = i;
                } 
            
                if (i < *menor){
                    *menor = i;
                }
            }
        }
    }
}
