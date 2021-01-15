#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMaximumGenerated(int n) {
    vector<int> generated(n+1);
    int ret = 0;
    for (int i = 0; i <= n; ++i) {
      if (i > 1) {
        if (i % 2 == 0) {
          generated[i] = generated[i / 2];
        } else {
          generated[i] = generated[i / 2] + generated[i / 2 + 1];
        }
      } else if (i == 1) {
        generated[i] = 1;
      } else if (i == 0) {
        generated[i] = 0;
      }
      ret = max(generated[i], ret);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n, expected;

  n = 7, expected = 3;
  EXPECT_EQ(expected, sol.getMaximumGenerated(n));

  n = 2, expected = 1;
  EXPECT_EQ(expected, sol.getMaximumGenerated(n));

  n = 3, expected = 2;
  EXPECT_EQ(expected, sol.getMaximumGenerated(n));

  exit(EXIT_SUCCESS);
}
