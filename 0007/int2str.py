class Solution:
    minimum = 2 ** 31 * -1
    maximum = 2 ** 31 - 1

    def reverse_str(self, s: str) -> str:
        reversed_s = ''
        for i in range(len(s)-1, -1, -1):
            reversed_s += s[i]
        return reversed_s

    def reverse(self, x: int) -> int:
        coef = 1
        if x < 0:
            coef = -1
        s = str(x * coef)
        ret = int(self.reverse_str(s)) * coef
        if ret < self.minimum or ret > self.maximum:
            return 0
        return ret


if __name__ == '__main__':
    sol = Solution()
    assert sol.reverse(123) == 321
    assert sol.reverse(-123) == -321
    assert sol.reverse(120) == 21
    assert sol.reverse(7463847412) == 2147483647
    assert sol.reverse(8463847412) == 0
    assert sol.reverse(-8463847412) == -2147483648
    assert sol.reverse(-9463847412) == 0
