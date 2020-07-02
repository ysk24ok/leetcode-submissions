from queue import Queue
from typing import *


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        q = Queue()
        ret = []
        if root is None:
            return ret
        q.put((root, 0))
        while not q.empty():
            node, level = q.get()
            if len(ret) <= level:
                ret.insert(0, [node.val])
            else:
                ret[-1-level].append(node.val)
            if node.left is not None:
                q.put((node.left, level+1))
            if node.right is not None:
                q.put((node.right, level + 1))
        return ret


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    assert sol.levelOrderBottom(root) == [[15,7],[9,20],[3]]

    assert sol.levelOrderBottom(None) == []
