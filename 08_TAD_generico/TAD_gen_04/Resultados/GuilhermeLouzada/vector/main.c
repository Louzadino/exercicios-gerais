#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    char caracter;
    int numAgencia;
    tBanco* banco = CriaBanco();

    LeBanco(banco);

    while(1){

        scanf("%c", &caracter);

        if (caracter == 'A'){
            tAgencia* agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        } else if (caracter == 'C'){
            tConta* conta = CriaConta();
            LeConta(conta);

            scanf("%d", &numAgencia);
            InsereContaBanco(banco, numAgencia, conta);
        } else if (caracter == 'F'){
            break;
        }
    }

    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;
}
