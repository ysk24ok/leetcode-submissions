struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        if nums.len() == 0 { return 0; }
        let mut dp: Vec<i32> = vec![0; nums.len()];
        dp[0] = nums[0];
        let mut max: i32 = nums[0];
        for idx in 1..nums.len() {
            if dp[idx-1] > 0 { dp[idx] = dp[idx-1]; }
            dp[idx] += nums[idx];
            max = std::cmp::max(max, dp[idx]);
        }
        return max;
    }
}

fn main() {
    let mut nums;

    nums = vec![-2,1,-3,4,-1,2,1,-5,4];
    assert!(Solution::max_sub_array(nums) == 6);

    nums = vec![-2,1,0,-1,2];
    assert!(Solution::max_sub_array(nums) == 2);

    nums = vec![];
    assert!(Solution::max_sub_array(nums) == 0);
}
