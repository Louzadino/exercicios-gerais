#include <stdio.h>
#include "tadgen.h"

int main(){

    int tam, tipo;
    tGeneric* generico;

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d %d", &tipo, &tam);

    generico = CriaGenerico(tipo, tam);
    LeGenerico(generico);
    ImprimeGenerico(generico);

    DestroiGenerico(generico);
    return 0;
}
