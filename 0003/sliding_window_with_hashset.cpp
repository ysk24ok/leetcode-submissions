#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    size_t l = 0, r = 0;
    unordered_set<char> uniq_chars;
    int longest = 0;
    while (r < s.size()) {
      if (uniq_chars.find(s[r]) == uniq_chars.end()) {
        longest = max(static_cast<int>(r - l + 1), longest);
        uniq_chars.insert(s[r++]);
      } else {
        uniq_chars.erase(s[l++]);
      }
    }
    return longest;
  }
};

int main() {
  Solution sol;
  string s;
  int expected;

  s = "abcabcbb", expected = 3;
  EXPECT_EQ(expected, sol.lengthOfLongestSubstring(s));

  s = "bbbbb", expected = 1;
  EXPECT_EQ(expected, sol.lengthOfLongestSubstring(s));

  s = "pwwkew", expected = 3;
  EXPECT_EQ(expected, sol.lengthOfLongestSubstring(s));

  s = "", expected = 0;
  EXPECT_EQ(expected, sol.lengthOfLongestSubstring(s));

  s = "abba", expected = 2;
  EXPECT_EQ(expected, sol.lengthOfLongestSubstring(s));

  s = "dvdf", expected = 3;
  EXPECT_EQ(expected, sol.lengthOfLongestSubstring(s));

  exit(EXIT_SUCCESS);
}
