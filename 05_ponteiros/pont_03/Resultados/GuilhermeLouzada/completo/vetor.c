#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

// Função para encontrar e trocar o menor valor no vetor
void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar) {
    int menor = *paraTrocar; 

    for (int i = 0; i < tam; i++) {
        if (vet[i] < menor) {
            menor = vet[i];
            vet[i] = *paraTrocar;
            *paraTrocar = menor;
        }
    }
}

void ImprimeDadosDoVetor(int *n, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d", n[i]);
        if (i < tam - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void OrdeneCrescente(int *vet, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        TrocaSeAcharMenor(&vet[i], tam - i, &vet[i]); 
    }
}
