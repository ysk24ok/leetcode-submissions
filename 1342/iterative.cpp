#include <gtest/gtest.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  int numberOfSteps (int num) {
    int steps = 0;
    while (num > 0) {
      if (num % 2 == 0) {
        num /= 2;
      } else {
        num -= 1;
      }
      steps++;
    }
    return steps;
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
