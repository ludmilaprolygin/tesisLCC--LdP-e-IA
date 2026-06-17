#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para calcular el precio final con descuento porcentual
double calculatePrice(double price, char* discount) {
    // Convertimos el descuento a un valor numérico (como un número de porcentaje)
    int disc_percent = atoi(strrchr(discount, '%') + 1);

    // Calculamos el descuento como un porcentaje del precio original
    double discount_amount = price * (disc_percent / 100.0);

    // Calcular el precio final aplicando el descuento
    double final_price = price - discount_amount;

    return final_price;
}

int main() {
    double price = 50; // Precio original del producto
    char* discount = "10%"; // Descuento como cadena de texto

    // Llamada a la función para calcular el precio final
    double final_price = calculatePrice(price, discount);

    printf("Precio original: $%.2f\n", price);
    printf("Descuento: %s\n", discount);
    printf("Precio final: $%.2f\n", final_price);

    return 0;
}