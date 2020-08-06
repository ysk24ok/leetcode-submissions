from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        num_set = set([])
        ret = []
        for num in nums:
            if num in num_set:
                ret.append(num)
                continue
            num_set.add(num)
        return ret


if __name__ == '__main__':
    sol = Solution()

    nums = [4, 3, 2, 7, 8, 2, 3, 1]
    expected = [2, 3]
    assert sol.findDuplicates(nums) == expected
