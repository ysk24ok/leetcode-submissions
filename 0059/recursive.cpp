#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    spiral(matrix, 0, 0, n, 1);
    return matrix;
  }

  void spiral(vector<vector<int>>& matrix, int start_i, int start_j, int n, int val) {
    if (n == 0) { return; }
    int i = start_i, j = start_j;
    matrix[i][j] = val++;
    if (n == 1) { return; }
    // upper-left -> upper-right
    ++j;
    for (; j < start_j + n; ++j) { matrix[i][j] = val++; }
    --j;
    // upper-right -> lower-right
    ++i;
    for (; i < start_i + n; ++i) { matrix[i][j] = val++; }
    --i;
    // lower-right -> lower-left
    --j;
    for (; j >= start_j; --j) { matrix[i][j] = val++; }
    ++j;
    // lower-left -> upper-left
    --i;
    for (; i > start_i; --i) { matrix[i][j] = val++; }
    spiral(matrix, i + 1, j + 1, n - 2, val);
  }
};

int main() {
  Solution sol;
  int n;
  vector<vector<int>> expected;

  n = 3;
  expected = {
    {1, 2, 3},
    {8, 9, 4},
    {7, 6, 5},
  };
  EXPECT_EQ(expected, sol.generateMatrix(n));

  n = 2;
  expected = {
    {1, 2},
    {4, 3},
  };
  EXPECT_EQ(expected, sol.generateMatrix(n));

  n = 1;
  expected = {
    {1},
  };
  EXPECT_EQ(expected, sol.generateMatrix(n));

  exit(EXIT_SUCCESS);
}
