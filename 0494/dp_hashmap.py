from typing import *

# 1         {1: 1, -1: 1}
# 1,1       {2: 1, 0: 2, -2: 1}
# 1,1,1     {3: 1, 1: 3, -1: 3, -3: 1}
# 1,1,1,1   {4: 1, 2: 4, 0: 6, -2: 4, -4: 1}
# 1,1,1,1,1 {5: 1, 3: 5, 1: 10, -1: 10, -3: 5, -5: 1}
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        dp = {}
        if len(nums) == 0:
            return 0
        self.countUp(dp, nums[0], 1)
        self.countUp(dp, -nums[0], 1)
        for i in range(1, len(nums)):
            num = nums[i]
            new_dp = {}
            for curr_sum, count in dp.items():
                self.countUp(new_dp, curr_sum + num, count)
                self.countUp(new_dp, curr_sum - num, count)
            dp = new_dp
        return dp[S] if S in dp else 0

    def countUp(self, dp, key, count):
        if key not in dp:
            dp[key] = 0
        dp[key] += count


if __name__ == '__main__':
    sol = Solution()

    nums, S, expected = [1,1,1,1,1], 3, 5
    assert sol.findTargetSumWays(nums, S) == expected

    nums, S, expected = [0,0,0,0,0,0,0,0,1], 1, 256
    assert sol.findTargetSumWays(nums, S) == expected
