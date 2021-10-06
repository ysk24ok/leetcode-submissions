from typing import List


# https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/92390/Python-O(n)-time-O(1)-space
# If the element is found for the second time, the value at the corresponding index is negative.
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ret = []
        for num in nums:
            idx = abs(num) - 1
            if nums[idx] > 0:
                nums[idx] *= -1
            else:
                ret.append(abs(num))
        return ret


if __name__ == '__main__':
    sol = Solution()

    nums = [4, 3, 2, 7, 8, 2, 3, 1]
    expected = [2, 3]
    assert sol.findDuplicates(nums) == expected
