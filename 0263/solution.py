from typing import *


class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:
            return False
        for prime_number in (5, 3, 2):
            while num % prime_number == 0:
                num /= prime_number
        return True if num == 1 else False


if __name__ == '__main__':
    sol = Solution()
    assert sol.isUgly(0) is False
    assert sol.isUgly(1)
    assert sol.isUgly(2)
    assert sol.isUgly(3)
    assert sol.isUgly(4)
    assert sol.isUgly(5)
    assert sol.isUgly(6)
    assert sol.isUgly(7) is False
    assert sol.isUgly(8)
