#ifndef _FRANQUIA_H
#define _FRANQUIA_H

#include "constantes.h"

typedef struct{
    char nome[MAX_NOME_FRANQUIA];
    char conferencia[MAX_NOME_CONFERENCIA]
    int vitorias;
    int derrotas;

} tFranquia;

tFranquia LeFranquia();

#endif
