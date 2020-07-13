from typing import *


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        return self.recursive(p, q)

    def recursive(self, p, q):
        if p is None:
            return True if q is None else False
        if q is None:
            return False
        if p.val != q.val:
            return False
        return self.recursive(p.left, q.left) and self.recursive(p.right, q.right)


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
