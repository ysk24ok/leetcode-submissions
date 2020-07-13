from typing import *


class Solution:
    def reverseBits(self, n: int) -> int:
        ret = 0
        for i in range(32):
            ret <<= 1
            ret += n % 2
            n >>= 1
        return ret


if __name__ == '__main__':
    sol = Solution()

    n, expected = 43261596, 964176192
    assert sol.reverseBits(n) == expected

    n, expected = 4294967293, 3221225471
    assert sol.reverseBits(n) == expected
