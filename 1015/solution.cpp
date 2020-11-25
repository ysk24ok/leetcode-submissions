#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    int remainder = 1;
    int length = 1;
    while (remainder % K != 0) {
      if (length > K) { return -1; }
      remainder *= 10;
      remainder += 1;
      remainder %= K;
      length++;
    }
    return length;
  }
};

int main() {
  Solution sol;
  int K, expected;

  K = 1, expected = 1;
  EXPECT_EQ(expected, sol.smallestRepunitDivByK(K));

  K = 2, expected = -1;
  EXPECT_EQ(expected, sol.smallestRepunitDivByK(K));

  K = 3, expected = 3;
  EXPECT_EQ(expected, sol.smallestRepunitDivByK(K));

  exit(EXIT_SUCCESS);
}
