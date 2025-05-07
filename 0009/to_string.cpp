#include <gtest/gtest.h>

#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0 || (x > 0 && x % 10 == 0)) { return false; }
    string s = to_string(x);
    size_t l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l++] != s[r--]) { return false; }
    }
    return true;
  }
};

int main() {
  Solution sol;
  int x;

  x = 121;
  EXPECT_TRUE(sol.isPalindrome(x));

  x = -121;
  EXPECT_FALSE(sol.isPalindrome(x));

  x = 10;
  EXPECT_FALSE(sol.isPalindrome(x));

  x = 0;
  EXPECT_TRUE(sol.isPalindrome(x));

  exit(EXIT_SUCCESS);
}
