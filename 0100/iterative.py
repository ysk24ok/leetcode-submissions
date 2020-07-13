from typing import *


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        que = []
        que.append((p, q))
        while len(que) > 0:
            p, q = que.pop(0)
            if p is None and q is None:
                continue
            elif (p is None and q is not None) or (p is not None and q is None):
                return False
            if p.val != q.val:
                return False
            que.append((p.left, q.left))
            que.append((p.right, q.right))
        return True


if __name__ == '__main__':
    sol = Solution()

    p = TreeNode(1)
    p.left = TreeNode(2)
    p.right = TreeNode(3)
    q = TreeNode(1)
    q.left = TreeNode(2)
    q.right = TreeNode(3)
    assert sol.isSameTree(p, q)

    p = TreeNode(1)
    p.left = TreeNode(2)
    q = TreeNode(1)
    q.right = TreeNode(2)
    assert not sol.isSameTree(p, q)

    p = TreeNode(1)
    p.left = TreeNode(2)
    p.right = TreeNode(1)
    q = TreeNode(1)
    q.left = TreeNode(2)
    q.right = TreeNode(1)
    assert sol.isSameTree(p, q)
