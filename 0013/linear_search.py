from typing import *


class Solution:
    def romanToInt(self, s: str) -> int:
        d = dict(I=1, V=5, X=10, L=50, C=100, D=500, M=1000)
        ret = 0
        for i in range(0, len(s)-1):
            c, c_next = s[i], s[i+1]
            if d[c] >= d[c_next]:
                ret += d[c]
            else:
                ret -= d[c]
        return ret + d[s[-1]]


if __name__ == '__main__':
    sol = Solution()
    assert sol.romanToInt("III") == 3
    assert sol.romanToInt("LVIII") == 58
    assert sol.romanToInt("MCMXCIV") == 1994
