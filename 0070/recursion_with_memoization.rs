struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut cache = vec![-1; n as usize + 1];
        return Solution::recursion(n, &mut cache);
    }

    fn recursion(n: i32, cache: &mut Vec<i32>) -> i32 {
        if n == 0 {
            return 1;
        } else if n < 0 {
            return 0;
        }
        let n_as_usize = n as usize;
        if cache[n_as_usize] != -1 {
            return cache[n_as_usize];
        }
        cache[n_as_usize] = Solution::recursion(n - 1, cache) + Solution::recursion(n - 2, cache);
        return cache[n_as_usize];
    }
}

fn main() {
    let (n, expected) = (2, 2);
    assert_eq!(Solution::climb_stairs(n), expected);

    let (n, expected) = (3, 3);
    assert_eq!(Solution::climb_stairs(n), expected);

    let (n, expected) = (1, 1);
    assert_eq!(Solution::climb_stairs(n), expected);
}
