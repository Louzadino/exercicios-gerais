#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int soma(int a, int b){
    return a + b;
}

int multiplicacao(int a, int b){

    return a * b;
}

int main(){

    Vetor *vetor = (Vetor*) calloc(1, sizeof(Vetor));
    int resultado;

    LeVetor(vetor);

    resultado = AplicarOperacaoVetor(vetor, soma);
    printf("Soma: %d\n", resultado);

    resultado = AplicarOperacaoVetor(vetor, multiplicacao);
    printf("Produto: %d", resultado);

    free(vetor);

    return 0;
}
