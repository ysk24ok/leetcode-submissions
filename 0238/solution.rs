struct Solution;

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n: usize = nums.len();
        let mut ret: Vec<i32> = vec![1; n];
        for idx in 1..n {
            ret[idx] = ret[idx-1] * nums[idx-1];
        }
        let mut right = 1;
        for idx in (1..n).rev() {
            right *= nums[idx];
            ret[idx-1] *= right;
        }
        return ret;
    }
}

fn main() {
    let nums: Vec<i32> = vec![1,2,3,4];
    let got: Vec<i32> = Solution::product_except_self(nums);
    let expected: Vec<i32> = vec![24,12,8,6];
    for idx in 0..4 {
        assert_eq!(got[idx], expected[idx]);
    }
}
