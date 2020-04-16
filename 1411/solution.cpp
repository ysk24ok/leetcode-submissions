#include <array>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

int dp[5001][4][4][4] = {};
constexpr array<int, 3> colors = {1, 2, 3};
constexpr int mod = 1e9+7;

class Solution {
 public:
  int numOfWays(int n) {
    return dfs(n, 0, 0, 0);
  }

  int dfs(int n, int a0, int b0, int c0) {
    if (n == 0) { return 1; }
    if (dp[n][a0][b0][c0] != 0) { return dp[n][a0][b0][c0]; }
    int ret = 0;
    for (const auto& a : colors) {
      if (a == a0) { continue; }
      for (const auto& b : colors) {
        if (b == b0 || b == a) { continue; }
        for (const auto& c : colors) {
          if (c == c0 || c == b) { continue; }
          ret += dfs(n-1, a, b, c);
          ret %= mod;
        }
      }
    }
    dp[n][a0][b0][c0] = ret;
    return ret;
  }
};

int main() {
  Solution sol;
  ExpectEqual(12, sol.numOfWays(1));
  ExpectEqual(54, sol.numOfWays(2));
  ExpectEqual(246, sol.numOfWays(3));
  ExpectEqual(106494, sol.numOfWays(7));
  ExpectEqual(30228214, sol.numOfWays(5000));
}
