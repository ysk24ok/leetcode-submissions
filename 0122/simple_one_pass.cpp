#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ret = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
      ret += max(prices[i] - prices[i-1], 0);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> prices;

  prices = {7,1,5,3,6,4};
  assert(sol.maxProfit(prices) == 7);

  prices = {1,2,3,4,5};
  assert(sol.maxProfit(prices) == 4);

  prices = {7,1,5,3,6,7,4};
  assert(sol.maxProfit(prices) == 8);

  prices = {};
  assert(sol.maxProfit(prices) == 0);

  prices = {1};
  assert(sol.maxProfit(prices) == 0);

  prices = {1,2};
  assert(sol.maxProfit(prices) == 1);

  prices = {2,1};
  assert(sol.maxProfit(prices) == 0);
}
