class Solution:
    def arrangeCoins(self, n: int) -> int:
        ok, ng = 0, n + 1
        # We want the maximum `mid` that satifies this condition.
        # When `mid=0`, it always satifies the condition. So we set `ok = 0` (why not -1?).
        # When `mid=n+1`, it always dissatifies the condition. So we set `ng=n+1`.
        is_ok = lambda n, mid: mid * (mid + 1) <= n * 2
        while abs(ng - ok) > 1:
            mid = int((ng + ok) / 2);
            if is_ok(n, mid):
                ok = mid
            else:
                ng = mid
        return ok


if __name__ == '__main__':
    sol = Solution()

    # n = 7
    # mid:                 0 1 2 3  4  5  6
    # mid * (mid + 1) / 2: 0 1 3 6 10 15 21
    #                       n    mid    mid * (mid+1)
    assert sol.arrangeCoins(0) == 0         # 0
    assert sol.arrangeCoins(1) == 1         # 2
    assert sol.arrangeCoins(2) == 1         # 2
    assert sol.arrangeCoins(3) == 2         # 6
    assert sol.arrangeCoins(4) == 2         # 6
    assert sol.arrangeCoins(5) == 2         # 6
    assert sol.arrangeCoins(6) == 3         # 12
    assert sol.arrangeCoins(7) == 3         # 12
    assert sol.arrangeCoins(8) == 3         # 12
    assert sol.arrangeCoins(9) == 3         # 12
    assert sol.arrangeCoins(10) == 4        # 20
