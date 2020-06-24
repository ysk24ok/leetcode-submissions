#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int numTrees(int n) {
    if (n == 0) { return 0; }
    vector<int> memo(n+1, -1);
    return recursive(n, memo);
  }

  int recursive(int n, vector<int>& memo) {
    if (n == 0 || n == 1) { return 1; }
    if (memo[n] != -1) { return memo[n]; }
    int ret = 0;
    for (int left = 0; left < n; left++) {
      int right = n - 1 - left;
      ret += recursive(left, memo) * recursive(right, memo);
    }
    return memo[n] = ret;
  }
};

int main() {
  Solution sol;
  int n, expected;

  n = 3, expected = 5;
  EXPECT_EQ(expected, sol.numTrees(n));

  n = 0, expected = 0;
  EXPECT_EQ(expected, sol.numTrees(n));

  n = 1, expected = 1;
  EXPECT_EQ(expected, sol.numTrees(n));

  n = 2, expected = 2;
  EXPECT_EQ(expected, sol.numTrees(n));

  exit(EXIT_SUCCESS);
}
