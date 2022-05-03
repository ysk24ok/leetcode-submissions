from typing import *

"""
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"
 |-|d|b|b|c|a|
--------------
-|t|f|f|f|f|f|
a|t|f|f|f|f|f|
a|t|t|t|t|t|f|
b|f|t|t|f|t|f|
c|f|f|t|t|t|t|
c|f|f|f|t|f|t|
"""

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        dp = [[False for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]
        dp[0][0] = True
        for i in range(len(s1)):
            dp[i+1][0] = dp[i][0] and s3[i] == s1[i]
        for j in range(len(s2)):
            dp[0][j+1] = dp[0][j] and s3[j] == s2[j]
        for i in range(len(s1)):
            for j in range(len(s2)):
                # (i + 1) + (j + 1) - 1 = i + j + 1
                dp[i+1][j+1] = (dp[i][j+1] and s3[i+j+1] == s1[i]) or (dp[i+1][j] and s3[i+j+1] == s2[j])
        return dp[len(s1)][len(s2)]
                


if __name__ == '__main__':
    sol = Solution()

    s1, s2, s3 = "aabcc", "dbbca", "aadbbcbcac"
    assert sol.isInterleave(s1, s2, s3)

    s1, s2, s3 = "aabcc", "dbbca", "aadbbbaccc"
    assert sol.isInterleave(s1, s2, s3) is False

    s1, s2, s3 = "", "", "a"
    assert sol.isInterleave(s1, s2, s3) is False

    s1, s2, s3 = "", "b", "b"
    assert sol.isInterleave(s1, s2, s3)
