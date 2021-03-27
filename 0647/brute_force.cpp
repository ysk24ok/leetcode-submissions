#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  int countSubstrings(string s) {
    int ret = 0;
    const size_t n = s.size();
    for (size_t start = 0; start < n; ++start) {
      for (size_t end = start; end < n; ++end) {
        if (isPalindrome(s.substr(start, end - start + 1))) {
          ret++;
        }
      }
    }
    return ret;
  }

  bool isPalindrome(const string s) {
    size_t start = 0, end = s.size() - 1;
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      ++start;
      --end;
    }
    return true;
  }
};

int main() {
  Solution sol;
  string s;
  int expected;

  s = "abc", expected = 3;
  EXPECT_EQ(expected, sol.countSubstrings(s));

  s = "aaa", expected = 6;
  EXPECT_EQ(expected, sol.countSubstrings(s));

  exit(EXIT_SUCCESS);
}
