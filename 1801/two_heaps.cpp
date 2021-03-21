#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

constexpr int mod = 1e9 + 7;

class Solution {
 public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    auto less = [](const pair<int, int>& left, const pair<int, int>& right) {
      return left.first < right.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(less)> buy_heap(less);
    auto greater = [](const pair<int, int>& left, const pair<int, int>& right) {
      return left.first > right.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> sell_heap(greater);
    for (const vector<int>& order : orders) {
      const int& price = order[0];
      int amount = order[1];
      if (order[2] == 0) { // buy
        while (!sell_heap.empty() && sell_heap.top().first <= price && amount > 0) {
          if (amount >= sell_heap.top().second) {
            amount -= sell_heap.top().second;
            sell_heap.pop();
          } else {
            const_cast<pair<int, int>&>(sell_heap.top()).second -= amount;
            amount = 0;
          }
        }
        if (amount > 0) {
          buy_heap.push({price, amount});
        }
      } else {  // sell
        while (!buy_heap.empty() && buy_heap.top().first >= price && amount > 0) {
          if (amount >= buy_heap.top().second) {
            amount -= buy_heap.top().second;
            buy_heap.pop();
          } else {
            const_cast<pair<int, int>&>(buy_heap.top()).second -= amount;
            amount = 0;
          }
        }
        if (amount > 0) {
          sell_heap.push({price, amount});
        }
      }
    }
    int ret = 0;
    while (!buy_heap.empty()) {
      ret += buy_heap.top().second;
      buy_heap.pop();
      ret %= mod;
    }
    while (!sell_heap.empty()) {
      ret += sell_heap.top().second;
      sell_heap.pop();
      ret %= mod;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> orders;
  int expected;

  orders = {{10, 5, 0}, {15, 2, 1}, {25, 1, 1}, {30, 4, 0}}, expected = 6;
  EXPECT_EQ(expected, sol.getNumberOfBacklogOrders(orders));

  orders = {{7, 1000000000, 1}, {15, 3, 0}, {5, 999999995, 0}, {5, 1, 1}}, expected = 999999984;
  EXPECT_EQ(expected, sol.getNumberOfBacklogOrders(orders));

  exit(EXIT_SUCCESS);
}
