#include <gtest/gtest.h>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    // dp[left][right] = dp[left+1][right-1] && s[left] == s[right]
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
    string ret = s.substr(0, 1);
    for (int left = s.size() - 1; left >= 0; --left) {
      for (int right = left; right < s.size(); ++right) {
        if (left == right ||
            (left + 1 == right && s[left] == s[right]) ||
            (dp[left+1][right-1] && s[left] == s[right])) {
          dp[left][right] = true;
          int size = right - left + 1;
          if (size > ret.size()) {
            ret = s.substr(left, size);
          }
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s, expected;

  s = "babad", expected = "aba";  // "bab" is also OK
  EXPECT_EQ(expected, sol.longestPalindrome(s));

  s = "cbbd", expected = "bb";
  EXPECT_EQ(expected, sol.longestPalindrome(s));

  s = "a", expected = "a";
  EXPECT_EQ(expected, sol.longestPalindrome(s));

  s = "ac", expected = "a";
  EXPECT_EQ(expected, sol.longestPalindrome(s));

  exit(EXIT_SUCCESS);
}
