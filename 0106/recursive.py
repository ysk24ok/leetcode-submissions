from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        return self.recursive(inorder, 0, len(inorder)-1,
                              postorder, 0, len(postorder)-1)

    def recursive(self, inorder, inorder_start, inorder_end,
                  postorder, postorder_start, postorder_end):
        if inorder_start > inorder_end or postorder_start > postorder_end:
            return None
        node = TreeNode(postorder[postorder_end])
        idx = inorder.index(node.val)
        if idx > inorder_start:
            inorder_left_end = idx - 1
            postorder_left_end = postorder_start + (inorder_left_end - inorder_start)
            node.left = self.recursive(inorder, inorder_start, inorder_left_end,
                                       postorder, postorder_start, postorder_left_end)
        if idx < inorder_end:
            inorder_right_start = idx + 1
            postorder_right_end = postorder_end - 1
            postorder_right_start = postorder_right_end - (inorder_end - inorder_right_start)
            node.right = self.recursive(inorder, inorder_right_start, inorder_end,
                                        postorder, postorder_right_start, postorder_right_end)
        return node


if __name__ == '__main__':
    sol = Solution()

    #     3
    #    / \
    #   9  20
    #     /  \
    #    15   7
    inorder, postorder = [9, 3, 15, 20, 7], [9, 15, 7, 20, 3]
    got = sol.buildTree(inorder, postorder)
    assert got.val == 3
    assert got.left.val == 9
    assert got.left.left is None
    assert got.left.right is None
    assert got.right.val == 20
    assert got.right.left.val == 15
    assert got.right.right.val == 7
    assert got.right.left.left is None
    assert got.right.left.right is None
    assert got.right.right.left is None
    assert got.right.right.right is None

    #  1
    #   \
    #    2
    inorder, postorder = [1, 2], [2, 1]
    got = sol.buildTree(inorder, postorder)
    assert got.val == 1
    assert got.left is None
    assert got.right.val == 2
    assert got.right.left is None
    assert got.right.right is None

    #   1
    #  /
    # 2
    inorder, postorder = [2, 1], [2, 1]
    got = sol.buildTree(inorder, postorder)
    assert got.val == 1
    assert got.left.val == 2
    assert got.right is None
    assert got.left.left is None
    assert got.left.right is None

    #     1
    #    /
    #   2
    #    \
    #     3
    inorder, postorder = [2, 3, 1], [3, 2, 1]
    got = sol.buildTree(inorder, postorder)
    assert got.val == 1
    assert got.left.val == 2
    assert got.right is None
    assert got.left.left is None
    assert got.left.right.val == 3
    assert got.left.right.left is None
    assert got.left.right.right is None
