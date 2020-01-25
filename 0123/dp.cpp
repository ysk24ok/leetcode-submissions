#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

constexpr int kTransactionCount = 2;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
// dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    size_t size = prices.size();
    if (size == 0) return 0;
    vector<vector<int>> dp(kTransactionCount+1, vector<int>(size, 0));
    for (size_t k = 1; k <= kTransactionCount; k++) {
      int valley = prices[0];
      for (size_t i = 1; i < size; i++) {
        valley = min(valley, prices[i] - dp[k-1][i-1]);
        dp[k][i] = max(
          prices[i] - valley,   // sell
          dp[k][i-1]  // do nothing
        );
      }
    }
    return dp[kTransactionCount][size-1];
  }
};

int main() {
  Solution sol;
  vector<int> prices;

  prices = {3,3,5,0,0,3,1,4};
  assert(sol.maxProfit(prices) == 6);

  prices = {1,2,3,4,5};
  assert(sol.maxProfit(prices) == 4);

  prices = {7,6,4,3,1};
  assert(sol.maxProfit(prices) == 0);
}
