from typing import *


class Solution:
    def myPow(self, x: float, n: int) -> float:
        ret = 1
        abs_n = abs(n)
        while abs_n > 0:
            if abs_n & 1 == 1:
                ret *= x
            abs_n >>= 1
            x *= x
        return ret if n > 0 else 1 / ret


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
