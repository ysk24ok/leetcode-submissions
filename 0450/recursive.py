# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if root is None:
            return root
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        else:  # key == root.val
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            node = self.findMinNode(root.right)
            root.val = node.val
            root.right = self.deleteNode(root.right, root.val)
        return root

    def findMinNode(self, node):
        while node.left is not None:
            node = node.left
        return node


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(7)
    key = 3
    got = sol.deleteNode(root, key)
    assert got.val == 5
    assert got.left.val == 4
    assert got.right.val == 6
    assert got.left.left.val == 2
    assert got.right.right.val == 7

    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(7)
    key = 0
    got = sol.deleteNode(root, key)
    assert got.val == 5
    assert got.left.val == 3
    assert got.right.val == 6
    assert got.left.left.val == 2
    assert got.left.right.val == 4
    assert got.right.right.val == 7
