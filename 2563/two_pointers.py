from typing import *


class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        return self.countLessThan(nums, upper + 1) - self.countLessThan(nums, lower)

    def countLessThan(self, nums: List[int], upper: int) -> int:
        l, r = 0, len(nums) - 1
        count = 0
        while l < r:
            sum = nums[l] + nums[r]
            if sum < upper:
                count += r - l
                l += 1
            else:
                r -= 1
        return count


if __name__ == '__main__':
    sol = Solution()

    nums, lower, upper, expected = [0,1,7,4,4,5], 3, 6, 6
    assert sol.countFairPairs(nums, lower, upper) == expected

    nums, lower, upper, expected = [1,7,9,2,5], 11, 11, 1
    assert sol.countFairPairs(nums, lower, upper) == expected