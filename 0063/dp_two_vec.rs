// memory complexity: O(2m)
struct Solution;

impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m: usize = obstacle_grid.len();
        let n: usize = obstacle_grid[0].len();
        let mut prev = vec![0; m];
        // prev[0]
        if obstacle_grid[0][0] == 0 {
            prev[0] = 1;
        }
        // prev[1..m]
        for i in 1..m {
            if obstacle_grid[i][0] == 0 {
                prev[i] = prev[i-1];
            }
        }
        for j in 1..n {
            let mut curr = vec![0; m];
            // curr[0]
            if obstacle_grid[0][j] == 0 {
                curr[0] = prev[0];
            }
            // curr[1..m]
            for i in 1..m {
                if obstacle_grid[i][j] == 0 {
                    curr[i] = prev[i] + curr[i-1];
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
}

fn main() {
    let obstacle_grid1: Vec<Vec<i32>> = vec![vec![1]];
    assert_eq!(Solution::unique_paths_with_obstacles(obstacle_grid1), 0);
    let obstacle_grid2: Vec<Vec<i32>> = vec![vec![0,0],vec![1,0],vec![0,0]];
    assert_eq!(Solution::unique_paths_with_obstacles(obstacle_grid2), 1);
    let obstacle_grid3: Vec<Vec<i32>> = vec![vec![0,0,0],vec![0,1,0],vec![0,0,0]];
    assert_eq!(Solution::unique_paths_with_obstacles(obstacle_grid3), 2);
}
