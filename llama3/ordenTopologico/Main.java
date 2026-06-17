package llama3;

import java.util.*;

class Graph {
    private Map<String, List<String>> adjacencyList;

    public Graph() {
        this.adjacencyList = new HashMap<>();
    }

    public void addVertex(String vertex) {
        if (!adjacencyList.containsKey(vertex)) {
            adjacencyList.put(vertex, new ArrayList<>());
        }
    }

    public void addEdge(String from, String to) {
        if (adjacencyList.containsKey(from) && adjacencyList.containsKey(to)) {
            adjacencyList.get(from).add(to);
        }
    }

    public List<String> topologicalSort() {
        Map<String, Integer> inDegree = new HashMap<>();
        for (String vertex : adjacencyList.keySet()) {
            inDegree.put(vertex, 0);
        }

        for (String vertex : adjacencyList.keySet()) {
            for (String neighbor : adjacencyList.get(vertex)) {
                inDegree.put(neighbor, inDegree.getOrDefault(neighbor, 0) + 1);
            }
        }

        List<String> sortedVertices = new ArrayList<>();
        Queue<String> queue = new LinkedList<>();

        for (String vertex : inDegree.keySet()) {
            if (inDegree.get(vertex) == 0) {
                queue.offer(vertex);
            }
        }

        while (!queue.isEmpty()) {
            String vertex = queue.poll();
            sortedVertices.add(vertex);

            for (String neighbor : adjacencyList.get(vertex)) {
                inDegree.put(neighbor, inDegree.get(neighbor) - 1);
                if (inDegree.get(neighbor) == 0) {
                    queue.offer(neighbor);
                }
            }
        }

        return sortedVertices;
    }
}

public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph();

        // Agregar vertices
        graph.addVertex("A");
        graph.addVertex("B");
        graph.addVertex("C");
        graph.addVertex("D");
        graph.addVertex("E");

        // Agregar aristas
        graph.addEdge("A", "B");
        graph.addEdge("A", "C");
        graph.addEdge("B", "D");
        graph.addEdge("C", "D");
        graph.addEdge("D", "E");

        List<String> sortedVertices = graph.topologicalSort();

        System.out.println("Orden topológico:");
        for (String vertex : sortedVertices) {
            System.out.print(vertex + " ");
        }
    }
}