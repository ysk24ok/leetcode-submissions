import random


def rand7():
    return random.randint(1, 7)


class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        row, col = 7, 7
        idx = (row - 1) * 7 + col
        while idx > 40:
            row = rand7()
            col = rand7()
            idx = (row - 1) * 7 + col
        return idx % 10 + 1


if __name__ == '__main__':
    sol = Solution()

    for _ in range(10):
        got = sol.rand10()
        assert got >= 1 and got <= 10
