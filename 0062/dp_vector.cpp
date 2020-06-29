#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> curr(n, 0);
    vector<int> prev(n, 1);
    for (int i = 1; i < m; ++i) {
      curr[0] = 1;
      for (int j = 1; j < n; ++j) {
        curr[j] = curr[j-1] + prev[j];
      }
      curr.swap(prev);
    }
    return prev[n-1];
  }
};

int main() {
  Solution sol;
  int m, n, expected;

  m = 3, n = 2, expected = 3;
  EXPECT_EQ(expected, sol.uniquePaths(m, n));

  m = 7, n = 3, expected = 28;
  EXPECT_EQ(expected, sol.uniquePaths(m, n));

  exit(EXIT_SUCCESS);
}
