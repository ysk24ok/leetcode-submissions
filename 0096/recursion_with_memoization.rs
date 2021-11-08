use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let mut memo: HashMap<i32, i32> = HashMap::new();
        memo.entry(0).or_insert(1);
        memo.entry(1).or_insert(1);
        return Solution::recursion(n, &mut memo);
    }

    fn recursion(n: i32, memo: &mut HashMap<i32, i32>) -> i32 {
        match memo.get(&n) {
            Some(num) => return *num,
            None => {}
        }
        let mut ret = 0;
        for i in 0..n {
            let num_left = Solution::recursion(i, memo);
            let num_right = Solution::recursion(n - i - 1, memo);
            ret += num_left * num_right;
        }
        memo.entry(n).or_insert(ret);
        return ret;
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
