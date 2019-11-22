#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int oddCells(int n, int m, vector<vector<int>>& indices) {
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (auto& pair : indices) {
      update_row(matrix, pair[0]);
      update_col(matrix, pair[1]);
    }
    int ret = 0;
    for (auto& row : matrix) {
      for (auto& v : row) {
        if (v % 2 == 1) {
          ret += 1;
        }
      }
    }
    return ret;
  }

  void update_row(vector<vector<int>>& matrix, int row_id) {
    for (auto& v : matrix[row_id]) {
      v += 1;
    }
  }

  void update_col(vector<vector<int>>& matrix, int col_id) {
    size_t n = matrix.size();
    for (int i = 0; i < n; i++) {
      matrix[i][col_id] += 1;
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> indices;
  int got;

  indices = {{0,1},{1,1}};
  got = sol.oddCells(2, 3, indices);
  assert(got == 6);

  indices = {{0,0}};
  got = sol.oddCells(1, 1, indices);
  assert(got == 0);

  indices = {{1,1},{0,0}};
  got = sol.oddCells(2, 2, indices);
  assert(got == 0);
}
