struct Solution;

impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {
        let mut num: i64 = 0;
        let mut total: i64 = 0;
        let n_as_i64 = n as i64;
        while total <= n_as_i64 {
            num += 1;
            total += num;
        }
        return (num - 1) as i32;
    }
}

fn main() {
    let (n, expected) = (5, 2);
    assert_eq!(Solution::arrange_coins(n), expected);

    let (n, expected) = (8, 3);
    assert_eq!(Solution::arrange_coins(n), expected);

    let (n, expected) = (2147483647, 65535);
    assert_eq!(Solution::arrange_coins(n), expected);
}
