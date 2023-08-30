#include <stdio.h>
#include <math.h>

typedef struct{
    float X, Y, raio;
} tCirculo;

float Distancia(tCirculo alvo, tCirculo disparo);

int main(){

    tCirculo alvo, disparo;

    scanf("%f %f %f\n", &alvo.X, &alvo.Y, &alvo.raio);
    scanf("%f %f %f", &disparo.X, &disparo.Y, &disparo.raio);

    if (Distancia(alvo, disparo) > (alvo.raio + disparo.raio)){
        printf("ERROU");
    } else {
        printf("ACERTOU");
    }

    return 0;
}

float Distancia(tCirculo alvo, tCirculo disparo){
    return sqrt(pow(disparo.X - alvo.X, 2) + pow(disparo.Y - alvo.Y, 2));
}
