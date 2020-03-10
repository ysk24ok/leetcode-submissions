// TODO: TLE
struct Solution;

impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let sum: i32 = nums.iter().sum();
        if sum % 2 == 1 { return false; }
        let target: i32 = sum / 2;
        return Solution::recursion(&nums, 0, target);
    }

    pub fn recursion(nums: &Vec<i32>, idx: usize, target: i32) -> bool {
        if target == 0 {
            return true;
        } else if target < 0 {
            return false;
        } else if idx == nums.len() {
            return false;
        }
        return Solution::recursion(&nums, idx+1, target) ||
            Solution::recursion(&nums, idx+1, target - nums[idx]);
    }
}

fn main() {
    let mut nums: Vec<i32>;

    nums = vec![1,5,11,5];
    assert!(Solution::can_partition(nums));

    nums = vec![1,2,3,5];
    assert!(!Solution::can_partition(nums));
}
