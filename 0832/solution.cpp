#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    const size_t n = A.size();
    for (size_t row = 0; row < n; ++row) {
      for (size_t i = 0; i < n / 2; ++i) {
        if (A[row][i] == A[row][n-i-1]) {
          A[row][i] ^= 1;
          A[row][n-i-1] ^= 1;
        }
      }
      if (n % 2 == 1) {
        A[row][n / 2] ^= 1;
      }
    }
    return A;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> A, expected;

  A = {
    {1, 1, 0},
    {1, 0, 1},
    {0, 0, 0},
  };
  expected = {
    {1, 0, 0},
    {0, 1, 0},
    {1, 1, 1},
  };
  EXPECT_EQ(expected, sol.flipAndInvertImage(A));

  A = {
    {1, 1, 0, 0},
    {1, 0, 0, 1},
    {0, 1, 1, 1},
    {1, 0, 1, 0},
  };
  expected = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 1},
    {1, 0, 1, 0},
  };
  EXPECT_EQ(expected, sol.flipAndInvertImage(A));

  exit(EXIT_SUCCESS);
}
