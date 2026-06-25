#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    VALUE_INT,
    VALUE_FLOAT,
    VALUE_CHAR,
    VALUE_STRING
} ValueType;

typedef struct {
    ValueType type;
    union {
        int i;
        float f;
        char c;
        const char *s;
    } data;
} Value;

static double value_to_double(const Value *value) {
    switch (value->type) {
        case VALUE_INT:
            return (double)value->data.i;

        case VALUE_FLOAT:
            return (double)value->data.f;

        case VALUE_CHAR:
            return (double)(value->data.c - '0');

        case VALUE_STRING:
            return strtod(value->data.s, NULL);

        default:
            return 0.0;
    }
}

double promedio_mayores_que_umbral(const Value values[], size_t count, double umbral) {
    if (values == NULL || count == 0) {
        return 0.0;
    }

    double suma = 0.0;
    size_t cantidad = 0;

    for (size_t i = 0; i < count; ++i) {
        double numero = value_to_double(&values[i]);
        if (numero > umbral) {
            suma += numero;
            ++cantidad;
        }
    }

    return (cantidad == 0) ? 0.0 : suma / (double)cantidad;
}

#include <stdio.h>

int main(void) {
    Value values[] = {
        { VALUE_INT,    .data.i = 1 },
        { VALUE_FLOAT,  .data.f = 30.0f },
        { VALUE_CHAR,   .data.c = '2' },
        { VALUE_STRING, .data.s = "40" },
        { VALUE_STRING, .data.s = "50" }
    };

    double result = promedio_mayores_que_umbral(values, sizeof(values) / sizeof(values[0]), 25.0);

    printf("Promedio: %.6f\n", result);
    return 0;
}