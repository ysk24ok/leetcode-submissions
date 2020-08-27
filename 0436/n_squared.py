from typing import List


# TODO: TLE
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        ret = [-1 for _ in range(n)]
        for i in range(n):
            # if j-th interval is to the right of i-th interval, ret[i] = j
            for j in range(n):
                if i == j:
                    continue
                if intervals[i][1] > intervals[j][0]:
                    continue
                if ret[i] == -1:
                    ret[i] = j
                    continue
                if intervals[j][0] < intervals[ret[i]][0]:
                    ret[i] = j
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
