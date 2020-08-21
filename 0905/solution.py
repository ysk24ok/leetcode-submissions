from typing import List


class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        odd_idx = 0
        for idx in range(len(A)):
            if A[idx] % 2 == 0:
                A[idx], A[odd_idx] = A[odd_idx], A[idx]
                odd_idx += 1
        return A


if __name__ == '__main__':
    sol = Solution()

    A = [3, 1, 2, 4]
    expected = [2, 4, 3, 1]
    assert sol.sortArrayByParity(A) == expected

    A = [2, 4, 3, 1]
    expected = [2, 4, 3, 1]
    assert sol.sortArrayByParity(A) == expected
