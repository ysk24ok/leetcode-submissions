use std::collections::HashMap;
use std::collections::hash_map::Entry::{Occupied, Vacant};

struct Solution;

impl Solution {
    pub fn fib(n: i32) -> i32 {
        let mut map = HashMap::new();
        map.entry(0).or_insert(0);
        map.entry(1).or_insert(1);
        return Solution::recursion(n, &mut map);
    }

    fn recursion(n: i32, map: &mut HashMap<i32, i32>) -> i32 {
        match map.entry(n) {
            Vacant(_) => Solution::recursion(n - 1, map) + Solution::recursion(n - 2, map),
            Occupied(entry) => *entry.get()
        }
    }
}

fn main() {
    assert_eq!(Solution::fib(0), 0);
    assert_eq!(Solution::fib(1), 1);
    assert_eq!(Solution::fib(2), 1);
    assert_eq!(Solution::fib(3), 2);
    assert_eq!(Solution::fib(4), 3);
}
