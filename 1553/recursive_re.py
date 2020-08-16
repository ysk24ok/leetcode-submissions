# causes RecursionError: maximum recursion depth exceeded in comparison
class Solution:
    def minDays(self, n: int) -> int:
        memo = {}
        return self.recursion(n, memo)

    def recursion(self, n, memo):
        if n <= 2:
            return n
        if n in memo:
            return memo[n]
        ret = self.recursion(n - 1, memo)
        if n % 3 == 0:
            ret = min(ret, self.recursion(int(n / 3), memo))
        if n % 2 == 0:
            ret = min(ret, self.recursion(int(n / 2), memo))
        memo[n] = ret + 1
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
