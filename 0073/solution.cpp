#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// time complexity: O(M * N)
// space complexity: O(M + N)
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return;
    set<int> rows;
    set<int> cols;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }
    for (auto& row_id : rows) {
      update_row(matrix, row_id);
    }
    for (auto& col_id : cols) {
      update_col(matrix, col_id);
    }
  }

  void update_row(vector<vector<int>>& matrix, int row_id) {
    for (int j = 0; j < matrix[row_id].size(); j++) {
      matrix[row_id][j] = 0;
    }
  }

  void update_col(vector<vector<int>>& matrix, int col_id) {
    for (int i = 0; i < matrix.size(); i++) {
      matrix[i][col_id] = 0;
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
  for (int i = 0; i < matrix.size(); i++) {
    assert(matrix[i] == expected[i]);
  }

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
  for (int i = 0; i < matrix.size(); i++) {
    assert(matrix[i] == expected[i]);
  }
}
