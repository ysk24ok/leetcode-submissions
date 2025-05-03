#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // The value is 1 if the character (key) is seen in the current substring, 0 otherwise.
    unordered_map<char, int> map;
    size_t start = 0;
    int ret = 0;
    for (size_t end = 0; end < s.size(); ++end) {
      const char& c = s[end];
      if (map.find(c) != map.end() && map[c] > 0) {
        // Move the left pointer to the right until there is no overlapped character in the current substring.
        while (map[c] > 0) { map[s[start++]]--; }
      }
      map[c]++;
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
