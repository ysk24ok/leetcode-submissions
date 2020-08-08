from typing import List
from collections import deque, defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        q = deque()
        d = defaultdict(lambda: defaultdict(list))
        q.append((root, 0, 0))
        min_x, max_x = 2 ** 31 - 1, - 2 ** 31
        min_y, max_y = 2 ** 31 - 1, - 2 ** 31
        while len(q) > 0:
            node, x, y = q.popleft()
            min_x = min(min_x, x)
            max_x = max(max_x, x)
            min_y = min(min_y, y)
            max_y = max(max_y, y)
            d[x][y].append(node.val)
            if node.left:
                q.append((node.left, x-1, y-1))
            if node.right:
                q.append((node.right, x+1, y-1))
        ret = []
        for x in range(min_x, max_x+1):
            if x not in d:
                continue
            subret = []
            for y in reversed(range(min_y, max_y+1)):
                if y not in d[x]:
                    continue
                subret.extend(sorted(d[x][y]))
            ret.append(subret)
        return ret


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    expected = [[9], [3, 15], [20], [7]]
    assert sol.verticalTraversal(root) == expected
