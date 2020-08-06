from typing import List


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
