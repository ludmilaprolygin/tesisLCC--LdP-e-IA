#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un grafo como una lista de adyacencia
typedef struct {
    int numNodes;
    int **adjList; // matriz de adyacencia (numNodes x numNodes)
} Graph;

// Función para crear un grafo a partir de un archivo de texto
Graph* createGraph(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    int numNodes, edges;
    fscanf(fp, "%d %d", &numNodes, &edges);

    Graph *graph = (Graph*) malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjList = (int**) malloc(numNodes * sizeof(int*));

    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = (int*) malloc((edges + 1) * sizeof(int));
    }

    int node, edge;
    for (int i = 0; i <= edges; i++) {
        fscanf(fp, "%d %d", &node, &edge);
        graph->adjList[node][i] = edge;
    }

    fclose(fp);

    return graph;
}

// Función para realizar un Topological Sort utilizando el algoritmo de Kahn
void topologicalSort(Graph *graph) {
    int visited[graph->numNodes];
    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = 0;
    }

    int queue[graph->numNodes];
    int front = -1, rear = -1;

    // Marcar los nodos con grado cero como visitados
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjList[i][0] == 0) { // nodo con grado cero
            visited[i] = 1;
            queue[++rear] = i;
        }
    }

    while (front != rear) {
        int node = queue[front++];
        printf("%d ", node); // imprimir el nodo visitado

        for (int i = 0; i < graph->numNodes; i++) {
            if (graph->adjList[i][0] == node) { // encontrar nodos adyacentes
                graph->adjList[i][0]--;
                if (graph->adjList[i][0] == 0) { // nodo con grado cero
                    visited[i] = 1;
                    queue[++rear] = i;
                }
            }
        }
    }

    printf("\n");
}

int main() {
    Graph *graph = createGraph("grafo.txt"); // crear un grafo a partir de un archivo de texto

    if (!graph) {
        return -1; // error al crear el grafo
    }

    topologicalSort(graph); // realizar un Topological Sort

    for (int i = 0; i < graph->numNodes; i++) {
        free(graph->adjList[i]);
    }
    free(graph->adjList);
    free(graph);

    return 0;
}