from typing import List


class Solution:
    def numsSameConsecDiff(self, N: int, K: int) -> List[int]:
        self.ret = []
        start = 1 if N > 1 else 0
        for num in range(start, 10):
            self.recursion(num, 0, N, K)
        return self.ret

    def recursion(self, num, idx, N, K):
        if idx == N - 1:
            self.ret.append(num)
            return
        prev_digit = num % 10
        if K == 0:
            self.recursion(num * 10 + prev_digit, idx + 1, N, K)
        else:
            if prev_digit - K >= 0:
                self.recursion(num * 10 + prev_digit - K, idx + 1, N, K)
            if prev_digit + K <= 9:
                self.recursion(num * 10 + prev_digit + K, idx + 1, N, K)


if __name__ == '__main__':
    sol = Solution()

    N, K = 3, 7
    expected = [181, 292, 707, 818, 929]
    assert sol.numsSameConsecDiff(N, K) == expected

    N, K = 2, 1
    expected = [
        10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98]
    assert sol.numsSameConsecDiff(N, K) == expected

    N, K = 1, 0
    expected = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    assert sol.numsSameConsecDiff(N, K) == expected

    N, K = 2, 0
    expected = [11, 22, 33, 44, 55, 66, 77, 88, 99]
    assert sol.numsSameConsecDiff(N, K) == expected
