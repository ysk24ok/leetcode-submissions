#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ret(num+1);
    if (num == 0) { return ret; }
    long pow2 = 1;
    long next_pow2 = 2;
    for (int i = 1; i <= num; ++i) {
      if (i == next_pow2) {
        pow2 *= 2;
        next_pow2 *= 2;
        ret[i] = 1;
      } else {
        ret[i] = ret[i-pow2] + 1;
      }
    }
    return ret;
  }
};

void check(const vector<int>& expected, const vector<int>& got) {
  ASSERT_EQ(expected.size(), got.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(expected[i], got[i]);
  }
}

int main() {
  Solution sol;
  vector<int> expected, got;

  expected = {0};
  got = sol.countBits(0);
  check(expected, got);

  expected = {0,1};
  got = sol.countBits(1);
  check(expected, got);

  expected = {0,1,1};
  got = sol.countBits(2);
  check(expected, got);

  expected = {0,1,1,2};
  got = sol.countBits(3);
  check(expected, got);

  expected = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
  got = sol.countBits(15);
  check(expected, got);

  exit(EXIT_SUCCESS);
}
