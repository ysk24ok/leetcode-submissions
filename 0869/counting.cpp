#include <gtest/gtest.h>

#include <array>
#include <cstdlib>

using namespace std;

class Solution {
 public:
  bool reorderedPowerOf2(int N) {
    array<int, 10> count = countDigit(N);
    for (int i = 0; i < 31; ++i) {
      if (count == countDigit(1 << i)) {
        return true;
      }
    }
    return false;
  }

  array<int, 10> countDigit(int N) {
    array<int, 10> count = {0};
    while (N > 0) {
      count[N % 10]++;
      N /= 10;
    }
    return count;
  }
};

int main() {
  Solution sol;
  int N;
  bool expected;

  N = 1, expected = true;
  EXPECT_EQ(expected, sol.reorderedPowerOf2(N));

  N = 10, expected = false;
  EXPECT_EQ(expected, sol.reorderedPowerOf2(N));

  N = 16, expected = true;
  EXPECT_EQ(expected, sol.reorderedPowerOf2(N));

  N = 24, expected = false;
  EXPECT_EQ(expected, sol.reorderedPowerOf2(N));

  N = 46, expected = true;
  EXPECT_EQ(expected, sol.reorderedPowerOf2(N));

  exit(EXIT_SUCCESS);
}
