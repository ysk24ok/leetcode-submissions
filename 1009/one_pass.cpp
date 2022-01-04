#include <gtest/gtest.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  int bitwiseComplement(int n) {
    if (n == 0) {
      return 1;
    }
    int ret = 0;
    for (int i = 0; i < 32; ++i) {
      if (n == 0) {
        break;
      }
      if ((n & 1) == 0) {
        ret += (1 << i);
      }
      n >>= 1;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n;
  int expected;

  n = 5, expected = 2;
  EXPECT_EQ(expected, sol.bitwiseComplement(n));

  n = 7, expected = 0;
  EXPECT_EQ(expected, sol.bitwiseComplement(n));

  n = 10, expected = 5;
  EXPECT_EQ(expected, sol.bitwiseComplement(n));

  n = 0, expected = 1;
  EXPECT_EQ(expected, sol.bitwiseComplement(n));

  exit(EXIT_SUCCESS);
}
