struct Solution {}

impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        // 1 4 5 2 3 -> 1 4 5 3 2
        // 1 4 5 3 2 -> 1 5 2 3 4
        // index whose value is bigger than the right one
        let mut last_idx = 0;
        for idx in 1..nums.len() {
            if nums[idx-1] < nums[idx] {
                last_idx = idx;
            }
        }
        // 5 4 3 2 1 -> 1 2 3 4 5
        if (last_idx == 0) {
            Solution::reverse(nums, 0);
            return;
        }
        /*
        if last_idx == nums.len() - 1 {
            Solution::swap(nums, last_idx - 1, last_idx);
        }
        */
        // 1 4 5 2 3
        // 1 4 5 3 2 -> 1 5 2 3 4
        let idx_to_swap = last_idx - 1;
        let mut second_idx_to_swap = last_idx;
        for idx in last_idx..nums.len()-1 {
            if nums[last_idx] < nums[idx] {
                break;
            }
            second_idx_to_swap = idx;
        }
    }

    pub fn swap(nums: &mut Vec<i32>, i: usize, j: usize) {
        let tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    pub fn reverse(nums: &mut Vec<i32>, i: usize) {
        let mut start_idx = i;
        let mut end_idx = nums.len() - 1;
        while start_idx < end_idx {
            Solution::swap(nums, start_idx, end_idx);
            start_idx++;
            end_idx--;
        }
    }
}

fn main() {
    let mut v: Vec<i32> = vec![1, 2, 3, 4, 5];
    Solution::next_permutation(&mut v);
    assert_eq!(v, [1, 2, 3, 5, 4]);

    v = vec![1, 2, 3, 5, 4];
    Solution::next_permutation(&mut v);
    assert_eq!(v, [1, 2, 4, 3, 5]);

    v = vec![1, 2, 4, 5, 3];
    Solution::next_permutation(&mut v);
    assert_eq!(v, [1, 2, 5, 3, 4]);

    v = vec![1, 4, 5, 3, 2];
    Solution::next_permutation(&mut v);
    assert_eq!(v, [1, 5, 2, 3, 4]);

    v = vec![1, 5, 4, 3, 2];
    Solution::next_permutation(&mut v);
    assert_eq!(v, [2, 1, 3, 4, 5]);
}
