from leetcode.tree import String2Tree, TreeNode


class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return self.recursion(root, False)

    def recursion(self, node, is_left):
        if node.left is None and node.right is None:
            return node.val if is_left else 0
        ret = 0
        if node.left is not None:
            ret += self.recursion(node.left, True)
        if node.right is not None:
            ret += self.recursion(node.right, False)
        return ret


if __name__ == '__main__':
    sol = Solution()

    #   3
    #  / \
    # 9  20
    #   /  \
    #  15   7
    root = String2Tree("3 9 20 # # 15 7")
    expected = 24
    assert sol.sumOfLeftLeaves(root) == expected

    #     3
    #    / \
    #   9  20
    #  /  /  \
    # 10 15   7
    root = String2Tree("3 9 20 10 # 15 7")
    expected = 25
    assert sol.sumOfLeftLeaves(root) == expected

    root = String2Tree("3")
    expected = 0
    assert sol.sumOfLeftLeaves(root) == expected

    root = None
    expected = 0
    assert sol.sumOfLeftLeaves(root) == expected
