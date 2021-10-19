use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn next_greater_element(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::new();
        let mut map: HashMap<&i32, i32> = HashMap::new();
        let mut ret = Vec::with_capacity(nums1.len());
        for num in nums2.iter().rev() {
            while stack.len() > 0 && num >= stack.last().unwrap() {
                stack.pop();
            }
            if stack.len() > 0 {
                map.entry(num).or_insert(*stack.last().unwrap());
            } else {
                map.entry(num).or_insert(-1);
            }
            stack.push(*num);
        }
        for num in nums1 {
            ret.push(*map.get(&num).unwrap());
        }
        return ret;
    }
}

fn main() {
    let (nums1, nums2, expected) = (vec![4, 1, 2], vec![1, 3, 4, 2], vec![-1, 3, -1]);
    assert_eq!(Solution::next_greater_element(nums1, nums2), expected);

    let (nums1, nums2, expected) = (vec![2, 4], vec![1, 2, 3, 4], vec![3, -1]);
    assert_eq!(Solution::next_greater_element(nums1, nums2), expected);
}
