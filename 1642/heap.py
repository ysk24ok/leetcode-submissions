import heapq
from typing import *


class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        heap = []
        for i in range(len(heights) - 1):
            d = heights[i + 1] - heights[i]
            if d <= 0:
                continue
            heapq.heappush(heap, d)
            # Since we want to save ladders for the larger jumps,
            # in this case we have to consume bricks.
            if len(heap) > ladders:
                bricks -= heapq.heappop(heap)
                if bricks < 0:
                    return i
        return len(heights) - 1


if __name__ == '__main__':
    sol = Solution()

    heights, bricks, ladders, expected = [4, 2, 7, 6, 9, 14, 12], 5, 1, 4
    assert sol.furthestBuilding(heights, bricks, ladders) == expected

    heights, bricks, ladders, expected = [4, 12, 2, 7, 3, 18, 20, 3, 19], 10, 2, 7
    assert sol.furthestBuilding(heights, bricks, ladders) == expected

    heights, bricks, ladders, expected = [14, 3, 19, 3], 17, 0, 3
    assert sol.furthestBuilding(heights, bricks, ladders) == expected
