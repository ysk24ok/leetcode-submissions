#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

/**
 *  | - e a t
 * ----------
 * -| 0 1 2 3
 * s| 1 2 3 4
 * e| 2 1 2 3
 * a| 3 2 1 2
 */
class Solution {
 public:
  int minDistance(string word1, string word2) {
    const size_t m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (size_t i = 1; i <= m; ++i) {
      dp[i][0] = dp[i-1][0] + 1;
    }
    for (size_t j = 1; j <= n; ++j) {
      dp[0][j] = dp[0][j-1] + 1;
    }
    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (word1[i-1] == word2[j-1]) {
          dp[i][j] = dp[i-1][j-1];
        } else {
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  Solution sol;
  string word1, word2;
  int expected;

  word1 = "sea", word2 = "eat", expected = 2;
  EXPECT_EQ(sol.minDistance(word1, word2), expected);

  word1 = "leetcode", word2 = "etco", expected = 4;
  EXPECT_EQ(sol.minDistance(word1, word2), expected);

  exit(EXIT_SUCCESS);
}
