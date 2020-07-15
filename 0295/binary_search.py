from typing import *


class MedianFinder:

    def __init__(self):
        self.nums = []

    def addNum(self, num: int) -> None:
        ok, ng = -1, len(self.nums)
        is_ok = lambda nums, mid, num: nums[mid] < num
        while abs(ng - ok) > 1:
            mid = int((ng - ok) / 2) + ok
            if (is_ok(self.nums, mid, num)):
                ok = mid
            else:
                ng = mid
        if ok < len(self.nums) - 1:
            self.nums.insert(ok+1, num)
        else:
            self.nums.append(num)

    def findMedian(self) -> float:
        if len(self.nums) % 2 == 0:
            idx = int(len(self.nums) / 2)
            return (self.nums[idx-1] + self.nums[idx]) / 2
        else:
            idx = int(len(self.nums) / 2)
            return self.nums[idx]


if __name__ == '__main__':
    finder = MedianFinder()
    finder.addNum(1)
    finder.addNum(2)
    assert finder.findMedian() == 1.5
    finder.addNum(3)
    assert finder.findMedian() == 2
