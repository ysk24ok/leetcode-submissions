#include <gtest/gtest.h>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int brokenCalc(int X, int Y) {
    int num_operations = 0;
    while (Y > X) {
      num_operations++;
      if (Y % 2 == 1) {
        Y++;
      } else {
        Y /= 2;
      }
    }
    return num_operations + X - Y;
  }
};

int main() {
  Solution sol;
  int X, Y, expected;

  X = 2, Y = 3, expected = 2;
  EXPECT_EQ(expected, sol.brokenCalc(X, Y));

  X = 5, Y = 8, expected = 2;
  EXPECT_EQ(expected, sol.brokenCalc(X, Y));

  X = 3, Y = 10, expected = 3;
  EXPECT_EQ(expected, sol.brokenCalc(X, Y));

  X = 1024, Y = 1, expected = 1023;
  EXPECT_EQ(expected, sol.brokenCalc(X, Y));

  exit(EXIT_SUCCESS);
}
