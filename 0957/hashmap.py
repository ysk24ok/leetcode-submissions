from typing import *


class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        num_cells = len(cells)
        prev = cells
        memo = {self.calc_hash(prev): N}
        while N > 0:
            N -= 1
            curr = [0 for _ in range(num_cells)]
            for cell_id in range(1, num_cells-1):
                if prev[cell_id - 1] == prev[cell_id + 1]:
                    curr[cell_id] = 1
            h = self.calc_hash(curr)
            if h not in memo:
                memo[h] = N
            else:
                diff = memo[h] - N
                N %= diff
            prev = curr
        return prev

    def calc_hash(self, cells):
        radix = 1
        h = 0
        for cell in cells:
            h += radix * cell
            radix *= 10
        return h


if __name__ == '__main__':
    sol = Solution()

    cells = [0,1,0,1,1,0,0,1]
    N = 7
    assert sol.prisonAfterNDays(cells, N) == [0,0,1,1,0,0,0,0]

    cells = [1,0,0,1,0,0,1,0]
    N = 1000000000
    assert sol.prisonAfterNDays(cells, N) == [0,0,1,1,1,1,1,0]
