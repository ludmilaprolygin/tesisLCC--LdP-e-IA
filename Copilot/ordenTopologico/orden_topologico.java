import java.util.*;

public class orden_topologico {
    
    private int vertices;
    private List<Integer>[] adyacencia;
    private Stack<Integer> pila;
    private boolean[] visitado;
    
    @SuppressWarnings("unchecked")
    public orden_topologico(int vertices) {
        this.vertices = vertices;
        this.adyacencia = new LinkedList[vertices];
        this.pila = new Stack<>();
        this.visitado = new boolean[vertices];
        
        for (int i = 0; i < vertices; i++) {
            adyacencia[i] = new LinkedList<>();
        }
    }
    
    public void agregarArista(int origen, int destino) {
        adyacencia[origen].add(destino);
    }
    
    private void dfs(int vertice) {
        visitado[vertice] = true;
        
        for (Integer vecino : adyacencia[vertice]) {
            if (!visitado[vecino]) {
                dfs(vecino);
            }
        }
        
        pila.push(vertice);
    }
    
    public void calcularOrdenTopologico() {
        Arrays.fill(visitado, false);
        
        for (int i = 0; i < vertices; i++) {
            if (!visitado[i]) {
                dfs(i);
            }
        }
        
        System.out.println("Orden Topológico:");
        while (!pila.isEmpty()) {
            System.out.print(pila.pop() + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        orden_topologico grafo = new orden_topologico(6);
        
        grafo.agregarArista(5, 2);
        grafo.agregarArista(5, 0);
        grafo.agregarArista(4, 0);
        grafo.agregarArista(4, 1);
        grafo.agregarArista(2, 3);
        grafo.agregarArista(3, 1);
        
        grafo.calcularOrdenTopologico();
    }
}
