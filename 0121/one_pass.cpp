#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ret = 0;
    if (prices.size() == 0) return ret;
    int min_price = prices[0];
    for (size_t i = 1; i < prices.size(); ++i) {
      min_price = min(min_price, prices[i]);
      ret = max(ret, prices[i] - min_price);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> prices;

  prices = {7,1,5,3,6,4};
  assert(sol.maxProfit(prices) == 5);

  prices = {7,6,4,3,1};
  assert(sol.maxProfit(prices) == 0);

  prices = {};
  assert(sol.maxProfit(prices) == 0);
}
