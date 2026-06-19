#include <stdio.h>

double calculate_average_above_threshold(int prices[], int size, int threshold) {
    if (size == 0) {
        return 0;
    }

    int count = 0;
    double sum = 0;

    for (int i = 0; i < size; ++i) {
        if (prices[i] > threshold) {
            sum += prices[i];
            ++count;
        }
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}

int main() {
    int prices[] = {10, 20, 30, 40, 50};
    int size = sizeof(prices) / sizeof(prices[0]);
    int threshold = 20;

    double average = calculate_average_above_threshold(prices, size, threshold);

    printf("El precio promedio de los productos mayores al umbral es: %.2f\n", average);

    return 0;
}