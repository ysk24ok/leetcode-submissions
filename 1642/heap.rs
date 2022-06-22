use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct Solution;

impl Solution {
    pub fn furthest_building(heights: Vec<i32>, bricks: i32, ladders: i32) -> i32 {
        let mut heap = BinaryHeap::new();
        let mut current_bricks = bricks;
        for idx in 0..heights.len()-1 {
            let diff = heights[idx + 1] - heights[idx];
            if diff <= 0 {
                continue;
            }
            heap.push(Reverse(diff));
            if heap.len() > ladders as usize {
                current_bricks -= heap.pop().unwrap().0;
                if current_bricks < 0 {
                    return idx as i32;
                }
            }
        }
        return (heights.len() - 1) as i32;
    }
}

fn main() {
    let (heights, bricks, ladders, expected) = (vec![4, 2, 7, 6, 9, 14, 12], 5, 1, 4);
    assert_eq!(Solution::furthest_building(heights, bricks, ladders), expected);

    let (heights, bricks, ladders, expected) = (vec![4, 12, 2, 7, 3, 18, 20, 3, 19], 10, 2, 7);
    assert_eq!(Solution::furthest_building(heights, bricks, ladders), expected);

    let (heights, bricks, ladders, expected) = (vec![14, 3, 19, 3], 17, 0, 3);
    assert_eq!(Solution::furthest_building(heights, bricks, ladders), expected);
}
