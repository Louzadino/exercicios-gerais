#include <stdio.h>
#include "calculadora.h"

float soma(float a, float b){
    return a + b;
}

float subtracao(float a, float b){
    return a - b;
}

float multiplicacao(float a, float b){
    return a * b;
}

float divisao(float a, float b){
    if (b != 0){
        return a / b;
    }

    return 0.0;
}

float calculadora(float num1, float num2, char operacao){

    switch (operacao){
        case 'a':
            return Calcular(num1, num2, soma);
        case 's':
            return Calcular(num1, num2, subtracao);
        case 'm':
            return Calcular(num1, num2, multiplicacao);
        case 'd':
            return Calcular(num1, num2, divisao);
        default:
            break;
    }

    return 0;
}

void printResultado(float resultado, float num1, float num2, char operacao){

    char simboloOp;

    switch (operacao){
        case 'a':
            simboloOp = '+';
            break;
        case 's':
            simboloOp = '-';
            break;
        case 'm':
            simboloOp = 'x';
            break;
        case 'd':
            simboloOp = '/';
            break;
        default:
            break;
    }

    printf("%.2f %c %.2f = %.2f\n", num1, simboloOp, num2, resultado);
}

int main(){

    float num1, num2;
    char operacao;

    while (1){
        scanf(" %c", &operacao);  // Adicionado espaço antes do %c para consumir espaços em branco.

        if (operacao == 'f')
            break;

        scanf("%f %f", &num1, &num2);

        float resultado = calculadora(num1, num2, operacao);
        printResultado(resultado, num1, num2, operacao);
    }

    return 0;
}
