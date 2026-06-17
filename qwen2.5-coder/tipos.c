#include <stdio.h>
#include <string.h>

// Función para calcular el precio final con un descuento porcentual
float calcularPrecioFinal(float precio, const char* descuento) {
    float porcentajeDescuento = 0.0;
    
    // Convertir la cadena de texto a número (suponiendo es decimal)
    sscanf(descuento, "%f", &porcentajeDescuento);
    
    // Asegurarse que el descuento esté entre 0 y 100%
    if (porcentajeDescuento < 0.0) porcentajeDescuento = 0.0;
    else if (porcentajeDescuento > 100.0) porcentajeDescuento = 100.0;
    
    // Calcular el descuento y el precio final
    float descuentoValor = precio * (porcentajeDescuento / 100.0);
    float precioFinal = precio - descuentoValor;
    
    return precioFinal;
}

int main() {
    // Datos de ejemplo
    float precioOriginal = 50.0;
    const char* descuentoPorcentaje = "10";
    
    // Calcular el precio final
    float precioFinal = calcularPrecioFinal(precioOriginal, descuentoPorcentaje);
    
    // Mostrar los resultados
    printf("Precio original: %.2f\n", precioOriginal);
    printf("Descuento (%s%%): %.2f\n", descuentoPorcentaje, precioOriginal * (atoi(descuentoPorcentaje) / 100.0));
    printf("Precio final: %.2f\n", precioFinal);
    
    return 0;
}