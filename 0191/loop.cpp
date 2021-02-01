#include <gtest/gtest.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    uint32_t mask = 1;
    for (int i = 0; i < 32; i++) {
      if (mask & n) count++;
      mask <<= 1;
    }
    return count;
  }
};

int main() {
  Solution sol;
  uint32_t i;
  int expected;

  i = 0b00000000000000000000000000000001, expected = 1;
  EXPECT_EQ(expected, sol.hammingWeight(i));

  i = 0b00000000000000000000000000001011, expected = 3;
  EXPECT_EQ(expected, sol.hammingWeight(i));

  i = 0b00000000000000000000000010000000, expected = 1;
  EXPECT_EQ(expected, sol.hammingWeight(i));

  i = 0b11111111111111111111111111111101, expected = 31;
  EXPECT_EQ(expected, sol.hammingWeight(i));
}
