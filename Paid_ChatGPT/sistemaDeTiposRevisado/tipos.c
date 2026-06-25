#include <stdio.h>
#include <stdlib.h>

typedef enum {
    INT,
    FLOAT,
    CHAR,
    STRING
} Tipo;

typedef struct {
    Tipo tipo;
    union {
        int i;
        float f;
        char c;
        char *s;
    } valor;
} Elemento;

double convertirANumero(Elemento e) {
    switch (e.tipo) {
        case INT:
            return (double)e.valor.i;

        case FLOAT:
            return (double)e.valor.f;

        case CHAR:
            return (double)(e.valor.c - '0');

        case STRING:
            return atof(e.valor.s);

        default:
            return 0;
    }
}

double promedioMayoresAUmbral(Elemento arreglo[], int n, Elemento umbral) {
    double suma = 0.0;
    int cantidad = 0;

    double umbralNum = convertirANumero(umbral);

    for (int i = 0; i < n; i++) {
        double valor = convertirANumero(arreglo[i]);

        if (valor > umbralNum) {
            suma += valor;
            cantidad++;
        }
    }

    return (cantidad == 0) ? 0 : suma / cantidad;
}

int main() {
    Elemento arreglo[] = {
        {CHAR,   {.c = '1'}},
        {FLOAT,  {.f = 2.5}},
        {INT,    {.i = 30}},
        {STRING, {.s = "40"}},
        {FLOAT,  {.f = 50.0}}
    };

    Elemento umbral = {INT, {.i = 25}};

    double promedio = promedioMayoresAUmbral(arreglo, 5, umbral);

    printf("Promedio: %.2f\n", promedio);

    return 0;
}