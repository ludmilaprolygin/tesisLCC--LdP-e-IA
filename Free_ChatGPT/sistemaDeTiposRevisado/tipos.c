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
            return atof((char[]){e.valor.c, '\0'});

        case STRING:
            return atof(e.valor.s);
    }

    return 0.0;
}

double promedioMayores(Elemento precios[], int n, double umbral) {
    double suma = 0.0;
    int cantidad = 0;

    for (int i = 0; i < n; i++) {
        double valor = convertirANumero(precios[i]);

        if (valor > umbral) {
            suma += valor;
            cantidad++;
        }
    }

    return (cantidad == 0) ? 0.0 : suma / cantidad;
}

int main() {
    Elemento precios[] = {
        {INT,    {.i = 10}},
        {FLOAT,  {.f = 30.0f}},
        {CHAR,   {.c = '2'}},
        {STRING, {.s = "40"}},
        {STRING, {.s = "50"}}
    };

    int n = sizeof(precios) / sizeof(precios[0]);

    printf("%.2f\n", promedioMayores(precios, n, 25));

    return 0;
}