#include "gtest/gtest.h"

#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (const int& coin : coins) {
        if ((i - coin) < 0 || dp[i - coin] == numeric_limits<int>::max()) {
          continue;
        }
        dp[i] = min(dp[i - coin] + 1, dp[i]);
      }
    }
    return dp[amount] < numeric_limits<int>::max() ? dp[amount] : -1;
  }
};

int main() {
  Solution sol;
  vector<int> coins;
  int amount, expected;

  coins = {1, 2, 5}, amount = 11, expected = 3;
  EXPECT_EQ(expected, sol.coinChange(coins, amount));

  coins = {2}, amount = 3, expected = -1;
  EXPECT_EQ(expected, sol.coinChange(coins, amount));

  // This is a counterexample of a greedy method.
  // If solved in a greedy way, 153 = 100x1 + 30x1 + 1x23 (total 25)
  // but actually 153 = 30x5 + 1x3 (total 8).
  coins = {1, 30, 100}, amount = 153, expected = 8;
  EXPECT_EQ(expected, sol.coinChange(coins, amount));

  coins = {186, 419, 83, 408}, amount = 6249, expected = 20;
  EXPECT_EQ(expected, sol.coinChange(coins, amount));
}
