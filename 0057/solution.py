from typing import List


class Solution:
    def insert(self, intervals: List[List[int]],
               newInterval: List[int]) -> List[List[int]]:
        new_intervals = []
        merged_start = -1
        merged_end = -1
        done_with_new_interval = False
        for interval in intervals:
            if interval[1] < newInterval[0]:
                new_intervals.append(interval)
            elif newInterval[1] < interval[0]:
                if not done_with_new_interval:
                    if merged_start == -1 and merged_end == -1:
                        new_intervals.append(newInterval)
                    else:
                        new_intervals.append([merged_start, merged_end])
                done_with_new_interval = True
                new_intervals.append(interval)
            else:
                if merged_start == -1:
                    merged_start = min(interval[0], newInterval[0])
                else:
                    merged_start = min(merged_start, interval[0], newInterval[0])
                merged_end = max(merged_end, interval[1], newInterval[1])
        if not done_with_new_interval:
            if merged_start == -1 and merged_end == -1:
                new_intervals.append(newInterval)
            else:
                new_intervals.append([merged_start, merged_end])
            done_with_new_interval = True
        return new_intervals


if __name__ == '__main__':
    sol = Solution()

    intervals = [[1, 3], [6, 9]]
    newInterval = [4, 5]
    expected = [[1, 3], [4, 5], [6, 9]]
    assert sol.insert(intervals, newInterval) == expected

    intervals = [[1, 3], [6, 9]]
    newInterval = [2, 5]
    expected = [[1, 5], [6, 9]]
    assert sol.insert(intervals, newInterval) == expected

    intervals = [[1, 3], [6, 9]]
    newInterval = [1, 2]
    expected = [[1, 3], [6, 9]]
    assert sol.insert(intervals, newInterval) == expected

    intervals = [[1, 3], [6, 9]]
    newInterval = [4, 7]
    expected = [[1, 3], [4, 9]]
    assert sol.insert(intervals, newInterval) == expected

    intervals = [[1, 3]]
    newInterval = [4, 7]
    expected = [[1, 3], [4, 7]]
    assert sol.insert(intervals, newInterval) == expected

    intervals = [[1, 3], [6, 9]]
    newInterval = [5, 12]
    expected = [[1, 3], [5, 12]]
    assert sol.insert(intervals, newInterval) == expected

    intervals = [[1, 3], [6, 9]]
    newInterval = [8, 12]
    expected = [[1, 3], [6, 12]]
    assert sol.insert(intervals, newInterval) == expected

    intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
    newInterval = [4, 8]
    expected = [[1, 2], [3, 10], [12, 16]]
    assert sol.insert(intervals, newInterval) == expected
