#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int reachNumber(int target) {
    if (target < 0) { target *= -1; }
    int ret;
    int timestep = 0;
    int maxval = 0;
    while (true) {
      timestep++;
      maxval += timestep;
      if (0 <= target && target <= maxval && (maxval - target) % 2 == 0) {
        ret = timestep;
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int target, expected;

  target = 1, expected = 1;
  EXPECT_EQ(expected, sol.reachNumber(target));

  target = 2, expected = 3;
  EXPECT_EQ(expected, sol.reachNumber(target));

  target = 3, expected = 2;
  EXPECT_EQ(expected, sol.reachNumber(target));

  target = -1000000000, expected = 44723;
  EXPECT_EQ(expected, sol.reachNumber(target));

  exit(EXIT_SUCCESS);
}
