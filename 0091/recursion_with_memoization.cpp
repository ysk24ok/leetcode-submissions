#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    vector<int> memo(s.size(), -1);
    return dfs(s, 0, memo);
  }

  int dfs(const string& s, size_t i, vector<int>& memo) {
    if (i > s.size()) {
      return 0;
    } else if (i == s.size()) {
      return 1;
    }
    if (memo[i] != -1) {
      return memo[i];
    }
    int ret = 0; 
    if (s[i] == '0') {
      return 0;
    } else if (s[i] == '1') {
      ret += dfs(s, i + 2, memo);
      ret += dfs(s, i + 1, memo);
    } else if (s[i] == '2') {
      if (i + 1 < s.size() && (s[i + 1] != '7' and s[i + 1] != '8' and s[i + 1] != '9')) {
        ret += dfs(s, i + 2, memo);
      }
      ret += dfs(s, i + 1, memo);
    } else {
      ret += dfs(s, i + 1, memo);
    }
    memo[i] = ret;
    return ret;
  }
};

int main() {
  Solution sol;
  string s;
  int expected;

  s = "12", expected = 2;
  EXPECT_EQ(expected, sol.numDecodings(s));

  s = "226", expected = 3;
  EXPECT_EQ(expected, sol.numDecodings(s));

  s = "0", expected = 0;
  EXPECT_EQ(expected, sol.numDecodings(s));

  s = "06", expected = 0;
  EXPECT_EQ(expected, sol.numDecodings(s));

  s = "111111111111111111111111111111111111111111111", expected = 1836311903;
  EXPECT_EQ(expected, sol.numDecodings(s));

  exit(EXIT_SUCCESS);
}
