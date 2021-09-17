use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut counts = HashMap::new();
        let mut ret = Vec::new();
        for num in nums1 {
            *counts.entry(num).or_insert(0) += 1;
        }
        for num in nums2 {
            let option = counts.get_mut(&num);
            if option.is_none() {
                continue;
            }
            let val = option.unwrap();
            if val > &mut 0 {
                *val -= 1;
                ret.push(num);
            }
        }
        return ret;
    }
}

fn main() {
    let (nums1, nums2, expected) = (vec![1, 2, 2, 1], vec![2, 2], vec![2, 2]);
    assert_eq!(Solution::intersect(nums1, nums2), expected);

    let (nums1, nums2, expected) = (vec![4, 9, 5], vec![9, 4, 9, 8, 4], vec![9, 4]);
    assert_eq!(Solution::intersect(nums1, nums2), expected);
}
