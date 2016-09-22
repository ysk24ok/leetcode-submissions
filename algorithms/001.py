class Solution(object):

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        idx_map = {}
        i = 0
        j = len(nums) - 1
        for i in range(0, len(nums)):
            first = nums[i]
            second = target - first
            if second in idx_map:
                j = idx_map[second]
                return [i, j] if i < j else [j, i]
            idx_map[first] = i


if __name__ == '__main__':
    sol = Solution()
    assert sol.twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert sol.twoSum([3, 2, 4], 6) == [1, 2]
