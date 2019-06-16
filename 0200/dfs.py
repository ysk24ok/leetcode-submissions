from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    count += 1
        return count

    def dfs(self, grid, i, j):
        grid[i][j] = None
        if i - 1 >= 0 and grid[i-1][j] == '1':
            self.dfs(grid, i-1, j)
        if j - 1 >= 0 and grid[i][j-1] == '1':
            self.dfs(grid, i, j-1)
        if i + 1 < len(grid) and grid[i+1][j] == '1':
            self.dfs(grid, i+1, j)
        if j + 1 < len(grid[0]) and grid[i][j+1] == '1':
            self.dfs(grid, i, j+1)


if __name__ == '__main__':
    sol = Solution()
    d = [
        ['1', '1', '1', '1', '0'],
        ['1', '1', '0', '1', '0'],
        ['1', '1', '0', '0', '0'],
        ['0', '0', '0', '0', '0']
    ]
    assert sol.numIslands(d) == 1
    d = [
        ['1', '1', '0', '0', '0'],
        ['1', '1', '0', '0', '0'],
        ['0', '0', '1', '0', '0'],
        ['0', '0', '0', '1', '1']
    ]
    assert sol.numIslands(d) == 3
    d = [
        ['1','1','1'],
        ['0','1','0'],
        ['1','1','1']
    ]
    assert sol.numIslands(d) == 1

