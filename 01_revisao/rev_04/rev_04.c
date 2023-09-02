#include <stdio.h>

void ConverteDecParaOct(int numDecimal); //Converte um número inteiro decimal para octal

int main(){
    int numDecimal;

    scanf("%d", &numDecimal);

    ConverteDecParaOct(numDecimal);

    return 0;
}

void ConverteDecParaOct(int numDecimal){
    int numOctal[10];
    int i = 0;

    while(numDecimal > 0){
        numOctal[i] = numDecimal % 8;
        numDecimal /= 8;
        i++;
    }

    int j;
    for (j = i - 1; j >= 0; j--){
        printf("%d", numOctal[j]);
    }
}
