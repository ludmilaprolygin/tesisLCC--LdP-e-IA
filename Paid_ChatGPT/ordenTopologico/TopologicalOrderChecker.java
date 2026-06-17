package ordenTopologico;
import java.util.*;

public class TopologicalOrderChecker {

    public static <T> boolean esOrdenTopologico(
            Map<T, List<T>> grafo,
            List<T> orden
    ) {
        Set<T> nodos = new HashSet<>();

        for (Map.Entry<T, List<T>> entrada : grafo.entrySet()) {
            nodos.add(entrada.getKey());
            nodos.addAll(entrada.getValue());
        }

        if (!new HashSet<>(orden).equals(nodos)) {
            return false;
        }

        Map<T, Integer> posicion = new HashMap<>();

        for (int i = 0; i < orden.size(); i++) {
            posicion.put(orden.get(i), i);
        }

        for (Map.Entry<T, List<T>> entrada : grafo.entrySet()) {
            T u = entrada.getKey();

            for (T v : entrada.getValue()) {
                if (posicion.get(u) >= posicion.get(v)) {
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Map<String, List<String>> grafo = new HashMap<>();

        grafo.put("A", List.of("C"));
        grafo.put("B", List.of("C", "D"));
        grafo.put("C", List.of("E"));
        grafo.put("D", List.of("E"));
        grafo.put("E", List.of());

        List<String> orden1 = List.of("A", "B", "C", "D", "E");
        List<String> orden2 = List.of("C", "A", "B", "D", "E");

        System.out.println(esOrdenTopologico(grafo, orden1)); // true
        System.out.println(esOrdenTopologico(grafo, orden2)); // false
    }
}