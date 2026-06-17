import java.util.*;

public class VerificadorOrdenTopologico {

    /**
     * Verifica si el orden dado es un orden topológico válido.
     *
     * @param grafo Grafo representado como lista de adyacencia
     * @param orden Lista con el supuesto orden topológico
     * @return true si es válido, false en caso contrario
     */
    public static boolean esOrdenTopologico(
            Map<Integer, List<Integer>> grafo,
            List<Integer> orden) {

        // Verificar que tengan la misma cantidad de nodos
        if (orden.size() != grafo.size()) {
            return false;
        }

        // posición[vértice] = índice en el orden
        Map<Integer, Integer> posicion = new HashMap<>();

        for (int i = 0; i < orden.size(); i++) {
            posicion.put(orden.get(i), i);
        }

        // Revisar todas las aristas u -> v
        // En un orden topológico válido:
        // posición(u) < posición(v)
        for (Integer u : grafo.keySet()) {

            // El nodo debe existir en el orden
            if (!posicion.containsKey(u)) {
                return false;
            }

            for (Integer v : grafo.get(u)) {

                // El nodo destino también debe existir
                if (!posicion.containsKey(v)) {
                    return false;
                }

                if (posicion.get(u) >= posicion.get(v)) {
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {

        Map<Integer, List<Integer>> grafo = new HashMap<>();

        grafo.put(0, Arrays.asList(1, 2));
        grafo.put(1, Arrays.asList(3));
        grafo.put(2, Arrays.asList(3));
        grafo.put(3, new ArrayList<>());

        List<Integer> ordenValido = Arrays.asList(0, 1, 2, 3);
        List<Integer> ordenInvalido = Arrays.asList(1, 0, 2, 3);

        System.out.println(
                "Orden válido: " +
                esOrdenTopologico(grafo, ordenValido));

        System.out.println(
                "Orden inválido: " +
                esOrdenTopologico(grafo, ordenInvalido));
    }
}