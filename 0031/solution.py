from typing import *


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        m = len(nums)
        # 1. Find a last increasing pair
        last_inc_pair = -1, 0
        for i in range(m-1):
            if nums[i] < nums[i+1]:
                last_inc_pair = i, i + 1
        # 2. Find a minimum value which is larger than nums[last_inc_pair[0]]
        #    and swap them
        if last_inc_pair[0] >= 0:
            next_larger_idx = last_inc_pair[1]
            for i in range(last_inc_pair[1], m):
                if nums[last_inc_pair[0]] < nums[i]:
                    next_larger_idx = i
            self._swap(nums, last_inc_pair[0], next_larger_idx)
        # 3. Sort
        left, right = last_inc_pair[1], m - 1
        while left < right:
            self._swap(nums, left, right)
            left += 1
            right -= 1

    def _swap(self, nums, i, j):
        tmp = nums[i]
        nums[i] = nums[j]
        nums[j] = tmp


if __name__ == '__main__':
    sol = Solution()

    nums = [1, 2, 3, 4, 5]
    sol.nextPermutation(nums)
    assert nums == [1, 2, 3, 5, 4]

    nums = [2, 5, 1, 4, 3]
    sol.nextPermutation(nums)
    assert nums == [2, 5, 3, 1, 4]

    nums = [2, 5, 4, 3, 1]
    sol.nextPermutation(nums)
    assert nums == [3, 1, 2, 4, 5]

    nums = [5, 4, 3, 2, 1]
    sol.nextPermutation(nums)
    assert nums == [1, 2, 3, 4, 5]
