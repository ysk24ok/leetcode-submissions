struct Solution;

impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        if n == 1 {
            return vec![0];
        }
        let mut neighbors_of_nodes = vec![vec![]; n as usize];
        for edge in &edges {
            let start = edge[0] as usize;
            let end = edge[1] as usize;
            neighbors_of_nodes[start].push(end);
            neighbors_of_nodes[end].push(start);
        }
        let mut leaves = Vec::new();
        for node in 0..n as usize {
            if neighbors_of_nodes[node].len() == 1 {
                leaves.push(node);
            }
        }
        let mut remaining_node_count = n as usize;
        // if remaining_node_count is 1 or 2, they are the centroids
        while remaining_node_count > 2 {
            let mut new_leaves = Vec::new();
            for leaf in &leaves {
                let neighbor = neighbors_of_nodes[*leaf].pop().unwrap();
                neighbors_of_nodes[neighbor].retain(|&x| x != *leaf);
                if neighbors_of_nodes[neighbor].len() == 1 {
                    new_leaves.push(neighbor);
                }
            }
            remaining_node_count -= leaves.len();
            leaves = new_leaves;
        }
        return leaves.into_iter().map(|x| x as i32).collect();
    }
}

fn main() {
    let (n, edges, expected) = (4, vec![vec![1, 0], vec![1, 2], vec![1, 3]], vec![1]);
    assert_eq!(Solution::find_min_height_trees(n, edges), expected);

    let (n, edges, expected) = (6, vec![vec![3, 0], vec![3, 1], vec![3, 2], vec![3, 4], vec![5, 4]], vec![3, 4]);
    assert_eq!(Solution::find_min_height_trees(n, edges), expected);

    let (n, edges, expected) = (1, Vec::new(), vec![0]);
    assert_eq!(Solution::find_min_height_trees(n, edges), expected);

    let (n, edges, expected) = (2, vec![vec![0, 1]], vec![0, 1]);
    assert_eq!(Solution::find_min_height_trees(n, edges), expected);
}
