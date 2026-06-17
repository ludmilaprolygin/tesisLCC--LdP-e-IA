#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
	int destino;
	struct Nodo *siguiente;
} Nodo;

typedef struct {
	int vertices;
	Nodo **adyacencias;
} Grafo;

static Nodo *crear_nodo(int destino) {
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	if (nodo == NULL) return NULL;
	nodo->destino = destino;
	nodo->siguiente = NULL;
	return nodo;
}

static Grafo *crear_grafo(int vertices) {
	Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
	if (grafo == NULL) return NULL;

	grafo->vertices = vertices;
	grafo->adyacencias = (Nodo **)calloc((size_t)vertices, sizeof(Nodo *));
	if (grafo->adyacencias == NULL) {
		free(grafo);
		return NULL;
	}

	return grafo;
}

static void agregar_arista(Grafo *grafo, int origen, int destino) {
	Nodo *nodo = crear_nodo(destino);
	if (nodo == NULL) return;

	nodo->siguiente = grafo->adyacencias[origen];
	grafo->adyacencias[origen] = nodo;
}

static void liberar_grafo(Grafo *grafo) {
	if (grafo == NULL) return;
	for (int i = 0; i < grafo->vertices; i++) {
		Nodo *actual = grafo->adyacencias[i];
		while (actual != NULL) {
			Nodo *siguiente = actual->siguiente;
			free(actual);
			actual = siguiente;
		}
	}
	free(grafo->adyacencias);
	free(grafo);
}

static int dfs_topologico(const Grafo *grafo, int v, int *estado, int *orden, int *indice) {
	estado[v] = 1;
	for (Nodo *nodo = grafo->adyacencias[v]; nodo != NULL; nodo = nodo->siguiente) {
		int w = nodo->destino;
		if (estado[w] == 1) return 0;
		if (estado[w] == 0 && !dfs_topologico(grafo, w, estado, orden, indice)) return 0;
	}
	estado[v] = 2;
	orden[(*indice)++] = v;
	return 1;
}

int es_orden_topologico(const Grafo *grafo, int *orden) {
	int *estado = (int *)calloc((size_t)grafo->vertices, sizeof(int));
	if (estado == NULL) return 0;

	int indice = 0;
	for (int i = 0; i < grafo->vertices; i++) {
		if (estado[i] == 0) {
			if (!dfs_topologico(grafo, i, estado, orden, &indice)) {
				free(estado);
				return 0;
			}
		}
	}

	free(estado);

	for (int i = 0; i < grafo->vertices / 2; i++) {
		int tmp = orden[i];
		orden[i] = orden[grafo->vertices - 1 - i];
		orden[grafo->vertices - 1 - i] = tmp;
	}

	return 1;
}

int main(void) {
	int vertices, aristas;

	if (scanf("%d %d", &vertices, &aristas) != 2 || vertices <= 0 || aristas < 0) {
		fprintf(stderr, "Entrada invalida\n");
		return 1;
	}

	Grafo *grafo = crear_grafo(vertices);
	if (grafo == NULL) {
		fprintf(stderr, "No se pudo crear el grafo\n");
		return 1;
	}

	for (int i = 0; i < aristas; i++) {
		int origen, destino;
		if (scanf("%d %d", &origen, &destino) != 2 || origen < 0 || origen >= vertices || destino < 0 || destino >= vertices) {
			fprintf(stderr, "Arista invalida\n");
			liberar_grafo(grafo);
			return 1;
		}
		agregar_arista(grafo, origen, destino);
	}

	int *orden = (int *)malloc((size_t)vertices * sizeof(int));
	if (orden == NULL) {
		fprintf(stderr, "No se pudo reservar memoria\n");
		liberar_grafo(grafo);
		return 1;
	}

	if (es_orden_topologico(grafo, orden)) {
		printf("Si existe orden topologico:\n");
		for (int i = 0; i < vertices; i++) {
			printf("%d%c", orden[i], (i == vertices - 1) ? '\n' : ' ');
		}
	} else {
		printf("El grafo tiene un ciclo y no admite orden topologico.\n");
	}

	free(orden);
	liberar_grafo(grafo);
	return 0;
}
