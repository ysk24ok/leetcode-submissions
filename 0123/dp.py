from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        # dp[t, i] = max(dp[t, i-1],
        #                dp[t-1, j] - prices[j] + prices[i]) (0 <= j < n)
        num_transactions = 2
        dp = [[0 for _ in range(len(prices))]
              for _ in range(num_transactions+1)]
        for transaction in range(1, num_transactions+1):
            max_profit_when_buy = - 2 ** 32
            for day in range(1, len(prices)):
                max_profit_when_buy = max(
                    max_profit_when_buy,
                    dp[transaction-1][day-1] - prices[day-1]
                )
                dp[transaction][day] = max(
                    dp[transaction][day-1],
                    max_profit_when_buy + prices[day]
                )
        return dp[num_transactions][len(prices)-1]


if __name__ == '__main__':
    sol = Solution()

    prices = [3, 3, 5, 0, 0, 3, 1, 4]
    expected = 6
    assert sol.maxProfit(prices) == expected

    prices = [1, 2, 3, 4, 5]
    expected = 4
    assert sol.maxProfit(prices) == expected
