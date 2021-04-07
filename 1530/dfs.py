from collections import defaultdict

from leetcode import TreeNode, String2Tree


class Solution:
    def __init__(self):
        self._ret = 0

    def countPairs(self, root: TreeNode, distance: int) -> int:
        self._ret = 0
        counts = self.dfs(root, distance)
        return self._ret

    def dfs(self, node, distance):
        if node is None:
            return {}
        # leaf node
        if node.left is None and node.right is None:
            return {1: 1}
        counts_left = self.dfs(node.left, distance)
        counts_right = self.dfs(node.right, distance)
        counts = defaultdict(int)
        for dist_left, count_left in counts_left.items():
            counts[dist_left+1] += count_left
        for dist_right, count_right in counts_right.items():
            counts[dist_right+1] += count_right
        for dist_left, count_left in counts_left.items():
            for dist_right, count_right in counts_right.items():
                dist = dist_left + dist_right
                if dist <= distance:
                    self._ret += count_left * count_right
        return counts


if __name__ == '__main__':
    sol = Solution()

    root, distance, expected = String2Tree("1 2 3 # 4"), 3, 1
    assert sol.countPairs(root, distance) == expected

    root, distance, expected = String2Tree("1 2 3 4 5 6 7"), 3, 2
    assert sol.countPairs(root, distance) == expected

    root, distance, expected = String2Tree("7 1 4 6 # 5 3 # # # # # 2"), 3, 1
    assert sol.countPairs(root, distance) == expected
