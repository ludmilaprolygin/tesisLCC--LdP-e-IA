function esOrdenTopologico(grafo, orden) {
    // grafo: objeto donde cada clave es un nodo y su valor es lista de adyacentes
    // orden: arreglo con el supuesto orden topológico

    const posicion = new Map();

    for (let i = 0; i < orden.length; i++) {
        posicion.set(orden[i], i);
    }

    for (const nodo in grafo) {
        if (!posicion.has(nodo)) {
            return false;
        }

        for (const vecino of grafo[nodo]) {
            if (!posicion.has(vecino)) {
                return false;
            }

            if (posicion.get(nodo) > posicion.get(vecino)) {
                return false;
            }
        }
    }

    return true;
}

// Ejemplo de uso
const grafo = {
    A: ["C"],
    B: ["C", "D"],
    C: ["E"],
    D: ["F"],
    E: [],
    F: []
};

const orden1 = ["A", "B", "C", "D", "E", "F"];
const orden2 = ["C", "A", "B", "D", "E", "F"];

console.log(esOrdenTopologico(grafo, orden1)); // true
console.log(esOrdenTopologico(grafo, orden2)); // false