from typing import *


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        ng, ok = -1, len(nums)
        is_ok = lambda nums, mid, target: nums[mid] >= target
        while abs(ok - ng) > 1:
            mid = int((ok + ng) / 2)
            if is_ok(nums, mid, target):
                ok = mid
            else:
                ng = mid
        return ok if ok < len(nums) and nums[ok] == target else -1


if __name__ == '__main__':
    sol = Solution()

    nums, target, expected = [-1,0,3,5,9,12], 9, 4
    assert sol.search(nums, target) == expected

    nums, target, expected = [-1,0,3,5,9,12], 2, -1
    assert sol.search(nums, target) == expected

    nums, target, expected = [-1,0,3,5,9,12], 13, -1
    assert sol.search(nums, target) == expected
