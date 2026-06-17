#include <stdio.h>
#include <stdlib.h>

double precio_final(double precio, const char *descuento_texto) {
	double descuento = strtod(descuento_texto, NULL);
	return precio - (precio * descuento / 100.0);
}

int main(void) {
	double precio_final_resultado = precio_final(50, "10");
	printf("%.2f\n", precio_final_resultado);
	return 0;
}
