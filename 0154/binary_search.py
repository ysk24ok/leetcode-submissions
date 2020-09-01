from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left + 1 < right:
            mid = int((right - left) / 2) + left
            # pivot in the left half
            if nums[left] > nums[mid]:
                right = mid
            # pivot is in the right half
            elif nums[mid] > nums[right]:
                left = mid
            # no pivot is in this search space
            elif nums[left] < nums[mid] and nums[mid] < nums[right]:
                break
            # when nums[left] == nums[mid] or nums[mid] == nums[right],
            else:
                right -= 1
        return min(nums[left], nums[right])


if __name__ == '__main__':
    sol = Solution()

    nums, expected = [3, 4, 5, 1, 2], 1
    assert sol.findMin(nums) == expected

    nums, expected = [4, 5, 6, 7, 0, 1, 2], 0
    assert sol.findMin(nums) == expected

    nums, expected = [1, 2, 3], 1
    assert sol.findMin(nums) == expected

    nums, expected = [3, 3, 1, 3], 1
    assert sol.findMin(nums) == expected
