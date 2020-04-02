struct Solution;

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut num: i32 = n;
        while num != 1 {
            if num == 0 || num == 4 { return false; }
            let mut sum: i32 = 0;
            while num != 0 {
                let val: i32 = num % 10;
                sum += val * val;
                num /= 10;
            }
            num = sum;
        }
        return true;
    }
}

fn main() {
    assert!(Solution::is_happy(19));
    assert!(!Solution::is_happy(0));
    assert!(Solution::is_happy(1));
    // 2 -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4
    assert!(!Solution::is_happy(2));
    // 3 -> 9 -> 81 -> 65 -> 61 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4
    assert!(!Solution::is_happy(3));
    assert!(!Solution::is_happy(4));
    // 5 -> 25 -> 29 -> 85 -> 89 -> 145 -> 42 -> 20 -> 4
    assert!(!Solution::is_happy(5));
    // 6 -> 36 -> 45 -> 41 -> 17 -> 50 -> 25 -> ...
    assert!(!Solution::is_happy(6));
    // 7 -> 49 -> 97 -> 130 -> 10 -> 1
    assert!(Solution::is_happy(7));
    // 8 -> 64 -> 52 -> 29 -> 85 -> 89 -> 145 -> 42 -> 20 -> 4
    assert!(!Solution::is_happy(8));
    // 9 -> 81 -> 65 -> 61 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4
    assert!(!Solution::is_happy(9));
    assert!(Solution::is_happy(10));
}
