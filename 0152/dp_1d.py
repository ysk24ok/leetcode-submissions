from typing import *


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        m = len(nums)
        dp_max = [0 for _ in range(m+1)]
        dp_min = [0 for _ in range(m+1)]
        dp_max[0] = 1
        dp_min[0] = 1
        ret = -float('inf')
        for i in range(len(nums)):
            val1 = dp_max[i] * nums[i]
            val2 = dp_min[i] * nums[i]
            dp_max[i+1] = max(nums[i], val1, val2)
            dp_min[i+1] = min(nums[i], val1, val2)
            ret = max(ret, dp_max[i+1])
        return ret

if __name__ == '__main__':
    sol = Solution()

    nums, expected = [2, 3, -2, 4], 6
    assert sol.maxProduct(nums) == expected

    nums, expected = [-2, 0, -1], 0
    assert sol.maxProduct(nums) == expected
