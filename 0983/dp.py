from typing import List


class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [0 for i in range(days[-1]+1)]
        idx = 0
        for day in range(1, days[-1]+1):
            if days[idx] != day:
                dp[day] = dp[day-1]
                continue
            dp[day] = min(
                dp[day-1] + costs[0],
                dp[day-7] + costs[1] if day - 7 >= 0 else costs[1],
                dp[day-30] + costs[2] if day - 30 >= 0 else costs[2]
            )
            idx += 1
        return dp[-1]


if __name__ == '__main__':
    sol = Solution()

    days, costs = [1, 4, 6, 7, 8, 20], [2, 7, 15]
    expected = 11
    assert sol.mincostTickets(days, costs) == expected

    days, costs = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31], [2, 7, 15]
    expected = 17
    assert sol.mincostTickets(days, costs) == expected
