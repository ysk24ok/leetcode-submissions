from typing import *


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = int((right - left) / 2) + left
            if nums[mid] == target:
                return mid
            # no pivot in this search space
            if nums[left] < nums[right]:
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                # left, mid, pivot, right
                if nums[left] <= nums[mid]:
                    if nums[left] <= target and target < nums[mid]:
                        right = mid - 1
                    else:
                        left = mid + 1
                # left, pivot, mid, right
                else:
                    if nums[mid] < target and target <= nums[right]:
                        left = mid + 1
                    else:
                        right = mid - 1
        return -1


if __name__ == '__main__':
    sol = Solution()

    nums = [4,5,6,7,0,1,2]
    assert sol.search(nums, 4) == 0
    assert sol.search(nums, 5) == 1
    assert sol.search(nums, 6) == 2
    assert sol.search(nums, 7) == 3
    assert sol.search(nums, 0) == 4
    assert sol.search(nums, 1) == 5
    assert sol.search(nums, 2) == 6
    assert sol.search(nums, 3) == -1

    nums = [3,1]
    assert sol.search(nums, 3) == 0
    assert sol.search(nums, 1) == 1
    assert sol.search(nums, 2) == -1
