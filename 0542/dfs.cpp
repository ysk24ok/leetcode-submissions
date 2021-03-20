#include "gtest/gtest.h"

#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, numeric_limits<int>::max()));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dfs(matrix, dp, i, j);
      }
    }
    return dp;
  }

  int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
    const int m = matrix.size(), n = matrix[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return numeric_limits<int>::max();
    }
    // We have to do recursion when dp[i][j] is not in (0, 1)
    // because there may be shorter path to the nearest 0
    if (dp[i][j] == 0 || dp[i][j] == 1) {
      return dp[i][j];
    }
    if (matrix[i][j] == 0) {
      dp[i][j] = 0;
      return dp[i][j];
    } else if (matrix[i][j] == -1) {
      return dp[i][j];
    }
    matrix[i][j] = -1;  // mark as visited
    int d1 = dfs(matrix, dp, i+1, j);
    int d2 = dfs(matrix, dp, i, j+1);
    int d3 = dfs(matrix, dp, i-1, j);
    int d4 = dfs(matrix, dp, i, j-1);
    // When one of neighbor cells is 0,
    // it is clear that the distance to nearest 0 is 1
    if (d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0) {
      dp[i][j] = 1;
    } else {
      dp[i][j] = min({d1, d2, d3, d4, dp[i][j]});
      if (dp[i][j] < numeric_limits<int>::max()) {
        dp[i][j] += 1;
      }
    }
    matrix[i][j] = 1;
    return dp[i][j];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix, expected;

  matrix = {
    {0,0,0},
    {0,1,0},
    {0,0,0}
  };
  EXPECT_EQ(matrix, sol.updateMatrix(matrix));

  matrix = {
    {0,0,0},
    {0,1,0},
    {1,1,1}
  };
  expected = {
    {0,0,0},
    {0,1,0},
    {1,2,1}
  };
  EXPECT_EQ(expected, sol.updateMatrix(matrix));

  matrix = {
    {1,1,1},
    {1,1,0},
    {1,0,1}
  };
  expected = {
    {3,2,1},
    {2,1,0},
    {1,0,1}
  };
  EXPECT_EQ(expected, sol.updateMatrix(matrix));

  matrix = {
    {1,0,1,1,0,0,1,0,0,1},
    {0,1,1,0,1,0,1,0,1,1},
    {0,0,1,0,1,0,0,1,0,0},
    {1,0,1,0,1,1,1,1,1,1},
    {0,1,0,1,1,0,0,0,0,1},
    {0,0,1,0,1,1,1,0,1,0},
    {0,1,0,1,0,1,0,0,1,1},
    {1,0,0,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,0,1,0},
    {1,1,1,1,0,1,0,0,1,1}
  };
  expected = {
    {1,0,1,1,0,0,1,0,0,1},
    {0,1,1,0,1,0,1,0,1,1},
    {0,0,1,0,1,0,0,1,0,0},
    {1,0,1,0,1,1,1,1,1,1},
    {0,1,0,1,1,0,0,0,0,1},
    {0,0,1,0,1,1,1,0,1,0},
    {0,1,0,1,0,1,0,0,1,1},
    {1,0,0,0,1,2,1,1,0,1},
    {2,1,1,1,1,2,1,0,1,0},
    {3,2,2,1,0,1,0,0,1,1}
  };
  EXPECT_EQ(expected, sol.updateMatrix(matrix));

  matrix = {
    {1,1,1,1,1,1,0,1,1,1},
    {1,1,0,0,0,0,0,1,1,1},
    {0,1,0,1,1,1,1,0,0,0},
    {1,1,1,0,0,1,1,0,1,1},
    {1,0,1,1,1,0,1,1,1,1},
    {1,1,0,0,1,0,1,1,1,1},
    {1,0,1,0,0,0,1,1,0,1},
    {1,1,0,1,1,1,1,0,0,1},
    {1,1,1,1,0,0,0,1,1,0},
    {1,1,1,0,1,1,0,1,1,1}
  };
  expected = {
    {2,2,1,1,1,1,0,1,2,2},
    {1,1,0,0,0,0,0,1,1,1},
    {0,1,0,1,1,1,1,0,0,0},
    {1,1,1,0,0,1,1,0,1,1},
    {1,0,1,1,1,0,1,1,2,2},
    {2,1,0,0,1,0,1,2,1,2},
    {1,0,1,0,0,0,1,1,0,1},
    {2,1,0,1,1,1,1,0,0,1},
    {3,2,1,1,0,0,0,1,1,0},
    {3,2,1,0,1,1,0,1,2,1}
  };
  EXPECT_EQ(expected, sol.updateMatrix(matrix));

  matrix = {
    {0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,1,0,0,0,1,0,1,1,0,1,1,1,0,0,1,0,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,0,1,1,1,1},
    {1,0,1,1,1,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1},
    {1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,0,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0,0,1,1,0,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,0,0,1,1,1},
    {0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1,1,0,0,1,1,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,1,0,1,0,0,1,0,1,1,1},
    {1,1,0,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,1,1,0,1,1,0,0,1,0,1,0,1,1,0,1,0,1,1,0,0,1,0,0,0,1,0,1,1,0,0,1,0,1,0,0,1,1,1,0,1,0,1,1,1,0,0,0},
    {0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,1,1,0,0,1,0,1,1,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,1,0,0,1,0,0},
    {1,1,0,0,0,0,1,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,1,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,1},
    {1,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,1,0,0},
    {1,1,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,1,0,1,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,0,0,1,1,0,1,1,0,1},
    {0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,1,1,1,1,0,1,0,1,1,1,0,0,1,1,0,1,1,1,1},
    {0,0,0,1,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,0,0,0,0,1,0,1,0,1,1,1,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,0,0,1,1,1,0,1,0,0,1,1,0,0,1,0,0,1,1,1,0,0,0,1,1,0,1,0},
    {1,0,1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,0,1,0,1,1,0,0,0,1,1,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,0,0,1,1,0,0,0,1,0,0},
    {1,1,1,1,0,1,0,0,0,1,1,0,1,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,1,0},
    {1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1,0,0,1,1,0,1,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,0,1,1,0,0,0,1},
    {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,1,1,1,0,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,0,1,0,1,0,0,0,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,1,1,1},
    {1,0,0,1,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,0,1,1,1,0,0,1},
    {1,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,0,1,0,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,1,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0},
    {1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1},
    {1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,0,0,1,1,0,1,0,1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0},
    {0,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,1,0,0,0,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,0,1,0,1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,1,1,1,0,0,1,1,1,0,0,0,1,1},
    {1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,1,0,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0},
    {0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0},
    {0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,0,0},
    {0,1,1,1,1,1,0,1,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,1,0,0,1,0,0,1,1,1,1,0,1,0,1,1,1,0,0,0,1,0,1,1,0,1,0,0,0,1,1,0,0},
    {0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,1,0,0,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,1,1,0,0,0,0,1,0,1,1,1,1,0,1,1,0,0,0,1,0,1,1,1,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,0,0,1,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
    {0,1,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1,1},
    {0,0,0,0,1,0,1,1,0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,1,1,0,1,1,0,1,1,1,1,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,1,0,0,0,1,0,0,1,0,0,1,1,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,1,1},
    {1,1,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,1,1,0,0,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,1,0,1,0,0},
    {1,0,1,0,1,1,1,0,1,1,1,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1},
    {0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,1,1,0,1,1,0,0,1,1,1,0,1,1,0,1,0,1,1,1,0,1,0,1,1,0,1,1,0,1,0,0,1,0,1,1,1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0,0},
    {1,1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0,1,0,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,1,1,0,1,1,0,0,1,0,1,0,1,0,1,1,0,0,0,1,1,0,0,1},
    {1,0,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
    {1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,1,0},
    {0,1,0,0,0,0,0,1,0,0,1,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,1,0,1,0,1,1,0,1,0,0,1,1,1,1,0,0,1,1,0,1,0,0,1,0,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0},
    {0,0,0,0,0,0,1,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,1,1,1,0,0,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,0,1,0,0,1,1,0,1,0,1,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1},
    {0,0,0,0,1,0,1,1,1,0,0,1,1,1,1,1,0,1,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,0,1,1,0,0,1,0,0},
    {0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,0,1,0,0},
    {1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,0,0,1},
    {0,0,1,0,0,1,1,1,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,0,1,1,0,1,1,0,0,1,0,1,1,1,1,0,0,1,0,1,1,0,1,0,1,1,0,1,1,1,1,0,1,1,0,0},
    {1,1,1,0,0,0,0,1,0,1,1,0,0,1,0,1,0,0,0,1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,1,1,0,1,1,1,0,0,1,1,0,1,0,1,0,1,1,0,1,1,1,1,1,1},
    {1,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,0,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,1,0,1,0,1},
    {0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1},
    {1,1,1,1,1,0,0,1,1,1,0,1,1,0,0,1,0,0,1,0,0,1,1,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,0,1,0,0,0,1,1,0,0,1,0,1,1,1,0,1,0,1,1,0,0,1,1,1,1,0,0,1,0,0,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,0,1,1,1,0,1,0,0},
    {1,0,0,1,1,0,1,1,0,0,0,1,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,1,1,0,1,0,1,0,1,0,0},
    {1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,0,1,1,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0},
    {0,1,0,0,1,1,1,1,0,1,0,1,0,1,1,1,0,0,1,1,1,1,0,0,1,0,0,1,0,1,1,0,1,1,0,1,1,0,0,1,0,1,0,1,1,1,1,0,1,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,0},
    {0,1,0,0,1,1,1,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,0,0,1,1},
    {0,1,1,0,1,0,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0},
    {0,0,0,1,1,0,1,0,1,1,0,1,0,0,0,0,1,1,1,0,1,0,1,1,1,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1},
    {0,0,0,1,0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1,1,1,1,0,1,1,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,1,0,1,0,0,0,1},
    {0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,1,1,0,1,1},
    {1,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0,1,1,1,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0},
    {0,0,1,0,1,0,0,0,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,0,0,1,1,0,1,1,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0},
    {1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,1,0,1,1,1,0,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,0,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,1,0,1,0,1,0,0,1},
    {0,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,0,1,1,0,1,0,1,0,0,0},
    {1,0,0,1,0,0,1,0,1,1,0,0,1,0,1,1,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,1,0,1},
    {1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,0,0,1,0,1,1,0,0,1,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,1},
    {0,1,1,1,1,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,0,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,0,1,0,0,1,1,1,1,0,1,1,0,0,0,1,1,0,0,1,0,1,1,0,0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,0,1,1,1},
    {0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,1,0,0,1,0,0,0,0,1,1,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,0,0},
    {1,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,1,0,1,0,0,1,1,1,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,1,1,0,1,1,0,1},
    {1,0,1,1,1,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,0,0,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,1,0,1},
    {0,1,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,1,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0},
    {1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,0,1,1,0},
    {0,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,1,0,0,1,1,1},
    {0,1,0,0,1,0,0,1,1,0,0,0,1,0,0,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,0,1,1,1,0,0,0,1,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,1,0},
    {1,1,1,1,0,1,1,0,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,1,1,0,0,1,0,1,0,1,1,0,1,0,1,0,1,0},
    {1,1,1,0,1,1,1,0,1,0,1,1,1,0,0,1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,0,1,1,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,1,0,1,1,0,1,1,1},
    {0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,1,1,0},
    {1,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,1,0,0,1,1},
    {1,0,1,0,0,1,0,1,1,0,1,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,0,1,1,1,0,0,0,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1},
    {1,0,1,0,1,1,0,1,0,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,1,0,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,0},
    {1,1,0,1,0,0,1,1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,1,0,0,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,1,1},
    {0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,1,1,0,0,0,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,0,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0},
    {0,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,0,1,1,1,1,1,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1,1,1,1},
    {0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,1,0,1,0,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,1,0,0,0,1},
    {0,1,1,1,1,0,0,0,1,1,1,0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,1,1,1},
    {0,0,1,1,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,0,0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,0,1,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1},
    {1,0,1,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,0,0,0,0},
    {1,1,0,0,0,0,1,1,1,0,0,1,1,0,1,0,0,0,0,1,1,0,1,1,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,0,1,1,1,0,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,1,0,1},
    {1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,1,1},
    {0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,0,1,1,0,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,1,1,0,1,1,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,1},
    {1,0,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,1,1,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,1,0,1,0,1,1,0,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0},
    {0,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,1,0,1,1,1,0,0,1,1,1,0,0,1,0,1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,1,0},
    {1,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0,1,1,0,0,1,0,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0},
    {1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0},
    {1,0,0,1,1,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,1,0},
    {1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,1,1,0,1,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0,1,0,0,0},
    {0,0,1,1,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,1,0,0,0,0,1,0,0,1,0},
    {1,0,0,1,0,1,1,0,0,0,0,1,1,0,1,1,0,1,0,0,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,0,1,0,0,1,1,0,1},
    {0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,1,0,1},
    {0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,0,1,1,1,0,1,1,0,0},
    {0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,1,0,0,0,1,1,1,0,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1,0,0,0,0,0,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,1,0,0,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0},
    {1,0,1,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1},
    {0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1}
  };
  sol.updateMatrix(matrix);

  exit(EXIT_SUCCESS);
}
