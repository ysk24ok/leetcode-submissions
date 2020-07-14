from typing import *


class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        short_hand = minutes * 360 / 60
        long_hand = hour * 30 + minutes * 30 / 60
        angle = long_hand - short_hand
        if angle < 0:
            angle *= -1
        return min(angle, 360 - angle)


if __name__ == '__main__':
    sol = Solution()

    hour, minutes, expected = 12, 30, 165
    assert sol.angleClock(hour, minutes) == expected

    hour, minutes, expected = 3, 15, 7.5
    assert sol.angleClock(hour, minutes) == expected

    hour, minutes, expected = 4, 50, 155
    assert sol.angleClock(hour, minutes) == expected

    hour, minutes, expected = 12, 0, 0
    assert sol.angleClock(hour, minutes) == expected
