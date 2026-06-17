def es_orden_topologico(grafo, orden):
    """
    grafo: diccionario {nodo: [vecinos]}
           representa arcos nodo -> vecino

    orden: lista con los nodos en el supuesto orden topológico

    retorna True si orden es topológico, False si no
    """

    # 1. Verificar que el orden tenga exactamente los mismos nodos que el grafo
    nodos = set(grafo.keys())

    for vecinos in grafo.values():
        nodos.update(vecinos)

    if set(orden) != nodos:
        return False

    # 2. Guardar la posición de cada nodo en el orden propuesto
    posicion = {}

    for i, nodo in enumerate(orden):
        posicion[nodo] = i

    # 3. Para cada arco u -> v, u debe aparecer antes que v
    for u in grafo:
        for v in grafo[u]:
            if posicion[u] >= posicion[v]:
                return False

    return True

# Uso

grafo = {
    "A": ["C"],
    "B": ["C", "D"],
    "C": ["E"],
    "D": ["E"],
    "E": []
}

orden1 = ["A", "B", "C", "D", "E"]
orden2 = ["C", "A", "B", "D", "E"]

print(es_orden_topologico(grafo, orden1))  # True
print(es_orden_topologico(grafo, orden2))  # False