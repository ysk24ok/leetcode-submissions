from typing import *


class Solution:
    def myPow(self, x: float, n: int) -> float:
        ret = 1
        while n != 0:
            if n > 0:
                ret *= x
                n -= 1
            else:
                ret /= x
                n += 1
        return ret

if __name__ == '__main__':
    sol = Solution()

    x, n = 2.0, 10
    expected = 1024
    assert round(sol.myPow(x, n), 8) == expected

    x, n = 2.1, 3
    expected = 9.261
    assert round(sol.myPow(x, n), 8) == expected

    x, n = 2.0, -2
    expected = 0.25
    assert round(sol.myPow(x, n), 8) == expected
