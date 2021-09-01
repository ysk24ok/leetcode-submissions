use std::cmp;

struct Solution;

impl Solution {
    pub fn array_nesting(nums: Vec<i32>) -> i32 {
        let mut visited = vec![false; nums.len()];
        let mut ret = 0;
        for mut idx in 0_usize..nums.len() {
            let mut length = 0;
            while !visited[idx] {
                visited[idx] = true;
                length += 1;
                idx = nums[idx] as usize;
            }
            ret = cmp::max(length, ret);
        }
        return ret;
    }
}

fn main() {
    let (nums, expected) = (vec![5, 4, 0, 3, 1, 6, 2], 4);
    assert_eq!(Solution::array_nesting(nums), expected);

    let (nums, expected) = (vec![0, 1, 2], 1);
    assert_eq!(Solution::array_nesting(nums), expected);
}
