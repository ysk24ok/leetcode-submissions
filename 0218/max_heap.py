import heapq
from collections import defaultdict
from typing import List


class MaxHeap(object):

    def __init__(self):
        self.heap = []
        heapq.heapify(self.heap)

    def top(self):
        assert len(self.heap) > 0
        return self.heap[0]

    def push(self, item):
        heapq.heappush(self.heap, item)

    def pop(self):
        return heapq.heappop(self.heap)

    def empty(self):
        return len(self.heap) == 0


class Building:

    def __init__(self, height):
        self.height = height
        self.active = True

    def __lt__(self, other):
        return self.height >= other.height

    def deactivate(self):
        self.active = False

    def is_deactivated(self):
        return self.active is False


# https://briangordon.github.io/2014/08/the-skyline-problem.html
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        points = defaultdict(list)
        for start, end, height in buildings:
            building = Building(height)
            points[start].append(('add', building))
            points[end].append(('del', building))
        ret = []
        max_heap = MaxHeap()
        current_highest = 0
        for x, L in sorted(points.items(), key=lambda x: x[0]):
            for operation, building in L:
                if operation == 'add':
                    max_heap.push(building)
                elif operation == 'del':
                    building.deactivate()
            while not max_heap.empty() and max_heap.top().is_deactivated():
                max_heap.pop()
            if not max_heap.empty():
                highest = max_heap.top().height
                if current_highest != highest:
                    ret.append([x, highest])
                    current_highest = highest
            else:
                ret.append([x, 0])
        return ret


if __name__ == '__main__':
    sol = Solution()

    buildings = [[2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 10], [19, 24, 8]]
    expected = [[2, 10], [3, 15], [7, 12], [12, 0], [15, 10], [20, 8], [24, 0]]
    assert sol.getSkyline(buildings) == expected

    buildings = [[0, 1, 3]]
    expected = [[0, 3], [1, 0]]
    assert sol.getSkyline(buildings) == expected

    buildings = [[0, 2147483647, 2147483647]]
    expected = [[0, 2147483647], [2147483647, 0]]
    assert sol.getSkyline(buildings) == expected
