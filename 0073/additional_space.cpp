#include <gtest/gtest.h>

#include <set>
#include <vector>

using namespace std;

// time complexity: O(M * N)
// space complexity: O(M + N)
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    set<size_t> rows;
    set<size_t> cols;
    const size_t m = matrix.size(), n = matrix[0].size();
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }
    for (auto& row_id : rows) {
      update_row(matrix, n, row_id);
    }
    for (auto& col_id : cols) {
      update_col(matrix, m, col_id);
    }
  }

  void update_row(vector<vector<int>>& matrix, size_t n, size_t row_id) {
    for (size_t j = 0; j < n; j++) {
      matrix[row_id][j] = 0;
    }
  }

  void update_col(vector<vector<int>>& matrix, size_t m, size_t col_id) {
    for (size_t i = 0; i < m; i++) {
      matrix[i][col_id] = 0;
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix;
  vector<vector<int>> expected;

  matrix = {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  };
  expected = {
    {1, 0, 1},
    {0, 0, 0},
    {1, 0, 1}
  };
  sol.setZeroes(matrix);
  EXPECT_EQ(expected, matrix);

  matrix = {
    {0, 1, 2, 0},
    {3, 4, 5, 2},
    {1, 3, 1, 5}
  };
  expected = {
    {0, 0, 0, 0},
    {0, 4, 5, 0},
    {0, 3, 1, 0}
  };
  sol.setZeroes(matrix);
  EXPECT_EQ(expected, matrix);
}
