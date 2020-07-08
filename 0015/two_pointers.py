from typing import *


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        m = len(nums)
        ret = []
        for i in range(m):
            if i-1 >= 0 and nums[i-1] == nums[i]:
                continue
            rest = 0 - nums[i]
            left = i + 1
            right = m - 1
            while left < right:
                total = nums[left] + nums[right]
                if total > rest:
                    right -= 1
                elif total < rest:
                    left += 1
                else:
                    ret.append((nums[i], nums[left], nums[right]))
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right-1] == nums[right]:
                        right -= 1
                    left += 1
                    right -= 1
        return ret


if __name__ == '__main__':
    sol = Solution()

    # -4, -1, -1, 0, 1, 2
    nums = [-1, 0, 1, 2, -1, -4]
    expected = [(-1, -1, 2),(-1, 0, 1)]
    assert sol.threeSum(nums) == expected

    nums = []
    expected = []
    assert sol.threeSum(nums) == expected
