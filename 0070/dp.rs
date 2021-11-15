struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n == 1 {
            return n;
        }
        let (mut two_steps_below, mut one_step_below) = (1, 2);
        for _ in 3..(n + 1) as usize {
            let current = two_steps_below + one_step_below;
            two_steps_below = one_step_below;
            one_step_below = current;
        }
        return one_step_below;
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
