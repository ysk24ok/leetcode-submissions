#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

// dp[k][i] = max(dp[k][i-1], dp[k-1][j-1] + prices[i] - prices[j]) 
// transaction/prices| 3| 2| 6| 5| 0| 3|
// -------------------------------------
//                  0| 0| 0| 0| 0| 0| 0|
//                  1| 0| 0| 4| 4| 4| 4|
//                  2| 0| 0| 4| 4| 4| 7|
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    const size_t n = prices.size();
    if (n == 0) { return 0; }
    k = min(k, static_cast<int>(n / 2));
    vector<int> dp_prev(n);
    vector<int> dp_curr(n);
    for (int transaction = 1; transaction <= k; ++transaction) {
      int max_profit = -prices[0];  // buy
      for (int t = 1; t < n; ++t) {
        dp_curr[t] = max(
          dp_curr[t-1],           // stay
          prices[t] + max_profit  // sell
        );
        max_profit = max(
          max_profit,                 // but at previous t
          dp_prev[t-1] - prices[t]    // buy at t
        );
      }
      dp_curr.swap(dp_prev);
    }
    return dp_prev[n-1];
  }
};

int main() {
  Solution sol;
  int k;
  vector<int> prices;
  int expected;

  k = 2, prices = {2, 4, 1};
  expected = 2;
  EXPECT_EQ(expected, sol.maxProfit(k, prices));

  k = 2, prices = {3, 2, 6, 5, 0, 3};
  expected = 7;
  EXPECT_EQ(expected, sol.maxProfit(k, prices));

  exit(EXIT_SUCCESS);
}
