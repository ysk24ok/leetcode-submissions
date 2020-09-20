from typing import List


class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        mod = 10 ** 9 + 7
        m, n = len(grid), len(grid[0])
        dp = [
            [[2 ** 31 - 1, - 2 ** 31] for _ in range(n)] for i in range(m)
        ]
        dp[0][0][0] = dp[0][0][1] = grid[0][0]
        for i in range(1, m):
            dp[i][0][0] = dp[i][0][1] = dp[i-1][0][0] * grid[i][0]
        for j in range(1, n):
            dp[0][j][0] = dp[0][j][1] = dp[0][j-1][0] * grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                if grid[i][j] >= 0:
                    dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0])
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1])
                else:
                    dp[i][j][0] = max(dp[i-1][j][1], dp[i][j-1][1])
                    dp[i][j][1] = min(dp[i-1][j][0], dp[i][j-1][0])
                dp[i][j][0] *= grid[i][j]
                dp[i][j][1] *= grid[i][j]
        return dp[-1][-1][1] % mod if dp[-1][-1][1] >= 0 else -1


if __name__ == '__main__':
    sol = Solution()

    grid = [
        [-1, -2, -3],
        [-2, -3, -3],
        [-3, -3, -2]
    ]
    expected = -1
    assert sol.maxProductPath(grid) == expected

    grid = [
        [1, -2, 1],
        [1, -2, 1],
        [3, -4, 1]
    ]
    expected = 8
    assert sol.maxProductPath(grid) == expected

    grid = [
        [1,  3],
        [0, -4],
    ]
    expected = 0
    assert sol.maxProductPath(grid) == expected

    grid = [
        [1, 4, 4, 0],
        [-2, 0, 0, 1],
        [1, -1, 1, 1]
    ]
    expected = 2
    assert sol.maxProductPath(grid) == expected
