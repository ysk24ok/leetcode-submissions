from collections import deque
from typing import *


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        min_and_map = {}
        queue = deque()
        queue.append((root, 0, 1))
        while queue:
            node, level, idx = queue.popleft()
            if level not in min_and_map:
                min_and_map[level] = [float('inf'), 0]
            min_and_map[level][0] = min(idx, min_and_map[level][0])
            min_and_map[level][1] = max(idx, min_and_map[level][1])
            if node.left is not None:
                queue.append((node.left, level + 1, idx * 2))
            if node.right is not None:
                queue.append((node.right, level + 1, idx * 2 + 1))
        max_width = 0
        for min_val, max_val in min_and_map.values():
            max_width = max(max_width, max_val - min_val + 1)
        return max_width


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(2)
    root.left.left = TreeNode(5)
    root.left.right = TreeNode(3)
    root.right.right = TreeNode(9)
    assert sol.widthOfBinaryTree(root) == 4

    root = TreeNode(1)
    root.left = TreeNode(3)
    root.left.left = TreeNode(5)
    root.left.right = TreeNode(3)
    assert sol.widthOfBinaryTree(root) == 2

    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(2)
    root.left.left = TreeNode(5)
    assert sol.widthOfBinaryTree(root) == 2

    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(2)
    root.left.left = TreeNode(5)
    root.right.right = TreeNode(9)
    root.left.left.left = TreeNode(6)
    root.right.right.right = TreeNode(7)
    assert sol.widthOfBinaryTree(root) == 8
