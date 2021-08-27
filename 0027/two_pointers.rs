struct Solution;

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        if nums.len() == 0 {
            return 0;
        }
        let (mut left, mut right): (usize, usize) = (0, nums.len() - 1);
        while left < right {
            if nums[left] == val {
                nums.swap(left, right);
                right -= 1;
            } else {
                left += 1;
            }
        }
        let ret = left as i32;
        if nums[left] != val {
            return ret + 1;
        } else {
            return ret;
        }
    }
}

fn main() {
    let mut nums: Vec<i32>;
    let mut nums_expected: Vec<i32>;
    let mut val: i32;
    let mut expected: i32;

    nums = vec!{3, 2, 2, 3};
    val = 3;
    expected = 2;
    nums_expected = vec!{2, 2, 3, 3};
    assert_eq!(Solution::remove_element(&mut nums, val), expected);
    assert_eq!(nums, nums_expected);

    nums = vec!{0, 1, 2, 2, 3, 0, 4, 2};
    val = 2;
    expected = 5;
    nums_expected = vec!{0, 1, 4, 0, 3, 2, 2, 2};
    assert_eq!(Solution::remove_element(&mut nums, val), expected);
    assert_eq!(nums, nums_expected);

    nums = vec!{};
    val = 0;
    expected = 0;
    assert_eq!(Solution::remove_element(&mut nums, val), expected);

    nums = vec!{1};
    val = 1;
    expected = 0;
    nums_expected = vec!{1};
    assert_eq!(Solution::remove_element(&mut nums, val), expected);
    assert_eq!(nums, nums_expected);
}
