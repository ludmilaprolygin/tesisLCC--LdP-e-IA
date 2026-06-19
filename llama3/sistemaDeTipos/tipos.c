#include <stdio.h>
#include <stdlib.h>

double calcularPrecioPromedioMayorUMbral(double* precios, int tamano, double umbral) {
    if (tamano == 0) return 0; // lista vacía

    double suma = 0;
    int cuenta = 0;

    for (int i = 0; i < tamano; i++) {
        if (precios[i] > umbral) {
            suma += precios[i];
            cuenta++;
        }
    }

    return cuenta == 0 ? 0 : suma / cuenta;
}

int main() {
    double precios[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    int tamano = sizeof(precios) / sizeof(precios[0]);
    double umbral = 20;

    printf("Precio promedio mayor al umbral: %.2f\n", calcularPrecioPromedioMayorUMbral(precios, tamano, umbral));

    return 0;
}