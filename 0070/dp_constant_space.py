from typing import *


class Solution:
    def climbStairs(self, n: int) -> int:
        two_steps_below = 1
        one_steps_below = 1
        for i in range(2, n+1):
            current_steps = one_steps_below + two_steps_below
            two_steps_below = one_steps_below
            one_steps_below = current_steps
        return one_steps_below


if __name__ == '__main__':
    sol = Solution()

    n, expected = 2, 2
    assert sol.climbStairs(n) == expected

    n, expected = 3, 3
    assert sol.climbStairs(n) == expected
