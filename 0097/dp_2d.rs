struct Solution;

impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        if s1.len() + s2.len() != s3.len() {
            return false;
        }
        let mut dp = vec![vec![false; s2.len()+1]; s1.len()+1];
        dp[0][0] = true;
        for i in 0..s1.len() {
            dp[i+1][0] = dp[i][0] && s3.chars().nth(i) == s1.chars().nth(i);
        }
        for j in 0..s2.len() {
            dp[0][j+1] = dp[0][j] && s3.chars().nth(j) == s2.chars().nth(j);
        }
        for i in 0..s1.len() {
            for j in 0..s2.len() {
                // (i + 1) + (j + 1) - 1 = i + j + 1
                let bi = dp[i][j+1] && s3.chars().nth(i+j+1) == s1.chars().nth(i);
                let bj = dp[i+1][j] && s3.chars().nth(i+j+1) == s2.chars().nth(j);
                dp[i+1][j+1] = bi || bj;
            }
        }
        return dp[s1.len()][s2.len()];
    }
}

fn main() {
    let (s1, s2, s3) = (String::from("aabcc"), String::from("dbbca"), String::from("aadbbcbcac"));
    assert!(Solution::is_interleave(s1, s2, s3));

    let (s1, s2, s3) = (String::from("aabcc"), String::from("dbbca"), String::from("aadbbbaccc"));
    assert!(!Solution::is_interleave(s1, s2, s3));
}
