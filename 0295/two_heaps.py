import heapq
from typing import *


class PriorityQueue:

    def __init__(self, max_heap=False):
        self.heap = []
        heapq.heapify(self.heap)
        self.max_heap = max_heap

    def __len__(self):
        return len(self.heap)

    def top(self):
        if self.max_heap is False:
            return self.heap[0]
        else:
            return -self.heap[0]

    def push(self, num):
        if self.max_heap is False:
            heapq.heappush(self.heap, num)
        else:
            heapq.heappush(self.heap, -num)

    def pop(self):
        if self.max_heap is False:
            return heapq.heappop(self.heap)
        else:
            return -heapq.heappop(self.heap)


class MedianFinder:

    def __init__(self):
        self.max_heap = PriorityQueue(max_heap=True)
        self.min_heap = PriorityQueue()

    def addNum(self, num: int) -> None:
        self.max_heap.push(num)
        self.min_heap.push(self.max_heap.pop())
        if len(self.min_heap) > len(self.max_heap):
            self.max_heap.push(self.min_heap.pop())

    def findMedian(self) -> float:
        if len(self.max_heap) > len(self.min_heap):
            return self.max_heap.top()
        elif len(self.min_heap) > len(self.max_heap):
            return self.min_heap.top()
        else:
            return (self.max_heap.top() + self.min_heap.top()) / 2


if __name__ == '__main__':
    finder = MedianFinder()
    finder.addNum(1)
    finder.addNum(2)
    assert finder.findMedian() == 1.5
    finder.addNum(3)
    assert finder.findMedian() == 2
