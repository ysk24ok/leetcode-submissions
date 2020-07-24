from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        first_row_idx, first_col_idx = 0, 0
        ret = []
        if len(matrix) == 0:
            return ret
        row_length, col_length = len(matrix), len(matrix[0])
        while row_length > 0 and col_length > 0:
            self.oneCycle(matrix, ret,
                          first_row_idx, first_col_idx, row_length, col_length)
            first_row_idx += 1
            first_col_idx += 1
            row_length -= 2
            col_length -= 2
        return ret

    def oneCycle(self, matrix, ret,
                 first_row_idx, first_col_idx, row_length, col_length):
        last_row_idx = first_row_idx + row_length - 1
        last_col_idx = first_col_idx + col_length - 1
        # first row
        for col_idx in range(first_col_idx, last_col_idx+1):
            ret.append(matrix[first_row_idx][col_idx])
        # last col
        for row_idx in range(first_row_idx+1, last_row_idx+1):
            ret.append(matrix[row_idx][last_col_idx])
        # last row
        if first_row_idx < last_row_idx:
            for col_idx in reversed(range(first_col_idx, last_col_idx)):
                ret.append(matrix[last_row_idx][col_idx])
        # first col
        if first_col_idx < last_col_idx:
            for row_idx in reversed(range(first_row_idx+1, last_row_idx)):
                ret.append(matrix[row_idx][first_col_idx])


if __name__ == '__main__':
    sol = Solution()

    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    expected = [1, 2, 3, 6, 9, 8, 7, 4, 5]
    assert sol.spiralOrder(matrix) == expected

    matrix = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12]
    ]
    expected = [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
    assert sol.spiralOrder(matrix) == expected

    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
        [10, 11, 12],
    ]
    expected = [1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8]
    assert sol.spiralOrder(matrix) == expected

    matrix = []
    expected = []
    assert sol.spiralOrder(matrix) == expected
