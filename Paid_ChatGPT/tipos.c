#include <stdio.h>

float calcularPrecioFinal(float precio, float descuento) {
    return precio * (1.0f - descuento / 100.0f);
}

int main() {
    float precioFinal = calcularPrecioFinal(50, atof("10"));

    printf("Precio final: %.2f\n", precioFinal);

    return 0;
}