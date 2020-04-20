#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

int dp[51][101][51] = {};
constexpr int mod = 1e9 + 7;

class Solution {
 public:
  int numOfArrays(int n, int m, int k) {
    memset(dp, 0, sizeof(dp));
    return dfs(n, m, k, 0, 0, 0);
  }

  int dfs(int n, int m, int k, int i, int current_max, int current_cost) {
    if (i == n) { return (current_cost == k) ? 1 : 0; }
    if (dp[i][current_max][current_cost] > 0) { return dp[i][current_max][current_cost] - 1; }
    int ret = 0;
    for (int num = 1; num <= m; ++num) {
      int new_max = current_max;
      int new_cost = current_cost;
      if (num > new_max) {
        new_cost++;
        new_max = num;
      }
      if (new_cost > k) { break; }
      ret += dfs(n, m, k, i + 1, new_max, new_cost);
      ret %= mod;
    }
    dp[i][current_max][current_cost] = ret + 1;
    return ret;
  }
};

int main() {
  Solution sol;
  int n, m, k;

  n = 2, m = 3, k = 1;
  ExpectEqual(6, sol.numOfArrays(n, m, k));

  n = 5, m = 2, k = 3;
  ExpectEqual(0, sol.numOfArrays(n, m, k));

  n = 9, m = 1, k = 1;
  ExpectEqual(1, sol.numOfArrays(n, m, k));

  n = 50, m = 100, k = 25;
  ExpectEqual(34549172, sol.numOfArrays(n, m, k));

  n = 37, m = 17, k = 7;
  ExpectEqual(418930126, sol.numOfArrays(n, m, k));
}
