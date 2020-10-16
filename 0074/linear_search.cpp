#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const size_t m = matrix.size();
    if (m == 0) { return false; }
    const size_t n = matrix[0].size();
    if (n == 0) { return false; }
    size_t i = 0, j = 0;
    if (matrix[i][j] == target) { return true; }
    for (; i < m - 1; ++i) {
      if (matrix[i+1][j] == target) {
        return true;
      } else if (matrix[i+1][j] > target) {
        break;
      }
    }
    for (; j < n - 1; ++j) {
      if (matrix[i][j+1] == target) {
        return true;
      } else if (matrix[i][j+1] > target) {
        break;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix;
  int target;

  matrix = {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,50}
  };
  target = 3;
  EXPECT_TRUE(sol.searchMatrix(matrix, target));
  target = 13;
  EXPECT_FALSE(sol.searchMatrix(matrix, target));

  matrix = {{1}};
  target = 1;
  EXPECT_TRUE(sol.searchMatrix(matrix, target));

  exit(EXIT_SUCCESS);
}
