import heapq


class PriorityQueue:

    def __init__(self):
        self.heap = []
        heapq.heapify(self.heap)

    def __len__(self):
        return len(self.heap)

    def top(self):
        return self.heap[0]

    def push(self, num):
        heapq.heappush(self.heap, num)

    def pop(self):
        return heapq.heappop(self.heap)
