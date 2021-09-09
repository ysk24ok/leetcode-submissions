use std::cmp;
use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn order_of_largest_plus_sign(n: i32, mines: Vec<Vec<i32>>) -> i32 {
        let mut dp: Vec<Vec<i32>> = vec![vec![n; n as usize]; n as usize];
        let mut mines_set = HashSet::new();
        for mine in mines {
            mines_set.insert(mine[0] * n + mine[1]);
        }
        let mut res = 0;
        for r in 0..n {
            // from left
            let mut count = 0;
            for c in 0..n {
                count = if mines_set.contains(&(r * n + c)) { 0 } else { count + 1 };
                dp[r as usize][c as usize] = cmp::min(count, dp[r as usize][c as usize]);
            }
            // from right
            count = 0;
            for c in (0..n).rev() {
                count = if mines_set.contains(&(r * n + c)) { 0 } else { count + 1 };
                dp[r as usize][c as usize] = cmp::min(count, dp[r as usize][c as usize]);
            }
        }
        for c in 0..n {
            // from top
            let mut count = 0;
            for r in 0..n {
                count = if mines_set.contains(&(r * n + c)) { 0 } else { count + 1 };
                dp[r as usize][c as usize] = cmp::min(count, dp[r as usize][c as usize]);
            }
            // from bottom
            count = 0;
            for r in (0..n).rev() {
                count = if mines_set.contains(&(r * n + c)) { 0 } else { count + 1 };
                dp[r as usize][c as usize] = cmp::min(count, dp[r as usize][c as usize]);
                res = cmp::max(dp[r as usize][c as usize], res);
            }
        }
        return res;
    }
}

fn main() {
    let (n, mines, expected) = (5, vec![vec![4, 2]], 2);
    assert_eq!(Solution::order_of_largest_plus_sign(n, mines), expected);

    let (n, mines, expected) = (1, vec![vec![0, 0]], 0);
    assert_eq!(Solution::order_of_largest_plus_sign(n, mines), expected);
}
