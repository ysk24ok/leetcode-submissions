from typing import *


# idx = 7(73), next_warmer_day = 0, stack = [7(73)]
# idx = 6(76), next_warmer_day = 0, stack = [6(76)]
# idx = 5(72), next_warmer_day = 6, stack = [6(76), 5(72)]
# idx = 4(69), next_warmer_day = 5, stack = [6(76), 5(72), 4(69)]
# idx = 3(71), next_warmer_day = 5, stack = [6(76), 5(72), 3(71)]


class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ret = [0 for _ in range(len(T))]
        stack = []
        for idx in range(len(T)-1, -1, -1):
            temperature = T[idx]
            while len(stack) > 0 and temperature >= T[stack[-1]]:
                stack.pop()
            if len(stack) > 0:
                ret[idx] = stack[-1] - idx
            stack.append(idx)
        return ret


if __name__ == '__main__':
    sol = Solution()

    T, expected = [73, 74, 75, 71, 69, 72, 76, 73], [1, 1, 4, 2, 1, 1, 0, 0]
    assert sol.dailyTemperatures(T) == expected

    T, expected = [], []
    assert sol.dailyTemperatures(T) == expected

    T, expected = [89,62,70,58,47,47,46,76,100,70], [8, 1, 5, 4, 3, 2, 1, 1, 0, 0]
    assert sol.dailyTemperatures(T) == expected
