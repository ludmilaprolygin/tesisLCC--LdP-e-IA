from collections import deque

class Grafo:
    def __init__(self, vertices):
        self.V = vertices
        self.ady = [[] for _ in range(vertices)]

    def agregar_arista(self, u, v):
        """
        Agrega una arista dirigida u -> v
        """
        self.ady[u].append(v)

    def es_orden_topologico(self, orden):
        """
        Verifica si 'orden' es un orden topológico válido.

        Retorna:
            True  -> si es válido
            False -> si no lo es
        """

        # Debe contener todos los vértices exactamente una vez
        if len(orden) != self.V:
            return False

        if set(orden) != set(range(self.V)):
            return False

        # Posición de cada nodo en el orden
        posicion = [0] * self.V

        for i, nodo in enumerate(orden):
            posicion[nodo] = i

        # Para cada arista u -> v:
        # u debe aparecer antes que v
        for u in range(self.V):
            for v in self.ady[u]:
                if posicion[u] > posicion[v]:
                    return False

        return True


# ---------------------------
# Ejemplo de uso
# ---------------------------

g = Grafo(6)

g.agregar_arista(5, 2)
g.agregar_arista(5, 0)
g.agregar_arista(4, 0)
g.agregar_arista(4, 1)
g.agregar_arista(2, 3)
g.agregar_arista(3, 1)

orden1 = [5, 4, 2, 3, 1, 0]
orden2 = [4, 5, 2, 3, 0, 1]
orden3 = [5, 4, 3, 2, 1, 0]

print(g.es_orden_topologico(orden1))  # True
print(g.es_orden_topologico(orden2))  # True
print(g.es_orden_topologico(orden3))  # False