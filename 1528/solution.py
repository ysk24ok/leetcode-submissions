from typing import List


class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ret = ['x' for _ in range(len(s))]
        for c, idx in zip(s, indices):
            ret[idx] = c
        return ''.join(ret)


if __name__ == '__main__':
    sol = Solution()

    s, indices, expected = "codeleet", [4, 5, 6, 7, 0, 2, 1, 3], "leetcode"
    assert sol.restoreString(s, indices) == expected

    s, indices, expected = "abc", [0, 1, 2], "abc"
    assert sol.restoreString(s, indices) == expected

    s, indices, expected = "aiohn", [3, 1, 4, 2, 0], "nihao"
    assert sol.restoreString(s, indices) == expected

    s, indices, expected = "aaiougrt", [4, 0, 2, 6, 7, 3, 1, 5], "arigatou"
    assert sol.restoreString(s, indices) == expected
