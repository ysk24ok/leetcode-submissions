#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    size_t size = prices.size();
    if (size <= 1) return 0;
    vector<int> buy(size);
    vector<int> sell(size);
    buy[0] = - prices[0] - fee;
    for (size_t i = 1; i < size; i++) {
      buy[i] = max(sell[i-1] - prices[i] - fee, buy[i-1]);  // buy stock or do nothing
      sell[i] = max(prices[i] + buy[i-1], sell[i-1]);   // sell stock or do nothing
    }
    return sell[size - 1];
  }
};

int main() {
  Solution sol;
  vector<int> prices;
  int got;

  prices = {1,3,2,8,4,9};
  assert(sol.maxProfit(prices, 2) == 8);

  prices = {7,1,5,3,6,7,4};
  assert(sol.maxProfit(prices, 3) == 3);

  prices = {1,3,7,5,10,3};
  assert(sol.maxProfit(prices, 3) == 6);

  prices = {};
  assert(sol.maxProfit(prices, 1) == 0);

  prices = {1,2};
  assert(sol.maxProfit(prices, 1) == 0);

  prices = {1,4};
  assert(sol.maxProfit(prices, 1) == 2);

  prices = {2,1};
  assert(sol.maxProfit(prices, 1) == 0);

  prices = {1,4,3};
  assert(sol.maxProfit(prices, 1) == 2);
}
