use std::collections::VecDeque;
use std::rc::Rc;
use std::cell::{Ref, RefCell};

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}


pub fn get_node_ref(node: &Option<Rc<RefCell<TreeNode>>>) -> Ref<TreeNode> {
  return node.as_ref().unwrap().borrow();
}

pub fn create_treenode(s: &str) -> Option<Rc<RefCell<TreeNode>>> {
    let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
    let mut iter = s.split_ascii_whitespace();
    let val = iter.next();
    if val.is_none() {
        return None;
    }
    let num = val.unwrap().to_string().parse::<i32>().unwrap();
    let root = Rc::new(RefCell::new(TreeNode::new(num)));
    queue.push_back(Rc::clone(&root));
    while queue.len() > 0 {
        let parent = queue.pop_front().unwrap();
        let val = iter.next();
        if val.is_some() && val.unwrap() != "#" {
            let num = val.unwrap().to_string().parse::<i32>().unwrap();
            let node = Rc::new(RefCell::new(TreeNode::new(num)));
            parent.borrow_mut().left = Some(Rc::clone(&node));
            queue.push_back(Rc::clone(&node));
        }
        let val = iter.next();
        if val.is_some() && val.unwrap() != "#" {
            let num = val.unwrap().to_string().parse::<i32>().unwrap();
            let node = Rc::new(RefCell::new(TreeNode::new(num)));
            parent.borrow_mut().right = Some(Rc::clone(&node));
            queue.push_back(Rc::clone(&node));
        }
    }
    return Some(root);
}
