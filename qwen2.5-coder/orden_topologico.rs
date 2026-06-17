use std::collections::{VecDeque, HashMap};

// Representación de un nodo y su lista de adyacencias.
struct Node {
    id: usize,
    in_degree: u32, // Grado entrante del nodo.
    neighbors: Vec<usize>,
}

impl Node {
    fn new(id: usize) -> Self {
        Node { id, in_degree: 0, neighbors: Vec::new() }
    }

    fn add_neighbor(&mut self, neighbor_id: usize) {
        self.neighbors.push(neighbor_id);
    }
}

// Estructura para representar el grafo.
pub struct Graph {
    nodes: HashMap<usize, Node>,
}

impl Graph {
    pub fn new() -> Self {
        Graph { nodes: HashMap::new() }
    }

    // Añade un nodo al grafo con el identificador dado.
    pub fn add_node(&mut self, id: usize) {
        if !self.nodes.contains_key(&id) {
            self.nodes.insert(id, Node::new(id));
        }
    }

    // Añade una arista desde 'from' hasta 'to'.
    pub fn add_edge(&mut self, from: usize, to: usize) {
        let from_node = self.nodes.get_mut(&from).unwrap();
        let to_node = self.nodes.get_mut(&to).unwrap();

        from_node.add_neighbor(to);
        to_node.in_degree += 1;
    }

    // Realiza el recorrido topológico utilizando el algoritmo de Kahn.
    pub fn kahn_topo_sort(&self) -> Option<Vec<usize>> {
        let mut sorted = Vec::new();
        let mut queue = VecDeque::new();

        // Encuentra todos los nodos con grado entrante 0 y añade a la cola.
        for (id, node) in &self.nodes {
            if node.in_degree == 0 {
                queue.push_back(*id);
            }
        }

        while let Some(node_id) = queue.pop_front() {
            sorted.push(node_id);

            // Reduce el grado entrante de los vecinos del nodo actual.
            if let Some(node) = self.nodes.get(&node_id) {
                for &neighbor in &node.neighbors {
                    if let Some(neighbor_node) = self.nodes.get_mut(&neighbor) {
                        neighbor_node.in_degree -= 1;
                        if neighbor_node.in_degree == 0 {
                            queue.push_back(neighbor);
                        }
                    }
                }
            }
        }

        // Verifica si el grafo tiene un orden topológico válido.
        if sorted.len() != self.nodes.len() {
            None
        } else {
            Some(sorted)
        }
    }
}

// Ejemplo de uso:
fn main() {
    let mut graph = Graph::new();
    graph.add_node(1);
    graph.add_node(2);
    graph.add_node(3);
    graph.add_node(4);

    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 4);
    graph.add_edge(3, 4);

    if let Some(topo_order) = graph.kahn_topo_sort() {
        println!("Orden topológico: {:?}", topo_order);
    } else {
        println!("El grafo no tiene un orden topológico válido.");
    }
}