from typing import *

from leetcode.priority_queue import PriorityQueue

# assume N is the length of `nums`
# time comlexity:
#   building a hash map: O(N)
#   adding counts to a heapq: O(Nlogk)
#   getting k most frequent elements: O(klogk)
# space complexity:
#   a hash map: O(N)
#   a heapq: O(N)

class Item:
    def __init__(self, num, count):
        self.num = num
        self.count = -count

    def __lt__(self, other):
        return self.count < other.count

    def __eq__(self, other):
        return self.count == other.count


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for num in nums:
            if num not in freq:
                freq[num] = 0
            freq[num] += 1
        pq = PriorityQueue()
        for num, count in freq.items():
            item = Item(num, count)
            pq.push(item)
        ret = []
        for _ in range(k):
            ret.append(pq.pop().num)
        return ret


if __name__ == '__main__':
    sol = Solution()

    nums,  k = [1, 1, 1, 2, 2, 3], 2
    expected = [1, 2]
    assert sol.topKFrequent(nums, k) == expected

    nums,  k = [1], 1
    expected = [1]
    assert sol.topKFrequent(nums, k) == expected
