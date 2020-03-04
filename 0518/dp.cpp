#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int& coin : coins) {
      for (int i = coin; i <= amount; i++) {
        dp[i] += dp[i-coin];
      }
    }
    return dp[amount];
  }
};

int main() {
  Solution sol;
  vector<int> coins;
  int amount;

  // amount=1, (1)
  // amount=2, (1,1),(2)
  // amount=3, (1,1,1),(1,2)
  // amount=4, (1,1,1,1),(1,1,2),(2,2)
  // amount=5, (1,1,1,1,1),(1,1,1,2),(1,2,2),(5)
  coins = {1,2,5};
  amount = 5;
  assert(sol.change(amount, coins) == 4);

  // amount=1, (1)
  // amount=2, (2),(1,1)
  // amount=3, (2,1),(1,1,1)
  // amount=4, (2,2),(2,1,1),(1,1,1,1)
  // amount=5, (2,2,1),(2,1,1,1),(1,1,1,1,1),(5)
  coins = {2,1,5};
  amount = 5;
  assert(sol.change(amount, coins) == 4);

  coins = {2};
  amount = 3;
  assert(sol.change(amount, coins) == 0);

  coins = {10};
  amount = 10;
  assert(sol.change(amount, coins) == 1);
}
