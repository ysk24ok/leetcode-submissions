from typing import *


MINIMUM_TEMPERATURE = 30
MAXIMUM_TEMPERATURE = 100

class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ret = [-1 for _ in range(len(T))]
        next_warmer_days = [-1 for _ in range(MAXIMUM_TEMPERATURE+1)]
        for idx in range(len(T)-1, -1, -1):
            temperature = T[idx]
            if next_warmer_days[temperature] == -1:
                ret[idx] = 0
            else:
                ret[idx] = next_warmer_days[temperature] - idx
            for temp in range(MINIMUM_TEMPERATURE, temperature):
                next_warmer_days[temp] = idx
        return ret


if __name__ == '__main__':
    sol = Solution()

    T, expected = [73, 74, 75, 71, 69, 72, 76, 73], [1, 1, 4, 2, 1, 1, 0, 0]
    assert sol.dailyTemperatures(T) == expected

    T, expected = [], []
    assert sol.dailyTemperatures(T) == expected

    T, expected = [89,62,70,58,47,47,46,76,100,70], [8, 1, 5, 4, 3, 2, 1, 1, 0, 0]
    assert sol.dailyTemperatures(T) == expected
