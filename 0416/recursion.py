from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1:
            return False
        target = int(total / 2)
        # idx x target
        # -1: unvisited, 0: False, 1: True
        memo = [[-1 for _ in range(target)] for idx in range(len(nums))]
        return self.recursion(nums, 0, 0, target, memo)

    def recursion(self, nums, idx, current_total, target, memo):
        if current_total == target:
            return True
        elif current_total > target:
            return False
        if idx >= len(nums):
            return False
        if memo[idx][current_total] != -1:
            return True if memo[idx][current_total] == 1 else False
        can_partition = self.recursion(nums, idx+1, current_total + nums[idx], target, memo) or self.recursion(nums, idx+1, current_total, target, memo)
        memo[idx][current_total] = 1 if can_partition else 0
        return memo[idx][current_total]


if __name__ == '__main__':
    sol = Solution()

    nums = [1, 5, 11, 5]
    assert sol.canPartition(nums)

    nums = [1, 2, 3, 5]
    assert not sol.canPartition(nums)
