from typing import List


class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        start2idx = {}
        for idx, interval in enumerate(intervals):
            start2idx[interval[0]] = idx
        starts = sorted([interval[0] for interval in intervals])
        ret = []
        for interval in intervals:
            end = interval[1]
            ng, ok = -1, len(starts)
            while ok - ng > 1:
                mid = int((ok - ng) / 2) + ng
                if end <= starts[mid]:
                    ok = mid
                else:
                    ng = mid
            ret.append(start2idx[starts[ok]] if ok < len(starts) else -1)
        return ret


if __name__ == '__main__':
    sol = Solution()

    intervals = [[1, 2]]
    expected = [-1]
    assert sol.findRightInterval(intervals) == expected

    intervals = [[3, 4], [2, 3], [1, 2]]
    expected = [-1, 0, 1]
    assert sol.findRightInterval(intervals) == expected

    intervals = [[1, 4], [2, 3], [3, 4]]
    expected = [-1, 2, -1]
    assert sol.findRightInterval(intervals) == expected
