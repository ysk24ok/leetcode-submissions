from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        q = deque()
        q.append((root, 0))
        while len(q) > 0:
            node, prev_sum = q.popleft()
            curr_sum = prev_sum + node.val
            if not node.left and not node.right and curr_sum == sum:
                return True
            if node.left:
                q.append((node.left, curr_sum))
            if node.right:
                q.append((node.right, curr_sum))
        return False


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
