from typing import List


class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        # If the number of balls is greater than or equal to `m`,
        # a distance between two balls can be bigger.
        def isOk(d):
            prev_idx = 0
            num_balls = 1
            for idx in range(1, len(position)):
                if position[idx] - position[prev_idx] >= d:
                    num_balls += 1
                    prev_idx = idx
            return num_balls >= m

        position.sort()
        # `ok` and `ng` are a minimum distance between two balls.
        ok, ng = 0, position[-1] - position[0] + 1
        while (ng - ok) > 1:
            mid = int((ng - ok) / 2) + ok
            if isOk(mid):
                ok = mid
            else:
                ng = mid
        return ok


if __name__ == '__main__':
    sol = Solution()

    position, m = [1, 2, 3, 4, 7], 3
    expected = 3
    assert sol.maxDistance(position, m) == expected

    position, m = [5, 4, 3, 2, 1, 1000000000], 2
    expected = 999999999
    assert sol.maxDistance(position, m) == expected
