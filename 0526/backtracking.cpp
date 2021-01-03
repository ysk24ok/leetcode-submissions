#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int countArrangement(int n) {
    vector<bool> used(n+1, false);
    return dfs(n, 1, used);
  }

  int dfs(int n, int index, vector<bool>& used) {
    if (index > n) { return 1; }
    int count = 0;
    for (int num = 1; num <= n; ++num) {
      if (used[num]) { continue; }
      if (num % index == 0 || index % num == 0) {
        used[num] = true;
        count += dfs(n, index+1, used);
        used[num] = false;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  int n, expected;

  n = 2, expected = 2;
  EXPECT_EQ(expected, sol.countArrangement(n));

  n = 1, expected = 1;
  EXPECT_EQ(expected, sol.countArrangement(n));

  n = 3, expected = 3;
  EXPECT_EQ(expected, sol.countArrangement(n));

  n = 4, expected = 8;
  EXPECT_EQ(expected, sol.countArrangement(n));

  exit(EXIT_SUCCESS);
}
