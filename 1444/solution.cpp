#include <gtest/gtest.h>

#include <vector>

using namespace std;

constexpr static int mod = 1e9 + 7;

class Solution {
 public:
  int ways(vector<string>& pizza, int k) {
    const size_t m = pizza.size();
    const size_t n = pizza[0].size();
    // m x n x k+1 (k = 0 is dummy)
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
    // m+1 x n+1 (i = m and j = n are dummy)
    vector<vector<int>> prefix_sum(m+1, vector<int>(n+1, 0));
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        prefix_sum[i][j] = prefix_sum[i+1][j] + prefix_sum[i][j+1] - prefix_sum[i+1][j+1];
        prefix_sum[i][j] += pizza[i][j] == 'A' ? 1 : 0;
      }
    }
    return dfs(pizza, prefix_sum, dp, 0, 0, k-1);
  }

  int dfs(const vector<string>& pizza, const vector<vector<int>>& prefix_sum, vector<vector<vector<int>>>& dp, int i, int j, int k) {
    // no apples are remaining
    if (prefix_sum[i][j] == 0) { return 0; }
    // valid when apples are remaining in the last piece
    if (k == 0) { return 1; }
    if (dp[i][j][k] != -1) { return dp[i][j][k]; }
    int ret = 0;
    // cut horizontally
    for (int h = i + 1, m = pizza.size(); h < m; ++h) {
      if (prefix_sum[h][j] >= prefix_sum[i][j]) { continue; }
      ret += dfs(pizza, prefix_sum, dp, h, j, k-1) % mod;
      ret %= mod;
    }
    // cut vertically
    for (int v = j + 1, n = pizza[0].size(); v < n; ++v) {
      if (prefix_sum[i][v] >= prefix_sum[i][j]) { continue; }
      ret += dfs(pizza, prefix_sum, dp, i, v, k-1) % mod;
      ret %= mod;
    }
    dp[i][j][k] = ret;
    return ret;
  }
};

int main() {
  Solution sol;
  vector<string> pizza;
  int k;

  pizza = {"A..", "AAA", "..."};
  k = 3;
  EXPECT_EQ(3, sol.ways(pizza, k));

  pizza = {"A..", "AA.", "..."};
  k = 3;
  EXPECT_EQ(1, sol.ways(pizza, k));

  pizza = {"A..", "A..", "..."};
  k = 1;
  EXPECT_EQ(1, sol.ways(pizza, k));

  pizza = {"AAAA.", "A..A.", "AA.AA"};
  k = 5;
  EXPECT_EQ(39, sol.ways(pizza, k));
}
