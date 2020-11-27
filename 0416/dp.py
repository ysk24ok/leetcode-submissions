from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1:
            return False
        total = int(total / 2)
        dp = [False for _ in range(total + 1)]
        dp[0] = True
        for num in nums:
            for idx in range(total, -1 + num, -1):  # total, total-1, ..., num
                dp[idx] |= dp[idx - num]
        return dp[total]


if __name__ == '__main__':
    sol = Solution()

    nums = [1, 5, 11, 5]
    assert sol.canPartition(nums)

    nums = [1, 2, 3, 5]
    assert not sol.canPartition(nums)

    nums = [1, 2, 5]
    assert not sol.canPartition(nums)

    nums = [2, 2, 1, 1]
    assert sol.canPartition(nums)
