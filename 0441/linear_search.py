class Solution:
    def arrangeCoins(self, n: int) -> int:
        row_count = 0
        count = 1
        while n >= count:
            n -= count
            count += 1
            row_count += 1
        return row_count


if __name__ == '__main__':
    sol = Solution()
    assert sol.arrangeCoins(0) == 0
    assert sol.arrangeCoins(1) == 1
    assert sol.arrangeCoins(2) == 1
    assert sol.arrangeCoins(3) == 2
    assert sol.arrangeCoins(4) == 2
    assert sol.arrangeCoins(5) == 2
    assert sol.arrangeCoins(6) == 3
    assert sol.arrangeCoins(7) == 3
    assert sol.arrangeCoins(8) == 3
