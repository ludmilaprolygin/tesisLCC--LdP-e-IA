function esOrdenTopologico(grafo, orden) {
  const nodos = new Set();

  for (const [u, vecinos] of Object.entries(grafo)) {
    nodos.add(u);
    for (const v of vecinos) {
      nodos.add(v);
    }
  }

  if (orden.length !== nodos.size) {
    return false;
  }

  const vistos = new Set();
  const posicion = new Map();

  for (let i = 0; i < orden.length; i++) {
    const nodo = orden[i];

    if (!nodos.has(nodo) || vistos.has(nodo)) {
      return false;
    }

    vistos.add(nodo);
    posicion.set(nodo, i);
  }

  for (const [u, vecinos] of Object.entries(grafo)) {
    for (const v of vecinos) {
      if (posicion.get(u) >= posicion.get(v)) {
        return false;
      }
    }
  }

  return true;
}

// Ejemplo de uso
const grafo = {
  A: ["B", "C"],
  B: ["D"],
  C: ["D"],
  D: []
};

console.log(esOrdenTopologico(grafo, ["A", "B", "C", "D"])); // true
console.log(esOrdenTopologico(grafo, ["B", "A", "C", "D"])); // false