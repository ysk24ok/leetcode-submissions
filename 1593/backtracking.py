from typing import *


class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        return self.dfs(s, 0, set())

    def dfs(self, s: str, start: int, unique_substrs: set) -> int:
        if start == len(s):
            return len(unique_substrs)
        maxval = 0
        for end in range(start+1, len(s)+1):
            substr = s[start:end]
            if substr in unique_substrs:
                continue
            unique_substrs.add(substr)
            retval = self.dfs(s, end, unique_substrs)
            unique_substrs.remove(substr)
            if maxval < retval:
                maxval = retval
        return maxval


if __name__ == '__main__':
    sol = Solution()

    s, expected = "ababccc", 5
    assert sol.maxUniqueSplit(s) == expected

    s, expected = "aba", 2
    assert sol.maxUniqueSplit(s) == expected

    s, expected = "aa", 1
    assert sol.maxUniqueSplit(s) == expected
