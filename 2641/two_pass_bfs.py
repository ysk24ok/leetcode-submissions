from collections import deque
from typing import *

from leetcode.tree import String2Tree, TreeNode

class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = deque()
        q.append((root, 1))
        level_sum = []
        while len(q) > 0:
            node, level = q.popleft()
            if len(level_sum) != level:
                level_sum.append(node.val)
            else:
                level_sum[level-1] += node.val
            if node.left is not None:
                q.append((node.left, level+1))
            if node.right is not None:
                q.append((node.right, level+1))

        q.append((root, 1))
        while len(q) > 0:
            node, level = q.popleft()
            children_vals_sum = 0
            if node.left is not None:
                q.append((node.left, level+1))
                children_vals_sum += node.left.val
            if node.right is not None:
                q.append((node.right, level+1))
                children_vals_sum += node.right.val
            if node.left is not None:
                node.left.val = level_sum[level] - children_vals_sum
            if node.right is not None:
                node.right.val = level_sum[level] - children_vals_sum
        root.val = 0
        return root


if __name__ == '__main__':
    sol = Solution()

    root = String2Tree("5 4 9 1 10 # 7")
    root = sol.replaceValueInTree(root)
    assert root.val == 0
    assert root.left.val == 0
    assert root.right.val == 0
    assert root.left.left.val == 7
    assert root.left.right.val == 7
    assert root.right.right.val == 11

    root = String2Tree("3 1 2")
    root = sol.replaceValueInTree(root)
    assert root.val == 0
    assert root.left.val == 0
    assert root.right.val == 0
