#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  int removePalindromeSub(string s) {
    if (s.size() == 0) {
      return 0;
    } else if (isPalindrome(s)) {
      return 1;
    } else {
      return 2;
    }
  }

  bool isPalindrome(const string& s) {
    size_t l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string s;
  int expected;

  s = "ababa", expected = 1;
  EXPECT_EQ(expected, sol.removePalindromeSub(s));

  s = "abb", expected = 2;
  EXPECT_EQ(expected, sol.removePalindromeSub(s));

  s = "baabb", expected = 2;
  EXPECT_EQ(expected, sol.removePalindromeSub(s));

  s = "", expected = 0;
  EXPECT_EQ(expected, sol.removePalindromeSub(s));

  exit(EXIT_SUCCESS);
}
