#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

/**
 * (amount, index)
 * (5, 2) -> (0, 1) o
 *        -> (5, 1) -> (1, 0) -> (0, -1) o
 *                  -> (3, 0) -> (0, -1) o
 *                            -> (1, -1) x
 *                            -> (2, -1) x
 *                            -> (3, -1) x
 *                  -> (5, 0) -> (0, -1) o
 *                            -> (1, -1) x
 *                            -> ...
 *
 *     |   coin
 *     |  1  2  5
 * ---------------
 * a 0 | -1 -1 -1
 * m 1 |  1 -1 -1
 * o 2 | -1 -1 -1
 * u 3 |  1 -1 -1
 * n 4 | -1 -1 -1
 * t 5 |  1  3  4
 */
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
    return recursion(dp, amount, coins.size()-1, coins);
  }

  int recursion(vector<vector<int>>& dp, int amount, int index, const vector<int>& coins) {
    if (amount == 0) { return 1; }
    if (index < 0) { return 0; }
    if (dp[amount][index] != -1) { return dp[amount][index]; }
    int count = 0;
    int num = amount / coins[index];
    while (num >= 0) {
      int new_amount = amount - num * coins[index];
      if (new_amount < 0) { break; }
      int got = recursion(dp, new_amount, index-1, coins);
      count += got;
      num--;
    }
    dp[amount][index] = count;
    return count;
  }
};

int main() {
  Solution sol;
  vector<int> coins;
  int amount;

  coins = {1,2,5};
  amount = 5;
  EXPECT_EQ(4, sol.change(amount, coins));

  coins = {2,1,5};
  amount = 5;
  assert(sol.change(amount, coins) == 4);

  coins = {2};
  amount = 3;
  assert(sol.change(amount, coins) == 0);

  coins = {10};
  amount = 10;
  assert(sol.change(amount, coins) == 1);

  exit(EXIT_SUCCESS);
}
