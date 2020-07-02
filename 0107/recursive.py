from typing import *


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ret = []
        self.dfs(root, 0, ret)
        return ret

    def dfs(self, node, level, ret):
        if node is None:
            return
        if level >= len(ret):
            ret.insert(0, [node.val])
        else:
            ret[-1-level].append(node.val)
        self.dfs(node.left, level+1, ret)
        self.dfs(node.right, level+1, ret)


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    assert sol.levelOrderBottom(root) == [[15,7],[9,20],[3]]

    assert sol.levelOrderBottom(None) == []
