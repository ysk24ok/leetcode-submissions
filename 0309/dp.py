from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        buy = [0 for _ in range(len(prices))]
        sell = [0 for _ in range(len(prices))]
        # day 1
        buy[0] = -prices[0]
        # day 2
        buy[1] = max(-prices[1], buy[0])
        sell[1] = max(buy[0] + prices[1], sell[0])
        # after day 3
        for idx in range(2, len(prices)):
            # sell at day i-2 and buy at day i,
            # or buy at day i-1 and do nothing at day i
            buy[idx] = max(sell[idx-2] - prices[idx], buy[idx-1])
            # buy at day i-1 and sell at day i,
            # or sell at day i-1 and do nothing at day i
            sell[idx] = max(buy[idx-1] + prices[idx], sell[idx-1])
        return sell[-1]


if __name__ == '__main__':
    sol = Solution()

    prices = [1, 2, 3, 0, 2]
    expected = 3
    assert sol.maxProfit(prices) == expected

    prices = [3, 5]
    expected = 2
    assert sol.maxProfit(prices) == expected
