"""Reconocedor de orden topológico.

Funciones principales:
- es_orden_topologico(graph, ordering): devuelve True si ordering es un orden topológico
  válido para el grafo dirigido acíclico dado como lista de adyacencia o lista de aristas.
- kahn_topological_sort(graph): devuelve una ordenación topológica si el grafo es DAG,
  o None si tiene ciclos.

El grafo puede representarse como:
- dict: {u: [v1, v2, ...], ...}
- list de pares (u, v)
"""
from collections import defaultdict, deque
from typing import Dict, List, Tuple, Iterable, Optional


def _normalize_graph(graph) -> Dict:
    """Convierte distintas representaciones a un dict de adyacencia."""
    if graph is None:
        return {}
    if isinstance(graph, dict):
        # copia sencilla garantizando listas
        return {u: list(vs) for u, vs in graph.items()}
    # si es lista de aristas o secuencia de nodos de adyacencia
    adj = defaultdict(list)
    for item in graph:
        if isinstance(item, tuple) or isinstance(item, list):
            u, v = item
            adj[u].append(v)
            # asegurar existencia de v en el dict
            if v not in adj:
                adj[v] = adj[v]
        else:
            raise TypeError("Formato de grafo no soportado: use dict o lista de aristas")
    return dict(adj)


def es_orden_topologico(graph, ordering: Iterable) -> bool:
    """Verifica si 'ordering' es un orden topológico para 'graph'.

    graph: dict de adyacencia o lista de aristas (u,v).
    ordering: secuencia que contiene todos los nodos del grafo en algún orden.
    Devuelve True si para toda arista u->v, u aparece antes que v en ordering.
    """
    adj = _normalize_graph(graph)
    pos = {}
    for i, node in enumerate(ordering):
        pos[node] = i
    # todos los nodos del grafo deben estar en ordering
    all_nodes = set(adj.keys()) | {v for vs in adj.values() for v in vs}
    if set(pos.keys()) != all_nodes:
        return False
    for u, vs in adj.items():
        for v in vs:
            if pos[u] >= pos[v]:
                return False
    return True


def kahn_topological_sort(graph) -> Optional[List]:
    """Realiza Kahn y devuelve una ordenación topológica o None si hay ciclo."""
    adj = _normalize_graph(graph)
    indeg = {u: 0 for u in adj}
    for u, vs in adj.items():
        for v in vs:
            indeg.setdefault(v, 0)
            indeg[v] += 1
    q = deque([u for u, d in indeg.items() if d == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj.get(u, []):
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    if len(order) != len(indeg):
        return None
    return order


if __name__ == '__main__':
    # ejemplo mínimo
    G = {1: [2, 3], 2: [4], 3: [4], 4: []}
    topo = kahn_topological_sort(G)
    print('Topológica:', topo)
    print('Valida?', es_orden_topologico(G, topo) if topo is not None else False)
