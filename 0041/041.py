class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # TODO: try withou sorting
        nums.sort()
        prev_n = 0
        for n in nums:
            if n <= 0:
                continue
            # non-continuous, e.g. prev_n=3, n=5
            if n > prev_n + 1:
                return prev_n + 1
            prev_n = n
        return prev_n + 1


if __name__ == '__main__':
    sol = Solution()
    got = sol.firstMissingPositive([1,2,0])     # 0,1,2
    assert got == 3
    got = sol.firstMissingPositive([3,4,-1,1])  # -1,1,3,4
    assert got == 2
    got = sol.firstMissingPositive([])
    assert got == 1
    got = sol.firstMissingPositive([3,1,5,-3,-1])   # -3,-1,1,3,5
    assert got == 2
    got = sol.firstMissingPositive([4,0])       # 0,4
    assert got == 1
    got = sol.firstMissingPositive([1000,-1])   # -1,1000
    assert got == 1
    got = sol.firstMissingPositive([1,2,2,1,3,1,0,4,0]) # 0,0,1,1,1,2,2,3,4
    assert got == 5
    got = sol.firstMissingPositive([3,4,5])
    assert got == 1
