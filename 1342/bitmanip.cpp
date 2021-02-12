#include <gtest/gtest.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  int numberOfSteps (int num) {
    if (num == 0) { return 0; }
    int steps = 0;
    while (num > 1) {
      steps += (num & 1) ? 2 : 1;
      num >>= 1;
    }
    return steps + 1;
  }
};

int main() {
  Solution sol;
  int num, expected;

  num = 14, expected = 6;
  EXPECT_EQ(expected, sol.numberOfSteps(num));

  num = 8, expected = 4;
  EXPECT_EQ(expected, sol.numberOfSteps(num));

  num = 123, expected = 12;
  EXPECT_EQ(expected, sol.numberOfSteps(num));

  num = 0, expected = 0;
  EXPECT_EQ(expected, sol.numberOfSteps(num));

  exit(EXIT_SUCCESS);
}
