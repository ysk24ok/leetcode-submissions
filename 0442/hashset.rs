use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn find_duplicates(nums: Vec<i32>) -> Vec<i32> {
        let mut set = HashSet::new();
        let mut ret = Vec::new();
        for num in nums {
            if set.contains(&num) {
                ret.push(num);
            } else {
                set.insert(num);
            }
        }
        return ret;
    }
}

fn main() {
    let (nums, expected) = (vec![4, 3, 2, 7, 8, 2, 3, 1], vec![2, 3]);
    assert_eq!(Solution::find_duplicates(nums), expected);

    let (nums, expected) = (vec![1, 1, 2], vec![1]);
    assert_eq!(Solution::find_duplicates(nums), expected);

    let (nums, expected) = (vec![1], vec![]);
    assert_eq!(Solution::find_duplicates(nums), expected);
}
