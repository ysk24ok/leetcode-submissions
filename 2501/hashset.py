from typing import *


class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        unique_nums = set(nums)
        ret = -1
        for num in nums:
            square = num * num
            streak = 1
            while square in unique_nums:
                streak += 1
                if ret < streak:
                    ret = streak
                square *= square
        return ret


if __name__ == '__main__':
    sol = Solution()

    nums, expected = [4,3,6,16,8,2], 3
    assert sol.longestSquareStreak(nums) == expected

    nums, expected = [2,3,5,6,7], -1
    assert sol.longestSquareStreak(nums) == expected
