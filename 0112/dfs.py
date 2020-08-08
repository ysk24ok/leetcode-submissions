class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        return self.recursion(root, 0, sum)

    def recursion(self, node, prev_sum, sum):
        if not node:
            return False
        curr_sum = prev_sum + node.val
        if not node.left and not node.right and curr_sum == sum:
            return True
        return self.recursion(node.left, curr_sum, sum) or \
            self.recursion(node.right, curr_sum, sum)


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(5)
    root.left = TreeNode(4)
    root.left.left = TreeNode(11)
    root.left.left.left = TreeNode(7)
    root.left.left.right = TreeNode(2)
    root.right = TreeNode(8)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode(4)
    root.right.right.right = TreeNode(1)
    assert sol.hasPathSum(root, 22)
