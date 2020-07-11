from typing import *


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return self.recursive(nums, 0, {}) + [[]]

    def recursive(self, nums, start, memo):
        ret = []
        if start in memo:
            return memo[start]
        m = len(nums)
        idx = start
        while idx < m:
            ret.append([nums[idx]])
            for val in self.recursive(nums, idx+1, memo):
                ret.append([nums[idx]] + val)
            idx += 1
        memo[start] = ret
        return ret


if __name__ == '__main__':
    sol = Solution()

    nums = [1, 2, 3]
    got = sol.subsets(nums)
    assert len(got) == 8
    assert [] in got
    assert [1] in got
    assert [2] in got
    assert [3] in got
    assert [1,2] in got
    assert [1,3] in got
    assert [2,3] in got
    assert [1,2,3] in got
