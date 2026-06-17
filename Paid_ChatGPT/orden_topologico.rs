use std::collections::{HashMap, HashSet};

fn es_orden_topologico(
    grafo: &HashMap<&str, Vec<&str>>,
    orden: &[&str],
) -> bool {
    let mut nodos: HashSet<&str> = HashSet::new();

    for (u, vecinos) in grafo {
        nodos.insert(u);

        for v in vecinos {
            nodos.insert(v);
        }
    }

    if orden.iter().copied().collect::<HashSet<_>>() != nodos {
        return false;
    }

    let mut posicion: HashMap<&str, usize> = HashMap::new();

    for (i, nodo) in orden.iter().enumerate() {
        posicion.insert(nodo, i);
    }

    for (u, vecinos) in grafo {
        for v in vecinos {
            if posicion[u] >= posicion[v] {
                return false;
            }
        }
    }

    true
}

fn main() {
    let mut grafo: HashMap<&str, Vec<&str>> = HashMap::new();

    grafo.insert("A", vec!["C"]);
    grafo.insert("B", vec!["C", "D"]);
    grafo.insert("C", vec!["E"]);
    grafo.insert("D", vec!["E"]);
    grafo.insert("E", vec![]);

    let orden1 = vec!["A", "B", "C", "D", "E"];
    let orden2 = vec!["C", "A", "B", "D", "E"];

    println!("{}", es_orden_topologico(&grafo, &orden1)); // true
    println!("{}", es_orden_topologico(&grafo, &orden2)); // false
}