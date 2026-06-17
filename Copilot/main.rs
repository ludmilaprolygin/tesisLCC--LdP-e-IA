fn is_topological_order(n: usize, edges: &[(usize, usize)], order: &[usize]) -> bool {
    if order.len() != n {
        return false;
    }

    let mut position = vec![usize::MAX; n];

    for (idx, &node) in order.iter().enumerate() {
        if node >= n {
            return false;
        }
        if position[node] != usize::MAX {
            return false;
        }
        position[node] = idx;
    }

    for &(u, v) in edges {
        if u >= n || v >= n {
            return false;
        }
        if position[u] >= position[v] {
            return false;
        }
    }

    true
}

fn main() {
    let n = 6;
    let edges = vec![(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)];

    let orden_1 = vec![5, 4, 2, 3, 1, 0];
    let orden_2 = vec![4, 5, 2, 3, 1, 0];
    let orden_3 = vec![5, 2, 3, 4, 1, 0];

    println!(
        "orden_1 {:?} -> {}",
        orden_1,
        is_topological_order(n, &edges, &orden_1)
    );
    println!(
        "orden_2 {:?} -> {}",
        orden_2,
        is_topological_order(n, &edges, &orden_2)
    );
    println!(
        "orden_3 {:?} -> {}",
        orden_3,
        is_topological_order(n, &edges, &orden_3)
    );
}

#[cfg(test)]
mod tests {
    use super::is_topological_order;

    #[test]
    fn valid_order_returns_true() {
        let n = 6;
        let edges = vec![(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)];
        let order = vec![5, 4, 2, 3, 1, 0];

        assert!(is_topological_order(n, &edges, &order));
    }

    #[test]
    fn invalid_due_to_dependency_returns_false() {
        let n = 6;
        let edges = vec![(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)];
        let order = vec![2, 5, 4, 3, 1, 0];

        assert!(!is_topological_order(n, &edges, &order));
    }

    #[test]
    fn invalid_due_to_duplicates_returns_false() {
        let n = 4;
        let edges = vec![(0, 1), (1, 2)];
        let order = vec![0, 1, 1, 2];

        assert!(!is_topological_order(n, &edges, &order));
    }

    #[test]
    fn invalid_due_to_missing_node_returns_false() {
        let n = 4;
        let edges = vec![(0, 1), (1, 2)];
        let order = vec![0, 1, 2];

        assert!(!is_topological_order(n, &edges, &order));
    }
}
