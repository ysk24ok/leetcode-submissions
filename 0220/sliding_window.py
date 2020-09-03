import bisect
from typing import List


class Solution:
    def containsNearbyAlmostDuplicate(
            self, nums: List[int], k: int, t: int) -> bool:
        if t < 0:
            return False
        vals = []
        for i, num in enumerate(nums):
            left_idx = bisect.bisect_left(vals, num - t)    # lower_bound
            right_idx = bisect.bisect_right(vals, num + t)  # upper_bound
            if left_idx < right_idx:
                return True
            idx = bisect.bisect_left(vals, num)
            vals.insert(idx, num)
            if i >= k:
                idx = bisect.bisect_left(vals, nums[i-k])
                vals.pop(idx)
        return False


if __name__ == '__main__':
    # abs(nums[i] - nums[j]) <= t
    # abs(i - j) <= k
    sol = Solution()

    nums, k, t = [1, 2, 3, 1], 3, 0
    assert sol.containsNearbyAlmostDuplicate(nums, k, t)

    nums, k, t = [1, 0, 1, 1], 1, 2
    assert sol.containsNearbyAlmostDuplicate(nums, k, t)

    nums, k, t = [1, 5, 9, 1, 5, 9], 2, 3
    assert not sol.containsNearbyAlmostDuplicate(nums, k, t)
