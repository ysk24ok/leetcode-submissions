use std::cmp;

struct Solution;

impl Solution {
    pub fn max_count(m: i32, n: i32, ops: Vec<Vec<i32>>) -> i32 {
        let (mut a, mut b): (i32, i32) = (m, n);
        for op in ops {
          a = cmp::min(op[0], a);
          b = cmp::min(op[1], b);
        }
        return a * b;
    }
}

fn main() {
    let (m, n, ops, expected) = (3, 3, vec!{vec!{2, 2}, vec!{3, 3}}, 4);
    assert_eq!(Solution::max_count(m, n, ops), expected);

    let (m, n, ops, expected) = (3, 3, vec!{}, 9);
    assert_eq!(Solution::max_count(m, n, ops), expected);
}
