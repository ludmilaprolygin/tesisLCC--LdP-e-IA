import java.util.*;

public class TopologicalSort {
    private int V; // Número de vértices
    private LinkedList<Integer> adj[]; // Lista de adyacencia

    @SuppressWarnings("unchecked")
    public TopologicalSort(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    // Función auxiliar para agregar una arista al grafo
    public void addEdge(int v, int w) {
        adj[v].add(w);
    }

    // Función principal para realizar el orden topológico
    public int[] topologicalSort() {
        int[] inDegree = new int[V]; // Grado de entrada del vértice

        // Calcular los grados de entrada de cada vértice
        for (int i = 0; i < V; ++i)
            for (Integer pCrawl : adj[i])
                inDegree[pCrawl]++;

        Queue<Integer> queue = new LinkedList<>(); 

        // Añadir todos los vértices con grado de entrada 0 en la cola
        for (int i = 0; i < V; ++i)
            if (inDegree[i] == 0)
                queue.add(i);

        int[] topOrder = new int[V]; 
        int index = 0;

        // Procesar los vértices uno por uno
        while (!queue.isEmpty()) {
            Integer u = queue.poll();
            topOrder[index++] = u;

            for (Integer i : adj[u]) {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    queue.add(i);
            }
        }

        // Comprobar si se ha realizado un orden topológico
        if (index != V) {
            System.out.println("No hay orden topológico posible");
            return null;
        }

        return topOrder;
    }

    public static void main(String args[]) {
        TopologicalSort g = new TopologicalSort(6);
        g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);

        int[] topOrder = g.topologicalSort();
        if (topOrder != null) {
            System.out.println("El orden topológico del grafo es:");
            for (int i : topOrder)
                System.out.print(i + " ");
            System.out.println("");
        }
    }
}