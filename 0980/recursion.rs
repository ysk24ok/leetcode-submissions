struct Solution;

impl Solution {
    pub fn unique_paths_iii(grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());
        let mut num_total_non_obstacles = 0;
        let (mut start_i, mut start_j) = (0, 0);
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 0 {
                    num_total_non_obstacles += 1;
                } else if grid[i][j] == 1 {
                    num_total_non_obstacles += 1;
                    start_i = i;
                    start_j = j;
                }
            }
        }
        let mut visited: Vec<Vec<bool>> = vec![vec![false; n]; m];
        return Solution::recursion(&grid, &mut visited, start_i, start_j, num_total_non_obstacles, 0);
    }

    fn recursion(grid: &Vec<Vec<i32>>,
                 visited: &mut Vec<Vec<bool>>,
                 i: usize,
                 j: usize,
                 num_total_non_obstacles: i32,
                 num_current_non_obstacles: i32,
    ) -> i32 {
        if grid[i][j] == 2 && num_total_non_obstacles == num_current_non_obstacles {
            return 1;
        } else if grid[i][j] == 2 || grid[i][j] == -1 || visited[i][j] {
            return 0;
        }
        visited[i][j] = true;
        let mut ret = 0;
        let (m, n) = (grid.len(), grid[0].len());
        if i > 0 {
            ret += Solution::recursion(grid, visited, i - 1, j, num_total_non_obstacles, num_current_non_obstacles + 1);
        }
        if i < m - 1 {
            ret += Solution::recursion(grid, visited, i + 1, j, num_total_non_obstacles, num_current_non_obstacles + 1);
        }
        if j > 0 {
            ret += Solution::recursion(grid, visited, i, j - 1, num_total_non_obstacles, num_current_non_obstacles + 1);
        }
        if j < n - 1 {
            ret += Solution::recursion(grid, visited, i, j + 1, num_total_non_obstacles, num_current_non_obstacles + 1);
        }
        visited[i][j] = false;
        return ret;
    }
}

fn main() {
    let grid = vec![vec![1, 0, 0, 0], vec![0, 0, 0, 0], vec![0, 0, 2, -1]];
    let expected = 2;
    assert_eq!(Solution::unique_paths_iii(grid), expected);

    let grid = vec![vec![1, 0, 0, 0], vec![0, 0, 0, 0], vec![0, 0, 0, 2]];
    let expected = 4;
    assert_eq!(Solution::unique_paths_iii(grid), expected);

    let grid = vec![vec![0, 1], vec![2, 0]];
    let expected = 0;
    assert_eq!(Solution::unique_paths_iii(grid), expected);
}
