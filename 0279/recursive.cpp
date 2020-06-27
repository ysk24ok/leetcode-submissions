#include <algorithm>
#include <numeric>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> memo(n+1, -1);
    memo[0] = 0;
    return recursive(n, memo);
  }

  int recursive(int n, vector<int>& memo) {
    if (memo[n] != -1) { return memo[n]; }
    int min_count = numeric_limits<int>::max();
    for (int i = getMaximumSquareRoot(n); i > 0; --i) {
      int n_copy = n;
      int count = 0;
      int square = i * i;
      while (n_copy - square >= 0) {
        n_copy -= square;
        count++;
      }
      count += recursive(n_copy, memo);
      min_count = min(min_count, count);
    }
    return memo[n] = min_count;
  }

  int getMaximumSquareRoot(int n) {
    int i = 1, square = 1;
    while (n >= square) {
      if (n == square) { return i; }
      i++;
      square = i * i;
    }
    return i - 1;
  }
};

int main() {
  Solution sol;
  int n, expected;

  EXPECT_EQ(1, sol.getMaximumSquareRoot(1));
  EXPECT_EQ(1, sol.getMaximumSquareRoot(2));
  EXPECT_EQ(1, sol.getMaximumSquareRoot(3));
  EXPECT_EQ(2, sol.getMaximumSquareRoot(4));
  EXPECT_EQ(2, sol.getMaximumSquareRoot(5));

  n = 12, expected = 3;
  EXPECT_EQ(expected, sol.numSquares(n));

  n = 13, expected = 2;
  EXPECT_EQ(expected, sol.numSquares(n));

  exit(EXIT_SUCCESS);
}
