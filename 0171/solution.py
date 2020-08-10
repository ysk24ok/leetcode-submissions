class Solution:
    def titleToNumber(self, s: str) -> int:
        ret = 0
        for c in s:
            ret *= 26
            ret += ord(c) - ord('A') + 1
        return ret


if __name__ == '__main__':
    sol = Solution()

    s = "A"
    expected = 1
    assert sol.titleToNumber(s) == expected

    s = "AB"
    expected = 28
    assert sol.titleToNumber(s) == expected

    s = "ZY"
    expected = 701
    assert sol.titleToNumber(s) == expected
