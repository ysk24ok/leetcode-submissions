use std::cmp;

struct Solution;

/**
 * arr     = [9, 4, 2,10, 7, 8, 8, 1, 9]
 * dp_up   = [1, 1, 1, 3, 1, 5, 1, 1, 3]
 * dp_down = [1, 2, 2, 1, 4, 1, 1, 2, 1]
 * 
 * dp_up[k] = if (arr[k - 1] < arr[k]) dp_down[k-1] + 1 else 1
 * dp_down[k] = if (arr[k - 1] > arr[k]) dp_up[k-1] + 1 else 1
 */
*/
impl Solution {
    pub fn max_turbulence_size(arr: Vec<i32>) -> i32 {
        let (mut dp_down, mut dp_up) = (vec![1; arr.len()], vec![1; arr.len()]);
        let mut ret = 1;
        for k in 1..arr.len() {
            if arr[k - 1] < arr[k] {
                dp_up[k] = dp_down[k-1] + 1;
                ret = cmp::max(dp_up[k], ret);
            } else if arr[k - 1] > arr[k] {
                dp_down[k] = dp_up[k-1] + 1;
                ret = cmp::max(dp_down[k], ret);
            }

        }
        return ret;
    }
}

fn main() {
    let (arr, expected) = (vec![9, 4, 2, 10, 7, 8, 8, 1, 9], 5);
    assert_eq!(Solution::max_turbulence_size(arr), expected);

    let (arr, expected) = (vec![4, 8, 12, 16], 2);
    assert_eq!(Solution::max_turbulence_size(arr), expected);

    let (arr, expected) = (vec![100], 1);
    assert_eq!(Solution::max_turbulence_size(arr), expected);
}
