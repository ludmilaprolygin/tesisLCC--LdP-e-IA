#include <stdio.h>
#include <stdbool.h>

#define MAX_NODOS 100

bool esOrdenTopologico(int grafo[MAX_NODOS][MAX_NODOS],
                       int cantidadNodos,
                       int orden[]) {
    int posicion[MAX_NODOS];

    // posicion[nodo] = ubicación del nodo en el orden propuesto
    for (int i = 0; i < cantidadNodos; i++) {
        posicion[orden[i]] = i;
    }

    // Para cada arco u -> v, u debe aparecer antes que v
    for (int u = 0; u < cantidadNodos; u++) {
        for (int v = 0; v < cantidadNodos; v++) {
            if (grafo[u][v] == 1) {
                if (posicion[u] >= posicion[v]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n = 5;

    int grafo[MAX_NODOS][MAX_NODOS] = {0};

    grafo[0][2] = 1; // A -> C
    grafo[1][2] = 1; // B -> C
    grafo[1][3] = 1; // B -> D
    grafo[2][4] = 1; // C -> E
    grafo[3][4] = 1; // D -> E

    int orden1[] = {0, 1, 2, 3, 4}; // A B C D E
    int orden2[] = {2, 0, 1, 3, 4}; // C A B D E

    printf("%s\n", esOrdenTopologico(grafo, n, orden1) ? "true" : "false");
    printf("%s\n", esOrdenTopologico(grafo, n, orden2) ? "true" : "false");

    return 0;
}