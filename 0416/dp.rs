struct Solution;

impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let sum: i32 = nums.iter().sum();
        if sum % 2 == 1 { return false; }
        let half_sum = sum / 2;
        let half_sum_idx = half_sum as usize;
        let mut dp: Vec<bool>= vec![false; half_sum_idx+1];
        dp[0] = true;
        for num in nums {
            let num_idx = num as usize;
            for i in (num_idx..half_sum_idx+1).rev() {
                dp[i] = dp[i] || dp[i-num_idx];
            }
        }
        return dp[half_sum_idx];
    }
}

fn main() {
    let mut nums: Vec<i32>;

    nums = vec![1,5,11,5];
    assert!(Solution::can_partition(nums));

    nums = vec![1,2,3,5];
    assert!(!Solution::can_partition(nums));

    nums = vec![1,2,3,8];
    assert!(!Solution::can_partition(nums));
}
