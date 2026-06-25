#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función que calcula el promedio de los valores mayores a un umbral
double promedioMayores(char *arreglo, int tamArreglo, float umbral) {
    double sum = 0.0;
    int cuenta = 0;

    for (int i = 0; i < tamArreglo; i++) {
        // Convertimos el elemento actual a un double
        char *p = arreglo + i;
        double valor = strtod(p, NULL);

        if (valor > umbral) {
            sum += valor;
            cuenta++;
        }
    }

    if (cuenta == 0) {
        return 0.0; // No hay valores mayores al umbral
    } else {
        return sum / cuenta;
    }
}

int main() {
    char *arreglo = "10,20,30,40,50";
    int tamArreglo = strlen(arreglo);
    float umbral = 25.0;

    printf("Promedio de los valores mayores a %f: %.2f\n", umbral, promedioMayores(arreglo, tamArreglo, umbral));

    return 0;
}