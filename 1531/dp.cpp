#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

constexpr size_t N = 101;
int dp[N][N];

/**
 * dp[i][k]: the minimum length for s[:i] with at most k deletion.
 *
 * dp | 0 1 2
 * ----------
 * 0 -| 0 N N
 * 1 a| 1 0 N
 * 2 a| 2 1 0
 * 3 b| 3 2 1
 * 4 b| 4 3 2
 * 5 a| 5 4 2
 * 6 a| 6 5 2
 */

class Solution {
 public:
  int getLengthOfOptimalCompression(string s, int k) {
    size_t n = s.size();
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = 0; j < N; ++j) {
        dp[i][j] = N;
      }
    }
    dp[0][0] = 0;
    for (size_t i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        int cnt = 0, del = 0;
        // keep s[i], concat the same, remove the different
        // TODO: why remove the different?
        for (size_t l = i; l >= 1; --l) {
          if (s[l - 1] == s[i - 1]) cnt++;
          else del++;
          if (j - del >= 0)
            dp[i][j] = min(dp[i][j],
                           dp[l-1][j-del] + 1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1: 0));
        }
        // delete s[i]
        if (j > 0)
          dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
      }
    }
    return dp[n][k];
  }
};

int main() {
  Solution sol;
  string s;
  int k, expected;

  s = "aaabcccd", k = 2, expected = 4;
  EXPECT_EQ(expected, sol.getLengthOfOptimalCompression(s, k));

  s = "aabbaa", k = 2, expected = 2;
  EXPECT_EQ(expected, sol.getLengthOfOptimalCompression(s, k));

  s = "aaaaaaaaaaa", k = 0, expected = 3;
  EXPECT_EQ(expected, sol.getLengthOfOptimalCompression(s, k));

  exit(EXIT_SUCCESS);
}
