from typing import *


def isOk(nums, mid):
    if mid == 0:
        return True
    else:
        return nums[mid-1] < nums[mid]


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        ok, ng = -1, len(nums)
        while abs(ng - ok) > 1:
            mid = int((ng - ok) / 2) + ok
            if isOk(nums, mid):
                ok = mid
            else:
                ng = mid
        return ok


if __name__ == '__main__':
    sol = Solution()

    nums, expected = [1, 2, 3, 1], 2
    assert sol.findPeakElement(nums) == expected

    nums, expected = [1, 2, 1, 3, 5, 6, 4], 5
    assert sol.findPeakElement(nums) == expected

    nums, expected = [5, 4, 3, 2, 1], 0
    assert sol.findPeakElement(nums) == expected

    nums, expected = [1, 2, 3, 4, 5], 4
    assert sol.findPeakElement(nums) == expected
