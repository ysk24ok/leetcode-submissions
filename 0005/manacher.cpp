#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// https://klee.hatenablog.jp/entry/2020/06/18/210754
class Solution {
 public:
  string longestPalindrome(string s) {
    size_t n = 2 * s.size() + 1;
    string s_with_dummy(n, '#');
    for (size_t i = 0; i < s.size(); i++) {
      s_with_dummy[2 * i + 1] = s[i];
    }

    // c: center of a palindrome
    // r: radius of a palindrome
    // R: the maximum radius per center
    size_t c = 0, r = 0, c_max = 0, r_max = 0;
    vector<int> R(n);
    while (c < n) {
      while (r <= c && c + r < n && s_with_dummy[c - r] == s_with_dummy[c + r]) {
        r++;
      }
      R[c] = r;

      // s=abacababa
      // R=1214?????
      // c=3,r=4
      // k=1: 1+R[2]<4, so R[4]==R[2]
      // k=2: 2+R[1]==4, so R[5]!=R[1] because R[5] could be 3 if the string is 'abacabac'
      size_t k = 1;
      while (k <= c && c + k < n && k + R[c - k] < r) {
        R[c + k] = R[c - k];
        k++;
      }

      if (R[c] > r_max) {
        r_max = R[c];
        c_max = c;
      }

      c += k;
      r -= k;
    }

    string substr = s_with_dummy.substr(c_max - r_max + 1, r_max * 2 - 1);
    substr.erase(remove(substr.begin(), substr.end(), '#'), substr.end());
    return substr;
  }
};

int main() {
  Solution sol;
  string s, expected;

  s = "babad", expected = "bab";  // "aba" is also OK
  EXPECT_EQ(expected, sol.longestPalindrome(s));

  s = "cbbd", expected = "bb";
  EXPECT_EQ(expected, sol.longestPalindrome(s));

  s = "a", expected = "a";
  EXPECT_EQ(expected, sol.longestPalindrome(s));

  s = "ac", expected = "a";
  EXPECT_EQ(expected, sol.longestPalindrome(s));

  exit(EXIT_SUCCESS);
}
