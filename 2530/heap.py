import heapq
from typing import *

def divide_and_ceil(num: int) -> int:
    if num % 3 == 0:
        return int(num / 3)
    return int(num / 3) - 1

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        heap = [-num for num in nums]
        heapq.heapify(heap)
        count = 1
        score = 0
        while count <= k:
            num = heapq.heappop(heap)
            score -= num
            heapq.heappush(heap, divide_and_ceil(num))
            count += 1
        return score


if __name__ == '__main__':
    sol = Solution()

    nums, k, expected = [10,10,10,10,10], 5, 50
    assert sol.maxKelements(nums, k) == expected

    nums, k, expected = [1,10,3,3,3], 3, 17
    assert sol.maxKelements(nums, k) == expected

    nums, k, expected = [9], 3, 13
    assert sol.maxKelements(nums, k) == expected
