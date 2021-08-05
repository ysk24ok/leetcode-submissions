#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    // dp[i][j] means the biggest number of stones
    // you can get more than opponent picking piles in piles[i] ~ piles[j].
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      dp[i][i] = piles[i];
    }
    for (int d = 1; d < n; d++) {
      for (int i = 0; i < n - d; i++) {
        int j = i + d;
        dp[i][j] = max(
          piles[i] - dp[i + 1][j],  // pick piles[i]
          piles[j] - dp[i][j - 1]   // pick piles[j]
        );
      }
    }
    return dp[0][n - 1] > 0;
  }  
};

int main() {
  Solution sol;
  vector<int> p;
  bool expected;

  /**
   *  dp = {
   *   {5, 2, 4, 1},
   *   {0, 3, 1, 4},
   *   {0, 0, 4, 1},
   *   {0, 0, 0, 5},
   * } 
   */
  p = {5, 3, 4, 5}, expected = true;
  EXPECT_EQ(expected, sol.stoneGame(p));

  exit(EXIT_SUCCESS);
}
