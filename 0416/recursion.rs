struct Solution;

impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let sum: i32 = nums.iter().sum();
        if sum % 2 == 1 { return false; }
        let target: i32 = sum / 2;
        let target_usize : usize = target as usize;
        let mut dp: Vec<Vec<i32>> = vec![vec![-1; target_usize+1]; nums.len()];
        return Solution::recursion(&nums, 0, target, &mut dp);
    }

    pub fn recursion(nums: &Vec<i32>, idx: usize, target: i32, dp: &mut Vec<Vec<i32>>) -> bool {
        if target == 0 {
            return true;
        } else if target < 0 {
            return false;
        } else if idx == nums.len() {
            return false;
        }
        let target_usize : usize = target as usize;
        if dp[idx][target_usize] == 0 { return true; }
        else if dp[idx][target_usize] == 1 { return false; }
        let ret: bool = Solution::recursion(&nums, idx+1, target, dp) ||
            Solution::recursion(&nums, idx+1, target - nums[idx], dp);
        if ret { dp[idx][target_usize] = 0; }
        else { dp[idx][target_usize] = 1; }
        return ret;
    }
}

fn main() {
    let mut nums: Vec<i32>;

    nums = vec![1,5,11,5];
    assert!(Solution::can_partition(nums));

    nums = vec![1,2,3,5];
    assert!(!Solution::can_partition(nums));
}
