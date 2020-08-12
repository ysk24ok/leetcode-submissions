from typing import List


# i = 4
# i=0 [1, 0, 0, 0, 0]
# i=1 [1, 1, 0, 0, 0]
# i=2 [1, 2, 1, 0, 0]
# i=3 [1, 3, 3, 1, 0]
# i=4 [1, 4, 6, 4, 1]
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        prev = [0 for i in range(rowIndex+1)]
        curr = [0 for i in range(rowIndex+1)]
        for i in range(0, rowIndex+1):
            curr[0] = 1
            for j in range(1, i+1):
                curr[j] = prev[j] + prev[j-1]
            prev, curr = curr, prev
        return prev


if __name__ == '__main__':
    sol = Solution()

    rowIndex = 0
    expected = [1]
    assert sol.getRow(rowIndex) == expected

    rowIndex = 2
    expected = [1, 2, 1]
    assert sol.getRow(rowIndex) == expected

    rowIndex = 3
    expected = [1, 3, 3, 1]
    assert sol.getRow(rowIndex) == expected

    rowIndex = 4
    expected = [1, 4, 6, 4, 1]
    assert sol.getRow(rowIndex) == expected
