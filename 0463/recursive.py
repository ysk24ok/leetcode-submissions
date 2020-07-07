from typing import *


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 0:
                    continue
                return self.dfs(grid, i, j)

    def dfs(self, grid, i, j):
        m, n = len(grid), len(grid[0])
        if i >= m or i < 0 or j >= n or j < 0:
            return 1
        if grid[i][j] == -1:
            return 0
        if grid[i][j] == 0:
            return 1
        grid[i][j] = -1
        d1 = self.dfs(grid, i+1, j)
        d2 = self.dfs(grid, i, j+1)
        d3 = self.dfs(grid, i-1, j)
        d4 = self.dfs(grid, i, j-1)
        return d1 + d2 + d3 + d4


if __name__ == '__main__':
    sol = Solution()

    grid = [
        [0,1,0,0],
        [1,1,1,0],
        [0,1,0,0],
        [1,1,0,0]
    ]
    assert sol.islandPerimeter(grid) == 16
