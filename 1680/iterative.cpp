#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>

using namespace std;

constexpr int mod = 1e9 + 7;

class Solution {
 public:
  int concatenatedBinary(int n) {
    long target = 0;
    for (int i = 1; i <= n; ++i) {
      int num = i;
      int digits = 0;
      for (int j = 31; j > 0; --j) {
        int power = pow(2, j - 1);
        if (num >= power) {
          num -= power;
          digits = max(j, digits);
        }
      }
      target <<= digits;
      target += i;
      target %= mod;
    }
    return target;
  }
};

int main() {
  Solution sol;
  int n, expected;

  n = 1, expected = 1;
  EXPECT_EQ(expected, sol.concatenatedBinary(n));

  n = 3, expected = 27;
  EXPECT_EQ(expected, sol.concatenatedBinary(n));

  n = 12, expected = 505379714;
  EXPECT_EQ(expected, sol.concatenatedBinary(n));

  exit(EXIT_SUCCESS);
}
