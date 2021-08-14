#include <gtest/gtest.h>

#include <vector>

using namespace std;

// time complexity: O(mn * 2)
// space complexity: O(1)
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    const size_t m = matrix.size();
    if (m == 0) return;
    const size_t n = matrix[0].size();
    bool update_col0 = false;
    // set marker
    // Whether to update the first column depends on `update_col0`, not matrix[i][0]
    // because setting matrix[0][0] to 0 leads to incorrect updating the first column
    for (size_t i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) { update_col0 = true; }
      for (size_t j = 1; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    // update to zero
    for (size_t i = m; i > 0; --i) {
      for (size_t j = n; j > 1; --j) {
        if (matrix[i-1][0] == 0 || matrix[0][j-1] == 0) {
          matrix[i-1][j-1] = 0;
        }
      }
      if (update_col0) { matrix[i-1][0] = 0; }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix;
  vector<vector<int>> expected;

  matrix = {
    {1,1,1},
    {1,0,1},
    {1,1,1}
  };
  expected = {
    {1,0,1},
    {0,0,0},
    {1,0,1}
  };
  sol.setZeroes(matrix);
  EXPECT_EQ(expected, matrix);

  matrix = {
    {0,1,2,0},
    {3,4,5,2},
    {1,3,1,5}
  };
  expected = {
    {0,0,0,0},
    {0,4,5,0},
    {0,3,1,0}
  };
  sol.setZeroes(matrix);
  EXPECT_EQ(expected, matrix);

  matrix = {
    {1, 0, 3, 4},
    {5, 6, 7, 8},
    {9,10,11,12}
  };
  // After the marker is set:
  // {
  //   {0, 0, 0, 4},
  //   {5, 6, 7, 8},
  //   {9,10,11,12}
  // }
  expected = {
    {0,0, 0, 0},
    {5,0, 7, 8},
    {9,0,11,12}
  };
  sol.setZeroes(matrix);
  EXPECT_EQ(expected, matrix);

  matrix = {
    {1,1,1},
    {0,1,2}
  };
  expected = {
    {0,1,1},
    {0,0,0}
  };
  sol.setZeroes(matrix);
  EXPECT_EQ(expected, matrix);
}
