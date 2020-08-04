class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num <= 0:
            return False
        while num > 1:
            if num & 1 == 1 or num & 2 == 2:
                return False
            num >>= 2
        return num == 1


if __name__ == '__main__':
    sol = Solution()

    assert not sol.isPowerOfFour(-4)
    assert not sol.isPowerOfFour(0)
    assert sol.isPowerOfFour(1)
    assert not sol.isPowerOfFour(2)
    assert not sol.isPowerOfFour(3)
    assert sol.isPowerOfFour(4)
    assert not sol.isPowerOfFour(6)
    assert not sol.isPowerOfFour(8)
    assert not sol.isPowerOfFour(12)
    assert sol.isPowerOfFour(16)
