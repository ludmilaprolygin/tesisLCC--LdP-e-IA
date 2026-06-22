#include <stddef.h>

double promedio_mayores_que_umbral(const double *precios, size_t cantidad, double umbral) {
    if (precios == NULL || cantidad == 0) {
        return 0.0;
    }

    double suma = 0.0;
    size_t conteo = 0;

    for (size_t i = 0; i < cantidad; ++i) {
        if (precios[i] > umbral) {
            suma += precios[i];
            ++conteo;
        }
    }

    return conteo == 0 ? 0.0 : suma / (double)conteo;
}

int main(void) {
    double precios[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    size_t cantidad = sizeof(precios) / sizeof(precios[0]);
    double umbral = 25.0;

    double resultado = promedio_mayores_que_umbral(precios, cantidad, umbral);

    printf("Promedio de precios mayores a %.2f: %.2f\n", umbral, resultado);

    return 0;
}