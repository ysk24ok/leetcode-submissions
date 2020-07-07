from queue import Queue
from typing import *


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 0:
                    continue
                queue = Queue()
                queue.put((i, j))
                return self.bfs(grid, queue)

    def bfs(self, grid, queue):
        m, n = len(grid), len(grid[0])
        ret = 0
        while not queue.empty():
            i, j = queue.get()
            if i >= m or i < 0 or j >= n or j < 0:
                ret += 1
                continue
            if grid[i][j] == -1:
                continue
            elif grid[i][j] == 0:
                ret += 1
                continue
            grid[i][j] = -1
            queue.put((i+1, j))
            queue.put((i, j+1))
            queue.put((i-1, j))
            queue.put((i, j-1))
        return ret



if __name__ == '__main__':
    sol = Solution()

    grid = [
        [0,1,0,0],
        [1,1,1,0],
        [0,1,0,0],
        [1,1,0,0]
    ]
    assert sol.islandPerimeter(grid) == 16
