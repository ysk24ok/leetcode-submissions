#include <algorithm>
#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    const size_t m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ret = 0;
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) { continue; }
        ret += dfs(matrix, i, j, dp);
      }
    }
    return ret;
  }

  int dfs(const vector<vector<int>>& matrix, size_t i, size_t j, vector<vector<int>>& dp) {
    const size_t m = matrix.size(), n = matrix[0].size();
    if (i >= m || j >= n || matrix[i][j] == 0) { return 0; }
    if (dp[i][j] != -1) { return dp[i][j]; }
    int a = dfs(matrix, i + 1, j, dp), b = dfs(matrix, i, j + 1, dp), c = dfs(matrix, i + 1, j + 1, dp);
    dp[i][j] = min({a, b, c}) + 1;
    return dp[i][j];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix;

  matrix = {
    {0,1,1,1},
    {1,1,1,1},
    {0,1,1,1}
  };
  EXPECT_EQ(15, sol.countSquares(matrix));

  matrix = {
    {1,0,1},
    {1,1,0},
    {1,1,0}
  };
  EXPECT_EQ(7, sol.countSquares(matrix));

  matrix = {
    {0,1,1,0},
    {1,0,1,1},
    {0,1,1,1}
  };
  EXPECT_EQ(9, sol.countSquares(matrix));

  exit(EXIT_SUCCESS);
}
