from typing import *


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        i = 0
        while True:
            if i >= len(strs[0]):
                break
            c = strs[0][i]
            e = False
            for idx in range(1, len(strs)):
                if i >= len(strs[idx]) or c != strs[idx][i]:
                    e = True
                    break
            if e:
                break
            i += 1
        return strs[0][0:i]


if __name__ == '__main__':
    sol = Solution()

    strs, expected = ["flower","flow","flight"], "fl"
    assert sol.longestCommonPrefix(strs) == expected

    strs, expected = ["dog","racecar","car"], ""
    assert sol.longestCommonPrefix(strs) == expected

    strs, expected = [""], ""
    assert sol.longestCommonPrefix(strs) == expected
