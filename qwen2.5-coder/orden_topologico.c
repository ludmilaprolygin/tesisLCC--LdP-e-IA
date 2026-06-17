#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Grafo representado como una matriz de adyacencia
int graph[MAX_NODES][MAX_NODES];
int indegree[MAX_NODES];

void addEdge(int u, int v) {
    // Añadir una arista del nodo u al nodo v
    graph[u][v] = 1;
    indegree[v]++;
}

// Función para realizar el orden topológico usando el algoritmo de Kahn
void topologicalSort() {
    int count = 0; // Contador de nodos procesados
    int queue[MAX_NODES];
    int front = -1, rear = -1;

    // Encolar todos los nodos con grado entrante cero
    for (int i = 0; i < MAX_NODES; ++i) {
        if (indegree[i] == 0) {
            enqueue(queue, &front, &rear, i);
        }
    }

    while (front != -1) {
        int u = dequeue(queue, &front, &rear);

        // Imprimir el nodo actual
        printf("%d ", u);

        count++;

        for (int v = 0; v < MAX_NODES; ++v) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(queue, &front, &rear, v);
                }
            }
        }
    }

    // Verificar si todos los nodos fueron procesados
    if (count != MAX_NODES) {
        printf("\nNo se puede realizar el orden topológico.\n");
    } else {
        printf("\nOrden topológico exitoso.\n");
    }
}

// Función auxiliar para encolar
void enqueue(int queue[], int *front, int *rear, int item) {
    if (*front == -1 && *rear == -1) {
        *front = *rear = 0;
    } else {
        (*rear)++;
    }
    queue[*rear] = item;
}

// Función auxiliar para desencolar
int dequeue(int queue[], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("Error: Cola vacía.\n");
        return -1; // Error de cola vacía
    }
    int item = queue[*front];
    (*front)++;
    return item;
}

int main() {
    int n, e;

    printf("Ingrese el número de nodos: ");
    scanf("%d", &n);

    printf("Ingrese el número de aristas: ");
    scanf("%d", &e);

    for (int i = 0; i < e; ++i) {
        int u, v;
        printf("Ingrese la arista %d (formato u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topologicalSort();

    return 0;
}