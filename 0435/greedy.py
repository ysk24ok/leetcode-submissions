from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0
        intervals.sort(key=lambda x: x[1])
        end = intervals[0][1]
        non_overlapping_counts = 1
        for interval in intervals:
            if end <= interval[0]:
                non_overlapping_counts += 1
                end = interval[1]
        return len(intervals) - non_overlapping_counts


if __name__ == '__main__':
    sol = Solution()

    intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
    expected = 1
    assert sol.eraseOverlapIntervals(intervals) == expected

    intervals = [[1, 2], [1, 2], [1, 2]]
    expected = 2
    assert sol.eraseOverlapIntervals(intervals) == expected

    intervals = [[1, 2], [2, 3]]
    expected = 0
    assert sol.eraseOverlapIntervals(intervals) == expected
