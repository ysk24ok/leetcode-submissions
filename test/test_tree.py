from leetcode import String2Tree


def test_String2Tree():
    s = "1 2 3 4 5 6 7"
    got = String2Tree(s)
    assert got.val == 1
    assert got.left.val == 2
    assert got.right.val == 3
    assert got.left.left.val == 4
    assert got.left.right.val == 5
    assert got.right.left.val == 6
    assert got.right.right.val == 7
    assert got.left.left.left is None
    assert got.left.left.right is None
    assert got.left.right.left is None
    assert got.left.right.right is None
    assert got.right.left.left is None
    assert got.right.left.right is None
    assert got.right.right.left is None
    assert got.right.right.right is None


def test_String2Tree_either_left_or_right_node_does_not_exist():
    s = "3 # 20 6"
    got = String2Tree(s)
    assert got.val == 3
    assert got.left is None
    assert got.right.val == 20
    assert got.right.left.val == 6
    assert got.right.right is None
    assert got.right.left.left is None
    assert got.right.left.right is None


def test_String2Tree_both_left_right_nodes_do_not_exist():
    s = "3 9 20 # # 15 7"
    got = String2Tree(s)
    assert got.val == 3
    assert got.left.val == 9
    assert got.right.val == 20
    assert got.left.left is None
    assert got.left.right is None
    assert got.right.left.val == 15
    assert got.right.right.val == 7
    assert got.right.left.left is None
    assert got.right.left.right is None
    assert got.right.right.left is None
    assert got.right.right.right is None


def test_String2Tree_empty_string():
    s = ""
    got = String2Tree(s)
    assert got is None

    s = "    "
    got = String2Tree(s)
    assert got is None
