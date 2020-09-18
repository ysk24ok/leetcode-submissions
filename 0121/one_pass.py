from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ret = 0
        if len(prices) == 0:
            return ret
        valley, peak = prices[0], prices[0]
        for idx in range(1, len(prices)):
            price = prices[idx]
            if price < peak:
                ret = max(ret, peak - valley)
            peak = price
            valley = min(valley, price)
        ret = max(ret, peak - valley)
        return ret


if __name__ == '__main__':
    sol = Solution()

    prices = [7, 1, 5, 3, 6, 4]
    expected = 5
    assert sol.maxProfit(prices) == expected

    prices = [7, 6, 4, 3, 1]
    expected = 0
    assert sol.maxProfit(prices) == expected

    prices = []
    expected = 0
    assert sol.maxProfit(prices) == expected

    prices = [1, 2]
    expected = 1
    assert sol.maxProfit(prices) == expected
