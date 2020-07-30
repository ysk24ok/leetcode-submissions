import heapq
from typing import List


class Item:

    def __init__(self, task, count):
        self.task = task
        self.count = count

    def __lt__(self, other):
        return self.count > other.count


class MaxHeap:

    def __init__(self):
        self.heap = []

    def push(self, item):
        heapq.heappush(self.heap, item)

    def pop(self):
        return heapq.heappop(self.heap)


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counts = {}
        for task in tasks:
            if task not in counts:
                counts[task] = 0
            counts[task] += 1
        pushed = {}
        max_heap = MaxHeap()
        for task, count in counts.items():
            max_heap.push(Item(task, count))
            pushed[task] = True
        freq_per_tasks = {}
        current_timesteps = 0
        while True:
            if len(max_heap.heap) > 0:
                item = max_heap.pop()
                counts[item.task] -= 1
                pushed[item.task] = False
                freq_per_tasks[item.task] = current_timesteps
            for task, timesteps in freq_per_tasks.items():
                if current_timesteps - timesteps >= n and counts[task] > 0 and not pushed[task]:
                    max_heap.push(Item(task, counts[task]))
                    pushed[task] = True
            current_timesteps += 1
            if self.is_all_tasks_processed(counts):
                break
        return current_timesteps

    def is_all_tasks_processed(self, counts):
        for count in counts.values():
            if count > 0:
                return False
        return True


if __name__ == '__main__':
    sol = Solution()

    tasks, n = ["A", "A", "A", "B", "B", "B"], 2
    expected = 8
    assert sol.leastInterval(tasks, n) == expected

    tasks, n = ["A", "A", "A", "B", "B", "B"], 0
    expected = 6
    assert sol.leastInterval(tasks, n) == expected

    tasks, n = ["A", "A", "A", "A", "A", "A", "B", "C", "D", "E", "F", "G"], 2
    expected = 16
    assert sol.leastInterval(tasks, n) == expected

    tasks, n = ["A", "B", "C", "D", "A", "B", "V"], 3
    expected = 7
    assert sol.leastInterval(tasks, n) == expected
