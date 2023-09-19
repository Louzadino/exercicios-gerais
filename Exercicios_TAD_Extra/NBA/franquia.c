#include "franquia.h"
#include <stdio.h>

tFranquia LeFranquia(){
   
    tFranquia franquia;
    scanf("%s", franquia.nome);
    scanf("%s", franquia.conferencia);

    return franquia;
}
