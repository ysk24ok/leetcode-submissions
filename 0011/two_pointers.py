from typing import *


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_area = 0
        while left < right:
            if height[left] < height[right]:
                curr_area = height[left] * (right - left)
                left += 1
            else:
                curr_area = height[right] * (right - left)
                right -= 1
            max_area = max(curr_area, max_area)
        return max_area


if __name__ == '__main__':
    sol = Solution()

    height, expected = [1, 8, 6, 2, 5, 4, 8, 3, 7], 49
    assert sol.maxArea(height) == expected

    height, expected = [1, 1], 1
    assert sol.maxArea(height) == expected

    height, expected = [4, 3, 2, 1, 4], 16
    assert sol.maxArea(height) == expected

    height, expected = [1, 2, 1], 2
    assert sol.maxArea(height) == expected
