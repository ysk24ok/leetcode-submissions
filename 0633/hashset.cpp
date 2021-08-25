#include <gtest/gtest.h>

#include <unordered_set>

using namespace std;

class Solution {
 public:
  bool judgeSquareSum(int c) {
    unordered_set<long> set;
    for (long i = 0; i <= c; ++i) {
      long square = i * i;
      if (square > c) {
        break;
      }
      set.insert(square);
      if (set.find(c - square) != set.end()) {
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
