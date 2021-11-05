struct Solution;

impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {
        let (mut ok, mut ng): (i64, i64) = (0, n as i64 + 1);
        while ok + 1 < ng {
            let mid = (ng - ok) / 2 + ok;
            let total = (1 + mid) * mid / 2;
            if total <= n as i64 {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok as i32;
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
