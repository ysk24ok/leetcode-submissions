#include <algorithm>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

// time complexity: O(n^2)
class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    if (A.size() == 0 || A.size() == 1) return 0;
    vector<int> dp(A.size(), 0);
    int ret = 0;
    for (size_t idx = 1; idx < dp.size(); idx++) {
      for (size_t subidx = 0; subidx < idx; subidx++) {
        if (A[subidx] > A[idx]) continue;
        int width = idx - subidx;
        dp[idx] = max(dp[idx], dp[subidx] + width);
      }
      ret = max(ret, dp[idx]);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> A;
  int got, expected;

  A = {6,0,8,2,1,5};
  got = sol.maxWidthRamp(A);
  expected = 4;
  EXPECT_EQ(expected, got);

  A = {};
  got = sol.maxWidthRamp(A);
  expected = 0;
  EXPECT_EQ(expected, got);

  A = {1};
  got = sol.maxWidthRamp(A);
  expected = 0;
  EXPECT_EQ(expected, got);

  A = {9,8,1,0,1,9,4,0,4,1};
  got = sol.maxWidthRamp(A);
  expected = 7;
  EXPECT_EQ(expected, got);

  A = {7,8,9,1,2,3,4,5,6};
  got = sol.maxWidthRamp(A);
  expected = 5;
  EXPECT_EQ(expected, got);

  A = {1,2,3,0};
  got = sol.maxWidthRamp(A);
  expected = 2;
  EXPECT_EQ(expected, got);
}
