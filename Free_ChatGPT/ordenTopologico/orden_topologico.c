#include <stdio.h>
#include <stdbool.h>

#define MAX 100

/*
    Verifica si el arreglo "orden"
    es un orden topológico válido.
*/
bool esOrdenTopologico(
    int grafo[MAX][MAX],
    int vertices,
    int orden[]
) {
    int posicion[MAX];

    // Guardar posición de cada vértice
    for (int i = 0; i < vertices; i++) {
        posicion[orden[i]] = i;
    }

    // Verificar todas las aristas u -> v
    for (int u = 0; u < vertices; u++) {

        for (int v = 0; v < vertices; v++) {

            if (grafo[u][v]) {

                // u debe aparecer antes que v
                if (posicion[u] >= posicion[v]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {

    int vertices = 4;

    /*
        Grafo:

        0 -> 1
        0 -> 2
        1 -> 3
        2 -> 3
    */

    int grafo[MAX][MAX] = {0};

    grafo[0][1] = 1;
    grafo[0][2] = 1;
    grafo[1][3] = 1;
    grafo[2][3] = 1;

    int ordenValido[] = {0,1,2,3};
    int ordenInvalido[] = {1,0,2,3};

    if (esOrdenTopologico(grafo, vertices, ordenValido)) {
        printf("El orden es válido\n");
    } else {
        printf("El orden NO es válido\n");
    }

    if (esOrdenTopologico(grafo, vertices, ordenInvalido)) {
        printf("El orden es válido\n");
    } else {
        printf("El orden NO es válido\n");
    }

    return 0;
}