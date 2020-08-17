from typing import List


class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def isOk(divisor):
            sum = 0
            for num in nums:
                if num % divisor == 0:
                    sum += int(num / divisor)
                else:
                    sum += int(num / divisor) + 1
            return sum <= threshold

        ng, ok = 0, nums[-1] + 1
        while ok - ng > 1:
            mid = int((ok - ng) / 2) + ng
            if isOk(mid):
                ok = mid
            else:
                ng = mid
        return ok


if __name__ == '__main__':
    sol = Solution()

    nums, threshold = [1, 2, 5, 9], 6
    expected = 5
    assert sol.smallestDivisor(nums, threshold) == expected

    nums, threshold = [2, 3, 5, 7, 11], 11
    expected = 3
    assert sol.smallestDivisor(nums, threshold) == expected

    nums, threshold = [19], 5
    expected = 4
    assert sol.smallestDivisor(nums, threshold) == expected
