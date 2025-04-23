#include <gtest/gtest.h>

#include <iostream>

using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) { return 1; }
    int abs_n = n > 0 ? n : -n;
    double ret = 1;
    for (int i = 0; i < abs_n; i++) {
      ret *= x;
    }
    return n > 0 ? ret : 1 / ret;
  }
};

int main() {
  Solution sol;
  double x, expected;
  int n;

  x = 2.0, n = 10, expected = 1024.0;
  EXPECT_NEAR(expected, sol.myPow(x, n), 0.0001);

  x = 2.1, n = 3, expected = 9.261;
  EXPECT_NEAR(expected, sol.myPow(x, n), 0.0001);

  x = 2.0, n = -2, expected = 0.25;
  EXPECT_NEAR(expected, sol.myPow(x, n), 0.0001);

  exit(EXIT_SUCCESS);
}
