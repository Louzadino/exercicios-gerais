#include <stdio.h>
#include "string_utils.h"

int string_length(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void string_copy(char *src, char *dest){
    int i = 0; 
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void string_upper(char *str){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32; //Converte para maiuscula na tabela ASCII
        } 
        
        i++;
    }
}

void string_lower(char *str){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32; //Converte para minuscula na tabela ASCII
        } 
        
        i++;
    }
}

void string_reverse(char *str){
    int length = string_length(str);
    int i = 0, j = length - 1;

    while (i < j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
