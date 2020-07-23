from collections import defaultdict
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        counts = defaultdict(int)
        for num in nums:
            counts[num] += 1
        ret = []
        for num, count in counts.items():
            if count == 1:
                ret.append(num)
        return ret


if __name__ == '__main__':
    sol = Solution()

    nums = [1, 2, 1, 3, 2, 5]
    expected = [3, 5]
    assert sol.singleNumber(nums) == expected
