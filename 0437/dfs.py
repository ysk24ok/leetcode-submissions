from collections import defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.ret = 0

    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.ret = 0
        self.recursion(root, sum)
        return self.ret

    def recursion(self, node, sum):
        new_paths = defaultdict(int)
        if not node:
            return new_paths
        paths = self.recursion(node.left, sum)
        for prev_sum, count in paths.items():
            new_paths[prev_sum + node.val] += count
        paths = self.recursion(node.right, sum)
        for prev_sum, count in paths.items():
            new_paths[prev_sum + node.val] += count
        new_paths[node.val] += 1
        self.ret += new_paths[sum]
        return new_paths


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(10)
    root.left = TreeNode(5)
    root.left.left = TreeNode(3)
    root.left.left.left = TreeNode(3)
    root.left.left.right = TreeNode(-2)
    root.left.right = TreeNode(2)
    root.left.right.right = TreeNode(1)
    root.right = TreeNode(-3)
    root.right.right = TreeNode(11)
    assert sol.pathSum(root, 8) == 3

    root = TreeNode(1)
    assert sol.pathSum(root, 1) == 1
