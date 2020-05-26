#include <algorithm>
#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    const size_t m = A.size(), n = B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (A[i-1] == B[j-1]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        } else {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  Solution sol;
  vector<int> A, B;

  A = {1,4,2}, B = {1,2,4};
  EXPECT_EQ(2, sol.maxUncrossedLines(A, B));

  A = {2,5,1,2,5}, B = {10,5,2,1,5,2};
  EXPECT_EQ(3, sol.maxUncrossedLines(A, B));

  A = {1,3,7,1,7,5}, B = {1,9,2,5,1};
  EXPECT_EQ(2, sol.maxUncrossedLines(A, B));

  A = {1,4,2,4}, B = {1,2,4,3};
  EXPECT_EQ(3, sol.maxUncrossedLines(A, B));

  exit(EXIT_SUCCESS);
}
