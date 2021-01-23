#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    const size_t m = mat.size(), n = mat[0].size();
    vector<int> vec(max(m, n));
    sortDiagonally(mat, vec, 0, 0);
    for (size_t i = 1; i < m; ++i) {
      sortDiagonally(mat, vec, i, 0);
    }
    for (size_t j = 1; j < n; ++j) {
      sortDiagonally(mat, vec, 0, j);
    }
    return mat;
  }

  void sortDiagonally(vector<vector<int>>& mat, vector<int>& vec, size_t i, size_t j) {
    const size_t m = mat.size(), n = mat[0].size();
    fill(vec.begin(), vec.end(), numeric_limits<int>::max());
    size_t idx = 0;
    while (i < m && j < n) {
      vec[idx++] = mat[i++][j++];
    }
    sort(vec.begin(), vec.end());
    for (size_t k = idx; k > 0; --k) {
      mat[i-1][j-1] = vec[idx-1];
      --idx;
      --i;
      --j;
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> mat, expected;

  mat = {
   {3, 3, 1, 1},
   {2, 2, 1, 2},
   {1, 1, 1, 2},
  };
  expected = {
   {1, 1, 1, 1},
   {1, 2, 2, 2},
   {1, 2, 3, 3},
  };
  EXPECT_EQ(expected, sol.diagonalSort(mat));

  exit(EXIT_SUCCESS);
}
