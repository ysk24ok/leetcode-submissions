struct Solution;

/*
 *   - a b c d e
 * - 0 0 0 0 0 0
 * a 0 1 1 1 1 1
 * b 0 0 2 2 2 2
 * c 0 0 2 3 3 3
 */

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let m = text1.len();
        let n = text2.len();
        let mut dp = vec![vec![0; n+1]; m+1];
        let mut i : usize = 1;
        for c1 in text1.chars() {
            let mut j : usize = 1;
            for c2 in text2.chars() {
                dp[i][j] = std::cmp::max(dp[i][j-1], dp[i-1][j]);
                if c1 == c2 {
                    dp[i][j] = std::cmp::max(dp[i-1][j-1] + 1, dp[i][j]);
                }
                j += 1;
            }
            i += 1;
        }
        return dp[m][n];
    }
}

fn main() {
    let mut text1: String;
    let mut text2: String;

    text1 = "abcde".to_string();
    text2 = "abc".to_string();
    assert_eq!(3, Solution::longest_common_subsequence(text1, text2));

    text1 = "abc".to_string();
    text2 = "abc".to_string();
    assert_eq!(3, Solution::longest_common_subsequence(text1, text2));

    text1 = "abc".to_string();
    text2 = "def".to_string();
    assert_eq!(0, Solution::longest_common_subsequence(text1, text2));
}
