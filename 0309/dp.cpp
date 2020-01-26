#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    size_t size = prices.size();
    if (size == 0) return 0;
    vector<int> buy(size, 0);
    vector<int> sell(size, 0);
    buy[0] -= prices[0];
    for (size_t i = 1; i < size; i++) {
      if (i == 1) {
        buy[i] = max(- prices[i], buy[i-1]);
      } else {
        buy[i] = max(sell[i-2] - prices[i], buy[i-1]);
      }
      sell[i] = max(buy[i-1] + prices[i], sell[i-1]);
    }
    return sell[size-1];
  }
};

int main() {
  Solution sol;
  vector<int> prices;

  prices = {1,2,3,0,2};
  assert(sol.maxProfit(prices) == 3);

  prices = {};
  assert(sol.maxProfit(prices) == 0);
}
