from typing import *


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        ret = []
        if len(intervals) == 0:
            return ret
        prev_s = intervals[0][0]
        prev_e = intervals[0][1]
        for idx in range(1, len(intervals)):
            curr_s, curr_e = intervals[idx]
            # [1, 4] and [5, 10]
            if prev_e < curr_s:
                ret.append([prev_s, prev_e])
                prev_s = curr_s
                prev_e = curr_e
            # [1, 4] and [2, 6]
            elif prev_e >= curr_s and prev_e < curr_e:
                prev_e = curr_e
        ret.append([prev_s, prev_e])
        return ret


if __name__ == '__main__':
    sol = Solution()

    intervals = [[1,3],[2,6],[8,10],[15,18]]
    expected = [[1,6],[8,10],[15,18]]
    assert sol.merge(intervals) == expected

    intervals = [[1,4],[4,5]]
    expected = [[1,5]]
    assert sol.merge(intervals) == expected

    intervals = [[1,5]]
    expected = [[1,5]]
    assert sol.merge(intervals) == expected

    intervals = []
    expected = []
    assert sol.merge(intervals) == expected

    intervals = [[1,4],[2,3]]
    expected = [[1,4]]
    assert sol.merge(intervals) == expected
