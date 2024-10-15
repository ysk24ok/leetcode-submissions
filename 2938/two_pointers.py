from typing import *

class Solution:
    def minimumSteps(self, s: str) -> int:
        left, right = 0, len(s) - 1
        moves = 0
        while True:
            while left < len(s) and s[left] == "0":
                left += 1
            while 0 <= right and s[right] == "1":
                right -= 1
            if left >= right:
                break
            moves += right - left
            left += 1
            right -= 1
        return moves


if __name__ == '__main__':
    sol = Solution()

    s, expected = "101", 1
    assert sol.minimumSteps(s) == expected

    s, expected = "100", 2
    assert sol.minimumSteps(s) == expected

    s, expected = "0111", 0
    assert sol.minimumSteps(s) == expected
