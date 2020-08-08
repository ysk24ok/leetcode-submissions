from collections import defaultdict, deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        ret = 0
        if not root:
            return 0
        q = deque()
        q.append((root, defaultdict(int)))
        while len(q) > 0:
            node, paths = q.popleft()
            new_paths = defaultdict(int)
            for prev_sum, count in paths.items():
                curr_sum = prev_sum + node.val
                new_paths[curr_sum] += count
            new_paths[node.val] += 1
            if sum in new_paths:
                ret += new_paths[sum]
            if node.left:
                q.append((node.left, new_paths))
            if node.right:
                q.append((node.right, new_paths))
        return ret


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
