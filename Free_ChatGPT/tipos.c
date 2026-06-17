#include <stdio.h>
#include <stdlib.h>

double precioFinal(double precio, const char *descuento) {
    double porcentaje = atof(descuento);
    return precio * (1 - porcentaje / 100.0);
}

int main() {
    double resultado = precioFinal(50, "10");
    printf("%.2f\n", resultado);
    return 0;
}