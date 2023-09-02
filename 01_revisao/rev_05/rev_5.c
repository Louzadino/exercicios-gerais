#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int xi, xj, xf, yf;
    char ordem[5];
    int Moveu;

} Personagem;

void ResolveLabirinto(int linhas, int colunas, int mapa[linhas][colunas], Personagem player);

int main(){

    int linhas, colunas;
    int l, c;
    Personagem player;

    //Leitura do mapa
    scanf("%d %d\n", &linhas, &colunas);

    int mapa[linhas][colunas];

    for (l = 1; l <= linhas; l++){
        for (c = 1; c <= colunas; c++){
            scanf("%d", &mapa[l][c]);
        }
    }

    //Leitura da posição inicial e final do personagem
    scanf("%d %d\n", &player.xi, &player.xj);
    scanf("%d %d\n", &player.xf, &player.yf);

    //Leitura da prioridade de movimento
    scanf("%c\n", player.ordem);

    //Resolução do labirinto
    ResolveLabirinto(linhas, colunas, mapa, player);

    return 0;
}

void ResolveLabirinto(int linhas, int colunas, int mapa[linhas][colunas], Personagem player){

    int i, j;
    int moveu = 0;

    while(player.xi != player.xf && player.xj != player.yf){
        for (i = 0; i < 5; i++){
            if (player.ordem[i] == 'C'){
                if (mapa[player.xi - 1][player.xj] != 1 && player.xi - 1 > 0){
                    player.xi -= 1;
                    moveu = 1;
                }
            } else if (player.ordem[i] == 'B'){
                if (mapa[player.xi + 1][player.xj] != 1 && player.xi + 1 <= linhas){
                    player.xi += 1;
                    moveu = 1;
                }               
            } else if (player.ordem[i] == 'E'){
                if (mapa[player.xi - 1][player.xj] != 1 && player.xj - 1 > 0){
                    player.xj -= 1;
                    moveu = 1;
                }               
            } else if (player.ordem[i] == 'D'){
                if (mapa[player.xi + 1][player.xj] != 1 && player.xj + 1 <= colunas){
                    player.xj += 1;
                    moveu = 1;
                }                  
            }

            if (moveu)
                break;
        }

        printf("(%d,%d)", player.xi, player.xj);
    }
}
