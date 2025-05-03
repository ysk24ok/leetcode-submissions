#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // key is a character, value is an index of the key
    unordered_map<char, size_t> map;
    size_t start = 0;
    int ret = 0;
    for (size_t end = 0; end < s.size(); ++end) {
      const char& c = s[end];
      if (map.find(c) != map.end()) {
        start = max(map[c] + 1, start);
      }
      map[c] = end;
      ret = max(static_cast<int>(end - start + 1), ret);
    }
    return ret;
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
