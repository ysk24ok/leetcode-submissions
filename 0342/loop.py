class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num <= 0:
            return False
        while num > 1:
            if num % 4 != 0:
                return False
            num /= 4
        return True


if __name__ == '__main__':
    sol = Solution()

    assert not sol.isPowerOfFour(-4)
    assert not sol.isPowerOfFour(0)
    assert sol.isPowerOfFour(1)
    assert not sol.isPowerOfFour(2)
    assert not sol.isPowerOfFour(3)
    assert sol.isPowerOfFour(4)
