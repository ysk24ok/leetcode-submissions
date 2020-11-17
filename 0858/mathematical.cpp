#include <gtest/gtest.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  int mirrorReflection(int p, int q) {
    int d = gcd(p, q);
    p /= d;
    q /= d;
    if (q % 2 == 0) { return 0; }
    return p % 2 == 0 ? 2 : 1;
  }

  int gcd(int p, int q) {
    if (q == 0) { return p; }
    return gcd(q, p % q);
  }
};

int main() {
  Solution sol;
  int p, q, expected;

  p = 2, q = 1, expected = 2;
  EXPECT_EQ(expected, sol.mirrorReflection(p, q));

  p = 4, q = 2, expected = 2;
  EXPECT_EQ(expected, sol.mirrorReflection(p, q));

  p = 164, q = 98, expected = 2;
  EXPECT_EQ(expected, sol.mirrorReflection(p, q));

  exit(EXIT_SUCCESS);
}
