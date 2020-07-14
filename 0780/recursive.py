from typing import *


class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        if tx < sx and ty < sy:
            return False
        if tx > ty:
            return self.recursive(sx, sy, tx, ty)
        else:
            return self.recursive(sy, sx, ty, tx)

    def recursive(self, sx, sy, tx, ty):
        if ty < sy:
            return False
        elif ty == sy:
            if tx < sx:
                return False
            return ((tx - sx) % sy) == 0
        else:
            return self.recursive(sy, sx, ty, tx % ty)


if __name__ == '__main__':
    sol = Solution()

    sx, sy, tx, ty = 1, 1, 3, 5
    assert sol.reachingPoints(sx, sy, tx, ty)

    sx, sy, tx, ty = 1, 1, 2, 2
    assert not sol.reachingPoints(sx, sy, tx, ty)

    sx, sy, tx, ty = 1, 1, 1, 1
    assert sol.reachingPoints(sx, sy, tx, ty)

    sx, sy, tx, ty = 1, 1, 1000000000, 1
    assert sol.reachingPoints(sx, sy, tx, ty)

    sx, sy, tx, ty = 9, 5, 12, 8
    assert not sol.reachingPoints(sx, sy, tx, ty)

    sx, sy, tx, ty = 9, 10, 9, 19
    assert sol.reachingPoints(sx, sy, tx, ty)

    sx, sy, tx, ty = 3, 7, 3, 4
    assert not sol.reachingPoints(sx, sy, tx, ty)
