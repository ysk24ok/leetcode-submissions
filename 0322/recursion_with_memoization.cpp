#include "gtest/gtest.h"

#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount);
    return recursion(coins, amount, dp);
  }

  int recursion(const vector<int>& coins, int amount, vector<int>& dp) {
    if (amount == 0) return 0;
    else if (amount < 0) return -1;
    if (dp[amount-1] != 0) return dp[amount-1];
    size_t size = coins.size();
    int min_coins = numeric_limits<int>::max();
    for (int i = 0; i < size; i++) {
      int coin = coins[i];
      int num_coins = recursion(coins, amount-coin, dp);
      if (num_coins != -1) min_coins = min(num_coins + 1, min_coins);
    }
    dp[amount-1] = (min_coins == numeric_limits<int>::max()) ? -1 : min_coins;
    return dp[amount-1];
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
