#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) { return 0; }
    unordered_map<char, int> map;
    size_t start = 0;
    int ret = 1;
    map[s[0]]++;
    for (size_t end = 1; end < s.size(); ++end) {
      const char& c = s[end];
      if (map.find(c) != map.end() && map[c] > 0) {
        while (map[c] > 0) {
          map[s[start]]--;
          start++;
        }
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

  exit(EXIT_SUCCESS);
}
