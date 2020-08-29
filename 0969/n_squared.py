from typing import List


class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        res = []
        for x in range(len(A), 1, -1):
            i = A.index(x)
            res.extend([i + 1, x])
            A = A[:i:-1] + A[:i]
        return res


if __name__ == '__main__':
    sol = Solution()

    A = [3, 2, 4, 1]
    expected = [3, 4, 2, 3, 1, 2]
    assert sol.pancakeSort(A) == expected
    sol = Solution()

    A = [1, 2, 3]
    expected = [3, 3, 2, 2]
    assert sol.pancakeSort(A) == expected
