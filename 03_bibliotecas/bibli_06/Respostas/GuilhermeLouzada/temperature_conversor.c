#include <stdio.h>
#include <math.h>
#include "temperature_conversor.h"

float convert_celsius_to_kelvin(float temperature){
    return (temperature + 273.15);
}

float convert_celsius_to_fahrenheit(float temperature){
    return ((temperature * (9.0 / 5.0)) + 32);
}

float convert_kelvin_to_celsius(float temperature){
    return (temperature - 273.15);
}

float convert_kelvin_to_fahrenheit(float temperature){
    return ((temperature - 273.15) * (9.0/5.0) + 32);
}

float convert_fahrenheit_to_celsius(float temperature){
    return ((temperature - 32) * (5.0/9.0)); 
}

float convert_fahrenheit_to_kelvin(float temperature){
    return ((temperature - 32) * (5.0/9.0) + 273.15);
}

float convert_temperature(float temperature, float convert_func(float temperature)){
    
}