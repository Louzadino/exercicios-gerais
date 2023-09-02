#include <stdio.h>

void GeraTrianguloFloyd(int n);

int main(){

    int n;

    scanf("%d", &n);

    GeraTrianguloFloyd(n);

    return 0;
}

void GeraTrianguloFloyd(int n){

    int i, j, num = 1;

    for (i = 1; i <= n; i++){
        for (j = 1; j <= i; j++){
            printf("%d ", num);
            num++;
        } 
        printf("\n");
    }
}
