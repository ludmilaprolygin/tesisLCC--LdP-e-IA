use std::collections::{HashMap, HashSet};

pub struct TopologicalOrder {
    order: Vec<String>,
}

impl TopologicalOrder {
    pub fn new(graph: &HashMap<String, Vec<(String, u32)>>) -> Self {
        let mut visited = HashMap::new();
        let mut stack = Vec::new();
        let mut result = Vec::new();

        for node in graph.keys() {
            if !visited.contains_key(node) {
                dfs(node, graph, &mut visited, &mut stack, &mut result);
            }
        }

        TopologicalOrder { order: result }
    }

    pub fn get_order(&self) -> &Vec<String> {
        &self.order
    }
}

fn dfs(node: &String, graph: &HashMap<String, Vec<(String, u32)>>, visited: &mut HashMap<String, bool>, stack: &mut Vec<String>, result: &mut Vec<String>) {
    visited.insert(node.clone(), true);
    for (neighbor, _) in graph.get(node).unwrap_or(&vec![]) {
        if !visited.contains_key(neighbor) {
            dfs(neighbor, graph, visited, stack, result);
        }
    }
    stack.push(node.clone());
}

fn main() {
    let mut graph = HashMap::new();
    graph.insert("A".to_string(), vec![("B", 1), ("C", 2)]);
    graph.insert("B".to_string(), vec![("D", 3)]);
    graph.insert("C".to_string(), vec![]);
    graph.insert("D".to_string(), vec![("E", 4), ("F", 5)]);
    graph.insert("E".to_string(), vec![]);
    graph.insert("F".to_string(), vec![]);

    let topological_order = TopologicalOrder::new(&graph);
    println!("{:?}", topological_order.get_order());
}