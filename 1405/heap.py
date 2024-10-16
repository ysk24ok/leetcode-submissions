import heapq
from typing import *

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        heap = []
        if a > 0:
            heapq.heappush(heap, (-a, "a"))
        if b > 0:
            heapq.heappush(heap, (-b, "b"))
        if c > 0:
            heapq.heappush(heap, (-c, "c"))

        chars = []
        while len(heap) > 0:
            score, c = heapq.heappop(heap)
            if len(chars) >= 2 and chars[-2] == c and chars[-1] == c:
                if len(heap) == 0:
                    break
                next_score, next_c = heapq.heappop(heap)
                chars.append(next_c)
                heapq.heappush(heap, (score, c))
                if next_score < -1:
                    heapq.heappush(heap, (next_score + 1, next_c))
            else:
                chars.append(c)
                if score < -1:
                    heapq.heappush(heap, (score + 1, c))
        return "".join(chars)


if __name__ == '__main__':
    sol = Solution()

    a, b, c = 1, 1, 7
    expected = ("ccaccbcc", "ccbccacc")
    assert sol.longestDiverseString(a, b, c) in expected

    a, b, c = 7, 1, 0
    expected = "aabaa"
    assert sol.longestDiverseString(a, b, c) == expected
