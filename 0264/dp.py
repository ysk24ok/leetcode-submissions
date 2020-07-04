from typing import *


#  i 0 1 2 3 4 5 6
# dp 1 2 3 4 5 6 8
# p2 0 1 1 2 2 3 4
# p3 0 0 1 1 1 2 2
# p5 0 0 0 0 1 1 1
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [None for _ in range(n)]
        dp[0] = 1
        p2, p3, p5 = 0, 0, 0
        for i in range(1, n):
            dp[i] = min(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5)
            if dp[i] == dp[p2] * 2:
                p2 += 1
            if dp[i] == dp[p3] * 3:
                p3 += 1
            if dp[i] == dp[p5] * 5:
                p5 += 1
        return dp[n-1]

if __name__ == '__main__':
    sol = Solution()

    assert sol.nthUglyNumber(1) == 1
    assert sol.nthUglyNumber(2) == 2
    assert sol.nthUglyNumber(3) == 3
    assert sol.nthUglyNumber(4) == 4
    assert sol.nthUglyNumber(5) == 5
    assert sol.nthUglyNumber(6) == 6
    assert sol.nthUglyNumber(7) == 8
    assert sol.nthUglyNumber(10) == 12
    assert sol.nthUglyNumber(11) == 15
