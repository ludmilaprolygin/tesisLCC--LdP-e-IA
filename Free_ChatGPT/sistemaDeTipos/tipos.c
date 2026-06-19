#include <stddef.h>

double promedio_mayores_que(const double precios[], size_t n, double umbral) {
    double suma = 0.0;
    size_t cantidad = 0;

    for (size_t i = 0; i < n; i++) {
        if (precios[i] > umbral) {
            suma += precios[i];
            cantidad++;
        }
    }

    return (cantidad == 0) ? 0.0 : suma / cantidad;
}

#include <stdio.h>

int main(void) {
    double precios[] = {10.0, 20.0, 30.0, 40.0, 50.0};

    printf("%.2f\n", promedio_mayores_que(precios, 5, 25.0)); // 35.00
    printf("%.2f\n", promedio_mayores_que(precios, 5, 50.0)); // 0.00

    return 0;
}