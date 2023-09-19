#include <stdio.h>
#include "constantes.h"
#include "torneio.h"

int main(){
    
    tTorneio torneio;
    char tipo;
    int sair = 0;
    torneio.qtdFranquias = 0;

    while(scanf("%c", &tipo) == 1 && tipo != 'E'){

        if (tipo == 'F'){
            torneio.franquias[torneio.qtdFranquias] = LeFranquia();
            torneio.qtdFranquias++;
        } else if (tipo == 'P'){

        }
    }

    for (int i = 0; i < torneio.qtdFranquias; i++){
        printf("%s %s\n", torneio.franquias[i].nome, torneio.franquias[i].conferencia);
    }

    return 0;
}
