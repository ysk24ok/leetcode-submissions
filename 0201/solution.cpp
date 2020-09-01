#include <gtest/gtest.h>

using namespace std;

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int shift = 0;
    while (m != n) {
      m >>= 1;
      n >>= 1;
      shift++;
    }
    return m << shift;
  }
};

int main() {
  Solution sol;

  // 5: 0101
  // 6: 0110
  // 7: 0111
  EXPECT_EQ(4, sol.rangeBitwiseAnd(5, 7));
  // 0: 0
  // 1: 1
  EXPECT_EQ(0, sol.rangeBitwiseAnd(0, 1));
}
