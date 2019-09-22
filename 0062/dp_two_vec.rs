// memory complexity: O(2m)
struct Solution;

impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let um: usize = m as usize;
        let un: usize = n as usize;
        let mut prev = Vec::with_capacity(um);
        let mut curr = Vec::with_capacity(um);
        for _ in 0..um {
            prev.push(1);
            curr.push(1);
        }
        for _ in 1..un {
            for i in 1..um {
                curr[i] = curr[i-1] + prev[i];
            }
            // swap vector
            let tmp = prev;
            prev = curr;
            curr = tmp;
        }
        return prev[um-1];
    }
}

fn main() {
    assert_eq!(Solution::unique_paths(1, 1), 1);
    assert_eq!(Solution::unique_paths(1, 2), 1);
    assert_eq!(Solution::unique_paths(2, 1), 1);
    assert_eq!(Solution::unique_paths(3, 2), 3);
    assert_eq!(Solution::unique_paths(7, 3), 28);
}
