from typing import List


class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        starts = {}
        intervals = {}
        for idx, c in enumerate(S):
            if c not in intervals:
                intervals[c] = [idx, idx]
                starts[idx] = c
            if idx > intervals[c][1]:
                intervals[c][1] = idx
        ret = []
        idx = 0
        while idx < len(S):
            c = starts[idx]
            partition = [intervals[c][0], intervals[c][1]]
            for c, (start, end) in intervals.items():
                if partition[0] < start and start < partition[1]:
                    partition[1] = max(partition[1], end)
            idx = partition[1] + 1
            ret.append(idx - partition[0])
        return ret


if __name__ == '__main__':
    sol = Solution()

    S = "ababcbacadefegdehijhklij"
    expected = [9, 7, 8]
    sol.partitionLabels(S)
