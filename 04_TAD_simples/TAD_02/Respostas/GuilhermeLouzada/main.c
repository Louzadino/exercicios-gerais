#include <stdio.h>
#include "eleicao.h"

int main(){
    tEleicao eleicao;

    eleicao = InicializaEleicao(eleicao);
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);

    return 0;
}
