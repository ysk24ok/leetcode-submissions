class Solution:
    def minDays(self, n: int) -> int:
        memo = {}
        return self.recursion(n, memo)

    def recursion(self, n, memo):
        if n <= 2:
            return n
        if n in memo:
            return memo[n]
        memo[n] = 1 + min(
            n % 2 + self.recursion(int(n / 2), memo),
            n % 3 + self.recursion(int(n / 3), memo)
        )
        return memo[n]


if __name__ == '__main__':
    sol = Solution()

    assert sol.minDays(10) == 4
    assert sol.minDays(6) == 3
    assert sol.minDays(1) == 1
    assert sol.minDays(56) == 6
    assert sol.minDays(993654) == 20
    assert sol.minDays(9209408) == 23
    assert sol.minDays(84806671) == 32
