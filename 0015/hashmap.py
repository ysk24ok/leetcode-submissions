from typing import *


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        m = len(nums)
        val_count = {}
        for i in range(m):
            if nums[i] not in val_count:
                val_count[nums[i]] = 0
            val_count[nums[i]] += 1
        ret  = []
        for i in range(m):
            if i - 1 >= 0 and nums[i] == nums[i-1]:
                continue
            val_count[nums[i]] -= 1
            for j in range(i+1, m):
                if j - 1 >= i + 1 and nums[j] == nums[j-1]:
                    continue
                val_count[nums[j]] -= 1
                rest = 0 - nums[i] - nums[j]
                if rest < nums[j] or rest not in val_count or val_count[rest] == 0:
                    val_count[nums[j]] += 1
                    continue
                ret.append((nums[i], nums[j], rest))
                val_count[nums[j]] += 1
            val_count[nums[i]] += 1
        return ret


if __name__ == '__main__':
    sol = Solution()

    nums = [-1, 0, 1, 2, -1, -4]
    expected = [(-1, -1, 2),(-1, 0, 1)]
    assert sol.threeSum(nums) == expected

    nums = []
    expected = []
    assert sol.threeSum(nums) == expected
