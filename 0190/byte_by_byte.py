from typing import *


class Solution:

    def __init__(self):
        self.memo = [-1 for i in range(2 ** 8)]

    def reverseBits(self, n: int) -> int:
        ret = 0
        for i in range(4):
            byte = n & 255
            if self.memo[byte] != -1:
                reversed_byte = self.memo[byte]
            else:
                reversed_byte = self.reverseBitsInOneByte(byte)
                self.memo[byte] = reversed_byte
            ret <<= 8
            ret += reversed_byte
            n >>= 8
        return ret

    def reverseBitsInOneByte(self, n):
        ret = 0
        for i in range(8):
            ret <<= 1
            ret += n & 1
            n >>= 1
        return ret


if __name__ == '__main__':
    sol = Solution()

    n, expected = 43261596, 964176192
    assert sol.reverseBits(n) == expected

    n, expected = 4294967293, 3221225471
    assert sol.reverseBits(n) == expected
