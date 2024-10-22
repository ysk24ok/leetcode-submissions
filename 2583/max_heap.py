import heapq
from collections import deque
from typing import *

from leetcode.tree import TreeNode, String2Tree

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        heap = []
        q = deque()
        q.append((root, 1))
        max_levels = 0
        while len(q) > 0:
            node, level = q.popleft()
            if max_levels < level:
                max_levels = level
            if len(heap) < level:
                heap.append(-node.val)
            else:
                heap[level-1] -= node.val
            if node.left is not None:
                q.append((node.left, level+1))
            if node.right is not None:
                q.append((node.right, level+1))
        heapq.heapify(heap)
        if k > max_levels:
            return -1
        while k > 0:
            level_sum = 0 - heapq.heappop(heap)
            k -= 1
        return level_sum


if __name__ == '__main__':
    sol = Solution()

    root, k, expected = String2Tree("5 8 9 2 1 3 7 4 6"), 2, 13
    assert sol.kthLargestLevelSum(root, k) == expected

    root, k, expected = String2Tree("1 2 # 3"), 1, 3
    assert sol.kthLargestLevelSum(root, k) == expected

    root, k, expected = String2Tree("5 8 9 2 1 3 7"), 4, -1
    assert sol.kthLargestLevelSum(root, k) == expected
