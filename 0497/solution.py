import random
from typing import List


class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.rect_indices = [i for i in range(len(self.rects))]
        self.weights = [(rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1)
                        for rect in rects]

    def pick(self) -> List[int]:
        if len(self.rects) == 0:
            return []
        rect_idx = random.choices(self.rect_indices, weights=self.weights)[0]
        rect = self.rects[rect_idx]
        return [random.randint(rect[0], rect[2]),
                random.randint(rect[1], rect[3])]


if __name__ == '__main__':
    rects = [[1, 1, 5, 5]]
    sol = Solution(rects)
    sol.pick()
