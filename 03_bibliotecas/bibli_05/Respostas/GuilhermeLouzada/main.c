#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

int main(){
    char str[100];
    int option;

    fgets(str, sizeof(str), stdin);

    // Remove a quebra de linha gerada pelo fgets
    int len = string_length(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    while(1){
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");

        scanf("%d\n", &option);

        switch (option){
            case 1:
                printf("Tamanho da string: %d\n", len);
                break;

            case 2:
                char dest[100];
                string_copy(str, dest);
                printf("String copiada: %s\n", dest);
                break;

            case 3:
                string_upper(str);
                printf("String convertida para maiusculas: %s\n", str);
                break;

            case 4:
                string_lower(str);
                printf("String convertida para minusculas: %s\n", str);
                break;
            
            case 5:
                string_reverse(str);
                printf("String invertida: \n");
                printf("%s\n", str);
                break;
            
            case 6:
                exit(1);
            
            default:
                break;
        }

        printf("\n");
    }

    return 0;
}
