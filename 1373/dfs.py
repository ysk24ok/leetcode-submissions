# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        self.ret = - 2 ** 31
        self.recursion(root, -4 * 10 ** 4, 4 * 10 ** 4)
        if self.ret < 0:
            return 0
        print(self.ret)
        return self.ret

    def recursion(self, node, minval, maxval):
        ret = node.val
        valid = True
        val_left = 0
        val_right = 0
        if node.left is not None:
            left = self.recursion(node.left, minval, node.val)
            if left is not None:
                val_left = left
            else:
                valid = False
        if node.right is not None:
            right = self.recursion(node.right, node.val, maxval)
            if right is not None:
                val_right = right
            else:
                valid = False
        # when either left of right subtree is invalid,
        # the whole tree is invalid
        if valid is False:
            return None
        if node.val < minval or maxval < node.val:
            valid = False
        print(node.val, ret, minval, maxval)
        ret += val_left + val_right
        self.ret = max(self.ret, ret)
        return ret if valid else None


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(1)
    root.left = TreeNode(4)
    root.right = TreeNode(3)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(2)
    root.right.right = TreeNode(5)
    root.right.right.left = TreeNode(4)
    root.right.right.right = TreeNode(6)
    expected = 20
    assert sol.maxSumBST(root) == expected

    #       4
    #      /
    #     3
    #    / \
    #   1   2
    root = TreeNode(4)
    root.left = TreeNode(3)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(2)
    expected = 2
    assert sol.maxSumBST(root) == expected

    root = TreeNode(-4)
    root.left = TreeNode(-2)
    root.right = TreeNode(-5)
    expected = 0
    assert sol.maxSumBST(root) == expected

    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    expected = 6
    assert sol.maxSumBST(root) == expected

    #        8
    #       / \
    #      9   8
    #       \   \
    #        9   1
    #           / \
    #          -3  5
    #           \   \
    #            -2  6
    root = TreeNode(8)
    root.left = TreeNode(9)
    root.right = TreeNode(8)
    root.left.right = TreeNode(9)
    root.right.right = TreeNode(1)
    root.right.right.left = TreeNode(-3)
    root.right.right.right = TreeNode(5)
    root.right.right.left.right = TreeNode(-2)
    root.right.right.right.right = TreeNode(6)
    expected = 11
    assert sol.maxSumBST(root) == expected

    #     1
    #      \
    #       10
    #      /  \
    #     -5   20
    root = TreeNode(1)
    root.right = TreeNode(10)
    root.right.left = TreeNode(-5)
    root.right.right = TreeNode(20)
    expected = 25
    assert sol.maxSumBST(root) == expected
