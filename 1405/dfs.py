from typing import *

# XXX: TLE
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        return self.dfs(a, b, c, "", {})

    def dfs(self, a: int, b: int, c: int, s: str, memo: Dict[Tuple, str]) -> str:
        ret = s
        if a > 0 and (len(s) <= 1 or s[-2:] != "aa"):
            candidate = self.dfs(a - 1, b, c, s + "a", memo)
            if len(candidate) > len(ret):
                ret = candidate
        if b > 0 and (len(s) <= 1 or s[-2:] != "bb"):
            candidate = self.dfs(a, b - 1, c, s + "b", memo)
            if len(candidate) > len(ret):
                ret = candidate
        if c > 0 and (len(s) <= 1 or s[-2:] != "cc"):
            candidate = self.dfs(a, b, c - 1, s + "c", memo)
            if len(candidate) > len(ret):
                ret = candidate
        return ret


if __name__ == '__main__':
    sol = Solution()

    a, b, c = 1, 1, 7
    expected = ("ccaccbcc", "ccbccacc")
    assert sol.longestDiverseString(a, b, c) in expected

    a, b, c = 7, 1, 0
    expected = "aabaa"
    assert sol.longestDiverseString(a, b, c) == expected
