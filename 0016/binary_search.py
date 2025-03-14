from typing import *


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = 2 ** 31
        for i in range(0, len(nums)-2):
            for j in range(i + 1, len(nums)-1):
                l, r = j, len(nums)
                while r - l > 1:
                    m = int((l + r) / 2)
                    total = nums[i] + nums[j] + nums[m]
                    if abs(total - target) < abs(closest - target):
                        closest = total
                    if total < target:
                        l = m
                    elif total > target:
                        r = m
                    else:
                        return closest
        return closest


if __name__ == '__main__':
    sol = Solution()
    
    nums, target, expected = [-1, 2, 1, -4], 1, 2
    assert sol.threeSumClosest(nums, target) == expected
    
    nums, target, expected = [0, 0, 0], 1, 0
    assert sol.threeSumClosest(nums, target) == expected
    
    nums, target, expected = [0, 0, 0], 10000, 0
    assert sol.threeSumClosest(nums, target) == expected
    
    nums, target, expected = [1, 2, 7, 13], 12, 10
    assert sol.threeSumClosest(nums, target) == expected
