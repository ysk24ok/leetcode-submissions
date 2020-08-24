from collections import deque

from leetcode.tree import String2Tree, TreeNode


class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        ret = 0
        if root is None:
            return ret
        q = deque()
        q.append((root, False))
        while len(q) > 0:
            node, is_left = q.popleft()
            if node.left is None and node.right is None and is_left:
                ret += node.val
                continue
            if node.left is not None:
                q.append((node.left, True))
            if node.right is not None:
                q.append((node.right, False))
        return ret


if __name__ == '__main__':
    sol = Solution()

    #   3
    #  / \
    # 9  20
    #   /  \
    #  15   7
    root = String2Tree("3 9 20 # # 15 7")
    expected = 24
    assert sol.sumOfLeftLeaves(root) == expected

    #     3
    #    / \
    #   9  20
    #  /  /  \
    # 10 15   7
    root = String2Tree("3 9 20 10 # 15 7")
    expected = 25
    assert sol.sumOfLeftLeaves(root) == expected

    root = String2Tree("3")
    expected = 0
    assert sol.sumOfLeftLeaves(root) == expected

    root = None
    expected = 0
    assert sol.sumOfLeftLeaves(root) == expected
