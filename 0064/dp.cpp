#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    const size_t m = grid.size();
    if (m == 0) return 0;
    const size_t n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, numeric_limits<int>::max()));
    dp[0][0] = grid[0][0];
    for (size_t i = 1; i < m; ++i) { dp[i][0] = dp[i-1][0] + grid[i][0]; }
    for (size_t j = 1; j < n; ++j) { dp[0][j] = dp[0][j-1] + grid[0][j]; }
    for (size_t i = 1; i < m; ++i) {
      for (size_t j = 1; j < n; ++j) {
        dp[i][j] = min({dp[i][j], dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]});
      }
    }
    return dp[m-1][n-1];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid;

  grid = {
    {1,3,1},
    {1,5,1},
    {4,2,1}
  };
  EXPECT_EQ(7, sol.minPathSum(grid));

  grid = {};
  EXPECT_EQ(0, sol.minPathSum(grid));
}
