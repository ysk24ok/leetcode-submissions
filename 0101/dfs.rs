use std::rc::Rc;
use std::cell::RefCell;

use leetcode::{TreeNode, create_treenode};

struct Solution;

impl Solution {
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if root.is_none() {
            return false;
        }
        let root_ref = root.as_ref().unwrap().borrow();
        return Solution::recursive(&root_ref.left, &root_ref.right);
    }

    fn recursive(left: &Option<Rc<RefCell<TreeNode>>>, right: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if (left.is_none() && right.is_some()) || (left.is_some() && right.is_none()) {
            return false;
        } else if left.is_none() && right.is_none() {
            return true;
        }
        let (left_ref, right_ref) = (left.as_ref().unwrap().borrow(), right.as_ref().unwrap().borrow());
        if left_ref.val != right_ref.val {
            return false;
        }
        return Solution::recursive(&left_ref.left, &right_ref.right) && Solution::recursive(&left_ref.right, &right_ref.left);
    }
}

fn main() {
    let (root, expected) = (create_treenode("1 2 2 3 4 4 3"), true);
    assert_eq!(Solution::is_symmetric(root), expected);

    let (root, expected) = (create_treenode("1 2 2 # 3 # 3"), false);
    assert_eq!(Solution::is_symmetric(root), expected);

    let (root, expected) = (create_treenode("2 3 3 4 5 5"), false);
    assert_eq!(Solution::is_symmetric(root), expected);
}
