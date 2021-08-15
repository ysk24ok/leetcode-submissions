struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() == 0 {
            return 0;
        }
        let mut left: usize = 0;
        for right in 0..nums.len() {
            if nums[left] == nums[right] {
                continue;
            }
            left += 1;
            nums[left] = nums[right];
        }
        let left: i32 = left as i32;
        return left + 1;
    }
}

fn main() {
    let (mut nums, expected_nums, expected_ret) = (vec![1, 1, 2], vec![1, 2, 2], 2);
    assert_eq!(Solution::remove_duplicates(&mut nums), expected_ret);
    assert_eq!(nums, expected_nums);

    let mut nums = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
    let expected_nums = vec![0, 1, 2, 3, 4, 2, 2, 3, 3, 4];
    let expected_ret = 5;
    assert_eq!(Solution::remove_duplicates(&mut nums), expected_ret);
    assert_eq!(nums, expected_nums);

    let (mut nums, expected_nums, expected_ret) = (vec![], vec![], 0);
    assert_eq!(Solution::remove_duplicates(&mut nums), expected_ret);
    assert_eq!(nums, expected_nums);

    let (mut nums, expected_nums, expected_ret) = (vec![1], vec![1], 1);
    assert_eq!(Solution::remove_duplicates(&mut nums), expected_ret);
    assert_eq!(nums, expected_nums);
}
