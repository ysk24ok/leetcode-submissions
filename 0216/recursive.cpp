#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ret;
    vector<int> combination;
    recursive(1, k, n, combination, ret);
    return ret;
  }

  void recursive(int start, int k, int n, vector<int>& combination, vector<vector<int>>& ret) {
    if (k == 0) {
      if (n == 0) {
        ret.push_back(combination);
      }
      return;
    }
    for (int i = start; i < 10; ++i) {
      if (i > n) {
        break;
      }
      combination.push_back(i);
      recursive(i+1, k-1, n-i, combination, ret);
      combination.pop_back();
    }
  }
};

int main() {
  Solution sol;
  int k, n;
  vector<vector<int>> expected;

  k = 3, n = 7;
  expected = {{1,2,4}};
  EXPECT_EQ(expected, sol.combinationSum3(k, n));

  k = 3, n = 9;
  expected = {{1,2,6},{1,3,5},{2,3,4}};
  EXPECT_EQ(expected, sol.combinationSum3(k, n));

  exit(EXIT_SUCCESS);
}
