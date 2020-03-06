#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 *   x a y b z c d
 * a 0 1 1 1 1 1 1
 * x 1 1 1 1 1 1 1
 * b 1 1 1 2 2 2 2
 * y 1 1 2 2 2 2 2
 * c 1 1 2 2 2 3 3
 * d 1 1 2 2 2 3 4
 * z 1 1 2 2 3 3 4
 */

/**
 *   a a a a a a
 * a 1 1 1 1 1 1
 * b 1 1 1 1 1 1
 * a 1 2 2 2 2 2
 */
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    size_t s1 = text1.size(), s2 = text2.size();
    if (s1 == 0 || s2 == 0) return 0;
    vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));
    for (size_t i = 0; i < s1; i++) {
      for (size_t j = 0; j < s2; j++) {
        if (text1[i] == text2[j]) {
          dp[i+1][j+1] = max({dp[i][j] + 1, dp[i+1][j], dp[i][j+1]});
        } else {
          dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
      }
    }
    return dp[s1][s2];
  }
};

int main() {
  Solution sol;
  string text1;
  string text2;

  text1 = "abcde";
  text2 = "ace";
  assert(sol.longestCommonSubsequence(text1, text2) == 3);

  text1 = "abc";
  text2 = "abc";
  assert(sol.longestCommonSubsequence(text1, text2) == 3);

  text1 = "abc";
  text2 = "def";
  assert(sol.longestCommonSubsequence(text1, text2) == 0);

  text1 = "xaybzcd";
  text2 = "axbycdz";
  assert(sol.longestCommonSubsequence(text1, text2) == 4);

  text1 = "aaaaaa";
  text2 = "abaca";
  assert(sol.longestCommonSubsequence(text1, text2) == 3);

  text1 = "abaca";
  text2 = "aaaaaa";
  assert(sol.longestCommonSubsequence(text1, text2) == 3);

  text1 = "psnw";
  text2 = "vozsh";
  assert(sol.longestCommonSubsequence(text1, text2) == 1);
}
