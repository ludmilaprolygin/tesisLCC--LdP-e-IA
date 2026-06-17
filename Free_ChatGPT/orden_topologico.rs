use std::collections::HashMap;

/*
    Verifica si "orden" es
    un orden topológico válido.
*/
fn es_orden_topologico(
    grafo: &Vec<Vec<usize>>,
    orden: &Vec<usize>,
) -> bool {

    let n = grafo.len();

    // Deben aparecer todos los vértices
    if orden.len() != n {
        return false;
    }

    // posicion[v] = índice de v en el orden
    let mut posicion = HashMap::new();

    for (i, &v) in orden.iter().enumerate() {
        posicion.insert(v, i);
    }

    // Verificar cada arista u -> v
    for u in 0..n {

        for &v in &grafo[u] {

            let pos_u = match posicion.get(&u) {
                Some(p) => p,
                None => return false,
            };

            let pos_v = match posicion.get(&v) {
                Some(p) => p,
                None => return false,
            };

            // u debe aparecer antes que v
            if pos_u >= pos_v {
                return false;
            }
        }
    }

    true
}

fn main() {

    /*
        Grafo:

        0 -> 1
        0 -> 2
        1 -> 3
        2 -> 3
    */

    let grafo = vec![
        vec![1, 2], // 0
        vec![3],    // 1
        vec![3],    // 2
        vec![],     // 3
    ];

    let orden_valido = vec![0, 1, 2, 3];
    let orden_invalido = vec![1, 0, 2, 3];

    println!(
        "Orden válido: {}",
        es_orden_topologico(&grafo, &orden_valido)
    );

    println!(
        "Orden inválido: {}",
        es_orden_topologico(&grafo, &orden_invalido)
    );
}