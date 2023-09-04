#include <stdio.h>
#include "temperature_conversor.h"

int main(){
    float temp;
    char scale1, scale2;

    scanf("%f %c %c", &temp, &scale1, &scale2);

    if (scale1 == 'c'&& scale2 == 'k'){ //Celcius para kelvin
        printf("Temperature: %.2fK", convert_celsius_to_kelvin(temp));
    } else if (scale1 == 'c' && scale2 == 'f'){
        printf("Temperature: %.2fFº", convert_celsius_to_fahrenheit(temp));
    } else if (scale1 == 'k' && scale2 == 'c'){
        printf("Temperature: %.2fCº", convert_kelvin_to_celsius(temp));
    } else if (scale1 == 'k' && scale2 == 'f'){
        printf("Temperature: %.2fFº", convert_kelvin_to_fahrenheit(temp));
    } else if (scale1 == 'f' && scale2 == 'c'){
        printf("Temperature: %.2fCº", convert_fahrenheit_to_celsius(temp));
    } else if (scale1 == 'f' && scale2 == 'k'){
        printf("Temperature: %.2fK", convert_fahrenheit_to_kelvin(temp));
    }

    return 0;
}
