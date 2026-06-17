import networkx as nx

def topological_sort(G):
    """
    Reconoce el orden topológico (Topological Sort) de un grafo dirigido G.
    
    Devuelve una lista de nodos en orden topológico si es posible, None si no lo es.
    """
    try:
        return list(nx.topological_sort(G))
    except nx.NetworkXUnconnectedError:
        return None

# Ejemplo de uso
G = nx.DiGraph()  # Grafo dirigido
G.add_edges_from([(1, 2), (2, 3), (3, 4)])  # Agregamos aristas
print(topological_sort(G))  # [1, 2, 3, 4]