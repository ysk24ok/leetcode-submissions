from typing import *


class MedianFinder:

    def __init__(self):
        self._list = []

    def addNum(self, num: int) -> None:
        self._list.append(num)
        self._list.sort()

    def findMedian(self) -> float:
        if len(self._list) % 2 == 0:
            idx = int(len(self._list) / 2)
            return (self._list[idx-1] + self._list[idx]) / 2
        else:
            idx = int(len(self._list) / 2)
            return self._list[idx]


if __name__ == '__main__':
    finder = MedianFinder()
    finder.addNum(1)
    finder.addNum(2)
    assert finder.findMedian() == 1.5
    finder.addNum(3)
    assert finder.findMedian() == 2
