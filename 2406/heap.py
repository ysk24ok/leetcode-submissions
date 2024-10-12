from heapq import heappush, heappop
from typing import List

class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        num_groups = 1
        heap = [(intervals[0][1], num_groups-1)]
        for idx in range(1, len(intervals)):
            interval = intervals[idx]
            # if not overlapped, add the interval to the group
            if heap[0][0] < interval[0]:
                _, group = heappop(heap)
                heappush(heap, (interval[1], group))
            # if overlapped, add the interval to a new group
            else:
                heappush(heap, (interval[1], num_groups))
                num_groups += 1
        return num_groups


if __name__ == '__main__':
    sol = Solution()

    intervals, expected = [[5,10],[6,8],[1,5],[2,3],[1,10]], 3
    assert sol.minGroups(intervals) == expected

    intervals, expected = [[1,3],[5,6],[8,10],[11,13]], 1
    assert sol.minGroups(intervals) == expected
