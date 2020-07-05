from typing import *


class Solution:
    def mySqrt(self, x: int) -> int:
        ok, ng = -1, x + 1
        is_ok = lambda x, mid: mid * mid <= x
        while abs(ng - ok) > 1:
            mid = int((ng - ok) / 2) + ok
            if is_ok(x, mid):
                ok = mid
            else:
                ng = mid
        return ok


if __name__ == '__main__':
    sol = Solution()
    assert sol.mySqrt(1) == 1
    assert sol.mySqrt(2) == 1
    assert sol.mySqrt(3) == 1
    assert sol.mySqrt(5) == 2
    assert sol.mySqrt(6) == 2
    assert sol.mySqrt(7) == 2
    assert sol.mySqrt(8) == 2
    assert sol.mySqrt(9) == 3
