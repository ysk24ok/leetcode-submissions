#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    const size_t m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> ret(m, vector<int>(n, static_cast<int>(m * n)));
    // From top-left to bottom-right
    for (size_t r = 0; r < m; ++r) {
      for (size_t c = 0; c < n; ++c) {
        if (matrix[r][c] == 0) {
          ret[r][c] = 0;
          continue;
        }
        if (r > 0) {
          ret[r][c] = min(ret[r-1][c] + 1, ret[r][c]);

        }
        if (c > 0) {
          ret[r][c] = min(ret[r][c-1] + 1, ret[r][c]);
        }
      }
    }
    // From bottom-right to top-left
    for (size_t r = m; r > 0; --r) {
      for (size_t c = n; c > 0; --c) {
        if (matrix[r-1][c-1] == 0) {
          continue;
        }
        if (r < m) {
          ret[r-1][c-1] = min(ret[r][c-1] + 1, ret[r-1][c-1]);
        }
        if (c < n) {
          ret[r-1][c-1] = min(ret[r-1][c] + 1, ret[r-1][c-1]);
        }
      }
    }
    return ret;
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

  exit(EXIT_SUCCESS);
}
