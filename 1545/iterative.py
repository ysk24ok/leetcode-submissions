from typing import *


class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        num_reversed = 0
        for n in range(n, 1, -1):
            length = 2 ** n - 1
            half_bit = int(length / 2) + 1 
            if k > half_bit:
                k = half_bit - (k - half_bit)
                num_reversed += 1
            elif k < half_bit:
                continue
            else:
                return "1" if num_reversed % 2 == 0 else "0"
        return "0" if num_reversed % 2 == 0 else "1"


if __name__ == '__main__':
    sol = Solution()

    n, k, expected = 3, 1, "0"
    assert sol.findKthBit(n, k) == expected

    n, k, expected = 4, 11, "1"
    assert sol.findKthBit(n, k) == expected

    n, k, expected = 4, 12, "0"
    assert sol.findKthBit(n, k) == expected
