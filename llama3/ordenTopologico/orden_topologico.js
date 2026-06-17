function TopologicalSort(graph) {
  const visited = new Set();
  const order = [];

  function visit(vertex) {
    if (visited.has(vertex)) return;
    visited.add(vertex);

    for (const neighbor of graph[vertex]) {
      visit(neighbor);
    }

    order.push(vertex);
  }

  for (const vertex in graph) {
    if (!visited.has(vertex)) {
      visit(vertex);
    }
  }

  return order;
}

// Ejemplo de uso:
const graph = {
  'A': ['B', 'C'],
  'B': ['D', 'E'],
  'C': ['F'],
  'D': [],
  'E': ['F'],
  'F': []
};

console.log(TopologicalSort(graph)); // Output: ["A", "B", "C", "D", "E", "F"]