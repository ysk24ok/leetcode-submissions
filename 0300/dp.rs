struct Solution;

// dp[i] is the length of longest increasing substring
// of all increasing substring whose last element is nums[i]
//  nums: [4, 2, 3, 1, 5]
//  dp:   [1, 1, 2, 1, 3]
// time complexity: O(n^2)
// space complexity: O(n)
impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let size: usize = nums.len();
        if size == 0 { return 0; }
        let mut ret: i32 = 1;
        let mut dp: Vec<i32> = vec![1; size];
        for idx in 1..size {
            for subidx in 0..idx {
                if nums[subidx] >= nums[idx] { continue; }
                dp[idx] = std::cmp::max(dp[subidx] + 1, dp[idx]);
            }
            ret = std::cmp::max(ret, dp[idx]);
        }
        return ret;
    }
}

fn main() {
    let mut nums;

    nums = vec![4];
    assert!(Solution::length_of_lis(nums) == 1);

    nums = vec![2,2];
    assert!(Solution::length_of_lis(nums) == 1);

    nums = vec![4,2,3,1,5];
    assert!(Solution::length_of_lis(nums) == 3);

    nums = vec![10,9,2,5,3,7,101,18];
    assert!(Solution::length_of_lis(nums) == 4);
}
