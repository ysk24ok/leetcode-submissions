from typing import List


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        ret = 0
        for j in range(len(mat[0])):
            indices = []
            for i in range(len(mat)):
                if mat[i][j] != 0:
                    indices.append(i)
                if len(indices) > 1:
                    for i in indices:
                        mat[i][j] = -1
        for i in range(len(mat)):
            indices = []
            for j in range(len(mat[0])):
                if mat[i][j] != 0:
                    indices.append(j)
                if len(indices) > 1:
                    for j in indices:
                        mat[i][j] = -1
        ret = 0
        for row in mat:
            for val in row:
                if val == 1:
                    ret += 1
        return ret


if __name__ == '__main__':
    sol = Solution()

    mat = [
        [1, 0, 0],
        [0, 0, 1],
        [1, 0, 0]
    ]
    expected = 1
    assert sol.numSpecial(mat) == expected

    mat = [
        [1, 0, 0],
        [0, 1, 0],
        [0, 0, 1]
    ]
    expected = 3
    assert sol.numSpecial(mat) == expected

    mat = [
        [0, 0, 0, 1],
        [1, 0, 0, 0],
        [0, 1, 1, 0],
        [0, 0, 0, 0]
    ]
    expected = 2
    assert sol.numSpecial(mat) == expected

    mat = [
        [0, 0, 0, 0, 0],
        [1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 0, 1, 1]
    ]
    expected = 3
    assert sol.numSpecial(mat) == expected

    mat = [
        [0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 1],
        [0, 0, 0, 0, 1, 0, 0, 0],
        [1, 0, 0, 0, 1, 0, 0, 0],
        [0, 0, 1, 1, 0, 0, 0, 0]
    ]
    expected = 1
    assert sol.numSpecial(mat) == expected
