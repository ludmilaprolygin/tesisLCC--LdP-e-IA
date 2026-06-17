class Graph {
    constructor(vertices) {
        this.V = vertices; // Número de vértices
        this.adjList = new Map(); // Lista adyacente del grafo

        for (let i = 0; i < vertices; i++) {
            this.adjList.set(i, []);
        }
    }

    // Método para agregar una arista dirigida al grafo
    addEdge(v, w) {
        this.adjList.get(v).push(w);
    }

    // Método para encontrar el orden topológico del grafo usando Kahn's Algorithm
    topologicalSort() {
        const inDegree = Array(this.V).fill(0); // Grados entrantes de cada vértice

        // Calcular los grados entrantes de cada vértice
        this.adjList.forEach((neighbors) => {
            neighbors.forEach((neighbor) => {
                inDegree[neighbor]++;
            });
        });

        const queue = []; // Cola para almacenar vértices con grado entrante 0

        // Agregar todos los vértices con grado entrante 0 a la cola
        for (let i = 0; i < this.V; i++) {
            if (inDegree[i] === 0) {
                queue.push(i);
            }
        }

        const topologicalOrder = []; // Almacenar el orden topológico

        while (queue.length > 0) {
            const u = queue.shift(); // Extraer un vértice de la cola
            topologicalOrder.push(u);

            // Reducir los grados entrantes de los vecinos del vértice extraído
            this.adjList.get(u).forEach((neighbor) => {
                inDegree[neighbor]--;

                // Si el grado entrante del vecino se vuelve 0, agregarlo a la cola
                if (inDegree[neighbor] === 0) {
                    queue.push(neighbor);
                }
            });
        }

        // Verificar si el grafo es acíclico
        if (topologicalOrder.length !== this.V) {
            console.log("El grafo contiene un ciclo, no se puede realizar orden topológico.");
            return [];
        }

        return topologicalOrder;
    }
}

// Ejemplo de uso
const g = new Graph(6);
g.addEdge(5, 2);
g.addEdge(5, 0);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);

console.log("Orden topológico del grafo:");
console.log(g.topologicalSort());