from typing import List


# i = 4
# i=0 [1, 0, 0, 0, 0]
# i=1 [1, 1, 0, 0, 0]
# i=2 [1, 2, 1, 0, 0]
# i=3 [1, 3, 3, 1, 0]
# i=4 [1, 4, 6, 4, 1]
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ret = []
        prev = [0 for i in range(numRows)]
        curr = [0 for i in range(numRows)]
        for i in range(0, numRows):
            curr[0] = 1
            for j in range(1, i+1):
                curr[j] = prev[j] + prev[j-1]
            prev, curr = curr, prev
            ret.append(prev[0:i+1])
        return ret


if __name__ == '__main__':
    sol = Solution()

    numRows = 1
    expected = [[1]]
    assert sol.generate(numRows) == expected

    numRows = 2
    expected = [[1], [1, 1]]
    assert sol.generate(numRows) == expected

    numRows = 3
    expected = [[1], [1, 1], [1, 2, 1]]
    assert sol.generate(numRows) == expected

    numRows = 4
    expected = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]
    assert sol.generate(numRows) == expected

    numRows = 5
    expected = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
    assert sol.generate(numRows) == expected
