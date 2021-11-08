struct Solution;

impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let n_as_usize = n as usize;
        let mut dp = vec![0; n_as_usize + 1];
        dp[0] = 1;
        dp[1] = 1;
        for i in 2..n_as_usize+1 {
            for left in 0..i {
                let right = i - left - 1;
                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n_as_usize];
    }
}

fn main() {
    let (n, expected) = (3, 5);
    assert_eq!(Solution::num_trees(n), expected);

    let (n, expected) = (1, 1);
    assert_eq!(Solution::num_trees(n), expected);

    let (n, expected) = (19, 1767263190);
    assert_eq!(Solution::num_trees(n), expected);
}
