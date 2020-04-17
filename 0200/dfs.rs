struct Solution;

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let m: usize = grid.len();
        let mut ret: i32 = 0;
        for i in 0..m {
            let n: usize = grid[i].len();
            for j in 0..n {
                if grid[i][j] == '1' {
                    Solution::dfs(&mut grid, i, j);
                    ret += 1;
                }
            }
        }
        return ret;
    }

    pub fn dfs(grid: &mut Vec<Vec<char>>, i: usize, j: usize) {
        let m: usize = grid.len();
        let n: usize = grid[i].len();
        if grid[i][j] != '1' { return; }
        grid[i][j] = '-';
        if i > 0 { Solution::dfs(grid, i-1, j); }
        if i < m-1 { Solution::dfs(grid, i+1, j); }
        if j > 0 { Solution::dfs(grid, i, j-1); }
        if j < n-1 { Solution::dfs(grid, i, j+1); }
    }
}

fn main() {
    let mut grid: Vec<Vec<char>>;
    grid = vec![vec!['0'; 5]; 4];
    grid[0][0] = '1';
    grid[0][1] = '1';
    grid[0][2] = '1';
    grid[0][3] = '1';
    grid[1][0] = '1';
    grid[1][1] = '1';
    grid[1][3] = '1';
    grid[2][0] = '1';
    grid[2][1] = '1';
    assert_eq!(Solution::num_islands(grid), 1);

    grid = vec![vec!['0'; 5]; 4];
    grid[0][0] = '1';
    grid[0][1] = '1';
    grid[1][0] = '1';
    grid[1][1] = '1';
    grid[2][2] = '1';
    grid[3][3] = '1';
    grid[3][3] = '1';
    assert_eq!(Solution::num_islands(grid), 3);
}
