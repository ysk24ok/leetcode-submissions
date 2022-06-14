use std::cmp;

struct Solution;

impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let (m, n) = (word1.len(), word2.len());
        let mut dp = vec![vec![0; n + 1]; m + 1];
        for i in 1..m+1 {
            dp[i][0] = dp[i-1][0] + 1;
        }
        for j in 1..n+1 {
            dp[0][j] = dp[0][j-1] + 1;
        }
        for i in 1..m+1 {
            for j in 1..n+1 {
                if word1.chars().nth(i-1).unwrap() == word2.chars().nth(j-1).unwrap() {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = cmp::min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
}

fn main() {
    let (word1, word2, expected) = (String::from("sea"), String::from("eat"), 2);
    assert_eq!(Solution::min_distance(word1, word2), expected);

    let (word1, word2, expected) = (String::from("leetcode"), String::from("etco"), 4);
    assert_eq!(Solution::min_distance(word1, word2), expected);

    let (word1, word2, expected) = (String::from("a"), String::from("b"), 2);
    assert_eq!(Solution::min_distance(word1, word2), expected);
}
