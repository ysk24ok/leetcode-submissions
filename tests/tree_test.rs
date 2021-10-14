use std::rc::Rc;
use std::cell::RefCell;

use leetcode::{TreeNode, create_treenode, get_node_ref};

fn assert_node(
    node: &Option<Rc<RefCell<TreeNode>>>,
    expected_val: i32,
    has_left: bool,
    has_right: bool,
) {
    assert_eq!(node.is_some(), true);
    let node_ref = get_node_ref(&node);
    assert_eq!(node_ref.val, expected_val);
    assert_eq!(node_ref.left.is_some(), has_left);
    assert_eq!(node_ref.right.is_some(), has_right);
}

#[test]
fn test_create_treenode() {
    let root = create_treenode("10 100 1");
    assert_node(&root, 10, true, true);
    let root_ref = get_node_ref(&root);
    assert_node(&root_ref.left, 100, false, false);
    assert_node(&root_ref.right, 1, false, false);
}

#[test]
fn test_create_treenode_when_parent_node_does_not_have_left_node() {
    let root = create_treenode("10 # 100 1 10");
    assert_node(&root, 10, false, true);
    let root_ref = get_node_ref(&root);
    assert_node(&root_ref.right, 100, true, true);
    let right_ref = get_node_ref(&root_ref.right);
    assert_node(&right_ref.left, 1, false, false);
    assert_node(&right_ref.right, 10, false, false);
}

#[test]
fn test_create_treenode_when_parent_node_does_not_have_right_node() {
    let root = create_treenode("10 100 # 1 10");
    assert_node(&root, 10, true, false);
    let root_ref = get_node_ref(&root);
    assert_node(&root_ref.left, 100, true, true);
    let left_ref = get_node_ref(&root_ref.left);
    assert_node(&left_ref.left, 1, false, false);
    assert_node(&left_ref.right, 10, false, false);
}

#[test]
fn test_create_treenode_when_input_contains_irregular_whitespaces() {
    let root = create_treenode("  10    100  1    ");
    assert_node(&root, 10, true, true);
    let root_ref = get_node_ref(&root);
    assert_node(&root_ref.left, 100, false, false);
    assert_node(&root_ref.right, 1, false, false);
}

#[test]
fn test_create_treenode_when_input_is_empty() {
    let root = create_treenode("");
    assert_eq!(root.is_none(), true);
}
