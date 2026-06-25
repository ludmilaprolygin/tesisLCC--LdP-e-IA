#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculate_average(char* numbers[], int size) {
    float total = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        char* value_str = numbers[i];

        if (*value_str == '\0') continue; // Salta valores vacíos

        // Intenta convertir a int
        char *end;
        long int_value = strtol(value_str, &end, 10);
        if (*end == '\0') {
            total += (float)int_value;
            count++;
            continue;
        }

        // Intenta convertir a float
        float float_value = strtof(value_str, NULL);
        if (!isnan(float_value)) {
            total += float_value;
            count++;
            continue;
        }

        printf("Error: No se puede convertir el valor '%s' a un número.\n", value_str);
    }

    if (count == 0) {
        printf("No se encontraron valores numéricos válidos.\n");
        return 0;
    }

    return total / count;
}

int main() {
    char* numbers[] = {1, "20", 30.0, 40, "50"};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    float average = calculate_average(numbers, size);

    printf("El promedio de los valores numéricos es: %f\n", average);

    return 0;
}