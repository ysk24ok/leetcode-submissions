#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>

using namespace std;

class Solution {
 public:
  int bitwiseComplement(int N) {
    if (N == 0) { return 1; }
    int ret = 0;
    bool complement = false;
    for (int i = 30; i >= 0; --i) {
      int b = pow(2, i);
      if (N >= b) {
        N -= b;
        complement = true;
      } else if (complement) {
        ret += b;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int N;
  int expected;

  N = 5;
  expected = 2;
  EXPECT_EQ(expected, sol.bitwiseComplement(N));

  N = 7;
  expected = 0;
  EXPECT_EQ(expected, sol.bitwiseComplement(N));

  N = 10;
  expected = 5;
  EXPECT_EQ(expected, sol.bitwiseComplement(N));

  N = 0;
  expected = 1;
  EXPECT_EQ(expected, sol.bitwiseComplement(N));

  exit(EXIT_SUCCESS);
}
