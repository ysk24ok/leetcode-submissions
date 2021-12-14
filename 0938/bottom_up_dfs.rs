use std::rc::Rc;
use std::cell::RefCell;

use leetcode::{TreeNode, create_treenode};

struct Solution;

impl Solution {
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        return Solution::recursion(&root, low, high);
    }

    fn recursion(root: &Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        let mut sum = 0;
        if root.is_none() {
            return sum;
        }
        let root_ref = root.as_ref().unwrap().borrow();
        if low < root_ref.val {
            sum += Solution::recursion(&root_ref.left, low, high);
        }
        if root_ref.val < high {
            sum += Solution::recursion(&root_ref.right, low, high);
        }
        if low <= root_ref.val && root_ref.val <= high {
            sum += root_ref.val;
        }
        return sum;
    }
}

fn main() {
    /*         10
     *        /  \
     *       5    15
     *      / \     \
     *     3   7     18
     */
    let (root, low, high, expected) = (create_treenode("10 5 15 3 7 # 18"), 7, 15, 32);
    assert_eq!(Solution::range_sum_bst(root, low, high), expected);

    let (root, low, high, expected) = (create_treenode("10 5 15 3 7 13 18 1 # 6"), 6, 10, 23);
    assert_eq!(Solution::range_sum_bst(root, low, high), expected);
}
