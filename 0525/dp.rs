use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn find_max_length(nums: Vec<i32>) -> i32 {
        let mut ret: i32 = 0;
        let mut val: i32 = 0;
        let mut hashmap = HashMap::new();
        hashmap.insert(val, -1);
        for idx in 0..nums.len() {
            if nums[idx] == 1 {
                val += 1;
            } else {
                val -= 1;
            }
            hashmap.entry(val).or_insert(idx as i32);
            match hashmap.get(&val) {
                Some(&prev_idx) => { ret = std::cmp::max(ret, idx as i32 - prev_idx as i32); }
                None => {}
            }
        }
        return ret;
    }
}

fn main() {
    let mut nums: Vec<i32>;

    nums = vec![0, 1];
    assert!(Solution::find_max_length(nums) == 2);

    nums = vec![0, 1, 0];
    assert!(Solution::find_max_length(nums) == 2);

    nums = vec![];
    assert!(Solution::find_max_length(nums) == 0);

    nums = vec![0, 1, 0, 0, 1, 0];
    assert!(Solution::find_max_length(nums) == 4);
}
