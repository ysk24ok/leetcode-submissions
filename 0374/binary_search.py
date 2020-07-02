from typing import *


def guess(num: int) -> int:
    pick = 6
    if num > pick:
        return -1
    elif num < pick:
        return 1
    else:
        return 0


class Solution:
    def guessNumber(self, n: int) -> int:
        ok, ng = -1, n+1
        is_ok = lambda mid: guess(mid) >= 0
        while abs(ok - ng) > 1:
            mid = int((ng - ok) / 2) + ok
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok


if __name__ == '__main__':
    sol = Solution()
    assert sol.guessNumber(10) == 6
