from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        m = len(citations)
        ret = 0
        for idx in range(m):
            h = min(m - idx, citations[idx])
            ret = max(ret, h)
        return ret


if __name__ == '__main__':
    sol = Solution()

    # 0, 1, 3, 5, 6
    citations = [3, 0, 6, 1, 5]
    expected = 3
    assert sol.hIndex(citations) == expected

    citations = [0, 3, 3, 5, 6]
    expected = 3
    assert sol.hIndex(citations) == expected

    citations = [0]
    expected = 0
    assert sol.hIndex(citations) == expected

    citations = [100]
    expected = 1
    assert sol.hIndex(citations) == expected
