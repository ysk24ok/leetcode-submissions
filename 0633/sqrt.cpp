#include <gtest/gtest.h>

#include <cmath>

using namespace std;

class Solution {
 public:
  bool judgeSquareSum(int c) {
    for (long i = 0; i <= c; ++i) {
      long square = i * i;
      if (square > c) {
        break;
      }
      double root = sqrt(c - square);
      if (root == static_cast<int>(root)) {
          return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  int c;
  bool expected;

  c = 5, expected = true;
  EXPECT_EQ(expected, sol.judgeSquareSum(c));

  c = 4, expected = true;
  EXPECT_EQ(expected, sol.judgeSquareSum(c));

  c = 3, expected = false;
  EXPECT_EQ(expected, sol.judgeSquareSum(c));

  c = 2, expected = true;
  EXPECT_EQ(expected, sol.judgeSquareSum(c));

  c = 1, expected = true;
  EXPECT_EQ(expected, sol.judgeSquareSum(c));

  c = 0, expected = true;
  EXPECT_EQ(expected, sol.judgeSquareSum(c));

  c = 2147482647, expected = false;
  EXPECT_EQ(expected, sol.judgeSquareSum(c));

  exit(EXIT_SUCCESS);
}
