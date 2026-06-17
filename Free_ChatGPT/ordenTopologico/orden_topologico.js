function esOrdenTopologico(grafo, orden) {
    const posicion = {};

    // Guardar la posición de cada vértice en el orden propuesto
    for (let i = 0; i < orden.length; i++) {
        posicion[orden[i]] = i;
    }

    // Verificar que para cada arista u -> v,
    // u aparezca antes que v en el orden
    for (const u in grafo) {
        for (const v of grafo[u]) {
            if (posicion[u] >= posicion[v]) {
                return false;
            }
        }
    }

    return true;
}

const grafo = {
    A: ["B", "C"],
    B: ["D"],
    C: ["D"],
    D: []
};

console.log(
    esOrdenTopologico(grafo, ["A", "B", "C", "D"])
); // true

console.log(
    esOrdenTopologico(grafo, ["B", "A", "C", "D"])
); // false