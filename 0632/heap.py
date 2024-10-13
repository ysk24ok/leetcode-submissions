import heapq
from typing import *


class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heap = []
        for group, nums_of_group in enumerate(nums):
            heap.extend([(num, group) for num in nums_of_group])
        heapq.heapify(heap)

        start_num, end_num = 100001, -100001
        for group in range(len(nums)):
            num = nums[group][0]
            if num < start_num:
                start_num = num
            if num > end_num:
                end_num = num

        pointers = [0 for _ in range(len(nums))]
        min_range = [start_num, end_num]
        min_range_len = end_num - start_num
        _, group = heapq.heappop(heap)
        pointers[group] += 1
        while len(heap) > 0:
            if pointers[group] == len(nums[group]):
                break 
            start_num = heap[0][0]
            if end_num < nums[group][pointers[group]]:
                end_num = nums[group][pointers[group]]
            new_range_len = end_num - start_num
            if new_range_len < min_range_len:
                min_range = [start_num, end_num]
                min_range_len = new_range_len
            _, group = heapq.heappop(heap)
            pointers[group] += 1
        return min_range


if __name__ == '__main__':
    sol = Solution()

    nums, expected = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]], [20,24]
    assert sol.smallestRange(nums) == expected

    nums, expected = [[1,2,3],[1,2,3],[1,2,3]], [1,1]
    assert sol.smallestRange(nums) == expected

    nums, expected = [[1]], [1,1]
    assert sol.smallestRange(nums) == expected
