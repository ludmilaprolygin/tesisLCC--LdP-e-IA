#include <stdio.h>
#include <stddef.h>

double calcular_promedio_mayores_a_umbral(const double precios[],
                                          size_t cantidad_precios,
                                          double umbral)
{
    double suma = 0.0;
    size_t cantidad = 0;

    for (size_t i = 0; i < cantidad_precios; i++) {
        if (precios[i] > umbral) {
            suma += precios[i];
            cantidad++;
        }
    }

    return (cantidad == 0) ? 0.0 : suma / cantidad;
}

int main(void)
{
    const double precios[] = {10.0, 20.0, 30.0, 40.0, 50.0};

    double promedio = calcular_promedio_mayores_a_umbral(
        precios,
        sizeof(precios) / sizeof(precios[0]),
        25.0
    );

    printf("%.2f\n", promedio); /* 40.00 */

    return 0;
}