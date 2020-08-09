from collections import deque
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ret = 0
        q = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    grid[i][j] = 1  # mark as fresh
                    q.append((i, j, 0))
        while len(q) > 0:
            i, j, t = q.popleft()
            if grid[i][j] != 1:
                continue
            grid[i][j] = 2
            ret = max(ret, t)
            if i > 0:
                q.append((i-1, j, t+1))
            if i + 1 < m:
                q.append((i+1, j, t+1))
            if j > 0:
                q.append((i, j-1, t+1))
            if j + 1 < n:
                q.append((i, j+1, t+1))
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1
        return ret


if __name__ == '__main__':
    sol = Solution()

    grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
    expected = 4
    assert sol.orangesRotting(grid) == expected

    grid = [[2, 1, 1], [0, 1, 1], [1, 0, 1]]
    expected = -1
    assert sol.orangesRotting(grid) == expected

    grid = [[0, 2]]
    expected = 0
    assert sol.orangesRotting(grid) == expected
